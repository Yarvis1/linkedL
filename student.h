#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<cstring>

class student{
 public:
  student(int n, int g, const char* l);//constructor
  int getID();//get id
  void setID(int n);//set id
  const char* getName();//get name
  void setName(const char* n);//setname
  int getGpa();//return gpa
  void setGpa(int n);//set gpa
  void printData();//print everything
 private:
  int Id;
  int GPA;
  char name[25];
};
#endif
