#include <stdio.h>

// Función para calcular la raíz cuadrada usando el método de Newton
double sqrt_newton(double n) {
    double x = n;
    double y = 1.0;
    double epsilon = 0.15;  // Precisión deseada

    while (x - y > epsilon) {
        x = (x + y) / 2;
        y = n / x;
    }

    return x;
}

int main() {
    double num;
    printf("Ingrese un número: ");
    scanf("%lf", &num);

    if (num < 0) {
        printf("No se puede calcular la raíz cuadrada de un número negativo en C.\n");
    } else {
        double result = sqrt_newton(num);
        printf("La raíz cuadrada de %lf en C es %lf\n", num, result);
    }

    //ahora mediante asm
    

    return 0;
}