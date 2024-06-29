section .data
    msg db 'Hola Mundo', 0xA  ; El mensaje a imprimir con un salto de línea

section .bss

section .text
    global _start

_start:
    ; Escribir el mensaje
    mov rax, 1            ; syscall: sys_write
    mov rdi, 1            ; file descriptor: stdout
    mov rsi, msg          ; pointer to message
    mov rdx, 11           ; message length
    syscall               ; llamar al kernel

    ; Salir del programa
    mov rax, 60           ; syscall: sys_exit
    xor rdi, rdi          ; exit code: 0
    syscall               ; llamar al kernel