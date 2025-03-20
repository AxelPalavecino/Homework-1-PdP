# Homework-1-PdP

## Ejercicio 1: Matrices

En este ejercicio se implementa un programa en C++ que crea, llena e imprime una matriz cuadrada de enteros. Se hacen uso de punteros y memoria dinamica. 

### Descripción

El programa crea matrices cuadradas de diferentes tamaños, las llena con valores consecutivos y las imprime. Demuestra el manejo dinámico de memoria en C++ mediante la creación y liberación adecuada de matrices en R^2. 

### Funciones Principales

1. **createMatrix(int n)**: 
    - Crea una matriz cuadrada de enteros de tamaño n×n
    - Reserva memoria dinámicamente
    - Retorna un puntero a la matriz creada

2. **fillMatrix(int** matrix, int n)**:
    - Llena la matriz con números enteros consecutivos empezando en 1
    - Asigna los valores incrementalmente recorriendo fila por fila

3. **printMatrix(int** matrix, int n)**:
    - Imprime la matriz en orden inverso (desde la esquina inferior derecha)
    - Muestra cada elemento con formato "M_n[i][j] = valor"

4. **deleteMatrix(int** matrix, int n)**:
    - Libera la memoria asignada a la matriz
    - Evita fugas de memoria

### Casos de Prueba

El programa incluye tres test que se utilizan como casos de preuba, para verificar el funcionamiento de las funciones principales:
- **test_code()**: Crea, llena, imprime y elimina una matriz 5×5
- **test_code2()**: Opera con una matriz 10×10, se utilizan ciclos para imprimir y liberar memoria
- **test_code3()**: Opera con una matriz 15×15, se utilizan ciclos para imprimir y liberar memoria

### Compilación y Ejecución

Para compilar el programa:
```bash
g++ main.cpp Matrices.cpp -std=c++20 -o matrices
```

Para compilar con información de depuración (necesaria para herramientas de análisis):
```bash
g++ main.cpp Matrices.cpp -std=c++20 -g -o matrices
```

Para ejecutar con Valgrind para detección de fugas de memoria:
```bash
valgrind --leak-check=full ./matrices
```

Para un analisis minucioso de fugas de memoria con Valgrind:
```bash
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./matrices
```

Para ejecutar:
```bash
./matrices
```

### Estructura del Proyecto

- **Matrices.h**: Contiene las declaraciones de las funciones
- **Matrices.cpp**: Implementa las funciones declaradas en el header (Matrices.h)
- **main.cpp**: Contiene la función principal que ejecuta los casos de prueba 