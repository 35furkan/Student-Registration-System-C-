//Emre Furkan Akyol Section2  22103352
#ifndef Course_
#define Course_
#include <string>
#include <iostream>
#include "Student.h"
#include "Node.h"
#include"DoublyLinkedList.h"
using namespace std;
class Student;
class Course {
private:
	int id;
	string course_name;
	DoublyLinkedList<Student>* registeredStudents;
public:
	Course();
	Course(int id,string courseName);
	void setId(int id);
	void setName(string courseName);
	int getId();
	string getName();
	bool operator<(const Course& other)const;
	bool operator==(const Course& other)const;
};
#endif