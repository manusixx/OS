# Introducción – Ejemplos básicos de ejecución de programas

Esta carpeta contiene ejemplos utilizados para introducir conceptos fundamentales sobre la **ejecución de programas y el comportamiento del sistema operativo**.

Los ejemplos están basados en materiales del libro: Operating Systems: Three Easy Pieces (OSTEP), dentro de la sección de introducción http://pages.cs.wisc.edu/~remzi/OSTEP/intro.pdf

El objetivo es observar cómo distintos programas utilizan los recursos del sistema.

---

# Archivos incluidos

```text
intro
│
├── cpu.c
├── io.c
├── mem.c
├── threads.c
├── preprocesado.c
│
├── common.h
├── common_threads.h
│
├── Makefile
└── salida.txt
```

---

# Compilación

Los programas pueden compilarse mediante el `Makefile`.

```bash
make
make clean
```

Esto generará los ejecutables:

```text
cpu
io
mem
threads
```

También pueden compilarse manualmente, por ejemplo:

```bash
gcc cpu.c -o cpu
```

---

# Programas incluidos

## cpu.c

Programa que realiza trabajo de CPU intenso.

Permite observar cómo el sistema operativo ejecuta un programa que consume principalmente el **tiempo de procesador**.

**Ejemplo de ejecución:**
**1er ejemplo** 
```bash
./cpu A
```
<img width="1013" height="619" alt="image" src="https://github.com/user-attachments/assets/8d12b827-62c8-4353-91b2-ef93b1c1d822" />

**2do ejemplo** 
```bash
./cpu A & ./cpu B ./cpu c & ./cpu d 
```
<img width="1407" height="754" alt="image" src="https://github.com/user-attachments/assets/064a3ade-2342-466f-b049-28050d08fdb3" />

---

## io.c

Programa dominado por **operaciones de entrada/salida**.

Este ejemplo permite comparar el comportamiento de un programa que pasa gran parte del tiempo esperando operaciones de I/O. En este caso acceso al disco duro

**Ejemplo de ejecución:**
```bash
./io
cat /tmp/file
```
<img width="1017" height="114" alt="image" src="https://github.com/user-attachments/assets/f50ff9ca-8def-4346-bc88-818a676f216b" />

---

## mem.c

Ejemplo que explora el uso de la **memoria**.

Permite observar cómo los programas utilizan la memoria y cómo el sistema operativo administra este recurso.
**Ejemplo de ejecución:**

**1er ejemplo**
```bash
./mem 10
```
<img width="975" height="525" alt="image" src="https://github.com/user-attachments/assets/a224c3d4-e188-43d7-9211-a96693c61278" />

**2do ejemplo**
```bash
./mem 10 & ./mem 10
```
<img width="1024" height="253" alt="image" src="https://github.com/user-attachments/assets/a633706e-42a4-4e18-8192-4f1c2feb212c" />

---

## threads.c

Ejemplo simple de uso de **hilos (threads)**.

Permite observar cómo múltiples hilos pueden ejecutarse en un mismo proceso.

**Ejemplo de ejecución:**

**1er ejemplo**
```bash
./threads 1000
```
<img width="1093" height="196" alt="image" src="https://github.com/user-attachments/assets/8592ace0-1758-49e1-8fbb-ae3eb09994bb" />

**2do ejemplo repetir la misma instrucción muchas veces con un valor alto. Esto permite ver una condición de carrera**
```bash
./threads 10000000
```
<img width="1001" height="327" alt="image" src="https://github.com/user-attachments/assets/ed1b5e01-6a00-4cbe-8b41-3f3061cf4eb9" />


---

## preprocesado.c

Ejemplo que ilustra el proceso de **preprocesamiento del compilador en C**.

---

# Experimentos sugeridos

Ejecute los programas y observe su comportamiento utilizando herramientas del sistema:

```bash
ps
```

o

```bash
top
```

También puede ejecutar múltiples instancias del mismo programa para observar cómo el sistema operativo gestiona





