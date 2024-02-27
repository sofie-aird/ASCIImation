/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include <stdexcept>

using std::runtime_error;

// This file defines the methods for two classes: LinkedListNode and LinkedList.
// The LinkedListNode methods have been defined for you.  You are responsible
// for defining the LinkedList methods.

// //////// LinkedListNode /////////////////////////////////////////////////////

template <typename T>
LinkedListNode<T>::LinkedListNode(T val, LinkedListNode<T>* next) {
    this->value = val;
    this->next = next;
}

// //////// LinkedList /////////////////////////////////////////////////////////

template <typename T> LinkedList<T>::LinkedList() {
    this->size = 0;
    this->head = nullptr;
    this-> tail = nullptr;
}

template <typename T> LinkedList<T>::~LinkedList() {
    if (this->size == 0) {
        throw runtime_error("LinkedList::~LinkedList there are no nodes in the list.");
    } else{
        while (this->size != 0){
            for (int i=0; i<this->size; i++){
                LinkedListNode<T> * temp = this->head;
            }
            this->size --; 
        }
    }
    
}

template <typename T> void LinkedList<T>::checkInvariants() {
    int count = 0;
    LinkedListNode<T> * temp = this->head;
    while (temp != nullptr) {
        count += 1;
        temp = temp->next;
    }
    if (count != this->size) {
        throw runtime_error("LinkedList::checkInvariants count doesn't equal size");
    }
}

template <typename T> int LinkedList<T>::getSize() {
    return this->size;
}

template <typename T> bool LinkedList<T>::isEmpty() {
    if (this->size == 0) {
        return true;
    } else {
        return false;
    }
}

template <typename T> T LinkedList<T>::getFirst() {
    if (this->size == 0) {
        throw runtime_error("LinkedList::getFirst has no nodes in the list.");
    } else {
        return this->head->value;
    }
}

template <typename T> T LinkedList<T>::getLast() {
    if (this->size == 0) {
        throw runtime_error("LinkedList::getLast has no nodes in the list.");
    } else {
        return this->tail->value;
    }
}

template <typename T> T LinkedList<T>::get(int index) {
    if ((index < 0) || (index >= this->size)) {
        throw runtime_error("LinkedList::get index is out of range.");
    } else {
        LinkedListNode<T> * temp = this->head;
        int count = 0;
        while (count != index) {
            temp = temp->next;
            count++;
        }
        return temp->value;
    }
}

template <typename T> void LinkedList<T>::insertFirst(T value) {
    LinkedListNode<T>* node = new LinkedListNode<T>(value, this->head);
    this->head = node;
    if (this->size == 0) {
        this->tail = node;
    }
    this->size++;
}

template <typename T> void LinkedList<T>::insertLast(T value) {
    LinkedListNode<T>* node = new LinkedListNode<T>(value, this->head);
    this->tail = node;
    if (this->size == 0) {
        this->head = node;
    }
    this->size++;
}

template <typename T> T LinkedList<T>::removeFirst() {
    if (this->size == 0) {
        throw runtime_error("LinkedList::removeFirst there are no nodes in the list.");
    } 
    T val = this->head->value;
    if (this->size == 1) {
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        LinkedListNode<T> * temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    this->size--;
    return val;
}

template <typename T> T LinkedList<T>::removeLast() {
    if (this->size == 0) {
        throw runtime_error("LinkedList::removeLast there are no nodes in this list");
    }
    T val = this->tail->value; 
    if (this->size == 1) {
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        LinkedListNode<T> * temp = this->head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nullptr;
        this->tail = temp;
        this->size--;
        delete temp;
    } 
    return val;
}
