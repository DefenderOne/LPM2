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

int List::size() {
    return _size;
}

std::ostream& operator<<(std::ostream& writer, List& list) {
    Node* p = list.head;
    while (p->next->next != nullptr) {
        std::cout << p->next->flat->number << ' ';
        p = p->next;
    }
    std::cout << std::endl;
    return writer;
}

#pragma endregion