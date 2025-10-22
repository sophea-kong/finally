#ifndef CSLL_HPP
#define CSLL_HPP

#include "nodes.hpp"
#include <iostream>

class CSLL {
private:
    Node* tail;

public:
    CSLL() : tail(nullptr) {}

    ~CSLL() {
        if (!tail) return;
        Node* current = tail->next;
        Node* nextNode;
        while (current != tail) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete tail;
    }

    void insertFront(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void insertBack(int value) {
        insertFront(value);
        tail = tail->next;
    }

    bool deleteValue(int value) {
        if (!tail) return false;

        Node* current = tail->next;
        Node* prev = tail;
        do {
            if (current->value == value) {
                if (current == tail) {
                    if (tail == tail->next) {
                        delete tail;
                        tail = nullptr;
                    } else {
                        prev->next = current->next;
                        delete current;
                        tail = prev;
                    }
                } else {
                    prev->next = current->next;
                    delete current;
                }
                return true;
            }
            prev = current;
            current = current->next;
        } while (current != tail->next);

        return false;
    }

    bool search(int value) {
        if (!tail) return false;
        Node* current = tail->next;
        do {
            if (current->value == value) return true;
            current = current->next;
        } while (current != tail->next);
        return false;
    }

    void travel_n_nodes(int n) {
    if (!tail || n <= 0) {
        std::cout << "Invalid traversal.\n";
        return;
    }
    Node* current = tail->next;
    for (int i = 0; i < n; ++i) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "...\n";
    }

    void rotate_k_nodes(int k) {
        if (!tail || k <= 0) return;
        for (int i = 0; i < k; ++i) {
            tail = tail->next;
        }
    }

    void display() {
        if (!tail) {
            std::cout << "List is empty.\n";
            return;
        }
        Node* current = tail->next;
        do {
            std::cout << current->value << " -> ";
            current = current->next;
        } while (current != tail->next);
        std::cout << "(back to head)\n";
    }

    int get_size() {
        if (!tail) return 0;
        int count = 0;
        Node* temp = tail->next;
        while (temp != tail) {
            count += sizeof(temp);
            temp = temp->next;
        }
        return count;
    }
};

#endif
 
