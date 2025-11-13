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
     * @brief Dodaje element na koniec listy.
     */
    void push_back(T data);

    /**
     * @brief Wyświetla całą listę od początku do końca.
     */
    void display_forward();

    /**
     * @brief Dodaje element na początek listy.
     */
    void push_front(T data);

    /**
     * @brief Wyświetla całą listę od końca do początku.
     */
    void display_backward();

    /**
     * @brief Usuwa element z początku listy.
     */
    void pop_front();

    /**
     * @brief Usuwa element z końca listy.
     */
    void pop_back();
};