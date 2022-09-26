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
    BST<string> tree;

    tree.insert("four");
    tree.insert("score");
    tree.insert("and");
    tree.insert("seven");
    tree.insert("years");
    tree.insert("ago");

    tree.printPreorder();
    cout << endl << endl << endl;



    //tree.printPreorder();
    return 0;
}
