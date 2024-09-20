#include "Contact.hpp"
#include <fstream>
#include <vector>
using namespace std;

vector<Contact> contactList;

void addContact() {
    string name, phone, email;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Phone Number: ";
    getline(cin, phone);
    cout << "Enter Email: ";
    getline(cin, email);
    Contact newContact(name, phone, email);
    contactList.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}

void viewContacts() {
    if (contactList.empty()) {
        cout << "No contacts available." << endl;
    } else {
        for (const auto& contact : contactList) {
            contact.display();
            cout << "----------------------" << endl;
        }
    }
}

void searchContact() {
    string searchName;
    cout << "Enter the name of the contact to search: ";
    cin.ignore();
    getline(cin, searchName);
    bool found = false;
    for (const auto& contact : contactList) {
        if (contact.name == searchName) {
            contact.display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found!" << endl;
    }
}

void editContact() {
    string searchName;
    cout << "Enter the name of the contact to edit: ";
    cin.ignore();
    getline(cin, searchName);
    bool found = false;
    for (auto& contact : contactList) {
        if (contact.name == searchName) {
            cout << "Contact found! Enter new details." << endl;
            cout << "Enter new Phone Number: ";
            getline(cin, contact.phone);
            cout << "Enter new Email: ";
            getline(cin, contact.email);
            found = true;
            cout << "Contact updated successfully!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found!" << endl;
    }
}

void deleteContact() {
    string searchName;
    cout << "Enter the name of the contact to delete: ";
    cin.ignore();
    getline(cin, searchName);
    bool found = false;
    for (auto it = contactList.begin(); it != contactList.end(); ++it) {
        if (it->name == searchName) {
            contactList.erase(it);
            found = true;
            cout << "Contact deleted successfully!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found!" << endl;
    }
}

void saveContactsToFile() {
    ofstream file("contacts.txt");
    for (const auto& contact : contactList) {
        file << contact.name << endl;
        file << contact.phone << endl;
        file << contact.email << endl;
    }
    file.close();
    cout << "Contacts saved to file." << endl;
}

void loadContactsFromFile() {
    ifstream file("contacts.txt");
    if (file) {
        string name, phone, email;
        while (getline(file, name)) {
            getline(file, phone);
            getline(file, email);
            contactList.push_back(Contact(name, phone, email));
        }
        file.close();
        cout << "Contacts loaded from file." << endl;
    } else {
        cout << "No saved contacts found." << endl;
    }
}

void menu() {
    cout << "1. Add Contact" << endl;
    cout << "2. View Contacts" << endl;
    cout << "3. Search Contact" << endl;
    cout << "4. Edit Contact" << endl;
    cout << "5. Delete Contact" << endl;
    cout << "6. Save Contacts" << endl;
    cout << "7. Load Contacts" << endl;
    cout << "8. Exit" << endl;
}

int main() {
    int choice;
    loadContactsFromFile();  // Load contacts when the program starts
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                editContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                saveContactsToFile();
                break;
            case 7:
                loadContactsFromFile();
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
