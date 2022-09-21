/**
 * file: bst-student-proj3.h
 * author: Luke Smith
 * course: CSI 3334
 * assignment: project 3
 * due date: October 2, 2022
 *
 * This file contains the driver for the binary search tree.
 */

#ifndef BST_STUDENT_PROJ3
#define BST_STUDENT_PROJ3 

#include "bst-prof-proj3.h"

/* Place your implementation of the BSTNode, BST, and EncryptionTree classes
 * here.
 *
 * Your driver should #include this file, which (as you can see above) will also
 * #include the professor file.
 */


template<class Base>
BSTNode<Base>::~BSTNode() {
    if (getLeft()) {
        delete left;
    }
    if (getRight()) {
        delete right;
    }
}

template<class Base>
void BSTNode<Base>::printPreorder(ostream &os, string indent) const {

    if (this) {
        cout << this->getData() << endl;
        indent += "  ";
        getLeft()->printPreorder(os, indent);
        getRight()->printPreorder(os, indent);
    } else {
        //Figure out maybe null
    }

}


template<class Base>
const BSTNode<Base> *BSTNode<Base>::minNode() const {
    if (getLeft() != NULL) {
        getLeft()->minNode();
    } else {
        return NULL;
    }
}

template<class Base>
const BSTNode<Base> *BSTNode<Base>::maxNode() const {
    if (getRight() != NULL) {
        getRight()->maxNode();
    } else {
        return NULL;
    }
}

#endif

