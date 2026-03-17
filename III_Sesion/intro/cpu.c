#include <stdio.h>      // Librería estándar para entrada/salida (printf, fprintf)
#include <stdlib.h>     // Librería estándar para utilidades (exit)
#include "common.h"     // Cabecera personalizada que probablemente define Spin()

int main(int argc, char *argv[])   // Punto de entrada del programa
{
    if (argc != 2) {   // Verifica que se pase exactamente 1 argumento adicional
        fprintf(stderr, "usage: cpu <string>\n");  // Imprime mensaje de error en stderr
        exit(1);       // Termina el programa con código de error 1
    }

    char *str = argv[1];   // Guarda el argumento recibido en un puntero a char (no copia la cadena)

    while (1) {            // Bucle infinito (condición siempre verdadera)
        printf("%s\n", str);  // Imprime el string recibido por consola
        Spin(1);              // Ejecuta espera activa durante 1 segundo (consume CPU)
    }

    return 0;   // Nunca se ejecuta, porque el ciclo es infinito
}