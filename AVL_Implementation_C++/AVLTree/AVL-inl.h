#include "AVL.h"

template<typename K, typename V>
void AVL<K, V>::insert(K key, V value) {
    this->root = insertInSubtree(this->root, key, value);
    this->size++;
}

template<typename K, typename V>
void AVL<K, V>::remove(K key) {
    this->root = removeFromSubtree(this->root, key);
    this->size--;
}
