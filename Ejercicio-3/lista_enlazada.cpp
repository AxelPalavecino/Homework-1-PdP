#include "lista_enlazada.h"
#include <iostream>
#include <memory>

using namespace std;

shared_ptr<node> create_node(int value) {
    shared_ptr<node> new_node = make_shared<node>();
    new_node->value = value;
    new_node->next = nullptr;
    return new_node;
}

void push_front(shared_ptr<node> &head, int value) {
    shared_ptr<node> new_node = create_node(value);
    new_node->next = head;
    head = new_node;
}

void push_back(shared_ptr<node> &head, int value) {
    shared_ptr<node> new_node = create_node(value); 
    shared_ptr<node> current = head;

    if (!head) {
        head = new_node;
        return;
    }

    while (current->next) {
        current = current->next;
    }

    current->next = new_node;
}

void insert(shared_ptr<node> &head, int value, int position) {
    shared_ptr<node> new_node = create_node(value); 
    shared_ptr<node> current = head;
    shared_ptr<node> previous = nullptr;
    int current_position = 0;

    if (position == 0) {
        new_node->next = head;
        head = new_node;
        return;
    }

    while (current && current_position < position) {
        previous = current;
        current = current->next;
        current_position++;
    }

    if (current_position == position) {
        previous->next = new_node;
        new_node->next = current;
    } else {
        cout << "La posicion ingresada es mayor al largo de la lista, se insertara al final" << endl;
        push_back(head, value);
    }
}

void erase(shared_ptr<node> &head, int position) {
    shared_ptr<node> current = head;
    shared_ptr<node> previous = nullptr;
    int current_position = 0;

    if (position == 0) {
        head = head->next;
        return;
    }

    while (current && current_position < position) {
        previous = current;
        current = current->next;
        current_position++;
    }

    if (current_position == position) {
        previous->next = current->next;
    } else {
        cout << "La posición ingresada es mayor al largo de la lista, se borrará el último nodo" << endl;
        shared_ptr<node> last = head;
        shared_ptr<node> previous = nullptr;

        while (last->next) {
            previous = last;
            last = last->next;
        }

        previous->next = nullptr;
    }
}

void print_list(shared_ptr<node> head) {
    shared_ptr<node> current = head;

    while (current) {
        if (!current->next) {
            cout << current->value;
            break;
        }
        cout << current->value << "->";
        current = current->next;
    }

    cout << endl;
}

void test_code1() {

    cout << "Test 1" << endl << endl;

    shared_ptr<node> head = nullptr;

    push_front(head, 1);
    push_front(head, 2);
    push_front(head, 3);
    push_front(head, 4);
    push_front(head, 5);
    push_front(head, 6);
    push_front(head, 7);
    push_front(head, 8);
    push_front(head, 9);
    push_front(head, 10);

    print_list(head);

    push_back(head, 11);
    push_back(head, 12);
    push_back(head, 13);
    push_back(head, 14);
    push_back(head, 15);

    print_list(head);

    insert(head, 16, 0);
    insert(head, 17, 5);
    insert(head, 18, 10);
    insert(head, 19, 15);

    print_list(head);

    erase(head, 0);
    erase(head, 5);
    erase(head, 10);
    erase(head, 15);

    print_list(head);

    erase(head, 0);
    erase(head, 0);
    erase(head, 0);

    print_list(head);

    while (head) {
        erase(head, 0);
    }

    head = nullptr;

    cout << "------------------------------------" << endl;
}

void test_code2() {
    cout << "Test 2" << endl << endl;

    shared_ptr<node> head = nullptr;
    
    cout << "Lista vacia: ";
    print_list(head);
    
    for (int i = 20; i <= 25; i++) {
        push_back(head, i);
    }
    print_list(head);
    
    for (int i = 5; i >= 1; i--) {
        push_front(head, i);
    }
    print_list(head);
    
    insert(head, 100, 3);
    insert(head, 200, 0);
    insert(head, 300, 13);
    print_list(head);

    erase(head, 0);
    erase(head, 5);
    erase(head, 20);
    print_list(head);
    
    while (head) {
        erase(head, 0);
    }

    head = nullptr;
    
    cout << "------------------------------------" << endl;
}

void test_code3() {
    cout << "Test 3" << endl;
    
    shared_ptr<node> head = nullptr;
    
    print_list(head);
    
    insert(head, 100, 0);
    print_list(head);
    
    for (int i = 5; i > 0; i--) {
        push_back(head, i * 10);
    }
    print_list(head);
    
    for (int i = 1; i <= 5; i++) {
        push_front(head, i);
    }
    print_list(head);
    
    insert(head, 25, 3);
    insert(head, 35, 7);
    insert(head, 45, 12);
    print_list(head);
    insert(head, 999, 50);
    print_list(head);
    
    erase(head, 13);
    print_list(head);
    
    erase(head, 7);
    erase(head, 4);
    print_list(head);
    
    while (head) {
        erase(head, 0);
    }

    head = nullptr;
    
    cout << "------------------------------------" << endl;
}
