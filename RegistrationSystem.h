//Emre Furkan Akyol Section2  22103352
#include <string>
#include <iostream>
#include"Student.h"
#include "Course.h"
#include "Node.h"
#include"DoublyLinkedList.h"
#include "SinglyLinkedList.h"
using namespace std;
class RegistrationSystem {
public:
	RegistrationSystem();
	~RegistrationSystem();
	void addStudent(const int studentId, const string firstName, const string
		lastName);
	void deleteStudent(const int studentId);
	void addCourse(const int studentId, const int courseId, const string
		courseName);
	void withdrawCourse(const int studentId, const int courseId);
	void cancelCourse(const int courseId);
	void showStudent(const int studentId);
	void showCourse(const int courseId);
	void showAllStudents();

private:
	DoublyLinkedList<Student>* students;
	//SinglyLinkedList<Course>* courses;
};
