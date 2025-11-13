#include "LinkedList.h"
#include <iostream> 

// --- (KONSTRUKTOR) ---
template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr; // Na starcie lista jest pusta
    tail = nullptr; // Na starcie lista jest pusta
    size = 0;
}

// --- (DESTRUKTOR) ---
template <typename T>
LinkedList<T>::~LinkedList() {

}


template <typename T>
void LinkedList<T>::push_back(T data) {

    Node<T>* newNode = new Node<T>(data);
    size++;


    if (head == nullptr) {

        head = newNode;
        tail = newNode;
    } else {

        tail->pNext = newNode; // Ostatni element wskazuje na nowy
        newNode->pPrev = tail; // Nowy element wskazuje wstecz na stary ogon
        tail = newNode;        // Ustaw nowy element jako nowy ogon
    }
}

template <typename T>
void LinkedList<T>::display_forward() {
    std::cout << "Lista (Head->Tail): ";
    

    Node<T>* current = head;


    while (current != nullptr) {

        std::cout << current->data << " -> ";

        current = current->pNext;
    }
    std::cout << "NULL" << std::endl;
}

// --- POPRAWKA BŁĘDU LINKERA ---
// Mówi kompilatorowi, żeby wygenerował kod dla wersji <int>
template class LinkedList<int>;
template class Node<int>;