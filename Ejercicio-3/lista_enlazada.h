#pragma once 

#include <iostream>
#include <memory>

using namespace std;

struct node {
    int value;
    shared_ptr<node> next; 
};

/// @brief  Crea un nodo con un valor dado
/// @param value Valor que se le asignará al nodo
/// @return shared_ptr<node> Puntero inteligente al nodo creado
shared_ptr<node> create_node(int value);

/// @brief  Agrega un nodo al inicio de la lista
/// @param head Puntero inteligente al primer nodo de la lista
/// @param value Valor que se le asignará al nodo
void push_front(shared_ptr<node> &head, int value);

/// @brief  Agrega un nodo al final de la lista
/// @param head Puntero inteligente al primer nodo de la lista
/// @param value Valor que se le asignará al nodo
void push_back(shared_ptr<node> &head, int value);

/// @brief  Agrega un nodo en una posición específica de la lista
/// @param head Puntero inteligente al primer nodo de la lista
/// @param value Valor que se le asignará al nodo
/// @param position Posición en la que se agregará el nodo
void insert(shared_ptr<node> &head, int value, int position);

/// @brief  Elimina un nodo en una posición específica de la lista
/// @param head Puntero inteligente al primer nodo de la lista
/// @param position Posición en la que se eliminará el nodo
void erase(shared_ptr<node> &head, int position);

/// @brief  Imprime los valores de los nodos de la lista
/// @param head Puntero inteligente al primer nodo de la lista
void print_list(shared_ptr<node> head);

/// @brief  Función que prueba la funcionalidad de la lista enlazada
void test_code1();

/// @brief  Función que prueba la funcionalidad de la lista enlazada
void test_code2();

/// @brief  Función que prueba la funcionalidad de la lista enlazada
void test_code3();