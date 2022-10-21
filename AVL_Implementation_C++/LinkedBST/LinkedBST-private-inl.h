#include "LinkedBST.h"

using namespace std;

template<typename K, typename V>
V LinkedBST<K, V>::findInSubtree(LinkedBSTNode<K, V> *current, K key) {
    if (current == nullptr) {
        throw runtime_error("The key is not found.");
    } else if (key > current->getKey()) {
        return findInSubtree(current->getRight(), key);
    } else if (key < current->getKey()) {
        return findInSubtree(current->getLeft(), key);
    } else {
        return current->getValue();
    }
}

template<typename K, typename V>
bool LinkedBST<K, V>::containsInSubtree(LinkedBSTNode<K, V> *current, K key) {
    if (current == nullptr) {
        return false;
    } else if (current->getKey() == key) {
        return true;
    }

    if (key > current->getKey()) {
        return containsInSubtree(current->getRight(), key);
    } else {
        return containsInSubtree(current->getLeft(), key);
    }
}

template<typename K, typename V>
void LinkedBST<K, V>::updateInSubtree(LinkedBSTNode<K, V> *current, K key, V value) {
    if (current == nullptr) {
        throw runtime_error("The key is not found.");
    } else if (current->getKey() == key) {
        current->setValue(value);
        return;
    }

    if (key > current->getKey()) {
        return updateInSubtree(current->getRight(), key, value);
    } else {
        return updateInSubtree(current->getLeft(), key, value);
    }
}

template<typename K, typename V>
int LinkedBST<K, V>::getHeightInSubtree(LinkedBSTNode<K, V> *current) {
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
pair<K, V> LinkedBST<K, V>::getMinInSubtree(LinkedBSTNode<K, V> *current) {
    if (current == nullptr) {
        throw runtime_error("The tree is empty");
    }
    while (current->getLeft() != nullptr) {
        current = current->getLeft();
    }
    pair<K, V> min_pair;
    min_pair.first = current->getKey();
    min_pair.second = current->getValue();
    return min_pair;
}

template<typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMaxInSubtree(LinkedBSTNode<K, V> *current) {
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
LinkedBSTNode<K, V> *LinkedBST<K, V>::insertInSubtree(LinkedBSTNode<K, V> *current, K key, V value) {
    if (current == nullptr) {
        auto* new_node = new LinkedBSTNode<K, V>(key, value);
        return new_node;
    } else if (current->getKey() == key) {
        throw runtime_error("The key already exists.");
    } else if (key > current->getKey()) {
        current->setRight(insertInSubtree(current->getRight(), key, value));
        return current;
    } else {
        current->setLeft(insertInSubtree(current->getLeft(), key, value));
        return current;
    }
}

template<typename K, typename V>
LinkedBSTNode<K, V> *LinkedBST<K, V>::removeFromSubtree(LinkedBSTNode<K, V> *current, K key) {
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
            auto* replace_node = current->getRight();
            delete current;
            return replace_node;
        } else if (current->getRight() == nullptr) {
            auto* replace_node = current->getLeft();
            delete current;
            return replace_node;
        } else if (current->getLeft() != nullptr && current->getRight() != nullptr) {
            pair<K, V> node_value = getMaxInSubtree(current->getLeft());
            // delete the node that is used to replace
            current->setLeft(removeFromSubtree(current->getLeft(), node_value.first));
            // change the current pair to the replaced pair
            current->setKey(node_value.first);
            current->setValue(node_value.second);
            return current;
        }
    }
}

template<typename K, typename V>
void LinkedBST<K, V>::deleteSubtree(LinkedBSTNode<K, V> *current) {
    if (current == nullptr) {
        return;
    }
    deleteSubtree(current->getLeft());
    deleteSubtree(current->getRight());
    delete current;
    current = nullptr;
}

template<typename K, typename V>
void LinkedBST<K, V>::buildPreOrderTraversal(LinkedBSTNode<K, V> *current, List<pair<K, V>> *list) {
    pair<K, V> current_node;
    current_node.first = current->getKey();
    current_node.second = current->getValue();
    list->insertFirst(current_node);
    if (current->getLeft() != nullptr) {
        buildPreOrderTraversal(current->getLeft(), list);
    }
    if (current->getRight() != nullptr) {
        buildPreOrderTraversal(current->getRight(), list);
    }
}

template<typename K, typename V>
void LinkedBST<K, V>::buildPostOrderTraversal(LinkedBSTNode<K, V> *current, List<pair<K, V>> *list) {
    if (current->getLeft() != nullptr) {
        buildPostOrderTraversal(current->getLeft(), list);
    }
    if (current->getRight() != nullptr) {
        buildPostOrderTraversal(current->getRight(), list);
    }
    pair<K, V> current_node;
    current_node.first = current->getKey();
    current_node.second = current->getValue();
    list->insertFirst(current_node);
}

template<typename K, typename V>
void LinkedBST<K, V>::buildInOrderTraversal(LinkedBSTNode<K, V> *current, List<pair<K, V>> *list) {
    if (current->getLeft() != nullptr) {
        buildInOrderTraversal(current->getLeft(), list);
    }
    pair<K, V> current_node;
    current_node.first = current->getKey();
    current_node.second = current->getValue();
    list->insertFirst(current_node);
    if (current->getRight() != nullptr) {
        buildInOrderTraversal(current->getRight(), list);
    }
}

template<typename K, typename V>
int LinkedBST<K, V>::countNodes(LinkedBSTNode<K, V> *current) {
    if (current == nullptr) {
        return 0;
    } else {
        return this->countNodes(current->getLeft()) +
               this->countNodes(current->getRight()) + 1;
    }
}

template<typename K, typename V>
void LinkedBST<K, V>::verifyKeysBoundedBy(LinkedBSTNode<K, V> *current, bool minApplies, K minBound, bool maxApplies,
                                          K maxBound) {
    if (minApplies && current->getKey() < minBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a "
                            "right descendent with lesser key");
    }
    if (maxApplies && current->getKey() > maxBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a left "
                            "descendent with greater key");
    }
    if (current->getLeft() != nullptr) {
        verifyKeysBoundedBy(current->getLeft(), minApplies, minBound, true,
                            current->getKey());
    }
    if (current->getRight() != nullptr) {
        verifyKeysBoundedBy(current->getRight(), true, current->getKey(),
                            maxApplies, maxBound);
    }
}

template<typename K, typename V>
void LinkedBST<K, V>::displaySubtree(LinkedBSTNode<K, V> *current, int space) {
  if(current == nullptr) {
    return;
  }
  space += 10;
  displaySubtree(current->getRight(), space);
  cout << "\n";
  for(int i = 10; i < space; i++) {
    cout << "  ";
  }
  cout << current->getKey() << "\n";
  displaySubtree(current->getLeft(), space);
}
