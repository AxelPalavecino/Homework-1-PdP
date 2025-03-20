#pragma once

#include <iostream>
#include <string>
#define NAME_FILE "log.txt"

using namespace std;

/// @brief Función que lee el contenido del archivo de log.
/// @return void
void readContent();

/// @brief Función que registra un mensaje, y el nivel de importancia, y lo agrega en la linea final del archivo.
/// @param message Mensaje
/// @param levelImportance Nivel de importancia
/// @return void
void logMessage(string message, int levelImportance);

/// @brief que registra un mensaje de error, y el nombre del archivo y la línea de código, y lo agrega en la linea final del archivo.
/// @param errorMessage Mensaje de error
/// @param file Nombre del archivo
/// @param line Código de la línea
/// @return void
void logMessage(string message, string file, unsigned int line_code);

/// @brief Función que registra un mensaje de acceso de usuario, y el nombre del usuario, y lo agrega en la linea final del archivo.
/// @param message Mensaje de acceso
/// @param user Nombre del usuario
void logMessage(string message, string user);

/// @brief Función que generera un error en runtime, y lo registra en el archivo de log, y detiene la ejecución del programa con un código de error (return 1)
/// @return int Código de error
int test_code();