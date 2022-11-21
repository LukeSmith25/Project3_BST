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
    char comm;
    bool end = false;

    while (cin >> comm && !end) {

        switch(comm){
            case 'p':
                encryptTree.printPreorder(cout);
                break;

            case 'i':
                cin >> ws >> input >> ws;
                encryptTree.insert(input);
                break;
            case 'r':
                cin >> ws >> input >> ws;
                encryptTree.remove(input);
                break;

            case 'e':
                while(comm != '\''){
                    cin.get(comm);
                }
                cin >> input;
                if(input.at(0) != '\''){
                    while(input.at(input.size() - 1) != '\''){
                        cout << encryptTree.encrypt(input) << " ";
                        cin >> input;
                    }
                    if(input.at(input.size() - 1) == 'q'){
                        end = true;
                        input.erase(input.size() - 2);
                    }else{
                        input.erase(input.size() - 1);
                    }

                    cout << encryptTree.encrypt(input);

                } else if(input.at(input.size() - 1) == 'q'){
                    end = true;
                }
                cout << endl;

                break;

            case 'd':
                while(comm != '\''){
                    cin.get(comm);
                }
                cin >> input;
                if(input.at(0) != '\''){
                    while(input.at(input.size() - 1) != '\''){
                        if(encryptTree.decrypt(input)){
                            cout << *encryptTree.decrypt(input) << " ";
                        } else{
                            cout << "?" << " ";
                        }
                        cin >> input;

                    }
                    if(input.at(input.size() - 1) == 'q'){
                        end = true;
                        input.erase(input.size() - 2);
                    }else{
                        input.erase(input.size() - 1);
                    }
                    if(encryptTree.decrypt(input)){
                        cout << *encryptTree.decrypt(input);
                    } else{
                        cout << "?";
                    }
                } else if(input.at(input.size() - 1) == 'q'){
                    end = true;
                }
                cout << endl;


                break;
        }
    }
    return 0;
}