/*
 * This is the test file of the Linked List.
 * You may manipulate around to see if the implementation is correct.
 * Have fun!
 *
 * Swarthmore College, CS71, Group 7
 * */

#include <iostream>

#include "../adts/list.h"
#include "LinkedList.h"

using namespace std;

int main() {
    List<string>* linkedList = new LinkedList<string>();
    auto* linkedList_2 = new LinkedList<string>();
    cout << linkedList->isEmpty() << endl;
    linkedList->insertFirst("d");
    linkedList->insertFirst("c");
    linkedList->insertFirst("b");
    linkedList->insertFirst("a");
    linkedList_2->insertFirst("b");
    linkedList_2->insertFirst("a");
    // Get a
    cout << linkedList->get(0) << endl;
    cout << linkedList->getFirst() << endl;
    // Get b
    cout << linkedList->get(1) << endl;
    // Get c
    cout << linkedList->get(2) << endl;
    // Get d
    cout << linkedList->get(3) << endl;
    cout << linkedList->getLast() << endl;
    // Get size
    cout << "the size is " << linkedList->getSize() << endl;
    // Check invariants
    linkedList_2->checkInvariants();
    // insert at last
    linkedList->insertLast("e");
    linkedList->insertLast("f");
    linkedList->insertLast("g");
    cout << linkedList->get(4) << endl;
    cout << linkedList->get(5) << endl;
    cout << linkedList->get(6) << endl;
    // Remove first
    cout << linkedList_2->removeFirst() << endl;
    cout << linkedList_2->removeFirst() << endl;
    cout << "the size now is " << linkedList_2->getSize() << endl;
    // Remove last
    cout << linkedList->removeLast() << endl;
    cout << linkedList->removeLast() << endl;

    delete linkedList;
    delete linkedList_2;
    return 0;
}
