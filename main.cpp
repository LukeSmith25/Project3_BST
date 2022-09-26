/**
 * file: driver-proj3.cpp
 * author: Luke Smith
 * course: CSI 3334
 * assignment: project 3
 * due date: October 2, 2022
 *
 * This file contains the driver for the binary search tree.
 */

#include <iostream>
#include "bst-student-proj3.h"
using namespace std;

int main() {
    BST<int> tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(5);
    tree.insert(6);

    tree.printPreorder();
    cout << endl << endl << endl;

    tree.remove(3);

    tree.printPreorder();
    return 0;
}
