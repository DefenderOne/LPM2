#include "../Headers/list.h"
#include "../Headers/flat.h"

#pragma region Node Description

Node::Node(Flat* flat, Node* next, Node* prev) {
    this->flat = flat;
    this->next = next;
    this->prev = prev;
}

Node::~Node() {
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
    _size = 0;
}

// Undone
List::List(std::ifstream& reader) {
    
}

List::~List() {
    Node* deletedNode;
    while (head != nullptr) {
        deletedNode = head;
        head = head->next;
        delete deletedNode;
        deletedNode = nullptr;
    }
}

void List::pushBack(Flat* flat) {
    tail->prev->next = new Node(flat, tail, tail->prev);
    tail->prev = tail->prev->next;
    _size++;
}

void List::pushFront(Flat* flat) {
    head->next->prev = new Node(flat, head->next, head);
    head->next = head->next->prev;
    _size++;
}

void List::popBack() {
    if (tail->prev != head) {
        Node* deletedNode = tail->prev;
        deletedNode->prev->next = tail;
        tail->prev = deletedNode->prev;
        delete deletedNode;
        deletedNode = nullptr;
    }
}

void List::popFront() {
    if (head->next != tail) {
        Node* deletedNode = head->next;
        head->next = deletedNode->next;
        deletedNode->next->prev = head;
        delete deletedNode;
        deletedNode = nullptr;
    }
}

void List::pop(Node* deletedNode) {
    if (deletedNode != head && deletedNode != tail) {
        deletedNode->next->prev = deletedNode->prev;
        deletedNode->prev->next = deletedNode->next;
    }
}

int List::size() {
    return _size;
}

#pragma endregion