#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

   struct timespec ti, tf;
    double elapsed;
    

    clock_gettime(CLOCK_REALTIME, &ti);
    unsigned long long arr[199];
    unsigned long long num = 50, a_n_menos1=1, a_n_menos2=0, suma=0, jacob = 0, contador = 0;
    arr[0] = 0; arr[1] = 1;
    for(int i=2; i<num; i++){
      jacob = a_n_menos1 + 2*a_n_menos2;
      arr[i] = jacob;
      a_n_menos2 = a_n_menos1;  // a_n_menos1 = 0
      a_n_menos1 = jacob; // a_n_menos2 = 1
    }
    for(int i=0; i<num; i++){
        suma +=(arr[i]);
    }
    clock_gettime(CLOCK_REALTIME, &tf);
     elapsed =  (tf.tv_nsec - ti.tv_nsec);
    printf("El tiempo en nanosegundos que toma la función en C es %.2lf\n", elapsed);
    printf("La suma de los primeros 50 numeros es: %lld\n ", suma);

}