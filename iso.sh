#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/main_os.kernel isodir/boot/main_os.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "Continue with boot" {
	multiboot /boot/main_os.kernel
}
EOF
grub-mkrescue -o main_os.iso isodir
