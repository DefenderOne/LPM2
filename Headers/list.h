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

    void pop(Node* deletedNode);
    Node* findPlaceByAscending(Node* insertedNode);
    Node* findPlaceByDescending(Node* insertedNode);
    void pushAfter(Node* node, Flat* flat);
    void pushBefore(Node* node, Flat* flat);

    public:
    List();
    List(std::ifstream& reader);
    ~List();

    void pushBack(Flat* flat);
    void pushFront(Flat* flat);
    void popBack();
    void popFront();
    Flat& operator[](int index);

    int size();
    friend std::ostream& operator<<(std::ostream& writer, List& list);
};