# The Mind - Versión Consola en C++

## Descripción del proyecto
Este proyecto es una implementación en C++ del juego de cartas colaborativo "The Mind". El objetivo original del juego es que los jugadores colaboren para deshacerse de sus cartas jugándolas en orden ascendente en el centro de la mesa, sin comunicarse entre ellos. Esta versión adapta esa experiencia a un entorno de consola de texto.

## Decisiones de diseño y acotación
Para lograr un prototipo funcional y viable dentro del tiempo establecido para el proyecto, se realizaron las siguientes acotaciones respecto al juego físico original:
* **Sistema de Turnos:** Dado que la consola no permite interacción simultánea en tiempo real sin códigos más complejos, el juego se adaptó a un formato por turnos.
* **Límite de Jugadores:** Se fijó la partida exclusivamente para 2 jugadores, simplificando la gestión de la lógica.
* **Simplificación de mecánicas:** Se omitió el uso de "Shurikens" para enfocarnos en la mecánica principal que es jugar las cartas en orden ascendente, detectar errores o fallos y en ese caso perder vidas, y ejecutar el descarte automático cuando alguien se equivoque.

## Estructura del código y organización
Se implementó en múltiples archivos para mantener el código limpio y modular:
* `Carta.h / .cpp`: Entidad individual que almacena el valor de la carta.
* `Mazo.h / .cpp`: Colección estática de 100 cartas, encargada de la inicialización y el barajado aleatorio.
* `Jugador.h / .cpp`: Gestiona la mano de cartas, su ordenamiento automático y la jugada.
* `Partida.h / .cpp`: Motor central del juego. Controla las vidas, niveles, validación de la carta menor global, aplicación de errores y guardado o carga.
* `main.cpp`: Punto de entrada del programa que gestiona el menú principal.

## Compilación y ejecución
Se puede ejecutar con un compilador de C++ (como `g++`) y al ejecutar el siguiente comando en la terminal:

**Compilación:**
```bash
g++ main.cpp Carta.cpp Mazo.cpp Jugador.cpp Partida.cpp -o themind```


