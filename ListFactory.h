#pragma once
#include "LinkedList.h" 

template <typename T>
class ListFactory {
public:
    /**
     * @brief Statyczna metoda Factory tworząca nową listę na stercie
     * @return Wskaźnik do nowo utworzonej listy
     */
    static LinkedList<T>* createList() {

        return new LinkedList<T>();
    }
};