section .data
    A dd 1;valor del limite inferior
    B dd 20;valor del limite superior
    NUMERO dd 1;valor del numero
section .bss
    CantParejas resd 1 ; reservar 4 bytes para la cantidad de parejas
section .text
    global _start

_start:
    