#pragma once

template <typename T>
class Node {
public:
    T data;         // Dane przechowywane w węźle
    Node* pNext;    // Wskaźnik na następny węzeł
    Node* pPrev;    // Wskaźnik na poprzedni węzeł

    /**
     * @brief Konstruktor węzła.
     * @param data Wartość do przechowania w węźle.
     */
    Node(T data);
};

template <typename T>
Node<T>::Node(T data) {
    this->data = data;
    this->pNext = nullptr; 
    this->pPrev = nullptr; 
}