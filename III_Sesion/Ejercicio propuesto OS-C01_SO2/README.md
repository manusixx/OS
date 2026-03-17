# Ejercicio Propuesto – Ejecución de instrucciones

<img width="763" height="443" alt="image" src="https://github.com/user-attachments/assets/7ee2f3c6-b350-49a5-adf0-0d6a2bd229ea" />

Este ejercicio tiene como objetivo comprender cómo un procesador ejecuta instrucciones y cómo interactúa con dispositivos de **entrada/salida (I/O)**.

La actividad busca ilustrar el proceso de **ejecución de instrucciones a bajo nivel**, un concepto fundamental para entender posteriormente cómo los sistemas operativos gestionan la ejecución de programas.

---

# Descripción del problema

Suponga un procesador hipotético que tiene las siguientes instrucciones adicionales:

| Código | Instrucción                                           |
| ------ | ----------------------------------------------------- |
| 0011   | Cargar el acumulador (AC) desde un dispositivo de I/O |
| 0111   | Almacenar el acumulador (AC) en un dispositivo de I/O |

Se asume que las direcciones de los dispositivos externos de **I/O utilizan 12 bits**.

---

# Programa a ejecutar

El programa realiza las siguientes operaciones:

1. Cargar el acumulador **AC** desde el dispositivo **5**
2. Adicionar al acumulador el contenido de la dirección de memoria **940**
3. Almacenar el contenido del acumulador **AC** en el dispositivo **6**

---

# Supuestos

Para el desarrollo del ejercicio se consideran los siguientes valores iniciales:

* El valor recuperado del **dispositivo 5** es **3**
* El contenido de la **dirección de memoria 940** es **2**

# Resultados esperados

AC = 3        (lectura del dispositivo 5)
AC = 3 + 2    (suma con memoria 940)
AC = 5
Salida al dispositivo 6 = 5

# Misión
Deben descubrir cómo se llega a este resultado esperado.


---
