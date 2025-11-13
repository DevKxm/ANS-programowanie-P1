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

// --- NOWY TEST ---
    std::cout << "Test 5: Operacje na indeksach (insert, remove_at)" << std::endl;
    LinkedList<int> indexList;
    indexList.push_back(100);
    indexList.push_back(200);
    indexList.push_back(300);
    std::cout << "Lista poczatkowa:" << std::endl;
    indexList.display_forward(); // Powinno być: 100 -> 200 -> 300 -> NULL
    std::cout << "--------------------" << std::endl;

    std::cout << "Test wstawiania:" << std::endl;
    indexList.insert(5, 0); // Wstaw na początek
    indexList.display_forward(); // 5 -> 100 -> 200 -> 300
    
    indexList.insert(999, 4); // Wstaw na koniec (size=4)
    indexList.display_forward(); // 5 -> 100 -> 200 -> 300 -> 999
    
    indexList.insert(150, 2); // Wstaw w środek
    indexList.display_forward(); // 5 -> 100 -> 150 -> 200 -> 300 -> 999
    
    indexList.insert(1, -1); // Zły indeks (błąd)
    std::cout << "--------------------" << std::endl;

    std::cout << "Test usuwania:" << std::endl;
    indexList.remove_at(0); // Usuń z początku
    indexList.display_forward(); // 100 -> 150 -> 200 -> 300 -> 999
    
    indexList.remove_at(4); // Usuń z końca (size=5, index 4)
    indexList.display_forward(); // 100 -> 150 -> 200 -> 300

    indexList.remove_at(2); // Usuń ze środka
    indexList.display_forward(); // 100 -> 150 -> 300

    indexList.remove_at(99); // Zły indeks (błąd)
    std::cout << "--------------------" << std::endl;


    return 0;
}
