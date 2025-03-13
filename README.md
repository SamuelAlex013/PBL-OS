# PBL-OS

## Project Structure
```
PBL-OS/
├── PBL/
│   ├── boot/
│   │   ├── grub/
│   │   │   ├── grub.cfg
│   │   ├── kernel
│   ├── src/
│       ├── boot.asm
│       ├── kernel.c
│       ├── linker.ld
├── .gitignore
├── build.sh
├── PBL-OS.iso
├── README.md
```

## Description
PBL-OS is a minimalistic operating system designed as a project to understand OS fundamentals, including bootloaders, kernel development, and low-level system programming.

## Components
- **Bootloader**: Configured with GRUB, located in `boot/grub/grub.cfg`.
- **Kernel**: Main kernel binary found in `boot/kernel`, built from `src/kernel.c`.
- **Assembly Boot Code**: `src/boot.asm` is responsible for low-level initialization.
- **Linker Script**: `src/linker.ld` manages how different parts of the OS are linked together.
- **Build Script**: `build.sh` compiles and assembles the OS into an ISO file.

## Building the OS
To build and generate the bootable ISO:
```sh
chmod +x build.sh
./build.sh
```

## Running in QEMU
To test the OS in a virtual environment:
```sh
qemu-system-x86_64 -cdrom PBL-OS.iso
```

## Current Status
- The OS successfully boots into GRUB and loads the kernel.
- Basic structure is in place for further development.
