#include <stdint.h>
#include "screen.h"
#include "pagging.h"

void sleep(int ms)
{
    for (volatile int i = 0; i < ms * 1000; i++);
}

void kmain()
{
    print("Hello, Kernel World!");
    print("Welcome to the OS!");
    sleep(1000);
    paging();
    while(1);
}