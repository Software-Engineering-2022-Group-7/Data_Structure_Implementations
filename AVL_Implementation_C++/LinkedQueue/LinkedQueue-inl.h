#include "LinkedQueue.h"

template<typename T>
LinkedQueue<T>::LinkedQueue() {
    this->list = new LinkedList<T>();
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    delete this->list;
}

template<typename T>
void LinkedQueue<T>::enqueue(T element) {
    this->list->insertLast(element);
}

template<typename T>
T LinkedQueue<T>::dequeue() {
    return this->list->removeFirst();
}

template<typename T>
void LinkedQueue<T>::insert(T element) {
    this->enqueue(element);
}

template<typename T>
T LinkedQueue<T>::remove() {
    return this->dequeue();
}

template<typename T>
int LinkedQueue<T>::getSize() {
    return this->list->getSize();
}

template<typename T>
bool LinkedQueue<T>::isEmpty() {
    return this->list->isEmpty();
}

template<typename T>
T LinkedQueue<T>::peek() {
    return this->list->getFirst();
}
