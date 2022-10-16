#include "LinkedList.h"

template<typename T>
LinkedListNode<T>::LinkedListNode(T val, LinkedListNode<T> *next) {
    this->value = val;
    this->next = next;
}

template<typename T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    LinkedListNode<T> *current = this->head;
    while (current != nullptr) {
        LinkedListNode<T> *next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
void LinkedList<T>::checkInvariants() {
    int count = 0;
    LinkedListNode<T> *current = this->head;
    while (current != nullptr) {
        current = current->next;
        count++;
    }
    if (count != this->size) {
        throw runtime_error("The size of the list does not match");
    }
}

template<typename T>
int LinkedList<T>::getSize() {
    return this->size;
}

template<typename T>
bool LinkedList<T>::isEmpty() {
    return this->size == 0;
}

template<typename T>
T LinkedList<T>::getFirst() {
    if (this->isEmpty()) {
        throw runtime_error("The list is empty.");
    }
    return this->head->value;
}

template<typename T>
T LinkedList<T>::getLast() {
    if (this->isEmpty()) {
        throw runtime_error("The list is empty.");
    }
    return this->tail->value;
}

template<typename T>
T LinkedList<T>::get(int index) {
    if (index < 0 || index >= this->size) {
        throw runtime_error("The index is out of bound.");
    }
    int count = 0;
    LinkedListNode<T> *current = this->head;
    while (count != index) {
        current = current->next;
        count++;
    }
    return current->value;
}

template<typename T>
void LinkedList<T>::insertFirst(T value) {
    auto *node = new LinkedListNode<T>(value, nullptr);
    if (this->isEmpty()) {
        this->head = node;
        this->tail = node;
    } else {
        node->next = this->head;
        this->head = node;
    }
    this->size++;
}

template<typename T>
void LinkedList<T>::insertLast(T value) {
    auto *node = new LinkedListNode<T>(value, nullptr);
    if (this->isEmpty()) {
        this->head = node;
        this->tail = node;
    } else {
        this->tail->next = node;
        this->tail = node;
    }
    this->size++;
}

template<typename T>
T LinkedList<T>::removeFirst() {
    if (this->isEmpty()) {
        throw runtime_error("The list is empty.");
    } else if (this->size == 1) {
        T val = this->head->value;
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
        return val;
    } else {
        T val = this->head->value;
        LinkedListNode<T> *next = this->head->next;
        delete this->head;
        this->head = next;
        this->size--;
        return val;
    }
}

template<typename T>
T LinkedList<T>::removeLast() {
    if (this->isEmpty()) {
        throw runtime_error("The list is empty.");
    } else if (this->size == 1) {
        T val = this->head->value;
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
        return val;
    } else {
        LinkedListNode<T> *current = this->head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        current->next = nullptr;
        T val = this->tail->value;
        delete this->tail;
        this->tail = current;
        this->size--;
        return val;
    }
}