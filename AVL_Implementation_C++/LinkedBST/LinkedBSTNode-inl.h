#include "LinkedBSTNode.h"

template<typename K, typename V>
LinkedBSTNode<K, V>::LinkedBSTNode(K key, V value) {
    this->key = key;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

template<typename K, typename V>
LinkedBSTNode<K, V>::LinkedBSTNode(K key, V value, LinkedBSTNode<K, V> *left, LinkedBSTNode<K, V> *right) {
    this->key = key;
    this->value = value;
    this->left = left;
    this->right = right;
}

template<typename K, typename V>
K LinkedBSTNode<K, V>::getKey() {
    return this->key;
}

template<typename K, typename V>
void LinkedBSTNode<K, V>::setKey(K current_key) {
    this->key = current_key;
}

template<typename K, typename V>
V LinkedBSTNode<K, V>::getValue() {
    return this->value;
}

template<typename K, typename V>
void LinkedBSTNode<K, V>::setValue(V current_value) {
    this->value = current_value;
}

template<typename K, typename V>
LinkedBSTNode<K, V> *LinkedBSTNode<K, V>::getLeft() {
    return this->left;
}

template<typename K, typename V>
LinkedBSTNode<K, V> *LinkedBSTNode<K, V>::getRight() {
    return this->right;
}

template<typename K, typename V>
void LinkedBSTNode<K, V>::setLeft(LinkedBSTNode<K, V> *newLeft) {
    this->left = newLeft;
}

template<typename K, typename V>
void LinkedBSTNode<K, V>::setRight(LinkedBSTNode<K, V> *newRight) {
    this->right = newRight;
}