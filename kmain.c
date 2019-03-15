void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);


int main() {
    fb_write_cell(0, 'A', 2, 8);
    return 0;
}

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
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg) {
    char *fb = (char *) 0x000B8000;
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

struct example {
    unsigned char config;   /* bit 0 - 7   */
    unsigned short address; /* bit 8 - 23  */
    unsigned char index;    /* bit 24 - 31 */
} __attribute__((packed));