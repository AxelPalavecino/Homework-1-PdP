#include "sistema_log.h"
#include <iostream>
#include <string>
#include <fstream>
#include "../Ejercicio-1/Matrices.h"

using namespace std;

enum class Importance { 
    DEGUB, 
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};


void readContent() {
    ifstream file(NAME_FILE);
    string line;
    if (file.is_open()){
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
}

void logMessage(string message, int levelImportance) {

    if (message == "") {
        cout << "Error: Mensaje vacío" << endl;
        return;
    }
    ofstream logFile(NAME_FILE, ios::app);
    switch (levelImportance) {
    case static_cast<int>(Importance::DEGUB):
        
        if (logFile.is_open()) {
            logFile << "[DEBUG] " << message << endl;
        }
        logFile.close();
        
        break;

    case static_cast<int>(Importance::INFO):

        if (logFile.is_open()) {
            logFile << "[INFO] " << message << endl;
        }
        logFile.close();

        break;

    case static_cast<int>(Importance::WARNING):

        if (logFile.is_open()) {
            logFile << "[WARNING] " << message << endl;
        }
        logFile.close();
        break;
    
    case static_cast<int>(Importance::ERROR):

        if (logFile.is_open()) {
            logFile << "[ERROR] " << message << endl;
        }
        logFile.close();
        break;

    case static_cast<int>(Importance::CRITICAL):
        
        if (logFile.is_open()) {
            logFile << "[CRITICAL] " << message << endl;
        }
        logFile.close();
        break;
    
    default:
        cout << "Error: Nivel de importancia no válido" << endl;
        logFile.close();
        break;
    }
}

void logMessage(string message, string file, unsigned int line_code) {
    if (message == "" || file == "") {
        cout << "Error: Mensaje o archivo vacío" << endl;
        return;
    }
    ofstream logFile(NAME_FILE, ios::app);
        if (logFile.is_open()) {
            logFile << "[ERROR]" << message << " | File: " << file << " | Line: " << line_code << endl;
        }
    logFile.close();
}

void logMessage(string message, string user) {
    if (message == "" || user == "") {
        cout << "Error: Mensaje o usuario vacío" << endl;
        return;
    }
    ofstream logFile(NAME_FILE, ios::app);
    if (logFile.is_open()) {
        logFile << "[SECURITY]" << message << " | User: " << user << endl;
    }
    logFile.close();
}

int test_code() {

    cout << "Probando la creacion de matriz con tamaño inválido..." << endl;
    
    try {
        int** m = createMatrix(-1);
    } catch (const exception& e) {
        logMessage(e.what(), "Matrices.h", 10);
        cerr << e.what() << endl;
    }
    cout << "Probando el relleno de matriz con puntero nulo..." << endl;
    try {
        int** invalidMatrix = nullptr;
        if (!invalidMatrix) {
            throw runtime_error("El puntero de la matriz es nulo. No se puede llenar la matriz.");
        }
        fillMatrix(invalidMatrix, 3);
    } catch(const exception& e) {
        logMessage(e.what(), "Matrices.cpp", 20);
        cerr << e.what() << endl;
    }

    cout << "Probando division por cero..." << endl;
    try {
        int x = 10, y = 0;
        if (y == 0) {
            throw runtime_error("Se detecto division por cero");
        }
        cout << x / y << endl;
    } catch(...) {
        logMessage("Se detecto division por cero", "sistema_log.cpp", 30);
        cerr << "Error de division por cero" << endl;
    }

    cout << "Probando acceso inválido a memoria..." << endl;
    try {
        int* ptr = nullptr;
        if (!ptr) {
            throw runtime_error("Acceso inválido a memoria");
        }
        cout << *ptr << endl;
    } catch(...) {
        logMessage("Acceso inválido a memoria", "sistema_log.cpp", 40);
        cerr << "Error de acceso inválido a memoria" << endl;
    }
    cout << "Probando conversion de cadena a entero..." << endl;
    try {
        int value = stoi("noEsUn-numero");
        cout << value << endl;
    } catch(...) {
        logMessage("Error en la conversion de cadena", static_cast<int>(Importance::ERROR));
        cerr << "Error de conversion de cadena" << endl;
    }

    cout << "Probando lanzamiento de error personalizado..." << endl;
    try {
        throw runtime_error("Error personalizado detectado");
    } catch(...) {
        logMessage("Error personalizado detectado", "archivo_desconocido.cpp", 120);
        cerr << "Error personalizado lanzado" << endl;
    }

    cout << "Probando accion no autorizada 1 ..." << endl;
    try {
        throw runtime_error("Accion no autorizada");
    } catch(...) {
        logMessage("Intento de accion no autorizada", "Admin Granted");
        cerr << "Intento de accion no autorizada" << endl;
    }

    cout << "Probando accion no autorizada 2 ..." << endl;
    try {
        throw runtime_error("Accion no autorizada");
    } catch(...) {
        logMessage("Intento de accion no autorizada", "Admin Denied");
        cerr << "Intento de accion no autorizada" << endl;
    }

    cout << "Probando accion no autorizada 3 ..." << endl;
    try {
        throw runtime_error("Accion no autorizada");
    } catch(...) {
        logMessage("Intento de intervension", "Admin Denied");
        cerr << "Intento de accion no autorizada" << endl;
    }

    cout << "Probando varias entradas de log..." << endl;
    logMessage("Este es un mensaje de depuracion", static_cast<int>(Importance::DEGUB));
    logMessage("Este es un mensaje de informacion", static_cast<int>(Importance::INFO));
    logMessage("Este es un mensaje de advertencia", static_cast<int>(Importance::WARNING));
    logMessage("Este es un mensaje de error", static_cast<int>(Importance::ERROR));
    logMessage("Este es un mensaje crítico", static_cast<int>(Importance::CRITICAL));

    cout << "Leyendo contenido del log..." << endl;
    readContent();

    return 0;
}