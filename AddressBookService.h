#include <iostream>
#include <list>
#include "Person.h"

using namespace std;

class AddressBookService
{   
    public:
        list<Person> personList;
        void addRecord();
        void displayRecord();
        Person readInputsForAdd();

};

Person AddressBookService::readInputsForAdd() {
    string fname, lname, address, city, state;
    int zip;
    long long phone;

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