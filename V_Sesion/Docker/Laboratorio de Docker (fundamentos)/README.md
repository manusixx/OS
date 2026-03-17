# Docker – Comandos básicos e intermedios

Este documento reúne los comandos de Docker necesarios para desarrollar el **Taller 4 del curso de Sistemas Operativos**.

Docker permite ejecutar aplicaciones dentro de **contenedores aislados** que comparten el kernel del sistema operativo anfitrión. Esta tecnología se basa en principios fundamentales de los sistemas operativos como el aislamiento de procesos y la gestión de recursos. 

---

# 1. Verificar instalación

Verificar que Docker está instalado correctamente:

```bash
docker --version
docker info
```

---

# 2. Ejecutar el primer contenedor

El equivalente al **hello world** en Docker:

```bash
docker container run hello-world
```

Este comando:

1. busca la imagen en Docker Hub
2. la descarga si no existe localmente
3. crea un contenedor
4. ejecuta el contenedor

---

# 3. Descargar imágenes

Descargar una imagen desde Docker Hub:

```bash
docker image pull ubuntu
docker image pull busybox
docker image pull nginx
```

Buscar imágenes disponibles:

https://hub.docker.com

---

# 4. Listar imágenes

Mostrar las imágenes descargadas en el sistema:

```bash
docker image ls
```

o

```bash
docker images
```

---

# 5. Ejecutar contenedores

Ejecutar un contenedor simple:

```bash
docker container run busybox
```

Ejecutar un comando dentro del contenedor:

```bash
docker container run busybox echo "hello world"
```

Abrir una terminal interactiva dentro del contenedor:

```bash
docker container run -it busybox sh
```

Ejecutar un contenedor Ubuntu con Bash:

```bash
docker container run -it ubuntu /bin/bash
```

---

# 6. Listar contenedores

Contenedores en ejecución:

```bash
docker container ls
```

Todos los contenedores (incluidos detenidos):

```bash
docker container ls -a
```

También se puede usar:

```bash
docker ps
docker ps -a
```

---

# 7. Detener contenedores

Detener un contenedor:

```bash
docker container stop <container-id>
```

Ejemplo:

```bash
docker container stop 34ab8f2c
```

Salir desde dentro del contenedor:

```bash
exit
```

---

# 8. Reiniciar contenedores

Iniciar nuevamente un contenedor detenido:

```bash
docker container start <container-id>
```

---

# 9. Conectarse a un contenedor

Conectarse a un contenedor en ejecución:

```bash
docker container attach <container-id>
```

Salir sin detener el contenedor:

```
Ctrl + P
Ctrl + Q
```

---

# 10. Eliminar contenedores

Eliminar un contenedor detenido:

```bash
docker container rm <container-id>
```

Eliminar todos los contenedores detenidos:

```bash
docker container rm $(docker ps -a -f status=exited -q)
```

---

# 11. Eliminar imágenes

Eliminar una imagen:

```bash
docker image rm <image-id>
```

---

# 12. Ejecutar contenedores en segundo plano

Ejecutar un contenedor como servicio:

```bash
docker container run -d nginx
```

Ver logs del contenedor:

```bash
docker logs <container-id>
```

---

# 13. Mapear puertos

Ejecutar un servidor web accesible desde el host:

```bash
docker container run -p 8080:80 nginx
```

Acceder desde navegador:

```
http://localhost:8080
```

---

# 14. Crear una imagen con Dockerfile

Construir una imagen:

```bash
docker image build -t myimage .
```

Ejemplo de Dockerfile:

```Dockerfile
FROM ubuntu
RUN apt update
RUN apt install -y htop
```

---

# 15. Crear un contenedor con Nginx personalizado

Dockerfile ejemplo:

```Dockerfile
FROM nginx:latest
COPY index.html /usr/share/nginx/html
EXPOSE 80
CMD ["nginx", "-g", "daemon off;"]
```

Construir la imagen:

```bash
docker build -t mynginx .
```

Ejecutar el contenedor:

```bash
docker run -p 8080:80 mynginx
```

---

# 16. Compartir archivos con el host

Montar un volumen entre el host y el contenedor:

```bash
docker container run -p 8080:80 -v $(pwd)/HTML:/usr/share/nginx/html nginx
```

Esto permite modificar archivos en el host y ver los cambios inmediatamente en el contenedor.

---

# 17. Comandos útiles adicionales

Ver recursos utilizados por contenedores:

```bash
docker stats
```

Inspeccionar un contenedor:

```bash
docker inspect <container-id>
```

Ver puertos expuestos:

```bash
docker port <container-id>
```

---

# Resumen del flujo de trabajo

El flujo típico en Docker es:

1. Descargar una imagen
2. Crear un contenedor a partir de la imagen
3. Ejecutar el contenedor
4. Gestionar su ciclo de vida

Esto refleja el principio fundamental:

```
Imagen → Plantilla
Contenedor → Instancia en ejecución
```

De forma análoga a:

```
Programa → Archivo en disco
Proceso → Programa en ejecución
```
