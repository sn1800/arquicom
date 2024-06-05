#include <stdio.h>
#include <time.h>

void fibonacci_array(int n);
void fibonacci_accumulator(int n);

int main() {
    int n = 10;

    // Medir el tiempo de ejecución de la función con arreglos
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    fibonacci_array(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución (arreglos): %f segundos\n", cpu_time_used);

    // Medir el tiempo de ejecución de la función con acumulador
    start = clock();
    fibonacci_accumulator(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución (arreglos): %f segundos\n", cpu_time_used);

    return 0;
}

void fibonacci_array(int n) {
    int fib[n]; // Array para almacenar los números de Fibonacci

    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("Fibonacci sequence using array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}
void fibonacci_accumulator(int n) {
    int a = 0, b = 1, next;

    printf("Fibonacci sequence using accumulator:\n");
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            printf("%d ", a);
            continue;
        }
        if(i == 1) {
            printf("%d ", b);
            continue;
        }
        next = a + b;
        a = b;
        b = next;
        printf("%d ", next);
    }
    printf("\n");
}