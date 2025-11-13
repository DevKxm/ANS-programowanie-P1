#pragma once
#include "Node.h"
#include <iostream> 

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList();
    ~LinkedList();

    // --- NOWE METODY ---
    /**
     * @brief Dodaje element na koniec listy (wymóg: Dodaj element na koniec listy)
     * @param data Wartość do dodania.
     */
    void push_back(T data);

    /**
     * @brief Wyświetla całą listę od początku do końca (wymóg: Wyświetl całą listę)
     */
    void display_forward();
};