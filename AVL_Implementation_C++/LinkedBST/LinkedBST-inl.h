#include "LinkedBST.h"

using namespace std;

template<typename K, typename V>
LinkedBST<K, V>::LinkedBST() {
    this->size = 0;
    this->root = nullptr;
}

template<typename K, typename V>
LinkedBST<K, V>::~LinkedBST() {
    deleteSubtree(this->root);
}

template<typename K, typename V>
int LinkedBST<K, V>::getSize() {
    return this->size;
}

template<typename K, typename V>
bool LinkedBST<K, V>::isEmpty() {
    return this->size == 0;
}

template<typename K, typename V>
void LinkedBST<K, V>::insert(K key, V value) {
    this->root = insertInSubtree(this->root, key, value);
    this->size++;
}

template<typename K, typename V>
void LinkedBST<K, V>::update(K key, V value) {
    updateInSubtree(this->root, key, value);
}

template<typename K, typename V>
V LinkedBST<K, V>::get(K key) {
    return findInSubtree(this->root, key);
}

template<typename K, typename V>
bool LinkedBST<K, V>::contains(K key) {
    return containsInSubtree(this->root, key);
}

template<typename K, typename V>
void LinkedBST<K, V>::remove(K key) {
    this->root = removeFromSubtree(this->root, key);
    this->size--;
}

template<typename K, typename V>
vector<K> LinkedBST<K, V>::getKeys() {
    vector<pair<K, V>> list_vector;
    list_vector = traversePreOrder();
    vector<K> vector_key;
    for (int i = 0; i < list_vector.size(); i++) {
        vector_key.push_back(list_vector[i].first);
    }
    return vector_key;
}

template<typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::getItems() {
    vector<pair<K, V>> list_vector;
    list_vector = traversePreOrder();
    return list_vector;
}

template<typename K, typename V>
void LinkedBST<K, V>::checkInvariants() {
    if (this->countNodes(this->root) != this->size) {
        throw runtime_error(
                "Problem in BST: Node count doesn't match tree size");
    }
    if (this->root != nullptr) {
        // The bounds provided here are arbitrary because the false
        // arguments indicate that they do not apply.  But we need a
        // value of type K to fill this parameter since we don't have
        // globally min/max K values generically.
        this->verifyKeysBoundedBy(this->root, false, this->root->getKey(),
                                  false, this->root->getKey());
    }
}

template<typename K, typename V>
int LinkedBST<K, V>::getHeight() {
    return getHeightInSubtree(this->root);
}

template<typename K, typename V>
K LinkedBST<K, V>::getMaxKey() {
    return getMaxInSubtree(this->root).first;
}

template<typename K, typename V>
K LinkedBST<K, V>::getMinKey() {
    return getMinInSubtree(this->root).first;
}

template<typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traversePreOrder() {
    List<pair<K, V>> *pair_list = new LinkedList<pair<K, V>>();
    buildPreOrderTraversal(this->root, pair_list);
    vector<pair<K, V>> vector_list;
    while (!pair_list->isEmpty()) {
        vector_list.push_back(pair_list->removeLast());
    }
    delete pair_list;
    return vector_list;
}

template<typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traverseInOrder() {
    List<pair<K, V>> *pair_list = new LinkedList<pair<K, V>>();
    buildInOrderTraversal(this->root, pair_list);
    vector<pair<K, V>> vector_list;
    while (!pair_list->isEmpty()) {
        vector_list.push_back(pair_list->removeLast());
    }
    delete pair_list;
    return vector_list;
}

template<typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traversePostOrder() {
    List<pair<K, V>> *pair_list = new LinkedList<pair<K, V>>();
    buildPostOrderTraversal(this->root, pair_list);
    vector<pair<K, V>> vector_list;
    while (!pair_list->isEmpty()) {
        vector_list.push_back(pair_list->removeLast());
    }
    delete pair_list;
    return vector_list;
}

template<typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traverseLevelOrder() {
    Queue<LinkedBSTNode<K, V> *> *queue = new LinkedQueue<LinkedBSTNode<K, V> *>();
    vector<pair<K, V>> vector_list;
    LinkedBSTNode<K, V> *current_node;
    pair<K, V> current_pair;
    if (this->root == nullptr) {
        return vector_list;
    } else {
        queue->insert(this->root);
    }
    while (!queue->isEmpty()) {
        current_node = queue->remove();
        if (current_node->getLeft() != nullptr) {
            queue->insert(current_node->getLeft());
        }
        if (current_node->getRight() != nullptr) {
            queue->insert(current_node->getRight());
        }
        current_pair.first = current_node->getKey();
        current_pair.second = current_node->getValue();
        vector_list.push_back(current_pair);
    }
    delete queue;
    return vector_list;
}

template<typename K, typename V>
void LinkedBST<K, V>::displayTree() {
  cout << "Tree:\n";
  displaySubtree(this->root, 0);
  cout << "\n\n";
}
