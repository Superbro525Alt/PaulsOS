```bash
sudo apt update
sudo apt-get install -y build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo libisl-dev binutils
cd ~
git clone https://github.com/bminor/binutils-gdb.git
git clone https://github.com/gcc-mirror/gcc.git
export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"
mkdir build-binutils
cd build-binutils
../binutils-gdb/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install
cd ~
mkdir build-gcc
cd build-gcc
../gcc/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
```