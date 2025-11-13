#include <iostream>
#include "LinkedList.h"

int main() {
    // Listę przechowującą liczby całkowite (int)
    LinkedList<int> myList;


    std::cout << "Test 1: Pusta lista" << std::endl;
    myList.display_forward(); 
    std::cout << "--------------------" << std::endl;



    std::cout << "Test 2: Dodawanie elementow" << std::endl;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    myList.display_forward(); 
    std::cout << "--------------------" << std::endl;

    return 0;
}