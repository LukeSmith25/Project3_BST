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
        string value;
        int i;

        // Find location of whitespace and save everything prior
        size_t pos = input.find(' ');
        command = input.substr(0, pos);

        // Erase command from input including whitespace
        input.erase(0, pos+1);

        // If the command is not 1 char, skip iteration
        if (command.size() != 1) {
            continue;
        }

        // If command is "i", insert
        if (command == "i") {
            encryptTree.insert(input);
        }
        // If command is "r", remove
        else if (command == "r") {
            encryptTree.remove(input);
        }
        // If command is "e", encrypt
        else if (command == "e") {
            string word;
            i = 0;
            // Erase first ' character
            input.erase(0, 1);

            while (input.at(i) != '\'') {
                if (input.at(i) == ' ' || input.at(i+1) == '\'') {
                    cout << encryptTree.encrypt(word) << " ";
                    word.erase();
                } else {
                    word += input.at(i);
                }
                i++;
            }
            cout << endl;

        } else if (command == "d") {
            string word;
            i = 0;
            // Erase first ' character
            input.erase(0, 1);

            while (input.at(i) != '\'') {
                if (input.at(i) == ' ' || input.at(i+1) == '\'') {
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
    encryptTree.printPreorder();
    return 0;
}
