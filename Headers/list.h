#pragma once

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
    int size;

    public:
    List();
    ~List();
};