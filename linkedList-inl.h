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
    throw runtime_error("Not yet implemented: LinkedList::LinkedList");
}

template <typename T> LinkedList<T>::~LinkedList() {
    // TODO: Not yet implemented: LinkedList::~LinkedList
}

template <typename T> void LinkedList<T>::checkInvariants() {
    throw runtime_error("Not yet implemented: LinkedList::checkInvariants");
}

template <typename T> int LinkedList<T>::getSize() {
    throw runtime_error("Not yet implemented: LinkedList::getSize");
}

template <typename T> bool LinkedList<T>::isEmpty() {
    throw runtime_error("Not yet implemented: LinkedList::isEmpty");
}

template <typename T> T LinkedList<T>::getFirst() {
    throw runtime_error("Not yet implemented: LinkedList::getFirst");
}

template <typename T> T LinkedList<T>::getLast() {
    throw runtime_error("Not yet implemented: LinkedList::getLast");
}

template <typename T> T LinkedList<T>::get(int index) {
    throw runtime_error("Not yet implemented: LinkedList::get");
}

template <typename T> void LinkedList<T>::insertFirst(T value) {
    throw runtime_error("Not yet implemented: LinkedList::insertFirst");
}

template <typename T> void LinkedList<T>::insertLast(T value) {
    throw runtime_error("Not yet implemented: LinkedList::insertLast");
}

template <typename T> T LinkedList<T>::removeFirst() {
    throw runtime_error("Not yet implemented: LinkedList::removeFirst");
}

template <typename T> T LinkedList<T>::removeLast() {
    throw runtime_error("Not yet implemented: LinkedList::removeLast");
}
