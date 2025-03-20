#include "comparar_recursion.h"
#include <string>
#include <iostream>
#include <chrono>
using namespace std;

bool compare_recursive_string1(const string &str1, const string &str2, size_t index) {
    if (str1.size() != str2.size()) {
        return false;
    }
    if (index >= str1.size()) {
        return true;
    }
    if (str1[index] != str2[index]) {
        return false;
    }
    return compare_recursive_string1(str1, str2, index + 1);
}

bool compare_recursive_string2(const char *str1, const char *str2, size_t index) {
    if (str1[index] == '\0' && str2[index] == '\0') {
        return true;
    }
    if (str1[index] != str2[index]) {
        return false;
    }
    return compare_recursive_string2(str1, str2, index + 1);
}

constexpr bool compare_strings1(const char *str1, const char *str2, size_t index) {
    if (str1[index] == '\0' && str2[index] == '\0') {
        return true;
    }
    if (str1[index] != str2[index]) {
        return false;
    }
    return compare_strings1(str1, str2, index + 1);
}

constexpr bool compare_strings2(const string &str1, const string &str2, size_t index) {
    if (str1.size() != str2.size()) {
        return false;
    }
    if (index >= str1.size()) {
        return true;
    }
    if (str1[index] != str2[index]) {
        return false;
    }
    return compare_strings2(str1, str2, index + 1);
}

int test_code_ejecution() {

    cout << "-----------------------------------------------" << endl;

    cout << "Ejecutando pruebas de tiempo de ejecución..." << endl;

    const string str1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.";

    const string str2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.";

    const char *str3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.";

    const char *str4 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.";

    
    int char_faster_count = 0;
    int string_faster_count = 0;
    
    for (int i = 0; i < 10000; i++) {
        // Comparar strings
        auto startTimeStr = chrono::high_resolution_clock::now();
        bool resultStr = compare_recursive_string1(str1, str2);
        auto endTimeStr = chrono::high_resolution_clock::now();
        auto elapsedTimeStr = chrono::duration_cast<chrono::nanoseconds>(endTimeStr - startTimeStr).count();
        
        // Comparar char* 
        auto startTimeChar = chrono::high_resolution_clock::now();
        bool resultChar = compare_recursive_string2(str3, str4);
        auto endTimeChar = chrono::high_resolution_clock::now();
        auto elapsedTimeChar = chrono::duration_cast<chrono::nanoseconds>(endTimeChar - startTimeChar).count();
        
        if (elapsedTimeChar < elapsedTimeStr) {
            char_faster_count++;
        } else if (elapsedTimeStr < elapsedTimeChar) {
            string_faster_count++;
        }
    }
    
    cout << "Comparacion de 10000 intentos:" << endl;
    cout << "char* comparaciones fueron mas rapidas: " << char_faster_count << " veces" << endl;
    cout << "string comparaciones fueron mas rapidas: " << string_faster_count << " veces" << endl;
    if (char_faster_count > string_faster_count) {
        cout << "Resultado: char* comparaciones son generalmente mas rapidas" << endl;
    } else if (string_faster_count > char_faster_count) {
        cout << "Result: string comparaciones son generalmente mas rapidas" << endl;
    } else {
        cout << "Result: char* y string comparaciones son generalmente igual de rapidas" << endl;
    }

    auto startTime = chrono::high_resolution_clock::now();
    cout << "Resultado de comparación de string de muestra: " << compare_recursive_string1(str1, str2) << endl;
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    cout << "Tiempo de comparación de string de muestra: " << elapsedTime.count() << " nanosegundos" << endl;

    startTime = chrono::high_resolution_clock::now();
    cout << "Resultado de comparación de char* de muestra: " << compare_recursive_string2(str3, str4) << endl;
    endTime = chrono::high_resolution_clock::now();
    elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    cout << "Tiempo de comparación de char* de muestra: " << elapsedTime.count() << " nanosegundos" << endl;

    // Conclusion 

    cout << "-----------------------------------------------" << endl;

    cout << "El tipo de dato mas eficiente, y por ende el mas optimo en una toma de decisiones es: ";
    if (char_faster_count > string_faster_count) {
        cout << "[char*]" << endl;
    } else{
        cout << "[string]" << endl;
    }
    cout << "Es de esperar que el tipo mas eficiente de dato para este caso sea char* porque tiene un acceso directo a memoria" << endl;

    return 0;
}

int test_code_compile_time() {

    cout << "-----------------------------------------------" << endl;

    cout << "Ejecutando pruebas de tiempo de compilación..." << endl;

    const char* test_char1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.";
    const char* test_char2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.";
    const string test_str1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.";
    const string test_str2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.";

    int char_faster_count = 0;
    int string_faster_count = 0;
    
    for (int i = 0; i < 10000; i++) {
        // Comparacion de tiempo con char*
        auto startTimeChar = chrono::high_resolution_clock::now();
        bool resultChar = compare_strings1(test_char1, test_char2);
        auto endTimeChar = chrono::high_resolution_clock::now();
        auto elapsedTimeChar = chrono::duration_cast<chrono::nanoseconds>(endTimeChar - startTimeChar).count();
        
        // Comparación de tiempo con string
        auto startTimeStr = chrono::high_resolution_clock::now();
        bool resultStr = compare_strings2(test_str1, test_str2);
        auto endTimeStr = chrono::high_resolution_clock::now();
        auto elapsedTimeStr = chrono::duration_cast<chrono::nanoseconds>(endTimeStr - startTimeStr).count();
        
        // Comparar los tiempos de ejecución en tiempo de compilación
        if (elapsedTimeChar < elapsedTimeStr) {
            char_faster_count++;
        } else if (elapsedTimeStr < elapsedTimeChar) {
            string_faster_count++;
        }
    }
    
    // Printear Resultados
    cout << "Comparacion de 10000 intentos en compile-time functions:" << endl;
    cout << "char* comparaciones fueron mas rapidas: " << char_faster_count << " veces" << endl;
    cout << "string comparaciones fueron mas rapidas: " << string_faster_count << " veces" << endl;
    if (char_faster_count > string_faster_count) {
        cout << "Resultado: char* comparaciones son generalmente mas rapidas" << endl;
    } else if (string_faster_count > char_faster_count) {
        cout << "Resultado: string comparaciones son generalmente mas rapidas" << endl;
    } else {
        cout << "Resultado: char* y string comparaciones son generalmente igual de rapidas" << endl;
    }
    
    auto startTime = chrono::high_resolution_clock::now();
    bool result = compare_strings1(test_char1, test_char2);
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    cout << "Resultado de comparación de char* de muestra: " << result << endl;
    cout << "Tiempo de comparación de char* de muestra: " << elapsedTime.count() << " nanosegundos" << endl;

    startTime = chrono::high_resolution_clock::now();
    bool result2 = compare_strings2(test_str1, test_str2);
    endTime = chrono::high_resolution_clock::now();
    elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    cout << "Resultado de comparación de string de muestra: " << result2 << endl;
    cout << "Tiempo de comparación de string de muestra: " << elapsedTime.count() << " nanosegundos" << endl;

    // Conclusion 

    cout << "-----------------------------------------------" << endl;

    cout << "El tipo de dato mas eficiente, y por ende el mas optimo en una toma de decisiones es: ";
    if (char_faster_count > string_faster_count) {
        cout << "[char*]" << endl;
    } else{
        cout << "[string]" << endl;
    }
    cout << "Es de esperar que el tipo mas eficiente de dato para este caso sea char* porque tiene un acceso directo a memoria" << endl;
    return 0;
}
