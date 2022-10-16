/*
 * This is the test file of the AVL Tree.
 * You may manipulate around to see if the implementation is correct.
 * Have fun!
 *
 * Swarthmore College, CS71, Group 7
 * */

#include <iostream>

#include "../LinkedBST/LinkedBST.h"
#include "AVL.h"

using namespace std;

/**
 *         6
 *       /   \
 *      2     7
 *     / \     \
 *    1   5     9
 *       /
 *      3
 *       \
 *        4
 * */
int main() {
    LinkedBST<int, string> *avl = new AVL<int, string>();
    avl->insert(6, "6");
    avl->insert(2, "2");
    avl->insert(7, "7");
    // 1
    cout << "current height = " << avl->getHeight() << endl;
    avl->insert(1, "1");
    avl->insert(5, "5");
    // 2
    cout << "current height = " << avl->getHeight() << endl;
    avl->insert(9, "9");
    avl->insert(3, "3");
    avl->insert(4, "4");
    avl->checkInvariants();
    vector<int> key_list = avl->getKeys();
    for (auto &i: key_list) {
        cout << i << " ";
    }
    cout << endl;
    // 3
    cout << "current height = " << avl->getHeight() << endl;
    avl->remove(4);
    cout << "Does it contain 4: " << avl->contains(4) << endl;
    vector<int> key_list_2 = avl->getKeys();
    for (auto &i: key_list_2) {
        cout << i << " ";
    }
    cout << endl;
    avl->remove(2);
    cout << "Does it contain 2: " << avl->contains(2) << endl;
    vector<int> key_list_3 = avl->getKeys();
    for (auto &i: key_list_3) {
        cout << i << " ";
    }
    cout << endl;
    delete avl;
    return 0;
}