BITS 32

section .text
    ALIGN 4
    DD 0x1BADB002
    DD 0x00
    DD -(0x1BADB002 + 0x00)

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
    JMP HaltKernel ; .text section ends here

section .bss
    ALIGN 4
    RESB 8192
stack_space:

section .note.GNU-stack noalloc noexec nowrite progbits