/*
 * This is the implementation of the linked list.
 * The design of the linked list is separated into 2 files:
 * 1) LinkedList.h, which contains the class declarations.
 * 2) LinkedList-inl.h, which contains the implementations of the public methods.
 *
 * Swarthmore College, CS71, Group 7
 * */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

#include "../adts/list.h"

using std::runtime_error;

/**
 * This class represents a single node in a linked list. It contains
 * one list element as well as pointers to the nodes which follow it
 * (or NULL when those nodes don't exist).
 * @tparam T The type of data stored in the list.
 */
template<typename T>
class LinkedListNode {
public:
    /**
     * Constructs a new node.
     * @param val The value to store in the node.
     * @param next An optional pointer to the following node.
     *             If unspecified next should be set to nullptr.
     */
    LinkedListNode(T val, LinkedListNode<T> *next);

    T value;
    LinkedListNode<T> *next;
};

/**
 * This class implements this list ADT as a linked list.
 * @tparam T The type of data stored in the list.
 */
template<typename T>
class LinkedList : public List<T> {
public:
    LinkedList();

    ~LinkedList();

    /**
     * Confirms that there are this->size elements in the list.
     * @throws runtime_error if the invariant does not hold.
     */
    void checkInvariants();

    int getSize();

    bool isEmpty();

    T getFirst();

    T getLast();

    T get(int index);

    void insertFirst(T value);

    void insertLast(T value);

    T removeFirst();

    T removeLast();

private:
    LinkedListNode<T> *head;
    LinkedListNode<T> *tail;
    int size;
};

#include "LinkedList-inl.h"

#endif //LINKEDLIST_H