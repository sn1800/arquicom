#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


float sqrt_newton(float n);
extern void asmSquareNewton();


int main() {
    float num;
    printf("Ingrese un número: ");
    scanf("%lf", &num);

    if (num < 0) {
        printf("No se puede calcular la raíz cuadrada de un número negativo en C.\n");
    } else {

        double result = sqrt_newton(num);
        printf("La raíz cuadrada de %lf en C es %lf\n", num, result);
        elapsed = (tf.tv_sec - ti.tv_sec) * 1e9 + (tf.tv_nsec - ti.tv_nsec);
        printf("el tiempo en nanosegundos que toma la función en C es %lf\n", elapsed);


        //asmSquareNewton();
        //elapsed = (tf.tv_sec - ti.tv_sec) * 1e9 + (tf.tv_nsec - ti.tv_nsec);
        //printf("el tiempo en nanosegundos que toma la función en asm es %lf\n", elapsed);




    }
    
    //ahora mediante asm


    return 0;
}

// Función para calcular la raíz cuadrada usando el método de Newton
float sqrt_newton(float n) {
    float x = n;
    float y = 1.0;
    float epsilon = 0.15;  // Precisión deseada

    while (x - y > epsilon) {
        x = (x + y) / 2;
        y = n / x;
    }

    return x;
}