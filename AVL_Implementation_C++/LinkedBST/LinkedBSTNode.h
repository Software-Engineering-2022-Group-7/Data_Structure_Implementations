/*
 * This is the implementation of the linked Binary Search Tree Node.
 * The design of the node is separated into 2 files:
 * 1) LinkedBSTNode.h, which contains the class declarations.
 * 2) LinkedBSTNode-inl.h, which contains the implementations of the public methods.
 *
 * Swarthmore College, CS71, Group 7
 * */

#ifndef LINKEDBSTNODE_H
#define LINKEDBSTNODE_H

/**
 * A class to contain BST node data. This is similar to a linked list node: it
 * is just a simple data container.
 * @kparam K The type of the key.
 * @vparam V The type of the value.
 */
template<typename K, typename V>
class LinkedBSTNode {
public:
    /**
     * Creates a LinkedBSTNode with a set key and value.  The pointer fields are
     * set to nullptr.
     * @param key The key for this node.
     * @param value The value for this node.
     */
    LinkedBSTNode(K key, V value);

    /**
     * Creates a LinkedBSTNode with a set key, value, and children.
     * @param key The key for this node.
     * @param value The value for this node.
     * @param left The left child of this node.
     * @param right The right child of this node.
     */
    LinkedBSTNode(K key, V value, LinkedBSTNode<K, V> *left,
                  LinkedBSTNode<K, V> *right);

    /** Accessor and Mutator Methods for LinkedBSTNode **/
    K getKey();

    void setKey(K key);

    V getValue();

    void setValue(V value);

    LinkedBSTNode<K, V> *getLeft();

    LinkedBSTNode<K, V> *getRight();

    void setLeft(LinkedBSTNode<K, V> *newLeft);

    void setRight(LinkedBSTNode<K, V> *newRight);

private:
    K key;
    V value;
    LinkedBSTNode<K, V> *left;
    LinkedBSTNode<K, V> *right;
};

#include "LinkedBSTNode-inl.h"

#endif //LINKEDBSTNODE_H