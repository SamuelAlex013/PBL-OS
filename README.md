# PBL-OS

## Overview
PBL-OS is a minimalistic operating system designed as part of our OS project. It is bootable via a USB drive and features a custom kernel, basic command-line functionality, and a minimal UI.

## Features
- Custom bootloader using GRUB
- Basic kernel functionality
- Command-line shell (to be implemented)
- Simple filesystem (to be implemented)
- Minimal graphical interface (to be implemented)

## Required Tools for Development

### 1. Compiler & Build Tools
- `gcc` – To compile C code.
- `nasm` – To assemble assembly files (`boot.asm`).
- `ld` – GNU linker to link object files.

### 2. Bootloader & GRUB Tools
- `grub-pc-bin` – Provides GRUB bootloader binaries.
- `grub-common` – Required for GRUB utilities.
- `grub-mkrescue` – To create bootable ISO images.

### 3. ISO & Disk Image Tools
- `xorriso` – Used to create and manipulate ISO images.
- `mtools` – Helps in managing disk images without mounting them.

### 4. Emulator & Virtualization
- `qemu-system-x86` – To test the OS in a virtual machine.

## Installation & Setup
1. Install the necessary tools using the provided script:
   ```sh
   chmod +x tools.sh
   ./tools.sh
   ```
2. Build the OS:
   ```sh
   chmod +x build.sh
   ./build.sh
   ```
3. Run the OS in QEMU:
   ```sh
   qemu-system-x86_64 -cdrom PBL-OS.iso
   ```