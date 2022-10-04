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
        command = input.at(0);

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
            bool lastWord = false;
            i = 0;
            // Erase first ' character
            input.erase(0, 1);

            do {
                pos = input.find(' ');
                word = input.substr(0, pos);

                if (pos == string::npos) {
                    pos = input.find('\'');
                    word = input.substr(0, pos);
                    lastWord = true;
                }
                if (encryptTree.decrypt(word) == NULL) {
                    if (lastWord) {
                        cout << "?";
                    } else {
                        cout << "? ";
                    }
                } else {
                    if (lastWord) {
                        cout << *encryptTree.decrypt(word);
                    } else {
                        cout << *encryptTree.decrypt(word) << " ";
                    }
                }
                input.erase(0, pos+1);
            } while (!lastWord);
            cout << endl;

        } else if (command == "d") {
            string word;
            bool lastWord = false;
            i = 0;
            // Erase first ' character
            input.erase(0, 1);

            do {
                pos = input.find(' ');
                word = input.substr(0, pos);

                if (pos == string::npos) {
                    pos = input.find('\'');
                    word = input.substr(0, pos);
                    lastWord = true;
                }
                if (encryptTree.decrypt(word) == NULL) {
                    if (lastWord) {
                        cout << "?";
                    } else {
                        cout << "? ";
                    }
                } else {
                    if (lastWord) {
                        cout << *encryptTree.decrypt(word);
                    } else {
                        cout << *encryptTree.decrypt(word) << " ";
                    }
                }
                input.erase(0, pos+1);
            } while (!lastWord);
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
