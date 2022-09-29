/**
 * file: driver-proj3.cpp
 * author: Luke Smith
 * course: CSI 3334
 * assignment: project 3
 * due date: October 2, 2022
 *
 * This file contains the driver for the binary search encryptTree.
 */

#include <iostream>
#include "bst-student-proj3.h"
using namespace std;

int main() {
    EncryptionTree<string> encryptTree;

    encryptTree.insert("four");
    encryptTree.insert("score");
    encryptTree.insert("and");
    encryptTree.insert("seven");
    encryptTree.insert("years");
    encryptTree.insert("ago");
    encryptTree.printPreorder();
    cout << endl;

    cout << encryptTree.encrypt("four") << " ";
    cout << encryptTree.encrypt("and") << " ";
    cout << encryptTree.encrypt("ago") << " ";
    cout << encryptTree.encrypt("score") << " ";
    cout << encryptTree.encrypt("seven") << " ";
    cout << encryptTree.encrypt("years") << " ";
    cout << encryptTree.encrypt("founding") << " ";

    //encryptTree.remove("and");




    //encryptTree.printPreorder();
    return 0;
}
