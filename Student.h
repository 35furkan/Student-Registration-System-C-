//Emre Furkan Akyol Section2  22103352
#ifndef Student_
#define Student_
#include <string>
#include <iostream>
#include "Course.h"
#include "Node.h"
#include"SinglyLinkedList.h"
using namespace std; 
class Course;
class Student {
private:
	int id;
	string firstName;
	string lastName;
	SinglyLinkedList <Course>* courses;
public:
	Student();
	Student(int id, string firstName, string LastName);
	Student(const Student& copyStudent);
	virtual ~Student();
	void setId(int id);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	bool cancelCourseForStudent(int courseId);
	int getId();
	string getFirstName();
	string getLastName();
	bool operator<(const Student& other)const;
	bool operator==(const Student& other)const;
	Student& operator=(const Student& other);
	void addCourseForStudent(int courseId, string courseName);
	Node<Course>* specifiedCoursePtr(int courseNo);
	Node<Course>* getCoursesHeadPtr();
};
#endif