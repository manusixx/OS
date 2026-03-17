# Docker – Cheat Sheet para el laboratorio

Este documento reúne los comandos Docker más utilizados durante el laboratorio.

---

# Contenedores

Crear contenedor:

```
docker container run
```

Listar contenedores:

```
docker container ls
docker container ls -a
```

Entrar a contenedor:

```
docker container exec -it <container> bash
```

Detener contenedor:

```
docker container stop <container>
```

Eliminar contenedor:

```
docker container rm <container>
```

---

# Imágenes

Descargar imagen:

```
docker image pull <image>
```

Listar imágenes:

```
docker image ls
```

Eliminar imagen:

```
docker image rm <image>
```

---

# Volúmenes

Crear volumen:

```
docker volume create <volume>
```

Listar volúmenes:

```
docker volume ls
```

Inspeccionar volumen:

```
docker volume inspect <volume>
```

---

# Redes

Crear red:

```
docker network create <network>
```

Listar redes:

```
docker network ls
```

Inspeccionar red:

```
docker network inspect <network>
```

---

# Docker Compose

Ejecutar stack:

```
docker compose up -d
```

Ver servicios:

```
docker compose ps
```

Ver logs:

```
docker compose logs
```

Detener stack:

```
docker compose down
```

---

# Docker Swarm

Inicializar swarm:

```
docker swarm init
```

Desplegar stack:

```
docker stack deploy -c docker-compose.yml drupal-stack
```

Listar servicios:

```
docker service ls
```

Escalar servicio:

```
docker service scale drupal-stack_drupal=3
```
