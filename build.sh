#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

#Moving grub configuration file to iso directory
cp boot/grub/grub.cfg iso/boot/grub/grub.cfg
echo "grub.cfg moved to boot directory."

# Compile the C kernel file
gcc -m32 -fno-stack-protector -fno-builtin -c src/kernel.c -o kernel.o
echo "Kernel compiled successfully."

# Assemble the boot assembly file
nasm -f elf32 src/boot.asm -o boot.o
echo "Bootloader assembled successfully."

# Link the object files using the linker script
ld -m elf_i386 -T src/linker.ld -o kernel boot.o kernel.o
echo "Kernel linked successfully."

# Move the kernel to the iso directory
mv kernel iso/kernel
echo "Kernel moved to iso directory."

# Create the bootable ISO image with verbose output
grub-mkrescue -o PBL-OS.iso iso/
echo "Bootable ISO created successfully."

#delete the object files
rm -rf *.o
echo "Object files deleted."


# Run the OS in QEMU
qemu-system-i386 -cdrom PBL-OS.iso

