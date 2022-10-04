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
    string input;
    bool end = false;

    while (getline(cin, input) && !end) {
        string command;
        int spc = 32;
        int i = 0;
        command = input.at(0);
        input.erase(0, 2);

        if (command == "i") {
            encryptTree.insert(input);
        }
        else if (command == "r") {
            encryptTree.remove(input);
        }
        else if (command == "e") {
            string word;
            int delim = 39;
            i = 0;
            input.erase(0, 1);

            do {
                if (input.at(i) == ' ' || input.at(i+1) == (char)delim) {
                    cout << encryptTree.encrypt(word) << " ";
                    word.erase();
                } else {
                    word += input.at(i);
                }
                i++;
            } while (input.at(i) != (char)delim);
            cout << endl;

        } else if (command == "d") {
            string word;
            int delim = 39;
            i = 0;
            input.erase(0, 1);

            while (input.at(i) != (char)delim) {
                if (input.at(i) == ' ' || input.at(i+1) == (char)delim) {
                    if (encryptTree.decrypt(word) == NULL) {
                        i++;
                        word.erase();
                        cout << "? ";
                    } else {
                        cout << *encryptTree.decrypt(word) << " ";
                        word.erase();
                    }
                } else {
                    word += input.at(i);
                }
                i++;
            }
            cout << endl;


        } else if (command == "p") {
            encryptTree.printPreorder();
        } else if (command == "q") {
            end = true;
        } else {
            continue;
        }
    }

    return 0;
}
