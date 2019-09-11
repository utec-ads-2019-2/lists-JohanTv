#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front(){
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
            }
            else{
                temp->next = this->head;
                this->head = temp;
            }
            (this->nodes)++;

        }

        void push_back(T value) {
            Node<T>* temp = new Node<T>(value);
            if(empty()){
                this->head = temp;
                this->tail = temp;
            }
            else{
                this->tail->next = temp;
                this->tail = temp;
            }
            (this->nodes)++;
        }

        void pop_front() {
            if(empty()) throw new out_of_range("The list is empty");
            else{
                Node<T>* temp = this->head;
                this->head = this->head->next;
                delete temp;
                (this->nodes)--;
            }
        }
        void pop_back() {
            if(empty()) throw new out_of_range("The list is empty");
            else{
                Node<T>* temp = this->tail;
                int size = this->nodes-2;
                Node<T>* prev = this->head;
                while(size--){
                    prev = prev->next;
                }

                prev->next = nullptr;
                this->tail = prev;
                delete temp;

                (this->nodes)--;
            }
        }

        T operator[](int index) {
            if(0<=index && index<this->nodes) {
                Node<T> *temp = this->head;
                while (index--){
                    temp = temp->next;
                }
                return temp->data;
            }
            else throw new out_of_range("Out of range");

        }

        bool empty() {
            return (this->nodes == 0);
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            this->tail = nullptr;

            this->head->killSelf();
            this->head = nullptr;

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
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            ForwardIterator<T> it(this->head);
            return it;
        }

	    ForwardIterator<T> end() {
            ForwardIterator<T> it(this->tail);
            return it;
        }

        void merge(ForwardList<T> list) {
            Node<T>* temp = list.head;
            while(temp != nullptr){
                this->push_back(temp->data);
                temp = temp->next;
            }
        }
        ~ForwardList(){
            clear();
        }
};

#endif