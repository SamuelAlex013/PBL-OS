BITS 32

section .multiboot
    ALIGN 4
    DD 0x1BADB002
    DD 0x00
    DD -(0x1BADB002 + 0x00)

section .text
    global start
    extern kmain

start:
    CLI
    MOV esp, stack_space
    CALL kmain
    HLT

HaltKernel:
    CLI
    HLT
    JMP HaltKernel

section .bss
    ALIGN 4
    RESB 8192
stack_space:
