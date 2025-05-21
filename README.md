# 🖥️ PBL-OS – A Minimal x86 Operating System

PBL-OS is a minimalist 32-bit operating system developed from scratch to explore core OS concepts such as bootloading, kernel development, memory layout, and low-level system programming.

## 📁 Project Structure
```

PBL-OS/
├── PBL/
│ └── boot/
│ ├── grub/
│ │ └── grub.cfg # GRUB bootloader configuration
│ └── kernel # Compiled kernel
├── src/
│ ├── boot.asm # Assembly boot code
│ ├── kernel.c # Kernel written in C
│ └── linker.ld # Linker script for memory layout
├── build.sh # Build automation script
├── tools.sh # Optional helper tools
├── PBL-OS.iso # Output bootable ISO image
└── README.md # Project documentation

```


## ⚙️ Components

- **Bootloader**: Uses GRUB (via `grub.cfg`) to load the kernel at boot time.
- **Kernel**: Written in C, performs basic OS functions like printing and I/O.
- **Boot Code**: Assembly code (`boot.asm`) sets up initial CPU state and loads the kernel.
- **Linker Script**: Defines memory layout for linking the kernel ELF file.
- **Build Scripts**: `build.sh` compiles everything and creates the ISO.

## 🛠️ Build Instructions

### 🔧 Requirements

Ensure the following tools are installed:

- `nasm` – for assembling boot code
- `gcc` – for compiling C code
- `ld` – linker
- `grub-mkrescue` – to generate ISO

### 🧪 Build Command

```bash
chmod +x build.sh
./build.sh
```
This will output a file named PBL-OS.iso which you can boot using an emulator or burn to a USB drive.

💻 How to Run
To test using QEMU:
```bash
qemu-system-i386 -cdrom PBL-OS.iso
```

