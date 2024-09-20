#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;

    Contact() {}

    Contact(string n, string p, string e) {
        name = n;
        phone = p;
        email = e;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
    }
};

#endif
