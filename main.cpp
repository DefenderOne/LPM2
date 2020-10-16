#include <iostream>
#include "Headers/list.h"
#include "Headers/flat.h"

int main() {
    List list;
    std::cout << list.size() << std::endl;
    list.pushBack(new Flat(5));
    list.pushBack(new Flat(1000));
    list.pushFront(new Flat(55));
    std::cout << list << std::endl;
    list.popFront();
    list.popBack();
    std::cout << list << std::endl;

    system("pause");
}