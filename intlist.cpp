// intlist.cpp
// Implements class IntList
// Luis Bernuy , 18 april

#include "intlist.h"
#include <iostream>
using std::cout;

// constructor sets up empty list
IntList::IntList() {
    head = nullptr;
}

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    if (source.head == nullptr)
        return;

    head = new Node{source.head->info, nullptr};
    Node* src_node = source.head->next;
    Node* dest_node = head;

    while (src_node != nullptr) {
        dest_node->next = new Node{src_node->info, nullptr};
        dest_node = dest_node->next;
        src_node = src_node->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* new_node = new Node{value, nullptr};
    if (head == nullptr) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = new_node;
    }
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* new_node = new Node{value, head};
    head = new_node;
}

// return count of values
int IntList::count() const {
    int total = 0;
    Node* current = head;
    while (current != nullptr) {
        total++;
        current = current->next;
    }
    return total;
}

// return sum of values in list
int IntList::sum() const {
    int total = 0;
    Node* current = head;
    while (current != nullptr) {
        total += current->info;
        current = current->next;
    }
    return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->info == value)
            return true;
        current = current->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr)
        return 0;
    int max_val = head->info;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->info > max_val)
            max_val = current->info;
        current = current->next;
    }
    return max_val;
}

// returns average (arithmetic mean) of all values, or 0 if list is empty
double IntList::average() const {
    int total = sum();
    int num = count();
    return num == 0 ? 0.0 : static_cast<double>(total) / num;
}

// Assignment operator: deep copy from source
IntList& IntList::operator=(const IntList& source) {
    if (this == &source) return *this;

    // First, delete existing nodes
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;

    // Deep copy from source
    if (source.head == nullptr) return *this;

    head = new Node{source.head->info, nullptr};
    Node* src_node = source.head->next;
    Node* dest_node = head;

    while (src_node != nullptr) {
        dest_node->next = new Node{src_node->info, nullptr};
        dest_node = dest_node->next;
        src_node = src_node->next;
    }

    return *this;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclosed in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}
