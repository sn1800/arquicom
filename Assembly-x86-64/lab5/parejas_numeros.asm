section .data
    A dd 1;valor del limite inferior
    B dd 20;valor del limite superior
    NUMERO dd 1;valor del numero
section .bss
    CantParejas resd 1 ; reservar 4 bytes para la cantidad de parejas
section .text
    global _start

_start:

mov rcx , 0 ; contador de iterador
mov rbx , [A]; asignamos al registro rbx el valor de A
loop:
    mov rax , rbx
    mul [NUMERO];y= A*NUMERO
    cmp rax , [B]
    jg loop_end

    inc [CantParejas]
    inc rcx

    cmp rcx , [B]
    jle loop

loop_end:
    ; Salida del programa
    mov rax, 60                ; syscall: exit
    xor rdi, rdi               ; status 0
    syscall                    ; llamar al kernel
.done:
    ret