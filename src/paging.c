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

    // Identity-map first 4MB of memory (1 page table worth)
    for (int i = 0; i < 1024; i++) {
        page_table[i] = (i * 0x1000) | 3; // Present, read/write
    }

    // Specifically ensure 0xB8000 is mapped (optional redundancy)
    page_table[0xB8] = 0xB8000 | 3; // Explicitly map video memory

    // Set page directory to use our page table
    page_directory[0] = ((uint32_t)page_table) | 3;

    // Load page directory base register
    asm volatile("mov %0, %%cr3" : : "r"(page_directory));

    // Enable paging
    uint32_t cr0;
    asm volatile("mov %%cr0, %0" : "=r"(cr0));
    cr0 |= 0x80000000; // Set PG bit (bit 31) to enable paging
    asm volatile("mov %0, %%cr0" : : "r"(cr0));

    print("Paging enabled!\n");
}
