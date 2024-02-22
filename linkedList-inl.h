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
    // TODO: Not yet implemented: LinkedList::~LinkedList
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
    throw runtime_error("Not yet implemented: LinkedList::getSize");
}

template <typename T> bool LinkedList<T>::isEmpty() {
    throw runtime_error("Not yet implemented: LinkedList::isEmpty");
}

template <typename T> T LinkedList<T>::getFirst() {
    if (this->size == 0) {
        throw runtime_error("LinkedList::getFirst has no nodes in the list.");
    } else {
        return this->head->value;
    }
}

template <typename T> T LinkedList<T>::getLast() {
    throw runtime_error("Not yet implemented: LinkedList::getLast");
}

template <typename T> T LinkedList<T>::get(int index) {
    throw runtime_error("Not yet implemented: LinkedList::get");
}

template <typename T> void LinkedList<T>::insertFirst(T value) {
    LinkedListNode<T>* node = new LinkedListNode<T>(value, this->head);
    this->head = node;
    if (this->size == 0) {
        this->tail = node;
    }
    size++;
}

template <typename T> void LinkedList<T>::insertLast(T value) {
    LinkedListNode<T>* node = new LinkedListNode<T>(value, this->head);
    this->tail = node;
    if (this->size == 0) {
        this->head = node;
    }
    size++;
}

template <typename T> T LinkedList<T>::removeFirst() {
    if (this->size == 0) {
        throw runtime_error("LinkedList::removeFirst there are no nodes in the list.");
    } else if (size == 1) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        LinkedListNode<T> * temp = this->head->next;
        this->head = temp;
        delete temp;
    }
    size--;
    return this->head->value;
}

template <typename T> T LinkedList<T>::removeLast() {
    throw runtime_error("Not yet implemented: LinkedList::removeLast");
}
