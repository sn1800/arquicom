section .data
    binstr db "10101010"

section .bss
    respuesta resb 1 ; resb 1 => reservar 1 byte sin inicializar

section .text
    global _start

_start:
    mov r15,binstr ;  guardar la posicion de memoria (direccion) de binstr al registro r15
