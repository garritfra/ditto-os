#ifndef INCLUDE_IO
#define INCLUDE_IO


/** outb
 * Write bytes to an I/O port.
 * 
 * @param port The address of the I/O port
 */
extern void outb(unsigned short port, unsigned char data);

/** inb:
 *  Read a byte from an I/O port.
 *
 *  @param  port The address of the I/O port
 *  @return      The read byte
 */
unsigned char inb(unsigned short port);

#endif