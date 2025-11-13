#pragma once
#include "Node.h"
#include "Iterator.h" 
#include <iostream> 

template <typename T>
class LinkedList {
    
// --- SEKCJA PRYWATNA ---
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

    /**
     * @brief Zwraca wskaźnik na węzeł pod podanym indeksem.
     */
    Node<T>* get_node(int index);

// --- SEKCJA PUBLICZNA ---
public:
    LinkedList();
    ~LinkedList();
    int getSize();
    

    // Metody dodające
    void push_back(T data);
    void push_front(T data);
    void insert(T data, int index);

    // Metody usuwające
    void pop_back();
    void pop_front();
    void remove_at(int index);
    void clear(); 

    // Metody wyświetlające
    void display_forward();
    void display_backward();

    bool isEmpty(); // dopisana deklaracja
    


    // --- METODY ITERATORA ---
    ListIterator<T> begin();
    ListIterator<T> end();
};