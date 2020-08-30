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
        cout << "\n1. Add Person Details\n2. Display\n3. Edit Person Details\n4. Delete Record\n";
        cout << "5. Sort Records\n6. View By City And State\n7. Search\n8. Exit\nEnter Your Choice " << endl;
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
                service.viewByCityAndState();
                break;
            case 7:
                service.searchByCityOrState();
                break;
            case 8:
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