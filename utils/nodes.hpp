#ifndef NODES_HPP
#define NODES_HPP

struct Node{
    int value;
    Node* next;
};

struct DNode{
    int value;
    DNode* next;
    DNode* prev;
};

#endif