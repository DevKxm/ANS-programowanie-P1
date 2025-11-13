#include "LinkedList.h"
#include <iostream> 

// --- (KONSTRUKTOR) ---
template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr; 
    tail = nullptr; 
    size = 0;
}

// --- (DESTRUKTOR) ---
template <typename T>
LinkedList<T>::~LinkedList() {
    // Na razie jest pusty
}

// --- METODA 1: push_back ---
template <typename T>
void LinkedList<T>::push_back(T data) {
    Node<T>* newNode = new Node<T>(data);
    size++;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->pNext = newNode; 
        newNode->pPrev = tail; 
        tail = newNode;        
    }
}

// --- METODA 2: display_forward ---
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

// --- METODA 3: push_front ---
template <typename T>
void LinkedList<T>::push_front(T data) {
    Node<T>* newNode = new Node<T>(data);
    size++;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->pNext = head;  
        head->pPrev = newNode;  
        head = newNode;         
    }
}

// --- METODA 4: display_backward ---
template <typename T>
void LinkedList<T>::display_backward() {
    std::cout << "Lista (Tail->Head): ";
    Node<T>* current = tail;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->pPrev;
    }
    std::cout << "NULL" << std::endl;
}

// --- POPRAWKA BŁĘDU LINKERA ---
template class LinkedList<int>;
template class Node<int>;