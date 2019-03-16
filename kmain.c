#include "kmain.h"
#include "io.h"

int main()
{
    fb_write_cell(0, 'A', 0, 15);
    fb_write_cell(2, 'B', 0, 15);
    fb_write_cell(4, 'C', 0, 15);
    fb_move_cursor(6);
    return 0;
}