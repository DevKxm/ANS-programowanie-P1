#include "LinkedList.h"

// Implementacja konstruktora
template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr; // Na starcie lista jest pusta
    tail = nullptr; // Na starcie lista jest pusta
    size = 0;
}


template <typename T>
LinkedList<T>::~LinkedList() {

}

template class LinkedList<int>;

template class Node<int>;