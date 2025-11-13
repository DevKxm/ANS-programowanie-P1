#pragma once
#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head; // Wskaźnik na pierwszy element listy
    Node<T>* tail; // Wskaźnik na ostatni element listy
    int size;      // Licznik elementów

public:
    /**
     * @brief Konstruktor domyślny.
     */
    LinkedList();

    /**
     * @brief Destruktor (posprząta pamięć).
     */
    ~LinkedList();

};