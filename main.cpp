#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> myList;

    std::cout << "Test 1: Pusta lista" << std::endl;
    myList.display_forward();
    std::cout << "--------------------" << std::endl;

    std::cout << "Test 2: Dodawanie na koniec (push_back)" << std::endl;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.display_forward();
    std::cout << "--------------------" << std::endl;

    std::cout << "Test 3: Dodawanie na poczatek (push_front) i wysw. wstecz" << std::endl;
    myList.push_front(5);
    myList.push_front(1);

    std::cout << "Sprawdzenie do przodu:" << std::endl;
    myList.display_forward();

    std::cout << "Sprawdzenie do tylu:" << std::endl;
    myList.display_backward();
    std::cout << "--------------------" << std::endl;
    
// TEST 4//
    std::cout << "Test 4: Usuwanie elementow (pop_front, pop_back)" << std::endl;
    
    std::cout << "Usuwam z przodu (pop_front):" << std::endl;
    myList.pop_front(); // Usuwa '1'
    myList.display_forward(); // Powinno być: 5 -> 10 -> 20 -> 30 -> NULL

    std::cout << "Usuwam z tylu (pop_back):" << std::endl;
    myList.pop_back(); // Usuwa '30'
    myList.display_forward(); // Powinno być: 5 -> 10 -> 20 -> NULL

    std::cout << "Oprozniam liste:" << std::endl;
    myList.pop_front(); // Usuwa '5'
    myList.pop_back();  // Usuwa '20'
    myList.pop_front(); // Usuwa '10'
    
    std::cout << "Lista po oproznieniu:" << std::endl;
    myList.display_forward(); // Powinno być: NULL
    myList.display_backward(); // Powinno być: NULL

    std::cout << "Test usuwania z pustej listy:" << std::endl;
    myList.pop_front(); // Powinien pojawić się komunikat "Lista jest pusta..."
    myList.pop_back();  // Powinien pojawić się komunikat "Lista jest pusta..."
    std::cout << "--------------------" << std::endl;

    return 0;
}