# Exit immediately if a command exits with a non-zero status
set -e

# Compile the C kernel file
gcc -m32 -ffreestanding -fno-stack-protector -fno-builtin -c src/kernel.c -o kernel.o
echo "Kernel compiled successfully."

# Complile the screen header file
gcc -m32 -ffreestanding -fno-stack-protector -fno-builtin -c src/screen.c -o screen.o
echo "Screen header compiled successfully."

gcc -m32 -ffreestanding -fno-stack-protector -fno-builtin -c src/paging.c -o paging.o
echo "paging compiled successfully."

# Assemble the boot assembly file
nasm -f elf32 src/boot.asm -o boot.o
echo "Bootloader assembled successfully."


# Link the object files using the linker script
ld -m elf_i386 -T src/linker.ld -o kernel boot.o kernel.o screen.o paging.o
echo "Kernel linked successfully."

# Move the kernel to the boot directory
mv kernel PBL/boot/kernel
echo "Kernel moved to boot directory."

# Create the bootable ISO image
grub-mkrescue -o PBL-OS.iso PBL/
echo "Bootable ISO created successfully."

#delete the object files
rm -rf *.o
echo "Object files deleted."


# Run the OS in QEMU
qemu-system-x86_64 -cdrom PBL-OS.iso