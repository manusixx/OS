#include <unistd.h>     // Permite usar getpid()
#include <stdio.h>      // Permite usar printf() y fprintf()
#include <stdlib.h>     // Permite usar malloc(), atoi() y exit()
#include "common.h"     // Define la función Spin()

int main(int argc, char *argv[]) {   // Función principal del programa

    if (argc != 2) {                 // Verifica que el usuario pase exactamente 1 argumento
	fprintf(stderr, "usage: mem <value>\n");  // Imprime mensaje de error en stderr
	exit(1);                         // Termina el programa con código de error 1
    } 

    int *p;                          // Declara un puntero a entero (se almacenará en el stack)

    p = malloc(sizeof(int));         // Reserva memoria en el heap para un entero

    assert(p != NULL);               // Verifica que la reserva fue exitosa (si falla, aborta)

    printf("(%d) addr pointed to by p: %p\n", (int) getpid(), p);
    // Imprime:
    //  - El PID del proceso
    //  - La dirección virtual de memoria asignada en el heap

    *p = atoi(argv[1]);              // Convierte el argumento recibido a entero y lo almacena en la dirección apuntada por p

    while (1) {                      // Bucle infinito

	Spin(1);                         // Espera activa 1 segundo (consume CPU)

	*p = *p + 1;                     // Incrementa el valor almacenado en el heap

	printf("(%d) value of p: %d\n", getpid(), *p);
        // Imprime:
        //  - El PID del proceso
        //  - El valor actual almacenado en la memoria dinámica
    }

    return 0;                        // Nunca se ejecuta (el ciclo es infinito)
}