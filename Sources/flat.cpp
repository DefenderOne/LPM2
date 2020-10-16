#include "../Headers/flat.h"

Address::Address(std::string street, int buildingNumber, int flatNumber) {
    this->street = street;
    this->buildingNumber = buildingNumber;
    this->flatNumber = flatNumber;
}

std::string Address::GetFullAddress() {
    return street + ' ' + std::to_string(buildingNumber) + ' ' + std::to_string(flatNumber);
}

Square::Square(double overallSqaure, double livingSquare) {
    this->overallSquare = overallSqaure;
    this->livingSquare = livingSquare;
}

Flat::Flat(int roomsCount, int level, Square* square, int membersCount, Address* address) {
    this->roomsCount = roomsCount;
    this->level = level;
    this->square = square;
    this->membersCount = membersCount;
    this->address = address;
}

Flat::~Flat() {
    delete square;
    square = nullptr;
    delete address;
    address = nullptr;
}

int Flat::GetRoomsCount() {
    return roomsCount;
}

int Flat::GetLevel() {
    return level;
}

Square Flat::GetSquare() {
    return *square;
}

int Flat::GetMembersCount() {
    return membersCount;
}

Address Flat::GetAddress() {
    return *address;
}

int Flat::Compare(Flat* obj) {
    int result = -1;
    if (address->street > obj->address->street || 
        address->street == obj->address->street && address->buildingNumber > obj->address->buildingNumber ||
        address->street == obj->address->street && address->buildingNumber == obj->address->buildingNumber) {
            result = 1;
        }
    else {
        if (address->street == obj->address->street && 
        address->buildingNumber == obj->address->buildingNumber &&
        address->flatNumber == obj->address->flatNumber) {
            result = 0;
        }
    }
    return result;
}

