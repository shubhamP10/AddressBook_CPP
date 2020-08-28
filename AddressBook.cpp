#include <iostream>

using namespace std;

class Person {
    string firstName, lastName, address, city, state;
    int zip;
    long long phone;
    public:
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
    cout << "Name: " << this->firstName << " " << this->lastName << endl;
    cout << "Phone: " << this->phone << "\nState: " << this->state << endl;
}

void displayWelcomeMessage() {
    cout << "Welcome To Address Book Management" << endl;
}

int main() {

    displayWelcomeMessage();
    Person person("Shubham", "Pattar", "BG", "JKD", "KA", 587301, 8105215414);
    person.display();

    return 0;
}