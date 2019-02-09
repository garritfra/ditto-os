	BITS 16



start:
	mov ax, 07C0h	; Set up 4K stack space after this bootloader
	add ax, 288		; (4096 + 512) / 16 bytes per paragraph
	mov ss, ax
	mov sp, 4096

	mov ax, 07C0h	; Set data segment to where we're loaded
	add ax, 255
	mov ds, ax  

main_loop:	
    call read_char  ; Read character
    jmp main_loop   ; Repeat

read_char:
    mov ah, 0h      ; Call Function "Read Char"
    int 16h         ; Execute Keyboard Services
    
    mov ah, 0eh     ; Call Function "Write char to TTY
    int 10h         ; Execute Video Services

    cmp AL, 0x0d    ; Insert new line, if keystroke was return
    je new_line

    ret

new_line:
    mov AH, 03h     ; Get Cursor position
    int 10h

    add DH, 1       ; Add 1 to cursor position

    mov AH, 02h     ; Set Cursor to new position
    int 10h
    ret

print_string:		; Routine: output string in SI to screen
	mov ah, 0Eh		; int 10h 'print char' function

.repeat:
	lodsb			; Get character from string
	cmp al, 0
	je .done		; If char is zero, end of string
	int 10h			; Otherwise, print it
	jmp .repeat

.done:
	ret


	times 510-($-$$) db 0	; Pad remainder of boot sector with 0s
	dw 0xAA55		; The standard PC boot signature


