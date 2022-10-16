/*
 * This is the test file of the Linked Queue.
 * You may manipulate around to see if the implementation is correct.
 * Have fun!
 *
 * Swarthmore College, CS71, Group 7
 * */

#include <iostream>
#include <stdexcept>

#include "../adts/orderedCollection.h"
#include "../adts/queue.h"
#include "LinkedQueue.h"

using namespace std;

int main() {
    Queue<string>* linked_queue = new LinkedQueue<string>();
    linked_queue->insert("a");
    // peek a
    cout << linked_queue->peek() << endl;
    linked_queue->insert("b");
    // peek a
    cout << linked_queue->peek() << endl;
    // remove a
    cout << linked_queue->remove() << endl;
    // peek b
    cout << linked_queue->peek() << endl;
    // get size
    cout << "the size is " << linked_queue->getSize() << endl;
    // remove b
    cout << linked_queue->remove() << endl;
    // is empty
    cout << linked_queue->isEmpty() << endl;

    delete linked_queue;
    return 0;
}