#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T value): data(value), next(nullptr), prev(nullptr){};

    void killSelf() {
        if(next != nullptr) next->killSelf();
        delete this;
    }
};

#endif