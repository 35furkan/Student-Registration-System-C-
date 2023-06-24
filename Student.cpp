//Emre Furkan Akyol Section2  22103352
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;
Student::Student(int id, string firstName, string lastName) {
	courses = new SinglyLinkedList<Course>;
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
}
Student::Student() {
	this->id = -1;
	this->firstName = " ";
	this->lastName = " ";
	courses = new SinglyLinkedList<Course>;
}
Student::~Student() {
	if (courses != nullptr) {
		courses->clear();
		delete courses;
		courses = nullptr;
	}
	
}
Student::Student(const Student& copyStudent) {
	this->id = copyStudent.id;
	this->firstName = copyStudent.firstName;
	this->lastName = copyStudent.lastName;
	courses = new SinglyLinkedList<Course>;
	if (copyStudent.courses != nullptr && copyStudent.courses->getHeadPtr() != nullptr) {
		Node<Course>* curNodePtr = copyStudent.courses->getHeadPtr();
		while (curNodePtr != nullptr) {
			courses->addByOrder(*(curNodePtr->getItem()));
			curNodePtr = curNodePtr->getNext();
		}
	}

		
	

	//courses = new SinglyLinkedList<Course>(*copyStudent.courses);
}
Student& Student::operator=(const Student& other) {
	if (this != &other) {
		this->id = other.id;
		this->firstName = other.firstName;
		this->lastName = other.lastName;
		
		if (courses!=nullptr) {
			courses->clear();
			delete courses;
			courses = nullptr;
		}
		if (other.courses != nullptr && other.courses->getHeadPtr()!=nullptr) {
			Node<Course>* curNodePtr = other.courses->getHeadPtr();
			while (curNodePtr != nullptr) {
				courses->addByOrder(*(curNodePtr->getItem()));
				curNodePtr = curNodePtr->getNext();
			}
		}
		else {
			courses = new SinglyLinkedList<Course>;
		}
		//courses = new SinglyLinkedList<Course>(*other.courses);
	}
	return *this;
}
bool Student::cancelCourseForStudent(int courseId) {
	Node<Course>* curNodePtr = courses->getHeadPtr();
	while (curNodePtr != nullptr) {
		if (curNodePtr->getItem()->getId() == courseId) {
			courses->removeWithData(*(curNodePtr->getItem()));
			return true;
			break;
		}
		curNodePtr = curNodePtr->getNext();
	}
	return false;
}

void Student::setId(int id) {
	this->id = id;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
int Student::getId() {
	return id;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
bool Student::operator<(const Student& other) const {
	return this->id < other.id;
}
bool Student::operator==(const Student& other) const {
	return id == other.id;
}
Node<Course>* Student::specifiedCoursePtr(int courseNo) {
	Node<Course>* curPtr = courses->getHeadPtr();
	while (curPtr != nullptr) {
		if (curPtr->getItem()->getId() == courseNo) {
			return curPtr;
		}
		curPtr = curPtr->getNext();
	}
	return nullptr;

}
void Student::addCourseForStudent(int courseId, string courseName) {
	Course* newCourse = new Course(courseId, courseName);
	courses->addByOrder(*newCourse);
	delete newCourse;
}
Node<Course>* Student::getCoursesHeadPtr() {
	return courses->getHeadPtr();
}