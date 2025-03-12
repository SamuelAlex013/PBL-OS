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

### Compiling kernel.c:
```sh
gcc -m32 -fno-stack-protector -fno-builtin -c src/kernel.c -o kernel.o
```
### Compiling boot.s:
```sh
nasm -f elf32 src/boot.asm -o boot.o
```
### Linker link:
```sh
ld -m elf_i386 -T src/linker.ld -o kernel kernel.o boot.o
```

### Move to kernel to boot:
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
qemu-system-x86_64 -cdrom PBL-OS.iso
```
