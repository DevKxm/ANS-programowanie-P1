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

    return 0;
}