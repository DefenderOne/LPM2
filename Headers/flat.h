#pragma once

#include <string>

class Address {
    public:
    std::string street;
    int buildingNumber;
    int flatNumber;
    Address(std::string street = std::string(), int buildingNumber = int(), int flatNumber = int());
    std::string GetFullAddress();
};

class Square {
    public:
    double overallSquare;
    double livingSquare;
    Square(double overallSqaure = double(), double livingSquare = double());
};

class Flat {
    private:
    int roomsCount;
    int level;
    Square* square;
    int membersCount;
    Address* address;
    public:
    Flat(int roomsCount, int level, Square* square, int membersCount, Address* address);
    ~Flat();

    Address GetAddress();
    Square GetSquare();

    // (this > obj) => 1; (this == obj) => 0; (this < obj) => -1
    int Compare(Flat* obj);
};
