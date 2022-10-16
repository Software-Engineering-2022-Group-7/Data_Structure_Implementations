/*
 * This is the implementation of the linked queue.
 * The design of the linked queue is separated into 2 files:
 * 1) LinkedQueue.h, which contains the class declarations.
 * 2) LinkedQueue-inl.h, which contains the implementations of the public methods.
 *
 * Swarthmore College, CS71, Group 7
 * */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "../adts/queue.h"
#include "../LinkedList/LinkedList.h"

/**
 * The LinkedQueue is an implementation of the Queue interface using a
 * linked list.
 * @tparam T The type of elements stored in the queue.
 */
template<typename T>
class LinkedQueue : public Queue<T> {
public:
    LinkedQueue();

    ~LinkedQueue();

    void enqueue(T element);

    T dequeue();

    void insert(T element);

    T remove();

    int getSize();

    bool isEmpty();

    T peek();

private:
    LinkedList<T> *list;
};

#include "LinkedQueue-inl.h"

#endif //LINKEDQUEUE_H