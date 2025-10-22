#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include <iostream>
#include "nodes.hpp"
using namespace std;

class CircularDoublyLinkedList {
private:
    DNode* head;

public:

    CircularDoublyLinkedList() : head(nullptr) {}

    void insertFront(int value) {
        DNode* newNode = new DNode;

        if (head == nullptr) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }

        DNode* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    void insertBack(int value) {
        DNode* newNode = new DNode;

        if (head == nullptr) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }

        DNode* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void deleteFront() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        DNode* tail = head->prev;
        DNode* temp = head;

        head = head->next;
        head->prev = tail;
        tail->next = head;

        delete temp;
    }

    void deleteBack() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        DNode* tail = head->prev;
        DNode* newTail = tail->prev;

        newTail->next = head;
        head->prev = newTail;

        delete tail;
    }

    void display() const {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        DNode* temp = head;
        do {
            cout << temp->value << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    int get_size() {
        if (!head) return sizeof(*this); // only the object itself

        int total_size = sizeof(*this); // size of the CDLL object
        DNode* current = head;
        do {
            total_size += sizeof(*current); // size of each DNode
            current = current->next;
        } while (current != head);

        return total_size;
    }
};

#endif
