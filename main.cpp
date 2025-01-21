#include <iostream>
#include <cstring>
#include "student.h"
#include "head.h"

using namespace std;
//prototypes
float average(Node* head);
void print(Node* next);
Node* add(Node* current, student* newstudent);
Node* deleteStudent(Node* current, int id);
Node* head = nullptr;

int main() {
    bool running = true;//run loop
    char input[10];

    while (running) {
        cout << "Functions: ADD, DELETE, PRINT, END,AVE" << endl;
        cin.getline(input, 10);
	//add
	if(strcmp(input,"AVE")==0){
	 float avg = average(head);
    if (avg > 0.0) {
        cout << "Average GPA: " << avg << endl;
	}
}
        else if (strcmp(input, "ADD") == 0) {
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
//sort by ID value
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
        return current; //return current
    }
}
float averageHelper(Node* current, int& count) {
    if (!current) {
        return 0.0; // base case
    }

    count++; // increase for each node
    return current->getStudent()->getGpa() + averageHelper(current->getNext(), count);
}

float average(Node* head) {
    int count = 0;
    float totalGPA = averageHelper(head, count);

    if (count == 0) {
        cout << "No students in the list." << endl;
        return 0.0;
    }

    return totalGPA / count;
}

Node* deleteStudent(Node* current, int id) {
  	if(current==NULL){
	cout<<"no students in list"<<endl;
	}
	if (current->getStudent()->getID()==id){
	Node* temp = current;         // Save node to delete
	if(current->getNext()!=NULL){//if more than 1 item in list
	 current = current->getNext();
	delete temp->getStudent();
	temp=NULL;
	cout<<"student deleted"<<endl;
	return current;
	}
	else{
        current=NULL;
	delete temp->getStudent();
cout<<"student deleted"<<endl;
	return current;
   } } 
	else if(current->getNext()==NULL){
	cout<<"no student with that ID"<<endl;
	}
	else {
        current->setNext(deleteStudent(current->getNext(), id));
        return current;               // Return the current head
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
