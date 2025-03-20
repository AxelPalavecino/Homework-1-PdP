#pragma once // Esto evita la doble definición de clases y funciones

/// @brief Función que crea una matriz cuadrada de enteros
/// @param n 
/// @return 
int ** createMatrix(int n);

/// @brief Función que elimina una matriz cuadrada de enteros
/// @param matrix 
/// @param n 
void deleteMatrix(int** matrix, int n); 

/// @brief  Función que llena una matriz cuadrada de enteros con valores consecutivos
/// @param matrix 
/// @param n 
void fillMatrix(int** matrix, int n);

/// @brief Función que imprime la matriz cuadrada de enteros
/// @param matrix 
/// @param n 
void printMatrix(int** matrix, int n);

/// @brief Función que prueba la funcionalidad de las funciones de matrices
void test_code1M();

/// @brief Función que prueba la funcionalidad de las funciones de matrices
void test_code2();

/// @brief Función que prueba la funcionalidad de las funciones de matrices
void test_code3();