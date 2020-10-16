#pragma once

#include <iostream>

class Flat;
class Node {
    public:
    Flat* flat;
    Node* next;
    Node* prev;
    Node(Flat* flat = nullptr, Node* next = nullptr, Node* prev = nullptr);
    ~Node();
};

class List {
    private:
    Node* head;
    Node* tail;
    int _size;

    public:
    List();
    ~List();
    void pushBack(Flat* flat);
    void pushFront(Flat* flat);
    int size();
    friend std::ostream& operator<<(std::ostream& writer, List& list);
};