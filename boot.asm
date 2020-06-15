[org 0x7c00] ; tell the assembler that our offset is bootsector code

mov bx, HELLO
call print

call print_nl ; new line

jmp $

%include "print.asm"
%include "print_hex.asm"

; data
HELLO:
    db 'Hello, World', 0

; padding and magic number
times 510-($-$$) db 0
dw 0xaa55