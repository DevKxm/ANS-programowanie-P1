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

// Implementacja //

template <typename T>
void LinkedList<T>::pop_front() {

    if (head == nullptr) {
        std::cout << "Lista jest pusta, nie mozna usunac." << std::endl;
        return; 
    }

    size--;

    Node<T>* temp = head;


    if (head == tail) {
        // Lista staje się pusta
        head = nullptr;
        tail = nullptr;
    } else {

        head = head->pNext;
        // Nowy 'head' nie ma już elementu poprzedniego
        head->pPrev = nullptr;
    }

    delete temp;
}

template <typename T>
void LinkedList<T>::pop_back() {

    if (tail == nullptr) { // lub (head == nullptr)
        std::cout << "Lista jest pusta, nie mozna usunac." << std::endl;
        return; 
    }

    size--;

    Node<T>* temp = tail;


    if (head == tail) {
        // Lista staje się pusta
        head = nullptr;
        tail = nullptr;
    } else {

        tail = tail->pPrev;
        // Nowy 'tail' nie ma już elementu następnego
        tail->pNext = nullptr;
    }

    //Zzwolnienie pamięci po starym 'tail'
    delete temp;
}

// --- 4. IMPLEMENTACJA METODY POMOCNICZEJ ---
template <typename T>
Node<T>* LinkedList<T>::get_node(int index) {
    // Sprawdzamy, czy indeks jest prawidłowy
    if (index < 0 || index >= size) {
        return nullptr; // Zły indeks
    }


    // szuka od 'head'. W przeciwnym razie - od 'tail'.
    Node<T>* current;
    if (index < size / 2) {
        // Szukaj od początku
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->pNext;
        }
    } else {
        // Szukaj od końca
        current = tail;
        for (int i = size - 1; i > index; i--) {
            current = current->pPrev;
        }
    }
    return current;
}


// --- 5. IMPLEMENTACJA METOD PUBLICZNYCH ---

template <typename T>
void LinkedList<T>::insert(T data, int index) {

    if (index < 0 || index > size) {
        std::cout << "Blad: Nieprawidlowy indeks do wstawienia." << std::endl;
        return;
    }


    if (index == 0) {
        push_front(data);
        return;
    }
    if (index == size) {
        push_back(data);
        return;
    }

    // Wstawianie gdzieś w środku

    Node<T>* nextNode = get_node(index); // Np. C

    Node<T>* prevNode = nextNode->pPrev; // Np. B
    

    Node<T>* newNode = new Node<T>(data); // Np. X
    size++;

    // Przekieruje wskaźniki: B <-> X <-> C
    prevNode->pNext = newNode;
    newNode->pPrev = prevNode;
    
    newNode->pNext = nextNode;
    nextNode->pPrev = newNode;
}

template <typename T>
void LinkedList<T>::remove_at(int index) {
    // 1. Sprawdzenie, czy indeks jest w prawidłowym zakresie
    if (index < 0 || index >= size) {
        std::cout << "Blad: Nieprawidlowy indeks do usuniecia." << std::endl;
        return;
    }

    // 2. Użyje istniejących funkcji, jeśli to możliwe (przypadki brzegowe)
    if (index == 0) {
        pop_front();
        return;
    }
    if (index == size - 1) {
        pop_back();
        return;
    }

    // 3. Usuwanie gdzieś ze środka

    Node<T>* nodeToRemove = get_node(index); // Np. B
    

    Node<T>* prevNode = nodeToRemove->pPrev; // Np. A
    Node<T>* nextNode = nodeToRemove->pNext; // Np. C

    // Przekieruje wskaźniki, "omijając" usuwany węzeł: A <-> C
    prevNode->pNext = nextNode;
    nextNode->pPrev = prevNode;

    // 4. Zwolni pamięć i zmniejszy rozmiar
    delete nodeToRemove;
    size--;
}

// --- POPRAWKA BŁĘDU LINKERA ---
template class LinkedList<int>;
template class Node<int>;