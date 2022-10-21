#include "AVL.h"

template<typename K, typename V>
int AVL<K, V>::getBalance(LinkedBSTNode<K, V> *current) {
    if (current == nullptr) {
        return 0;
    }
    int leftHeight = getHeightInSubtree(current->getLeft());
    int rightHeight = getHeightInSubtree(current->getRight());
    return leftHeight - rightHeight;
}

template<typename K, typename V>
LinkedBSTNode<K, V> *AVL<K, V>::rightRotate(LinkedBSTNode<K, V> *current) {
    LinkedBSTNode<K, V> *left = current->getLeft();
    LinkedBSTNode<K, V> *right = left->getRight();

    left->setRight(current);
    current->setLeft(right);

    return left;
}

template<typename K, typename V>
LinkedBSTNode<K, V> *AVL<K, V>::leftRotate(LinkedBSTNode<K, V> *current) {
    LinkedBSTNode<K, V> *right = current->getRight();
    LinkedBSTNode<K, V> *left = right->getLeft();

    right->setLeft(current);
    current->setRight(left);

    return right;
}

template<typename K, typename V>
int AVL<K, V>::getHeightInSubtree(LinkedBSTNode<K, V> *current) {
    if (current == nullptr) {
        return -1;
    }
    int left_height = getHeightInSubtree(current->getLeft()) + 1;
    int right_height = getHeightInSubtree(current->getRight()) + 1;

    if (left_height >= right_height) {
        return left_height;
    } else {
        return right_height;
    }
}

template<typename K, typename V>
pair<K, V> AVL<K, V>::getMaxInSubtree(LinkedBSTNode<K, V> *current) {
    if (current == nullptr) {
        throw runtime_error("The tree is empty");
    }
    while (current->getRight() != nullptr) {
        current = current->getRight();
    }
    pair<K, V> max_pair;
    max_pair.first = current->getKey();
    max_pair.second = current->getValue();
    return max_pair;
}

template<typename K, typename V>
LinkedBSTNode<K, V> *AVL<K, V>::insertInSubtree(LinkedBSTNode<K, V> *current, K key, V value) {
    if (current == nullptr) {
        auto *new_node = new LinkedBSTNode<K, V>(key, value);
        return new_node;
    } else if (current->getKey() == key) {
        throw runtime_error("The key already exists.");
    } else if (key > current->getKey()) {
        current->setRight(insertInSubtree(current->getRight(), key, value));
    } else if (key < current->getKey()) {
        current->setLeft(insertInSubtree(current->getLeft(), key, value));
    }
    int balance = getBalance(current);

    // Left-left
    if (balance > 1 && key < current->getLeft()->getKey()) {
        current = rightRotate(current);
    }

    // Right-right
    if (balance < -1 && key > current->getRight()->getKey()) {
        current = leftRotate(current);
    }

    // Left-right
    if (balance > 1 && key > current->getLeft()->getKey()) {
        current->setLeft(leftRotate(current->getLeft()));
        return rightRotate(current);
    }

    // Right-left
    if (balance < -1 && key < current->getRight()->getKey()) {
        current->setRight(rightRotate(current->getRight()));
        return leftRotate(current);
    }

    return current;
}

template<typename K, typename V>
LinkedBSTNode<K, V> *AVL<K, V>::removeFromSubtree(LinkedBSTNode<K, V> *current, K key) {
    if (current == nullptr) {
        throw runtime_error("The key does not exist.");
    } else if (key > current->getKey()) {
        current->setRight(removeFromSubtree(current->getRight(), key));
        return current;
    } else if (key < current->getKey()) {
        current->setLeft(removeFromSubtree(current->getLeft(), key));
        return current;
    } else {
        if (current->getLeft() == nullptr && current->getRight() == nullptr) {
            delete current;
            current = nullptr;
            return current;
        } else if (current->getLeft() == nullptr) {
            auto *replace_node = current->getRight();
            delete current;
            current = replace_node;
        } else if (current->getRight() == nullptr) {
            auto *replace_node = current->getLeft();
            delete current;
            current = replace_node;
        } else if (current->getLeft() != nullptr && current->getRight() != nullptr) {
            pair<K, V> node_value = getMaxInSubtree(current->getLeft());
            // delete the node that is used to replace
            current->setLeft(removeFromSubtree(current->getLeft(), node_value.first));
            // change the current pair to the replaced pair
            current->setKey(node_value.first);
            current->setValue(node_value.second);
        }
    }

    if (current == nullptr) {
        return current;
    }

    int balance = getBalance(current);

    // Left-left Case
    if (balance > 1 && getBalance(current->getLeft()) >= 0) {
        return rightRotate(current);
    }

    // Left-right Case
    if (balance > 1 && getBalance(current->getLeft()) < 0) {
        current->setLeft(leftRotate(current->getLeft()));
        return rightRotate(current);
    }

    // Right-right Case
    if (balance < -1 && getBalance(current->getRight()) <= 0) {
        return leftRotate(current);
    }

    // Right-left Case
    if (balance < -1 && getBalance(current->getRight()) > 0) {
        current->setRight(rightRotate(current->getRight()));
        return leftRotate(current);
    }

    return current;
}
