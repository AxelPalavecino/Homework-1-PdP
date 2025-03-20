#include <iostream>
#include "Matrices.h"

using namespace std;

int main() {
    cout << "----------------------------------" << endl;
    cout << "Test 1 - Matriz 5x5" << endl << endl;

    test_code1M();

    cout << "----------------------------------" << endl;
    cout << endl << "Test 2 - Matriz 10x10" << endl << endl;
    test_code2();

    cout << "----------------------------------" << endl;
    cout << endl << "Test 3 - Matriz 15x15" << endl << endl;
    test_code3();
    return 0;
}