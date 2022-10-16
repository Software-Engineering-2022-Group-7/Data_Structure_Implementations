/*
 * This is the test file of the Linked Binary Search Tree.
 * You may manipulate around to see if the implementation is correct.
 * Have fun!
 *
 * Swarthmore College, CS71, Group 7
 * */

#include <iostream>
#include <stdexcept>
#include <vector>

#include "LinkedBST.h"

using namespace std;

/**
 *         6
 *       /   \
 *      2     7
 *     / \     \
 *    1   4     9
 *       /
 *      3
 * */
int main() {

    auto *bst = new LinkedBST<int, string>;
    bst->insert(6, "6");
    bst->insert(2, "2");
    bst->insert(7, "7");
    bst->insert(1, "1");
    bst->insert(4, "4");
    bst->insert(9, "9");
    bst->insert(3, "3");
    bst->checkInvariants();
    cout << bst->get(6) << endl;
    cout << bst->get(2) << endl;
    cout << bst->get(7) << endl;
    cout << bst->get(1) << endl;
    cout << bst->get(4) << endl;
    cout << bst->getHeight() << endl;
    bst->remove(1);
    cout << bst->contains(1) << endl;
    bst->remove(4);
    cout << bst->contains(4) << endl;
    cout << bst->getHeight() << endl;
    /**
     *         6
     *       /   \
     *      2     7
     *       \     \
     *       3     9
     * */
    vector<pair<int, string>> vector_list = bst->traversePreOrder();
    for (auto &i: vector_list) {
        cout << i.first << " ";
    }
    cout << endl;
    vector<pair<int, string>> vector_list_2 = bst->traversePostOrder();
    for (auto &i: vector_list_2) {
        cout << i.first << " ";
    }
    cout << endl;
    vector<pair<int, string>> vector_list_3 = bst->traverseInOrder();
    for (auto &i: vector_list_3) {
        cout << i.first << " ";
    }
    cout << endl;
    vector<pair<int, string>> vector_list_4 = bst->traverseLevelOrder();
    for (auto &i: vector_list_4) {
        cout << i.first << " ";
    }
    cout << endl;
    delete bst;
    return 0;
}
