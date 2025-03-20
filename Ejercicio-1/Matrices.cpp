#include <iostream>
#include "Matrices.h"

int ** createMatrix(int n) {
    int ** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    return matrix;
}


void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
}

void fillMatrix (int** matrix, int n) {
    int current = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = current;
            current++;
        }
    }
}

void printMatrix(int** matrix, int n) {
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            std::cout << "M_" << n << "[" << i << "]" << "[" << j << "]" << " = " << matrix[i][j] << std::endl;
        }
    }
}

void test_code() {
    int n = 5;
    int ** matrix = createMatrix(n);
    fillMatrix(matrix, n);
    printMatrix(matrix, n);
    deleteMatrix(matrix, n);
}

void test_code2() {
    int n = 10;
    int ** matrix = createMatrix(n);
    fillMatrix(matrix, n);
    printMatrix(matrix, n);
    deleteMatrix(matrix, n);
}

void test_code3() {
    int n = 15;
    int ** matrix = createMatrix(n);
    fillMatrix(matrix, n);
    printMatrix(matrix, n);
    deleteMatrix(matrix, n);
}