#include <iostream>
#include "AddressBookService.h"

using namespace std;

void displayWelcomeMessage() {
    cout << "---- Welcome To Address Book Management ----" << endl;
}

void createMenu() {
    int flag = 0;
    AddressBookService service;

    while(flag == 0) {
        cout << "\n1. Add Person Details\n2. Display\n3. Exit\n\tEnter Your Choice " << endl;
        int choice;
        cin >> choice;
        switch(choice) {
            case 1: 
                service.addRecord();
                break;
            case 2:
                service.displayRecord();
                break;
            case 3:
                flag = 1;
                break;
            default:
                cout << "Enter Valid Choice\n";
        }
    }
}

int main() {

    displayWelcomeMessage();
    createMenu();
    return 0;
}