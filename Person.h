#include <iostream>
using namespace std;

class Person {
    string firstName, lastName, address, city, state;
    int zip;
    long long phone;
    public:
        Person(){}
        Person(string fName, string lName, string address, string city, string state, int zip, long long phone);
        void display();
};

Person::Person(string fName, string lName, string address, string city, string state, int zip, long long phone) {
    this->firstName = fName;
    this->lastName = lName;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phone = phone;
}

void Person::display() {
    cout << "{ Name: " << this->firstName << " " << this->lastName;
    cout << ", Phone: " << this->phone << ", State: " << this->state << ", ";
    cout << "Address: " << this->address << ", City: " << this->city << ", Zip: " << this->zip << " }" << endl;
}
