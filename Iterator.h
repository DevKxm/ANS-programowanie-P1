#pragma once
#include "Node.h"

template <typename T>
class ListIterator {
private:

    Node<T>* currentNode;

public:
    // Konstruktor
    ListIterator(Node<T>* node) : currentNode(node) {}

    /**
     * @brief Operator dereferencji (*).
     * Zwraca dane z bieżącego węzła
     */
    T& operator*() {
        return currentNode->data;
    }

    /**
     * @brief Operator inkrementacji prefixowej (++it).
     * Przesuwa iterator na następny element
     */
    ListIterator<T>& operator++() {
        if (currentNode) {
            currentNode = currentNode->pNext;
        }
        return *this;
    }

    /**
     * @brief Operator dekrementacji prefixowej (--it).

     */
    ListIterator<T>& operator--() {
        if (currentNode) {
            // Możliwe bo jest lista dwukierunkowa
            currentNode = currentNode->pPrev; 
        }
        return *this;
    }

    /**
     * @brief Operator porównania (!=).
     * Sprawdza, czy dwa iteratory wskazują na różne węzły
     */
    bool operator!=(const ListIterator<T>& other) {
        return currentNode != other.currentNode;
    }
};