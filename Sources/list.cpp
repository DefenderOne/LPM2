#include "../Headers/list.h"

#pragma region Node Description

Node::Node(Flat* flat, Node* next, Node* prev) {
    this->flat = flat;
    this->next = next;
    this->prev = prev;
}

Node::~Node() {
    Node* p = head;
    delete flat;
    flat = nullptr;
    next = nullptr;
    prev = nullptr;
}

#pragma endregion

#pragma region List Container

List::List() {
    head = new Node(nullptr, tail);
    tail = new Node(nullptr, nullptr, head);
}

List::~List() {
    Node* p;
    while (p != nullptr) {
        p = head->next;
        delete head;
        head = nullptr;
    }
}

#pragma endregion