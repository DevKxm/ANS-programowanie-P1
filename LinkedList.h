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


    /**
     * @brief Dodaje element na koniec listy
     * @param data Wartość do dodania.
     */
    void push_back(T data);

    /**
     * @brief Wyświetla całą listę od początku do końca 
     */
    void display_forward();

    // --- NOWE METODY ---
    /**
     * @brief Dodaje element na początek listy.
     * @param data Wartość do dodania.
     */
    void push_front(T data);

    /**
     * @brief Wyświetla całą listę od końca do początku.
     */
    void display_backward();
    
};