# Arquitectura del laboratorio

Este laboratorio utiliza una arquitectura basada en contenedores compuesta por dos servicios principales:

* Drupal (servidor web)
* PostgreSQL (base de datos)

Ambos servicios se ejecutan en contenedores Docker independientes.

---

# Arquitectura lógica

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

---

# Componentes

## Drupal

Drupal es un sistema de gestión de contenidos (CMS) que se ejecuta como servidor web.

En este laboratorio:

* Se ejecuta dentro de un contenedor Docker
* Se conecta a PostgreSQL mediante una red Docker
* Expone el puerto 80 del contenedor en el puerto 8080 del host

---

## PostgreSQL

PostgreSQL es el servidor de base de datos utilizado por Drupal.

En este laboratorio:

* Se ejecuta dentro de un contenedor Docker
* Utiliza un volumen Docker para persistir datos
* Es accesible desde el contenedor Drupal mediante la red Docker

---

## Volumen Docker

El volumen permite que los datos de PostgreSQL se almacenen fuera del contenedor.

Esto evita que los datos se pierdan cuando el contenedor es eliminado.

---

## Red Docker

La red permite que los contenedores se comuniquen entre sí mediante sus nombres de host.

Por ejemplo:

```
Host PostgreSQL = postgres
```

Esto permite que Drupal se conecte directamente al servidor de base de datos.
