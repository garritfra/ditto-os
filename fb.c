#include "fb.h"

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg) {
    char *fb = (char *) 0x000B8000;
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

void fb_move_cursor(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos & 0x00FF);
}

/*
* Write frame buffer to screen 
*/
int fb_write(char *buf, unsigned int len) {

    for(int i = 0; i <= (int)len; i++) {
        fb_write_cell(get_cursor_position() * 2, buf[i], VGA_COLOR_BLACK, VGA_COLOR_WHITE);
        advance_cursor();
    }
    return 0;
}

/** read_scan_code:
     *  Reads a scan code from the keyboard
     *
     *  @return The scan code (NOT an ASCII character!)
     */
unsigned char read_scan_code(void) {
    return inb(KBD_DATA_PORT);
}

void advance_cursor(void) {
    fb_move_cursor(get_cursor_position() + 1);
}

unsigned short get_cursor_position(void)
{
    unsigned short pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((unsigned short)inb(0x3D5)) << 8;
    return pos;
}