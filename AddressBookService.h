#include <iostream>
#include <vector>
#include <algorithm>
#include "Person.h"

using namespace std;

class AddressBookService
{   
    public:
        vector<Person> personList;
        void addRecord();
        void displayRecord();
        void editRecord();
        void deleteRecord();
        Person readInputsForAdd(); 
};

Person AddressBookService::readInputsForAdd() {
    string fname, lname, address, city, state, zip, phone;

    cout << "Enter First Name: ";
    cin >> fname;
    cout << "Enter Last Name: ";
    cin >> lname;
    cout << "Enter Address: ";
    cin >> address;
    cout << "Enter City: ";
    cin >> city;
    cout << "Enter State: ";
    cin >> state;
    cout << "Enter Zip: ";
    cin >> zip;
    cout << "Enter Phone Number: ";
    cin >> phone;

    Person person(fname, lname, address, city, state, zip, phone);

    return person;
}

void AddressBookService::addRecord() {
    Person person = readInputsForAdd();
    personList.push_back(person);
}

void AddressBookService::displayRecord() {

    if(personList.size() != 0) {
        for (Person p: personList) {
            p.display();
        }
    }
    else {
        cout << "\nNo Records Found!!!\n";
    } 
}

int createEditMenu() {
    int choice;
    cout << "Select What You Want To Edit:" << endl;
    cout << "1. Address\n2. City\n3. State\n4. Zip\n5. Phone\n6. <- Back To Main Menu\n\tEnter Your Choice" << endl;
    cin >> choice;
    return choice;
}

void AddressBookService::editRecord() {
    int flag = 0, id = 0, selected;
    string newAddress, newCity, newState, newZip, newPhone;

    for (Person person : personList) {
        cout << "#ID: " << id << " ";
        person.display();
        id++;
    }

    cout << "Enter ID to Edit Details: ";
    cin >> selected;

    while(flag == 0) {
        int choice = createEditMenu();

        switch(choice) {
            case 1: 
                cout << "\nEnter New Address" << endl;
                cin >> newAddress;
                personList[selected].setAddress(newAddress);
                personList[selected].display();
                break;
            case 2:
                cout << "\nEnter New City" << endl;
                cin >> newCity;
                personList[selected].setCity(newCity);
                personList[selected].display();
                break;
            case 3:
                cout << "\nEnter New State" << endl;
                cin >> newState;
                personList[selected].setState(newState);
                personList[selected].display();
                break;
            case 4:
                cout << "\nEnter New Zip" << endl;
                cin >> newZip;
                personList[selected].setZip(newZip);
                personList[selected].display();
                break;
            case 5:
                cout << "\nEnter New Phone" << endl;
                cin >> newPhone;
                personList[selected].setPhone(newPhone);
                personList[selected].display();
                break;
            case 6:
                flag = 1;
            default:
                cout << "Enter Valid Choice\n";
        }
    }
}

void AddressBookService::deleteRecord() {
    string fname, lname;
    int position = 0;
    bool deleted = false;

    cout << "Enter First Name: ";
    cin >> fname;
    cout << "Enter Last Name: ";
    cin >> lname;

    auto person = personList.begin();
    while(person != personList.end()) {
        auto currentPerson = person++;
        if (fname == (*currentPerson).getFirstName() && lname == (*currentPerson).getLastName()) {
            personList.erase(currentPerson);
            deleted = true;
            break;
        }
    }

    if(deleted == true) {
        cout << "...Record Deleted Successfully..." << endl;
    } 
    else {
        cout << "...Match Not Found...!" << endl;
    }
}