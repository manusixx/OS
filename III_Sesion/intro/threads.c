#include <stdio.h>          // Permite usar printf() y fprintf()
#include <stdlib.h>         // Permite usar atoi() y exit()
#include "common.h"         // Utilidades auxiliares (ej. wrappers de error)
#include "common_threads.h" // Wrappers seguros para funciones pthread

volatile int counter = 0;   // Variable global compartida entre hilos (volatile evita optimizaciones agresivas del compilador)
int loops;                  // Variable global que indica cuántas veces incrementará cada hilo

void *worker(void *arg) {   // Función que ejecutará cada hilo
    int i;                  // Variable local del hilo (está en el stack del hilo)
    for (i = 0; i < loops; i++) {  // Ejecuta 'loops' veces
        counter++;          // Incrementa la variable global compartida (OPERACIÓN NO ATÓMICA)
    }
    return NULL;            // Termina la ejecución del hilo
}

int main(int argc, char *argv[]) {   // Función principal del programa

    if (argc != 2) {                 // Verifica que el usuario pase exactamente un argumento
	fprintf(stderr, "usage: threads <loops>\n");  // Mensaje de error
	exit(1);                         // Termina el programa
    } 

    loops = atoi(argv[1]);           // Convierte el argumento a entero y lo guarda en variable global

    pthread_t p1, p2;                // Declara dos identificadores de hilo

    printf("Initial value : %d\n", counter);  // Imprime el valor inicial del contador (0)

    Pthread_create(&p1, NULL, worker, NULL);  // Crea el primer hilo que ejecuta worker()
    Pthread_create(&p2, NULL, worker, NULL);  // Crea el segundo hilo que ejecuta worker()

    Pthread_join(p1, NULL);          // Espera a que el hilo p1 termine
    Pthread_join(p2, NULL);          // Espera a que el hilo p2 termine

    printf("Final value   : %d\n", counter);  // Imprime el valor final del contador

    return 0;                        // Termina el programa
}

