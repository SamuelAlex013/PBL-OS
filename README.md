# PBL-OS

## Directory Structure
```

```

## Prerequisites
Before testing the OS, ensure you have the following installed:
- GCC (for compiling the kernel)
- NASM (for assembling the kernel in assembly language)
- GRUB (for bootloader setup)
- QEMU (for testing the OS in a virtualized environment)

## Building the Kernel

### Compile the C kernel file:
```sh
gcc -m32 -fno-stack-protector -fno-builtin -c src/kernel.c -o kernel.o
```
### Assemble the boot assembly file:
```sh
nasm -f elf32 src/boot.asm -o boot.o
```
### Link the object files using the linker script::
```sh
ld -m elf_i386 -T src/linker.ld -o kernel boot.o kernel.o
```

### Move the kernel to the boot directory:
```sh
mv kernel boot/kernel
```

## Creating a Bootable ISO
Run the following command to create a bootable ISO:
```sh
grub-mkrescue -o PBL-OS.iso boot/
```

## Testing with QEMU
To run the OS using QEMU, execute:
```sh
qemu-system-i386 -cdrom PBL-OS.iso
```
