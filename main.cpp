#include <iostream>
#include <cstring>
#include "student.h"
#include "head.h"

using namespace std;
//prototypes
void print(Node* next);
Node* add(Node* current, student* newstudent);
Node* deleteStudent(Node* current, int id);
Node* head = nullptr;

int main() {
    bool running = true;//run loop
    char input[10];

    while (running) {
        cout << "Functions: ADD, DELETE, PRINT, END" << endl;
        cin.getline(input, 10);
	//add
        if (strcmp(input, "ADD") == 0) {
            int id;
            char name[40];
            float GPA;

            cout << "Enter ID number: ";
            cin >> id;
            cin.ignore();
            cout << "Enter name: ";
            cin.getline(name, 40);
            cout << "Enter GPA: ";
            cin >> GPA;
            cin.ignore();

            student* stu = new student(id, GPA, name);
            head = add(head, stu);
        }
	//delete
        else if (strcmp(input, "DELETE") == 0) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            cin.ignore();
            head = deleteStudent(head, id);
        }
	//print from head
        else if (strcmp(input, "PRINT") == 0) {
            print(head);
        }
	//quit while loop
        else if (strcmp(input, "END") == 0) {
            running = false;
        }
        else {
            cout << "Not valid input" << endl;
        }
    }

    return 0;
}
//adds sorting by ID value
Node* add(Node* current, student* newstudent) {
//sort
    if (!current || current->getStudent()->getID() > newstudent->getID()) {
        Node* newNode = new Node();
        newNode->setStudent(newstudent);
        newNode->setNext(current);
        return newNode; //returnnew head
    } else {
//move past
        current->setNext(add(current->getNext(), newstudent));
        return current; return current
    }
}

Node* deleteStudent(Node* current, int id) {
    if (!current) {
	//no id found
        cout << "Student with ID " << id << " not found." << endl;
        return nullptr;
    }

    if (current->getStudent()->getID() == id) {
        Node* temp = current;
        current = current->getNext();
        delete temp->getStudent();
        delete temp;
        cout << "Student with ID " << id << " deleted." << endl;
        return current; // Return the new head
    } else {
        current->setNext(deleteStudent(current->getNext(), id));
        return current; // Return the current head
    }
}

void print(Node* next) {//prints from given node
    if (!next) {
        return;
    }
    student* s = next->getStudent();
    if (s) {
        cout << "Name: " << s->getName() << ", ";
        cout << "ID: " << s->getID() << ", ";
        cout << "GPA: " << s->getGpa() << endl;
    }
    print(next->getNext()); // Recursive call
}
