/*
 * This is the implementation of the AVL Tree.
 * The design of the AVL is separated into 3 files:
 * 1) AVL.h, which contains the class declarations.
 * 2) AVL-inl.h, which contains the implementations of the public methods.
 * 3) AVL-private-inl.h, which contains the implementations of the private methods.
 *
 * Swarthmore College, CS71, Group 7
 * */

#ifndef AVL_H
#define AVL_H

#include <stdexcept>

#include "../LinkedBST/LinkedBST.h"

using std::runtime_error;

/**
 * This class is a child class of linked BST.
 * It modifies some methods of the linked BST to
 * implement an AVL Structure.
 * @kparam K The type of the key.
 * @vparam V The type of the value.
 */
template<typename K, typename V>
class AVL : public LinkedBST<K, V> {
public:

    void insert(K key, V value);

    void remove(K key);

private:
    /**
     * Given a BST node, get the current balance.
     * @param current The root of the subtree.
     * @return The balance of the subtree.
     */
    int getBalance(LinkedBSTNode<K, V> *current);

    /**
    * Given a BST node, right rotate it.
    * @param current The root of the subtree.
    * @return The new root of the subtree.
    */
    LinkedBSTNode<K, V> *rightRotate(LinkedBSTNode<K, V> *current);

    /**
    * Given a BST node, left rotate it.
    * @param current The root of the subtree.
    * @return The new root of the subtree.
    */
    LinkedBSTNode<K, V> *leftRotate(LinkedBSTNode<K, V> *current);

    /**
     * Given a BST node, determines the height of the subtree it represents.
     * @param current The root of the subtree.
     * @return The height of that subtree.
     */
    int getHeightInSubtree(LinkedBSTNode<K, V> *current);

    /**
     * Given a BST node, determines the maximum key which appears in its
     * subtree.
     * @param current The root of the subtree.
     * @return The key-value pair for the maximum key value that appears in that
     *         subtree.
     * @throws runtime_error If the subtree is empty.
     */
    pair<K, V> getMaxInSubtree(LinkedBSTNode<K, V> *current);

    /**
     * Given a BST node, inserts a new node with the provided key into the
     * subtree at the appropriate location.  If this function does not throw an
     * exception, it adds a new node to the subtree.  In particular, it will return a
     * non-null(ptr) value when given a null(ptr) root; the caller should then use this new
     * value to replace the old subtree.
     * @param current The root of the subtree.
     * @param key The key for which we are creating a mapping.
     * @param value The value for which we are creating a mapping.
     * @return The new root of the subtree.
     * @throws runtime_error If the provided key already exists in this tree.
     */
    LinkedBSTNode<K, V> *insertInSubtree(LinkedBSTNode<K, V> *current, K key,
                                         V value);

    /**
     * Given a BST node, removes the node with the specified key from the
     * subtree.
     * If this function does not throw an exception, it deletes a node from the
     * subtree, reducing the subtree's size by 1.  In that case, it will provide
     * a pointer to the new root of this subtree (since the subtree's root may
     * have been deleted or otherwise rearranged by this call).
     * @param current The root of the subtree.
     * @param key The key we are removing from the subtree.
     * @return The new root of the subtree.
     * @throws runtime_error If the provided key does not exist in this tree.
     */
    LinkedBSTNode<K, V> *removeFromSubtree(LinkedBSTNode<K, V> *current, K key);
};

#include "AVL-inl.h"
#include "AVL-private-inl.h"

#endif //AVL_H