#include <stdio.h>      // Permite usar sprintf()
#include <unistd.h>     // Permite usar write(), close() y fsync()
#include <assert.h>     // Permite usar assert()
#include <fcntl.h>      // Permite usar open() y las banderas O_*
#include <sys/stat.h>   // Define constantes de permisos como S_IRUSR, S_IWUSR
#include <sys/types.h>  // Define tipos usados por llamadas al sistema
#include <string.h>     // Permite usar strlen()

int main(int argc, char *argv[]) {
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    // Abre el archivo "/tmp/file"
    // O_WRONLY  → solo escritura
    // O_CREAT   → lo crea si no existe
    // O_TRUNC   → si existe, borra su contenido
    // S_IRUSR   → permiso de lectura para el usuario propietario
    // S_IWUSR   → permiso de escritura para el usuario propietario
    // Devuelve un descriptor de archivo (fd)

    assert(fd >= 0);
    // Verifica que open() no haya fallado
    // Si falla devuelve -1 y el programa termina

    char buffer[20];
    // Declara un arreglo de 20 bytes en el stack

    sprintf(buffer, "hello world\n");
    // Escribe la cadena "hello world\n" dentro del buffer

    int rc = write(fd, buffer, strlen(buffer));
    // write():
    // fd → descriptor del archivo
    // buffer → contenido a escribir
    // strlen(buffer) → cantidad de bytes a escribir
    // Devuelve el número de bytes escritos

    assert(rc == (strlen(buffer)));
     // Verifica que se hayan escrito todos los bytes

    fsync(fd);
    // Fuerza a que los datos pendientes se escriban físicamente en disco
    // Garantiza persistencia (no solo en caché del kernel)

    close(fd);
    // Cierra el descriptor de archivo
    // Libera el recurso en el kernel
    
    return 0;
}

