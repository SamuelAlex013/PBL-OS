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
If your kernel is in assembly:
```sh
nasm -f bin src/kernel.asm -o boot/kernel.bin
```
If transitioning to C, compile it with:
```sh
gcc -ffreestanding -c src/kernel.c -o boot/kernel.o
ld -T linker.ld -o boot/kernel.bin boot/kernel.o
```

## Configuring GRUB
Ensure `grub.cfg` contains the following:
```cfg
menuentry "PBL-OS" {
    multiboot /boot/kernel.bin
    boot
}
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
