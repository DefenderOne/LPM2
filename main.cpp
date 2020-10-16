#include <iostream>
#include <fstream>
#include "Headers/list.h"
#include "Headers/flat.h"

int main() {
    std::ifstream reader("Resources\\input.txt");
    if (reader) {
        List list(reader);
        std::cout << list << std::endl;
        reader.close();
    }

    system("pause");
}