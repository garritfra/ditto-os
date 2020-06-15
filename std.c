#include "std.h"
#include "fb.h"


void printf(char *buf) {
    fb_write(buf, strlen(buf));
}

void scanf(const char *format);

unsigned int strlen(const char *str) {
    const char *s;

    for (s = str; *s; ++s)
                ;
    return (s - str);
}