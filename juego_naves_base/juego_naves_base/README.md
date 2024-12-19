# Juego de Nave Contra Enemigos

Este es un juego simple implementado en C++ donde controlas una nave que debe disparar a los enemigos que se desplazan hacia abajo. El juego se ejecuta en una consola y usa las librerías `<iostream>`, `<conio.h>`, `<windows.h>`, y `<vector>`.

## Requisitos

- Un compilador C++ compatible con C++11 o superior.
- Sistema operativo Windows (por el uso de `conio.h` y `windows.h`).

## Funcionalidades

- **Movimiento de la nave**: Usa las teclas `a` (izquierda) y `d` (derecha) para mover la nave.
- **Disparo**: Usa la barra espaciadora para disparar un proyectil hacia los enemigos.
- **Enemigos**: Los enemigos se mueven hacia abajo y desaparecen cuando son alcanzados por el proyectil.
- **Mapa**: El juego se desarrolla en un mapa de 20x10, con bordes representados por `#`, la nave por `>` y los enemigos por `E`.

## Descripción del Código

1. **Mapa**: Se crea un mapa de tamaño definido por las constantes `ANCHO` (20) y `ALTO` (10). La nave se coloca inicialmente en la parte inferior central del mapa.
2. **Movimiento de la nave**: La nave se mueve dentro del mapa con las teclas `a` y `d`.
3. **Enemigos**: Los enemigos son representados por una lista de coordenadas. Se agregan enemigos al principio del juego y se mueven hacia abajo cada vez que el juego actualiza el estado.
4. **Disparo**: La nave dispara un proyectil que puede destruir enemigos si colisiona con ellos.

## Instrucciones de Ejecución

1. Clona este repositorio o descarga el archivo.
2. Abre el archivo con tu editor o IDE preferido y compílalo.
3. Ejecuta el programa en un entorno de Windows.

## Controles

- `a` - Mueve la nave a la izquierda.
- `d` - Mueve la nave a la derecha.
- `Espacio` - Dispara un proyectil.

## Notas

- Este juego funciona en una consola de Windows y puede requerir la instalación de un compilador compatible.
- El código utiliza la función `Sleep` de la biblioteca `<windows.h>` para controlar la velocidad del juego.

## Autor

Ayala Ian
