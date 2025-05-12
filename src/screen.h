#ifndef SCREEN_H
#define SCREEN_H


#define VGA_ADDRESS 0xB8000
#define MAX_X 80
#define MAX_Y 25
#define WHITE_ON_BLACK 0x0F

void clear();
void print(const char *);

#endif