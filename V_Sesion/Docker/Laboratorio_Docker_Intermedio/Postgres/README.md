# Postgres en Docker

En este repositorio se muestran algunas maneras como se puede llevar a cabo la
ejecución de la base de datos Postgres en un contenedor.

## Ejecución básica de Postgres

La forma más directa de ejecutar postgres es de la siguiente manera:

``` 
docker container run --name postgres-server -e POSTGRES_PASSWORD=passwd -d postgres:9.6.1
``` 

Para conectarse a la base de datos se puede hacer de la siguiente manera:

1- Se ingresa al contenedor que está ejecutando el servidor de la base de 
datos:
```
docker container exec -it --user postgres postgres-server bash
```
2- Al estar dentro del contenedor, ejecutar los comandos que se ven a
continuación en negrillas:
<pre>postgres@e9b98daf8a2d:/$ <b>psql</b>
psql (9.6.1)
Type "help" for help.

postgres=# <b>\l</b>
                                 List of databases
   Name    |  Owner   | Encoding |  Collate   |   Ctype    |   Access privileges   
-----------+----------+----------+------------+------------+-----------------------
 postgres  | postgres | UTF8     | en_US.utf8 | en_US.utf8 | 
 template0 | postgres | UTF8     | en_US.utf8 | en_US.utf8 | =c/postgres          +
           |          |          |            |            | postgres=CTc/postgres
 template1 | postgres | UTF8     | en_US.utf8 | en_US.utf8 | =c/postgres          +
           |          |          |            |            | postgres=CTc/postgres
(3 rows)

postgres=# <b>create database demo;</b>
CREATE DATABASE
postgres=# <b>\l</b>
                                 List of databases
   Name    |  Owner   | Encoding |  Collate   |   Ctype    |   Access privileges
-----------+----------+----------+------------+------------+-----------------------
 <b>demo</b>      | <b>postgres</b> | <b>UTF8</b>     | <b>en_US.utf8</b> | <b>en_US.utf8</b> |
 postgres  | postgres | UTF8     | en_US.utf8 | en_US.utf8 |
 template0 | postgres | UTF8     | en_US.utf8 | en_US.utf8 | =c/postgres          +
           |          |          |            |            | postgres=CTc/postgres
 template1 | postgres | UTF8     | en_US.utf8 | en_US.utf8 | =c/postgres          +
           |          |          |            |            | postgres=CTc/postgres
(4 rows)

postgres=# <b>\q</b>
could not save history to file "/home/postgres/.psql_history": No such file or directory
postgres@e9b98daf8a2d:/$ <b>exit</b>
</pre>

__NOTA__: observe que se ha creado una nueva base de datos llamada `demo`.

__Finalmente__ lleve a cabo la terminación de ejecución del contenedor usando 
el comando:
```
docker container stop postgres-server && docker container rm postgres-server
```

### Ejercicio 01

1- Lance nuevamente la ejecución del contenedor como se indicó anteriormente.

2- Indique si la base de datos __demo__ sigue estando presente.

3- Indique porqué __sí__ o porqué __no__ la base de datos sigue estando
presente.

## Postgres usando almacenamiento externo

En algunas ocasiones es deseable que ciertos datos de la base de datos queden 
aislados de los datos propios del contenedor de modo que si el contenedor
es borrado, los datos de la base de datos no se borran.
Para ello entonces creamos un espacio de almacenamiento en Docker, un 
__volumen__.
A este volumen lo llamaremos `postgres-vol`.
<pre>
docker volume create postgres-vol
</pre>

Ahora, se lanza la ejecución de postgres de la siguiente manera:
<pre>
docker container run --name postgres-server -e POSTGRES_PASSWORD=passwd <b>-e PGDATA=/var/lib/postgresql/data</b> <b>-v postgres-vol:/var/lib/postgresql/data</b> -d postgres:9.6.2
</pre>

Los datos que están ahora en __negrilla__ nos permiten indicar donde quedarán 
los datos de la base de datos (<b>-e PGDATA=/var/lib/postgresql/data</b>) y 
asociar esa ruta a un espacio de almacenamiento diferente al espacio de 
almacenamiento del contenedor (<b>-v postgres-vol:/var/lib/postgresql/data</b>).

### Ejercicio 02

Lleve a cabo los mismos pasos de interacción con la base de datos que ejecutó
en esta ocasión. 

1- Ingrese al contenedor que ejecuta la base de datos PostgreSQL.

2- Ingrese vía `psql` al motor de la base de datos.

3- Liste las bases de datos y tome un pantallazo de las bases de datos que se
encuentran disponibles.

4- Cree la base de datos `demo`.

5- Liste las bases de datos y asegúrese que la base de datos `demo` en 
encuentra en la lista de salida. Tome un pantallazo de la lista de bases de
datos presentadas.

6- Salga del motor de la base de datos, salga del contenedor, detenga el 
contenedor, borre el contenedor y vuelva correr el contenedor usando 
`docker container run ...`.

7- Vuelva a lanzar la ejecución del contenedor como se indicó en esta 
sección.

8- Lleve a cabo los pasos del 1 al 3. Se encuentra en esa lista la base de
datos `demo`.

9- Explique porqué __sí__ o porqué __no__ la base de datos sigue estando
presente.

## Limpiando todo

Finalice ejecutando desde una terminal linux en el computador anfitrión los 
siguientes comandos:

```
docker container stop postgres-server
docker container rm postgres-server
docker volume rm postgres-vol
```

## Ejercicio 03 - Integración con Drupal

Para este ejercicio debe llevar a cabo las siguientes tareas:

- Crear una red llamada `drupal-postgres`.

- Lanzar la ejecución de un contenedor de postgres **version 10**, que esté conectado a la red `drupal-postgres` y que el contenedor se llama `postgres-server`.

- Lanzar la ejecución de Drupal **versión 9**. Use la forma más sencilla de ejecución de un contenedor de Drupal conforme a lo indicado en la [página oficial de Drupal en Docker Hub](https://hub.docker.com/_/drupal). Antes de ejecutar el comando para lanzar la ejecución de un contenedor de Drupal tenga en cuenta lo siguiente:

  - Este contenedor debe estar conectado a la red  `drupal-postgres`.
  - El contenedor se debe llamar `drupal`.
  - Debe exponer el puerto `80` del contenedor `drupal` en el puerto `8080` del anfitrión.

- Valide los archivos de log del contenedor `postgres-server` y `drupal`. Si aparece algún mensaje de error consultar la razón del error y corregir.

- En el computador donde lanzó la ejecución de los contenedores, abra su navegador en el puerto <http://localhost:8080>.

- Proceda a configurar Drupal de modo que se integre este servidor de Drupal con el servidor de PostgreSQL que usted ejecutó en contenedor. En la interfaz de configuración tener en cuenta que:

  - Debe seleccionar como motor de base de datos **PostgreSQL**.
  - La base de datos se llama `postgres`.
  - El usuario es `postgres`.
  - El password es `passwd`, esto es verdad si usted ejecutó el servidor de PostgreSQL como se indicó en esta guía.
  - Debe seleccionar la configuración avanzada para indicar el nombre del servidor de base de datos. En la interfaz aparece `localhost`, cambiar por `postgres-server`, guardar y continuar.

Si a este punto no aparecen errores, la integración de Drupal con el servidor PostgreSQL está correcta.

## Limpiar todo

```
docker container rm -f postgres-server drupal
docker network rm drupal-postgres
```
