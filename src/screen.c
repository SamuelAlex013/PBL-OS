#include "screen.h"
#include <stdint.h>

void clear()
{
    uint16_t* vga = (uint16_t*)VGA_ADDRESS;
    for(int i = 0; i < MAX_X * MAX_Y; i++)
    {
        vga[i] = (0x0F << 8) | ' ';
    }
}

void print(const char *str)
{
    uint16_t* vga = (uint16_t*)VGA_ADDRESS;
    for(int i = 0; str[i] != '\0'; i++)
    {
        vga[i] = (WHITE_ON_BLACK << 8) | str[i];
    }
}