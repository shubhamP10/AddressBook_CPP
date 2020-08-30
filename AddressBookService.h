#include <iostream>
#include <vector>
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
        void sortRecords();
        Person readInputsForAdd(); 
        bool checkExists(string fname, string lname);
};

bool AddressBookService::checkExists(string fname, string lname) {
    
    for(Person person : personList) {
        if(fname == person.getFirstName() && lname == person.getLastName()) {
            return true;
        }
    }

    return false;
}

Person AddressBookService::readInputsForAdd() {
    string fname, lname, address, city, state, zip, phone;

    while(true) {
        cout << "Enter First Name: ";
        cin >> fname;
        cout << "Enter Last Name: ";
        cin >> lname;

        if(checkExists(fname, lname) == false)
            break;
        cout << "Person Already Exists!!! Please Enter Different Name" << endl;
    }
    
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
    cout << "1. Address\n2. City\n3. State\n4. Zip\n5. Phone\n6. Save And Exit\nEnter Your Choice" << endl;
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

int createSortMenu() {
    int choice;

    cout << "Sort By" << endl;
    cout << "1. Name\n2. City\n3. State\n4. Zip\n5. back\n" << endl;
    cout << "Enter You Choice: ";
    cin >> choice;

    return choice;
}

void AddressBookService::sortRecords() {  
    int flag = 0;

    while(flag == 0) {
        int choice = createSortMenu();

        switch(choice) {
            case 1: 
                for(int i = 0; i < personList.size() - 1; i++) {
                    for(int j = i + 1; j < (personList.size()); j++) {
                        if(personList[i].getFirstName() > personList[j].getFirstName()) {
                            swap(personList[i], personList[j]);
                        }
                    }
                }
                displayRecord();
                break;

            case 2: 
                for(int i = 0; i < personList.size() - 1; i++) {
                    for(int j = i + 1; j < (personList.size()); j++) {
                        if(personList[i].getCity() > personList[j].getCity()) {
                            swap(personList[i], personList[j]);
                        }
                    }
                }
                displayRecord();
                break;

            case 3: 
                for(int i = 0; i < personList.size() - 1; i++) {
                    for(int j = i + 1; j < (personList.size()); j++) {
                        if(personList[i].getState() > personList[j].getState()) {
                            swap(personList[i], personList[j]);
                        }
                    }
                }
                displayRecord();
                break;

            case 4: 
                for(int i = 0; i < personList.size() - 1; i++) {
                    for(int j = i + 1; j < (personList.size()); j++) {
                        if(personList[i].getZip() > personList[j].getZip()) {
                            swap(personList[i], personList[j]);
                        }
                    }
                } 
                displayRecord();
                break;

            case 5:
                flag = 1;
                break;
                
            default:
                cout << "Enter Valid Choice\n";
        }
    }
}