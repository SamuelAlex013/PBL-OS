#include "pagging.h"
#include "screen.h"
#include <stdint.h>


void paging()
{
    uint32_t *page_directory = (uint32_t *)0x00000000; // Page directory base address
    uint32_t *page_table = (uint32_t *)0x00001000;     // Page table base address

    // Clear the page directory and page table
    for (int i = 0; i < 1024; i++) {
        page_directory[i] = 0;
        page_table[i] = 0;
    }

    // Set up the first page table entry
    page_table[0] = 0x00000000 | 3; // Present, read/write, user mode

    // Set up the first page directory entry
    page_directory[0] = ((uint32_t)page_table) | 3; // Present, read/write, user mode

    // Load the page directory base register
    asm volatile("mov %0, %%cr3" : : "r"(page_directory));

    // Enable paging
    uint32_t cr0;
    asm volatile("mov %%cr0, %0" : "=r"(cr0));
    cr0 |= 1; // Set the PG bit to enable paging
    asm volatile("mov %0, %%cr0" : : "r"(cr0));

}