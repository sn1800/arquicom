section .data
    binstr db "10101010"

section .bss
    respuesta resb 1 ; resb 1 => reservar 1 byte sin inicializar

section .text
    global _start

_start:
    mov r15,binstr ;  guardar la posicion de memoria (direccion) de binstr al registro r15
    mov r14,128
    mov r13,2
    mov r12,0

mulbuc:
    mov al,[r15] ; estoy guardando en al el valor de "1"=49
    sub al,48 ; al = 1 (convertido de caracter a número) para convertir de caracter a número
    mul r14; RDX:RAX = RAX*R14
    add r12,rax; acumular r12

sigpa:
    xor rdx,rdx  ; anulo rdx -> 00000000 : xxxxxxxx
    mov rax,r14 ; pasar el valor de r14 al rax por la division
    div r13 ; division en 2
    mov r14,rax ; guardar el valor dividido en r14
    inc r15 ; siguiente direccion del caracter
    cmp r14,0 