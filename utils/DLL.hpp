#include <iostream>
#include <chrono>
#include <functional>

using namespace std;
using clk = chrono::high_resolution_clock;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int n;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
        n = 0;
    }

    void push_front(int val) {
        Node* node = new Node{val, nullptr, head};
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = node;
        n++;
    }

    void push_back(int val) {
        Node* node = new Node{val, tail, nullptr};
        if (tail) tail->next = node;
        tail = node;
        if (!head) head = node;
        n++;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        n--;
    }

    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        n--;
    }

    void erase(Node* node) {
        if (!node) return;
        if (node->prev) node->prev->next = node->next;
        else head = node->next;
        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
        delete node;
        n--;
    }

    void print() {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    Node* getHead() { return head; }
    Node* getTail() { return tail; }
    int size() { return n; }
};

void dll_observe(std::function<void()> func, string msg) {
    auto t0 = clk::now();
    func(); // Run the operation
    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout << msg << ": " << duration.count() << " nanosecond(s)" << endl;
}
