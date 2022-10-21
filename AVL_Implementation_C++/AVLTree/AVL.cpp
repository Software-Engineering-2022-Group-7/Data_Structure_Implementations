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

LinkedBST<string, int>* makeExampleAVL() {
  LinkedBST<string, int> *tree = new AVL<string, int>();
  tree->insert("6", 6);
  tree->insert("2", 2);
  tree->insert("7", 7);
  tree->insert("1", 1);
  tree->insert("4", 4);
  tree->insert("9", 9);
  tree->insert("3", 3);
  tree->displayTree();
  return tree;
}

LinkedBST<string, int>* inLeftLeftAVL() {
  LinkedBST<string, int> *tree = new AVL<string, int>();
  tree->insert("3", 3);
  tree->displayTree();
  tree->insert("2", 2);
  tree->displayTree();
  tree->insert("1", 1);
  tree->displayTree();
  return tree;
}

LinkedBST<string, int>* inRightRightAVL() {
  LinkedBST<string, int> *tree = new AVL<string, int>();
  tree->insert("1", 1);
  tree->displayTree();
  tree->insert("2", 2);
  tree->displayTree();
  tree->insert("3", 3);
  tree->displayTree();
  return tree;
}

LinkedBST<string, int>* inLeftRightAVL() {
  LinkedBST<string, int> *tree = new AVL<string, int>();
  tree->insert("3", 3);
  tree->displayTree();
  tree->insert("1", 1);
  tree->displayTree();
  tree->insert("2", 2);
  tree->displayTree();
  return tree;
}

LinkedBST<string, int>* inRightLeftAVL() {
  LinkedBST<string, int> *tree = new AVL<string, int>();
  tree->insert("1", 1);
  tree->displayTree();
  tree->insert("3", 3);
  tree->displayTree();
  tree->insert("2", 2);
  tree->displayTree();
  return tree;
}

LinkedBST<string, int>* reLeftLeftAVL() {
  LinkedBST<string, int> *tree = new AVL<string, int>();
  tree->insert("3", 3);
  tree->displayTree();
  tree->insert("4", 4);
  tree->displayTree();
  tree->insert("2", 2);
  tree->displayTree();
  tree->insert("1", 1);
  tree->displayTree();
  tree->remove("4");
  tree->displayTree();
  return tree;
}

LinkedBST<string, int>* reRightRightAVL() {
  LinkedBST<string, int> *tree = new AVL<string, int>();
  tree->insert("2", 2);
  tree->displayTree();
  tree->insert("1", 1);
  tree->displayTree();
  tree->insert("3", 3);
  tree->displayTree();
  tree->insert("4", 4);
  tree->displayTree();
  tree->remove("1");
  tree->displayTree();
  return tree;
}

LinkedBST<string, int>* reLeftRightAVL() {
  LinkedBST<string, int> *tree = new AVL<string, int>();
  tree->insert("3", 3);
  tree->displayTree();
  tree->insert("4", 4);
  tree->displayTree();
  tree->insert("1", 1);
  tree->displayTree();
  tree->insert("2", 2);
  tree->displayTree();
  tree->remove("4");
  tree->displayTree();
  return tree;
}

LinkedBST<string, int>* reRightLeftAVL() {
  LinkedBST<string, int> *tree = new AVL<string, int>();
  tree->insert("2", 2);
  tree->displayTree();
  tree->insert("1", 1);
  tree->displayTree();
  tree->insert("4", 4);
  tree->displayTree();
  tree->insert("3", 3);
  tree->displayTree();
  tree->remove("1");
  tree->displayTree();
  return tree;
}

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
    // LinkedBST<int, string> *avl = new AVL<int, string>();
    // avl->insert(6, "6");
    // avl->insert(2, "2");
    // avl->insert(7, "7");
    // // 1
    // cout << "current height = " << avl->getHeight() << endl;
    // avl->insert(1, "1");
    // avl->insert(5, "5");
    // // 2
    // cout << "current height = " << avl->getHeight() << endl;
    // avl->insert(9, "9");
    // avl->insert(3, "3");
    // avl->insert(4, "4");
    // avl->checkInvariants();
    // vector<int> key_list = avl->getKeys();
    // for (auto &i: key_list) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // // 3
    // cout << "current height = " << avl->getHeight() << endl;
    // avl->remove(4);
    // cout << "Does it contain 4: " << avl->contains(4) << endl;
    // vector<int> key_list_2 = avl->getKeys();
    // for (auto &i: key_list_2) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // avl->remove(2);
    // cout << "Does it contain 2: " << avl->contains(2) << endl;
    // vector<int> key_list_3 = avl->getKeys();
    // for (auto &i: key_list_3) {
    //     cout << i << " ";
    // }
    // cout << endl;

  /** emptyAVL */
  // LinkedBST<string, int> *tree = new AVL<string, int>();
  // bool size = (tree->getSize() == 0);
  // bool empty = (tree->isEmpty() == true);
  // cout << (size && empty);
  // tree->checkInvariants();

  /** exampleAVL */
  // LinkedBST<string, int> *tree = makeExampleAVL();
  // for (int i = 1; i <= 9; i++) {
  //   if (i != 5 && i != 8) {
  //     cout << (i == tree->get(to_string(i)));
  //   }
  // }
  // tree->checkInvariants();

  /** inLeftLeftAVL*/
  // LinkedBST<string, int> *tree = inLeftLeftAVL();
  // tree->checkInvariants();

  /** inRightRightAVL*/
  // LinkedBST<string, int> *tree = inRightRightAVL();
  // tree->checkInvariants();

  /** inLeftRightAVL*/
  // LinkedBST<string, int> *tree = inLeftRightAVL();
  // tree->checkInvariants();

  /** inRightLeftAVL*/
  // LinkedBST<string, int> *tree = inRightLeftAVL();
  // tree->checkInvariants();

  /** exampleAVLSize */
  // LinkedBST<string, int> *tree = makeExampleAVL();
  // cout << (7 == tree->getSize());
  // cout << (!tree->isEmpty());
  // tree->checkInvariants();

  /** update */
  LinkedBST<string, int> *tree = makeExampleAVL();
  tree->update("1", 3);
  // cout << (3 == tree->get("1"));
  // tree->update("1", 5);
  // cout << (5 == tree->get("1"));
  // tree->update("2", 1);
  // cout << (1 == tree->get("2"));
  // tree->checkInvariants();

  /** contains */
  // const tree = makeExampleAVL();
  // console.log(true == tree.contains("1"));
  // console.log(false == tree.contains("10"));
  // tree.checkInvariants();

  /** remove */
  // const tree = makeExampleAVL();
  // tree.remove("6");
  // console.log(false == tree.contains("6"));
  // tree.remove("7");
  // console.log(false == tree.contains("7"));
  // tree.displayTree();
  // tree.checkInvariants();

  /** reLeftLeftAVL*/
  // const tree = reLeftLeftAVL();
  // tree.checkInvariants();

  /** reRightRightAVL*/
  // const tree = reRightRightAVL();
  // tree.checkInvariants();

  /** reLeftRightAVL*/
  // const tree = reLeftRightAVL();
  // tree.checkInvariants();

  /** reRightLeftAVL*/
  // const tree = reRightLeftAVL();
  // tree.checkInvariants();

  /** getKeys */
  // const tree = makeExampleAVL();
  // const realKeys = tree.getKeys();
  // const expectedKeys = ["6", "2", "1", "4", "3", "7", "9"];
  // console.log(expectedKeys.length == realKeys.length);
  // for(let i = 0; i < expectedKeys.length; i++){
  //   console.log(expectedKeys[i] == realKeys[i]);
  // }
  // tree.checkInvariants();

  /** getItems */
  // const tree = makeExampleAVL();
  // const realItems = tree.getItems();
  // const expectedItems = [["6", 6], ["2", 2], ["1", 1], ["4", 4], ["3", 3],
  //                       ["7", 7], ["9", 9]];
  // console.log(expectedItems.length == realItems.length);
  // for(let i = 0; i < expectedItems.length; i++){
  //   console.log(expectedItems[i][0] == realItems[i][0] && expectedItems[i][1] == realItems[i][1]);
  // }
  // tree.checkInvariants();

  /** getHeight */
  // const tree = makeExampleAVL();
  // console.log(3 == tree.getHeight());
  // const emptyTree = new AVL();
  // console.log(-1 == emptyTree.getHeight());
  // tree.checkInvariants();

  /** getMax */
  // const tree = makeExampleAVL();
  // console.log("9" == tree.getMaxKey());
  // tree.checkInvariants();

  /** getMin */
  // const tree = makeExampleAVL();
  // console.log("1" == tree.getMinKey());
  // tree.checkInvariants();

  /** ExamplePreOrderTraversal */
  // const tree = makeExampleAVL();
  // const realTraversal = tree.traversePreOrder();
  // const expectedTraversal = [["6", 6], ["2", 2], ["1", 1], ["4", 4], ["3", 3],
  //                           ["7", 7], ["9", 9]];
  // console.log(expectedTraversal.length == realTraversal.length);
  // for(let i = 0; i < expectedTraversal.length; i++){
  //   console.log(expectedTraversal[i][0] == realTraversal[i][0] &&
  //               expectedTraversal[i][1] == realTraversal[i][1]);
  // }
  // tree.checkInvariants();

  /** ExamplePostOrderTraversal */
  // const tree = makeExampleAVL();
  // const realTraversal = tree.traversePostOrder();
  // const expectedTraversal = [["1", 1], ["3", 3], ["4", 4], ["2", 2], ["9", 9],
  //                           ["7", 7], ["6", 6]];
  // console.log(expectedTraversal.length == realTraversal.length);
  // for(let i = 0; i < expectedTraversal.length; i++){
  //   console.log(expectedTraversal[i][0] == realTraversal[i][0] &&
  //               expectedTraversal[i][1] == realTraversal[i][1]);
  // }
  // tree.checkInvariants();

  /** ExampleInOrderTraversal */
  // const tree = makeExampleAVL();
  // const realTraversal = tree.traverseInOrder();
  // const expectedTraversal = [["1", 1], ["2", 2], ["3", 3], ["4", 4], ["6", 6],
  //                           ["7", 7], ["9", 9]];
  // console.log(expectedTraversal.length == realTraversal.length);
  // for(let i = 0; i < expectedTraversal.length; i++){
  //   console.log(expectedTraversal[i][0] == realTraversal[i][0] &&
  //               expectedTraversal[i][1] == realTraversal[i][1]);
  // }
  // tree.checkInvariants();

  /** ExampleLevelOrderTraversal */
  // const tree = makeExampleAVL();
  // const realTraversal = tree.traverseLevelOrder();
  // const expectedTraversal = [["6", 6], ["2", 2], ["7", 7], ["1", 1], ["4", 4],
  //                           ["9", 9], ["3", 3]];
  // console.log(expectedTraversal.length == realTraversal.length);
  // for(let i = 0; i < expectedTraversal.length; i++){
  //   console.log(expectedTraversal[i][0] == realTraversal[i][0] &&
  //               expectedTraversal[i][1] == realTraversal[i][1]);
  // }
  // tree.checkInvariants();

    delete tree;
    return 0;
}
