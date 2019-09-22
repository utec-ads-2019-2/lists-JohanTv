#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
            this->current = other.current;
            return (*this);
        }

        bool operator!=(BidirectionalIterator<T> other) {
            if(this->current != other.current) return true;
            return false;
        }

        BidirectionalIterator<T> operator++() {
            this->current = this->current->next;
            return (*this);
        }

        BidirectionalIterator<T> operator--() {
            this->current = this->current->prev;
            return (*this);
        }

        T operator*() {
            // Falta controlar el caso vacío, esto puede explotar
            return this->current->data;
        }
};

#endif