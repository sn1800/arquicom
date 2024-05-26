
#include <stdio.h>
void print_hola_mundo(int a , int b , int *c){
    *c = a + b;
    printf("Hola mundo\n");
}