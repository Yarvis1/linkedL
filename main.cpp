#include<iostream>
#include<cstring>
#include "student.h"
#include "head.h"
using namespace std;
void add(student* newstudent);
void print (Node* next);
Node* head;
int main(){
  char input[10];
  cout<<"funtions: ADD,DELETE, PRINT,END"<<endl;
  cin.getline(input,10);
  if(strcmp(input,"ADD")==0){
    int id;
    const char name[40];
    double GPA;
    student* stu = new student(id,GPA,name);
    add(stu);
 }
   if(strcmp(input,"DELETE")==0){
     
  }
    if(strcmp(input,"PRINT")==0){
      print(head);
  }
     if(strcmp(input,"END")==0){

  }

  print(head);//print list
}
void add(student* newstudent){
  Node* current = head;//current is begginng of list
  if(current ==NULL){//create list if no head
    head= new Node();
    head->setStudent(newstudent);
  }
  else{//add to end of list
    while(current->getNext() != NULL){
      current = current->getNext();
    }
    current->setNext(new Node());
    current->getNext()->setStudent(newstudent);
}
}
void print(Node* next){
  if (next == head){//begin of list
    cout<<"list: "<<endl;
  }
  if(next!= NULL){//derefrence student pointer
    student* s = next->getStudent();
    if(s!=NULL){//prints student data
      cout<<"name: "<<s->getName()<<", ";
      cout<<"Id: "<<s->getID()<<", ";
      cout<<"GPA: "<<s->getGpa()<<", "<<endl;      
    }
    print(next->getNext());//prints next
  }
}

