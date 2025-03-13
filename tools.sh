# Update package list
sudo apt update

# Install required development tools
sudo apt install -y gcc nasm binutils grub-pc-bin grub-common grub-mkrescue xorriso mtools qemu-system-x86 gdb gdb-multiarch

# Confirm installation
echo "All necessary tools have been installed successfully."
