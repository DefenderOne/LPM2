#include <iostream>
#include <fstream>
#include "Headers/list.h"
#include "Headers/flat.h"

Flat& findFlatWithMaxMembersCount(List& list, std::string street, int buildingNumber) {
    int startIndex = 0;
    int result;
    for (int i = 0; i < list.size() && !startIndex; i++) {
        if (list[i].GetAddress().street == street && list[i].GetAddress().buildingNumber == buildingNumber) {
            startIndex = i;
            result = i;
        }
    }
    while (++startIndex < list.size() &&
     list[startIndex].GetAddress().street == street && 
     list[startIndex].GetAddress().buildingNumber == buildingNumber) {
         if (list[startIndex].GetMembersCount() > list[result].GetMembersCount()) {
             result = startIndex;
         }
    }
    return list[result];
}

int main() {
    std::string path;
    std::cout << "Input file name: ";
    std::cin >> path;
    std::ifstream reader(path);

    if (reader) {
        List flats(reader);
        std::cout << flats << std::endl;

        std::string street, temp;
        int buildingNumber;
        std::cout << "Input street name: ";
        std::cin >> street;
        std::getline(std::cin, temp);
        street += temp;
        std::cout << "Input building number: ";
        std::cin >> buildingNumber;
        std::cout << "Flat that has maximum of members registered at " << street << " " << buildingNumber << ":\n";
        Flat& result = findFlatWithMaxMembersCount(flats, street, buildingNumber);
        std::cout << result.GetAddress().GetFullAddress() << " with " << result.GetMembersCount() << " members." << std::endl;
    }
    else {
        std::cout << "File not found or there was an error opening it...\n";
    }

    system("pause");
}