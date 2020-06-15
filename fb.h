#ifndef INCLUDE_FRAMEBUFFER
#define INCLUDE_FRAMEBUFFER

#include "io.h"

/* The I/O ports */
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND 15

#define VGA_COLOR_BLACK 0
#define VGA_COLOR_BLUE 1
#define VGA_COLOR_GREEN 2
#define VGA_COLOR_CYAN 3
#define VGA_COLOR_RED 4
#define VGA_COLOR_MAGENTA 5
#define VGA_COLOR_BROWN 6
#define VGA_COLOR_LIGHT_GREY 7
#define VGA_COLOR_DARK_GREY 8
#define VGA_COLOR_LIGHT_BLUE 9
#define VGA_COLOR_LIGHT_GREEN 10
#define VGA_COLOR_LIGHT_CYAN 11
#define VGA_COLOR_LIGHT_RED 12
#define VGA_COLOR_LIGHT_MAGENTA 13
#define VGA_COLOR_LIGHT_BROWN 14
#define VGA_COLOR_WHITE 15

#define KBD_DATA_PORT   0x60


int fb_write(char *buf, unsigned int len);



/** fb_write_cell:
    *  Writes a character with the given foreground and background to position i
    *  in the framebuffer.
    * 
    *  @param i  The location in the framebuffer
    *  @param c  The character
    *  @param fg The foreground color
    *  @param bg The background color
    *
    *  @example fb_write_cell(0, 'A', 2, 8);
    */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);

/** fb_move_cursor:
     *  Moves the cursor of the framebuffer to the given position
     *
     *  @param pos The new position of the cursor
     */
void fb_move_cursor(unsigned short pos);

unsigned short get_cursor_position(void);

void advance_cursor(void);

#endif /* INCLUDE_IO_H */