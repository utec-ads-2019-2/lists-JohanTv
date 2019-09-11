#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() {
            if(this->head!= nullptr) return this->head->data;
            throw new out_of_range("The list is empty");
        }

        T back() {
            if(this->tail!= nullptr) return this->tail->data;
            throw new out_of_range("The list is empty");
        }

        void push_front(T value) {
            Node<T>* temp = new Node<T>(value);
            if(empty()){
                this->head = temp;
                this->tail = temp;
                this->head->prev = this->tail;
                this->tail->next = this->head;
            }
            else{
                temp->next = this->head;
                temp->prev = this->tail;
                this->head->prev = temp;
                this->tail->next = temp;
                this->head = temp;
            }
            (this->nodes)++;
        }

        void push_back(T value) {
            Node<T>* temp = new Node<T>(value);
            if(empty()){
                this->head = temp;
                this->tail = temp;
                this->head->prev = this->tail;
                this->tail->next = this->head;
            }
            else{
                temp->prev = this->tail;
                temp->next = this->head;
                this->tail->next= temp;
                this->head->prev= temp;
                this->tail = temp;
            }
            (this->nodes)++;
        }

        void pop_front() {
            if(empty()) {
                throw new out_of_range("The list is empty");
            }
            else{
                Node<T>* temp = this->head;
                this->head = this->head->next;

                this->tail->next = this->head;
                this->head->prev = this->tail;

                delete temp;
                (this->nodes)--;
            }
        }

        void pop_back() {
            if(empty()) {
                throw new out_of_range("The list is empty");
            }
            else{
                Node<T>* temp = this->tail;
                this->tail = this->tail->prev;

                this->head->prev = this->tail;
                this->tail->next = this->head;

                delete temp;
                (this->nodes)--;
            }
        }

        T operator[](int index) {
            Node<T> *temp = this->head;
            int recorrido = index%(this->nodes);
            while (recorrido--){
                temp = temp->next;
            }
            return temp->data;
        }

        bool empty() {
            return (this->nodes == 0);
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            this->head->prev = nullptr;
            this->tail->next = nullptr;

            this->head->killSelf();
            this->head = nullptr;
            this->tail = nullptr;

            this->nodes = 0;
        }

        void sort() {
            Node<T>* temp = this->head;
            int size = this->nodes;
            T* elements = new T[size];

            for(int i  = 0; i < size; i++){
                elements[i] = temp->data;
                temp = temp->next;
            }

            std::sort(elements,elements+size);

            temp = this->head;
            for(int i  = 0; i <size; i++){
                temp->data = elements[i];
                temp = temp->next;
            }
        }
    
        void reverse() {
            if(!empty()) {
                Node<T>* temp = this->head;
                int length = this->nodes;
                T* elements = new T[length];

                for (int i = 0; i < length; ++i) {
                    elements[i] = temp->data;
                    temp = temp->next;
                }
                std::reverse(elements,elements+length);
                temp = this->head;

                for (int j = 0; j < length; ++j) {
                    temp->data = elements[j];
                    temp = temp->next;
                }
            }
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            BidirectionalIterator<T> it(this->head);
            return it;
        }

	    BidirectionalIterator<T> end() {
            BidirectionalIterator<T> it(this->tail);
            return it;
        }

        void merge(CircularLinkedList<T> list) {
            Node<T>* temp = list.head;
            while(temp != list.tail){
                this->push_back(temp->data);
                temp = temp->next;
            }
            this->push_back(temp->data);
        }
};

#endif