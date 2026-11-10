# Actividad 8. Algoritmos Voraces (Greedy)

Dos problemas de optimización resueltos con una estrategia Greedy, en C++.

1. **Mochila fraccional**: maximizar el valor transportado tomando los objetos de mayor valor/peso primero (se permiten fracciones).
2. **Cobertura de antenas**: colocar la menor cantidad de antenas para cubrir todas las casas de una carretera.

## Estructura del proyecto

```
greedy-algorithms/
├── README.md
├── .gitignore
├── src/
│   ├── mochila_fraccional.cpp
│   └── cobertura_antenas.cpp
└── examples/
    ├── mochila1.txt
    ├── mochila2.txt
    ├── antenas1.txt
    └── antenas2.txt
```

## Requisitos

Un compilador de C++ (por ejemplo `g++` con soporte C++11 o superior).

## Compilar

Desde la carpeta raíz del proyecto:

```bash
g++ -std=c++11 -o mochila_fraccional src/mochila_fraccional.cpp
g++ -std=c++11 -o cobertura_antenas src/cobertura_antenas.cpp
```

## Ejecutar

Cada programa puede leer un archivo de entrada pasado como argumento, o leer desde el teclado si no se da ningún argumento.

```bash
./mochila_fraccional examples/mochila1.txt
./cobertura_antenas examples/antenas1.txt
```

### Formato de entrada

**Mochila fraccional** (`nombre valor peso`, un objeto por línea):

```
50
3
A 60 10
B 100 20
C 120 30
```

Primera línea: capacidad. Segunda línea: número de objetos. Luego un objeto por línea. Los valores deben ser ≥ 0 y los pesos > 0.

**Cobertura de antenas**:

```
5
7
1 2 7 11 20 21 30
```

Primera línea: rango de cobertura `R` (≥ 0). Segunda línea: número de casas. Tercera línea: posiciones de las casas (enteros, en cualquier orden).

### Salida de ejemplo

```
$ ./mochila_fraccional examples/mochila1.txt
Capacidad maxima: 50
Objetos seleccionados:
A completo
B completo
20/30 Parte del objeto C
Valor total obtenido: 240

$ ./cobertura_antenas examples/antenas1.txt
Antenas colocadas en:
6
25
Cantidad total: 2
```

## Complejidad

| Problema | Tiempo | Espacio |
|---|---|---|
| Mochila fraccional | O(n log n) | O(n) |
| Cobertura de antenas | O(n log n) | O(n) |

La explicación completa de las estrategias y el análisis de complejidad están en el PDF del informe.
