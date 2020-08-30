#include <iostream>
using namespace std;

class Person {
    string firstName, lastName, address, city, state, zip, phone;
    public:
        Person(){}
        Person(string fName, string lName, string address, string city, string state, string zip, string phone);
        
        void display();

        void setAddress(string address);
        void setCity(string city);
        void setState(string state);
        void setZip(string zip);
        void setPhone(string phone);

        string getFirstName();
        string getLastName();
        string getCity();
        string getState();
        string getZip();
};

Person::Person(string fName, string lName, string address, string city, string state, string zip, string phone) {
    this->firstName = fName;
    this->lastName = lName;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phone = phone;
}

void Person::display() {
    cout << "[ Name: " << this->firstName << " " << this->lastName;
    cout << ", Phone: " << this->phone << ", State: " << this->state << ", ";
    cout << "Address: " << this->address << ", City: " << this->city << ", Zip: " << this->zip << " ]" << endl;
}

void Person::setAddress(string address) {
    this->address = address;
}

void Person::setCity(string city) {
    this->city = city;
}

void Person::setState(string state) {
    this->state = state;
}

void Person::setZip(string zip) {
    this->zip = zip;
}

void Person::setPhone(string phone) {
    this->phone = phone;
}

string Person::getFirstName() {
    return this->firstName;
}

string Person::getLastName() {
    return this->lastName;
}

string Person::getCity() {
    return this->city;
}

string Person::getState() {
    return this->state;
}

string Person::getZip() {
    return this->zip;
}