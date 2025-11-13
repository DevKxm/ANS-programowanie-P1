#include <iostream>
#include "LinkedList.h"
#include "ListFactory.h"

int main() {
    // --- TESTOWANIE FABRYKI ---

    LinkedList<int>* myList = ListFactory<int>::createList();


    std::cout << "Test 1: Pusta lista" << std::endl;
    myList->display_forward();
    std::cout << "--------------------" << std::endl;

    std::cout << "Test 2: Dodawanie na koniec (push_back)" << std::endl;
    myList->push_back(10);
    myList->push_back(20);
    myList->push_back(30);
    myList->display_forward();
    std::cout << "--------------------" << std::endl;

    std::cout << "Test 3: Dodawanie na poczatek (push_front) i wysw. wstecz" << std::endl;
    myList->push_front(5);
    myList->push_front(1);
    std::cout << "Sprawdzenie do przodu:" << std::endl;
    myList->display_forward();
    std::cout << "Sprawdzenie do tylu:" << std::endl;
    myList->display_backward();
    std::cout << "--------------------" << std::endl;

    std::cout << "Test 4: Usuwanie elementow (pop_front, pop_back)" << std::endl;
    myList->pop_front();
    myList->display_forward();
    myList->pop_back();
    myList->display_forward();
    myList->pop_front();
    myList->pop_back();
    myList->pop_front();
    myList->pop_front();
    myList->pop_back();
    std::cout << "--------------------" << std::endl;


    // --- Test 5: Operacje na indeksach ---
    LinkedList<int>* indexList = ListFactory<int>::createList();
    indexList->push_back(100);
    indexList->push_back(200);
    indexList->push_back(300);
    indexList->insert(150, 2);
    indexList->remove_at(1);
    std::cout << "Test 5 (skrocony):" << std::endl;
    indexList->display_forward(); 
    std::cout << "--------------------" << std::endl;


    // --- Test 6: Clear ---
    std::cout << "Test 6: Czyszczenie listy (clear)" << std::endl;
    indexList->clear();
    indexList->display_forward();
    std::cout << "--------------------" << std::endl;


    // --- Test 8: Iterator ---
    LinkedList<int>* iterList = ListFactory<int>::createList();
    iterList->push_back(10);
    iterList->push_back(20);
    iterList->push_back(30);
    std::cout << "Test 8: Iterator (petla for)" << std::endl;
    for (ListIterator<int> it = iterList->begin(); it != iterList->end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;


    // --- SPRZĄTANIE PAMIĘCI ---

    std::cout << "Sprzatanie pamieci (wywolywanie delete):" << std::endl;
    delete myList;
    delete indexList;
    delete iterList;
    std::cout << "Pamiec posprzatana." << std::endl;

    return 0;
}