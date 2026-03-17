# Taller – Docker (Nivel Intermedio)

Este laboratorio profundiza en el uso de **contenedores Docker** mediante el estudio de la persistencia de datos, la comunicación entre contenedores y la orquestación de aplicaciones multiservicio.

A lo largo del taller se construirá progresivamente una arquitectura basada en contenedores con **PostgreSQL y Drupal**, lo que permitirá comprender cómo Docker facilita el despliegue reproducible de aplicaciones.

---

# Propósito

El propósito de este laboratorio es comprender cómo los contenedores pueden utilizarse para desplegar aplicaciones compuestas por múltiples servicios, analizando cómo Docker gestiona:

* persistencia de datos
* redes entre contenedores
* automatización del despliegue
* escalamiento de servicios

El laboratorio también permite relacionar estos mecanismos con conceptos fundamentales de los sistemas operativos como:

* aislamiento de procesos
* virtualización ligera
* gestión de almacenamiento
* comunicación entre servicios

---

# Objetivos de aprendizaje

Al finalizar este laboratorio, el estudiante debería ser capaz de:

1. Comprender el comportamiento **efímero de los contenedores Docker**.
2. Utilizar **volúmenes de Docker** para persistir datos.
3. Configurar **redes de contenedores** para la comunicación entre servicios.
4. Desplegar una aplicación multi-servicio utilizando **Drupal y PostgreSQL**.
5. Automatizar despliegues mediante **Docker Compose**.
6. Comprender el concepto de **stack de servicios**.
7. Escalar servicios utilizando **Docker Swarm**.

---

# Estructura del laboratorio

El laboratorio se desarrolla en cinco partes:

```
Parte 1 – Contenedores efímeros
Parte 2 – Persistencia con volúmenes
Parte 3 – Redes de contenedores
Parte 4 – Docker Compose
Parte 5 – Docker Swarm
```

---

# Arquitectura del laboratorio

Durante el desarrollo del taller se construirá progresivamente la siguiente arquitectura:

```
Browser
   │
   ▼
Drupal (container)
   │
   ▼
PostgreSQL (container)
   │
   ▼
Docker Volume
```

Posteriormente esta arquitectura será gestionada mediante:

* Docker Compose
* Docker Swarm

---

# Requisitos

Para ejecutar este laboratorio se requiere:

* Docker instalado
* acceso a terminal Linux o macOS
* conexión a internet

Verificar instalación:

```
docker --version
docker info
```

---

# Evidencias requeridas

Durante el desarrollo del laboratorio se solicitarán:

* capturas de pantalla de comandos ejecutados
* evidencia de contenedores en ejecución
* observaciones del comportamiento del sistema
* respuestas a preguntas de análisis

---

# Archivos del laboratorio

Este directorio incluye:

* README.md → Guía del laboratorio
* Taller 5-Docker Intermedio.pdf → Documento con la guía del laboratorio a realizar
* [Arquitectura del laboratorio](arquitectura.md)→ Explicación de la arquitectura usada
* [Docker Cheat Sheet](docker_cheatsheet.md) → Comandos Docker útiles

# Casos de Uso de Docker

- Cómo usar la imagen de [Postgres](./Postgres) con [Docker](https://www.docker.com/). 
[Enlace](https://hub.docker.com/_/postgres) a la imagen de Postgres en Docker Hub.
