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
        cout << "\n1. Add Person Details\n2. Display\n3. Edit Person Details\n4. Delete Record\n5. Sort By Name\n6. Exit\nEnter Your Choice " << endl;
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
                service.editRecord();
                break;
            case 4:
                service.deleteRecord();
                break;
            case 5:
                service.sortRecords();
                break;
            case 6:
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