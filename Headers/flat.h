#pragma once

#include <string>

class Address {
    public:
    std::string street;
    int buildingNumber;
    int flatNumber;
    Address(std::string street, int buildingNumber, int flatNumber);
    std::string GetFullAddress();
}

class Square {
    public:
    double overallSquare;
    double livingSquare;
    Square(double overallSqaure, double livingSquare);
}

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
    // Contains string street, building number, flat number
    Address GetAddress();

    // Contains Overall and Living Squares
    Square GetSquare();

    /*
        => 1 if this is bigger then obj
        => 0 if this and obj are equal
        => -1 if this is smaller then obj
    */
    int Compare(const Flat& obj);
};
