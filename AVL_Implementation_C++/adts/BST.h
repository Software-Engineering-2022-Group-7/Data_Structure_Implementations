#ifndef BST_H
#define BST_H

#include "dictionary.h"
#include <utility>
#include <vector>

using std::pair;
using std::vector;

/**
 * The interface for a binary search tree.  Note that it is a template
 * definition based on a type for key (K) and type for value (V).  A BST is a
 * dictionary structure; that is, elements are indexed by key and all keys must
 * be unique.  This interface therefore inherits from the Dictionary interface.
 * @tparam K The type of keys in the BST.
 * @tparam V The type of values in the BST.
 */
template<typename K, typename V>
class BST : public Dictionary<K, V> {
public:
    virtual ~BST() = default;

    /* See dictionary.h for a description of these methods */
    virtual int getSize() = 0;

    virtual bool isEmpty() = 0;

    virtual void insert(K key, V value) = 0;

    virtual void update(K key, V value) = 0;

    virtual V get(K key) = 0;

    virtual bool contains(K key) = 0;

    virtual void remove(K key) = 0;

    virtual vector<K> getKeys() = 0;

    virtual vector<pair<K, V>> getItems() = 0;

    /**
     * Returns a height for the tree (i.e., largest depth for any leaf node).
     * @return The height of this tree (or -1 if the tree is empty).
     */
    virtual int getHeight() = 0;

    /**
    * Returns the smallest key in this tree.
    * @return The minimum key in the BST.
    * @throws runtime_error If this BST is empty.
    */
    virtual K getMinKey() = 0;

    /**
     * Returns the largest key in this tree.
     * @return The maximum key in the BST.
     * @throws runtime_error If this BST is empty.
     */
    virtual K getMaxKey() = 0;

    /**
     * Obtains a pre-order traversal of the key-value pairs in this BST.
     * @return An STL vector containing all key-value pairs in this BST.  This
     *         vector is guaranteed to return the elements in a pre-order
     *         traversal.
     */
    virtual vector<pair<K, V>> traversePreOrder() = 0;

    /**
     * Obtains a in-order traversal of the key-value pairs in this BST.
     * @return An STL vector containing all key-value pairs in this BST.  This
     *         vector is guaranteed to return the elements in a in-order
     *         traversal.
     */
    virtual vector<pair<K, V>> traverseInOrder() = 0;

    /**
     * Obtains a post-order traversal of the key-value pairs in this BST.
     * @return An STL vector containing all key-value pairs in this BST.  This
     *         vector is guaranteed to return the elements in a post-order
     *         traversal.
     */
    virtual vector<pair<K, V>> traversePostOrder() = 0;

    /**
     * Obtains a level-order traversal of the key-value pairs in this BST.
     * @return An STL vector containing all key-value pairs in this BST.  This
     *         vector is guaranteed to return the elements in a level-order
     *         traversal.
     */
    virtual vector<pair<K, V>> traverseLevelOrder() = 0;
};

#endif //BST_H