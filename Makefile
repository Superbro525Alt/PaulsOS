all: setup build iso run

setup:
	./setup.sh

build:
	./build.sh

iso:
	./iso.sh

run:
	./qemu.sh

clean:
	./clean.sh
