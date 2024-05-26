#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


float sqrt_newton(float n);
extern void asmSquareNewton(int num,float &resultado);


int main() {
    float num;
    struct timespec ti, tf;
    double elapsed;
    // semilla para los números aleatorios
    srandom(time(NULL));


    printf("Ingrese un número: ");
    scanf("%f", &num);

    if (num < 0) {
        printf("No se puede calcular la raíz cuadrada de un número negativo en C.\n");
    } else {
        clock_gettime(CLOCK_REALTIME, &ti);
        float result = sqrt_newton(num);
        clock_gettime(CLOCK_REALTIME, &tf);
        printf("La raíz cuadrada de %f en C es %f\n", num, result);
        elapsed = (tf.tv_sec - ti.tv_sec) * 1e9 + (tf.tv_nsec - ti.tv_nsec);
        printf("el tiempo en nanosegundos que toma la función en C es %lf\n", elapsed);


        clock_gettime(CLOCK_REALTIME, &ti);
        asmSquareNewton(num,result);
        clock_gettime(CLOCK_REALTIME, &tf);
        elapsed = (tf.tv_sec - ti.tv_sec) * 1e9 + (tf.tv_nsec - ti.tv_nsec);
        printf("el tiempo en nanosegundos que toma la función en asm es %lf\n", elapsed);




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