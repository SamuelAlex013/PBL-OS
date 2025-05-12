#include "screen.h"
#include <stdint.h>

static int cursor_row = 0;
static int cursor_col = 0;

static inline void outb(uint16_t port, uint8_t val) {
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

void update_cursor(int row, int col) {
    uint16_t pos = row * MAX_X + col;

    outb(0x3D4, 0x0F);       // Tell VGA we are setting the low cursor byte
    outb(0x3D5, (uint8_t)(pos & 0xFF));
    outb(0x3D4, 0x0E);       // Now the high byte
    outb(0x3D5, (uint8_t)((pos >> 8) & 0xFF));
}


void clear() {
    uint16_t* vga = (uint16_t*)VGA_ADDRESS;
    for (int i = 0; i < MAX_X * MAX_Y; i++) {
        vga[i] = (WHITE_ON_BLACK << 8) | ' ';
    }
    cursor_row = 0;
    cursor_col = 0;
    update_cursor(cursor_row, cursor_col);
}


void print_char(char c) {
    uint16_t* vga = (uint16_t*)VGA_ADDRESS;

    if (c == '\n') {
        cursor_row++;
        cursor_col = 0;
    } else {
        int offset = cursor_row * MAX_X + cursor_col;
        vga[offset] = (WHITE_ON_BLACK << 8) | c;
        cursor_col++;
        if (cursor_col >= MAX_X) {
            cursor_col = 0;
            cursor_row++;
        }
    }
    update_cursor(cursor_row, cursor_col);
}


void print(const char *str) 
{
    for (int i = 0; str[i] != '\0'; i++) 
    {
        print_char(str[i]);
    }
}