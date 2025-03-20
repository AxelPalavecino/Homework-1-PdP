#pragma once
#include <string>

using namespace std;

/// @brief Función que compara dos strings de manera recursiva en tiempo de ejecución.
/// @param str1 String 1
/// @param str2 String 2
/// @param index Índice
/// @return bool
bool compare_recursive_string1(const string &str1, const string &str2, size_t index = 0);

/// @brief Función que compara dos char* de manera recursiva en tiempo de ejecución.
/// @param str1 Char* 1
/// @param str2 Char* 2
/// @param index Índice
/// @return bool
bool compare_recursive_string2(const char *str1, const char *str2, size_t index = 0);

/// @brief Función que compara dos char* de manera recursiva en tiempo de compilación.
/// @param str1 Char* 1
/// @param str2 Char* 2
/// @param index Índice
/// @return bool
constexpr bool compare_strings1(const char *str1, const char *str2, size_t index = 0);

/// @brief Función que compara dos strings de manera recursiva en tiempo de compilación.
/// @param str1 String 1
/// @param str2 String 2
/// @param index Índice
/// @return bool
constexpr bool compare_strings2(const string &str1, const string &str2, size_t index = 0);

/// @brief Función que ejecuta el código de prueba y repite 10000 veces el chequeo de que comparacion es mas rapida en tiempo de ejecución.
/// @return int
int test_code_ejecution();

/// @brief  Función que ejecuta el código de prueba y repite 10000 veces el chequeo de que comparacion es mas rapida de un codigo en tiempo de compilación.
/// @return int 
int test_code_compile_time();