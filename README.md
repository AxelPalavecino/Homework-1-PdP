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


## Ejercicio 2: Sistema de Log

En este ejercicio se implementa un sistema de registro (sistema de log) en C++ que permite documentar diferentes tipos de eventos, errores y mensajes durante la ejecución de un programa.

### Descripción

El sistema de log permite registrar mensajes con diferentes niveles de importancia (DEBUG, INFO, WARNING, ERROR, CRITICAL), mensajes de error específicos con información del archivo y línea de código, y mensajes de seguridad con información del usuario. Todos los mensajes se almacenan en un archivo de texto "log.txt". Para realizar este ejercicio se utilizaron sobrecarga de funciones, manejo de excepciones, enum, manejo de archivos,punteros, switch, etc.

### Funciones Principales

1. **logMessage(string message, int levelImportance)**:
    - Registra un mensaje con un nivel de importancia específico
    - Los niveles son: DEBUG(0), INFO(1), WARNING(2), ERROR(3), CRITICAL(4)
    - Formato: "[NIVEL] mensaje"

2. **logMessage(string message, string file, unsigned int line_code)**:
    - Registra un mensaje de error con información del archivo y línea de código
    - Útil para rastrear excepciones
    - Formato: "[ERROR] mensaje | File: archivo | Line: línea"

3. **logMessage(string message, string user)**:
    - Registra un mensaje de seguridad con información del usuario
    - Usado para eventos de acceso o autorización
    - Formato: "[SECURITY] mensaje | User: usuario"

4. **readContent()**:
    - Lee y muestra todo el contenido del archivo de log

5. **test_code()**:
    - Función que prueba el sistema de log con varios escenarios de error
    - Incluye manejo de excepciones y registro de diferentes tipos de errores

### Casos de Prueba

La función `test_code()` implementa varios escenarios para probar el sistema de log:
- Creación de matriz con tamaño inválido
- Manipulación de matriz con puntero nulo
- División por cero
- Acceso inválido a memoria
- Conversión de cadena a entero con formato incorrecto
- Lanzamiento de errores personalizados
- Eventos de seguridad (acciones no autorizadas)
- Registro de mensajes con diferentes niveles de importancia

### Compilación y Ejecución

Para compilar el programa:
```bash
g++ main.cpp sistema_log.cpp ../Ejercicio-1/Matrices.cpp -std=c++20 -o sistema_log
```

Para compilar con información de depuración (necesaria para herramientas de análisis):
```bash
g++ main.cpp sistema_log.cpp ../Ejercicio-1/Matrices.cpp -std=c++20 -g -o sistema_log
```

Para ejecutar con Valgrind para detección de fugas de memoria:
```bash
valgrind --leak-check=full ./sistema_log
```

Para un analisis minucioso de fugas de memoria con Valgrind:
```bash
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./sistema_log
```

Para ejecutar:
```bash
./sistema_log
```

### Estructura del Proyecto

- **sistema_log.h**: Contiene las declaraciones de las funciones de logging
- **sistema_log.cpp**: Implementa las funciones declaradas en el header
- **main.cpp**: Contiene la función principal que ejecuta los casos de prueba
- **log.txt**: Archivo donde se guardan todos los mensajes de log (se crea automáticamente)

### Ejemplo de Uso

El sistema puede utilizarse en cualquier programa C++ para registrar eventos importantes:

```cpp
#include "sistema_log.h"

try {
     // Alguna operación riesgosa
     int result = someRiskyFunction();
} catch (const std::exception& e) {
     // Registrar el error con información de archivo y línea
     logMessage(e.what(), "mi_archivo.cpp", 42);
}

// Registrar actividad de usuario
logMessage("Intento de acceso a datos confidenciales", "usuario123");

// Registrar mensaje informativo
logMessage("Aplicación iniciada correctamente", static_cast<int>(Importance::INFO));
```

El archivo de log resultante mostrará un historial cronológico de todos los eventos registrados, facilitando la depuración y el seguimiento de la actividad del programa. Es bastante utilizado en aplicaciones web, sistemas embebidos, etc. para monitorear el comportamiento del sistema.
