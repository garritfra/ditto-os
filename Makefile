prog: bin image

image:
	dd status=noxfer conv=notrunc if=boot.bin of=dittoOS.img

bin:
	nasm -f bin -o boot.bin boot.asm

run: prog
	qemu-system-x86_64 dittoOS.img