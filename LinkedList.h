#pragma once
#include "Node.h"
#include <iostream> 

template <typename T>
class LinkedList {
// --- SEKCJA PRYWATNA ---
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

    /**
     * @brief Zwraca wskaźnik na węzeł pod podanym indeksem
     */
    Node<T>* get_node(int index);

// --- SEKCJA PUBLICZNA ---
public:
    LinkedList();
    ~LinkedList();

    // Metody dodające
    void push_back(T data);
    void push_front(T data);
    void insert(T data, int index);

    // Metody usuwające
    void pop_back();
    void pop_front();
    void remove_at(int index);
    void clear(); // NOWA METODA
    
    // Metody wyświetlające
    void display_forward();
    void display_backward();
};