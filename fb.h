#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

/* The I/O ports */
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND 15

int write(char *buf, unsigned int len);

extern void outb(unsigned short port, unsigned char data);

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

#endif /* INCLUDE_IO_H */