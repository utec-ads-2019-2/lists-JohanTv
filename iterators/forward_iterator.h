#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class ForwardIterator : public Iterator<T> {
    public:
        ForwardIterator() : Iterator<T>() {};
        ForwardIterator(Node<T> *node) : Iterator<T>(node) {};

        ForwardIterator<T> operator=(ForwardIterator<T> other) {
            this->current = other.current;
            return (*this);
        }

        bool operator!=(ForwardIterator<T> other) {
            return (this->current != other.current);
        }

        ForwardIterator<T> operator++() {
            this->current = this->current->next;
            return (*this);
        }

        T operator*() {
            // Falta controlar el caso vacío, esto puede explotar
            return this->current->data;
        }
};

#endif