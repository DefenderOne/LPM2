#include <fstream>
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
    head = new Node(nullptr);
    tail = new Node(nullptr, nullptr, head);
    head->next = tail;
    _size = 0;
}

List::List(std::ifstream& reader) {
    head = new Node(nullptr);
    tail = new Node(nullptr, nullptr, head);
    head->next = tail;
    _size = 0;
    int roomsCount;
    int level;
    Square* square;
    int membersCount;
    Address* address;

    std::string street;
    while (std::getline(reader, street)) {
        square = new Square;
        address = new Address(street);
        reader >> roomsCount >> level >> 
        square->overallSquare >> square->livingSquare >>
        membersCount >> address->buildingNumber >> address->flatNumber;
        reader.get();
        Flat* flat = new Flat(roomsCount, level, square, membersCount, address);
        Node* insertedNode = new Node(flat);
        pushBefore(findPlaceByAscending(insertedNode), flat);
        // Remove when tested out
        std::cout << flat->GetAddress().GetFullAddress() << std::endl;
    }
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
        _size--;
    }
}

void List::popFront() {
    if (head->next != tail) {
        Node* deletedNode = head->next;
        head->next = deletedNode->next;
        deletedNode->next->prev = head;
        delete deletedNode;
        deletedNode = nullptr;
        _size--;
    }
}

void List::pop(Node* deletedNode) {
    if (deletedNode != head && deletedNode != tail) {
        deletedNode->next->prev = deletedNode->prev;
        deletedNode->prev->next = deletedNode->next;
        _size--;
    }
}

Node* List::findPlaceByAscending(Node* insertedNode) {
    Node* temp = head->next;
    Node* result = nullptr;
    while (temp->next != nullptr && result == nullptr) {
        if (temp->flat->Compare(insertedNode->flat) >= 0) {
            result = temp;
        }
        temp = temp->next;
    }
    if (result == nullptr) {
        result = tail;
    }
    return result;
    // pushBefore
}

Node* List::findPlaceByDescending(Node* insertedNode) {
    Node* temp = tail->prev;
    Node* result = nullptr;
    while (temp->prev != nullptr && result == nullptr) {
        if (temp->flat->Compare(insertedNode->flat) <= 0) {
            result = temp;
        }
        temp = temp->prev;
    }
    if (result == nullptr) {
        result = head;
    }
    return result;
    // pushAfter
}

void List::pushAfter(Node* node, Flat* flat) {
    Node* insertedNode = new Node(flat, node->next, node);
    node->next = insertedNode;
    insertedNode->next->prev = insertedNode;
    _size++;
}

void List::pushBefore(Node* node, Flat* flat) {
    Node* insertedNode = new Node(flat, node, node->prev);
    node->prev = insertedNode;
    insertedNode->prev->next = insertedNode;
    _size++;
}

int List::size() {
    return _size;
}

std::ostream& operator<<(std::ostream& writer, List& list) {
    Node* printedNode = list.head->next;
    while (printedNode->next != nullptr) {
        writer << printedNode->flat->GetAddress().GetFullAddress() << std::endl;
        printedNode = printedNode->next;
    }
    return writer;
}

#pragma endregion