//Emre Furkan Akyol Section2  22103352
#include "RegistrationSystem.h"
#include <string>
#include <iostream>

RegistrationSystem::RegistrationSystem() {
	students = new DoublyLinkedList<Student>;
	//courses = new SinglyLinkedList<Course>;

}
RegistrationSystem::~RegistrationSystem() {
	students->~DoublyLinkedList();
	delete students;
	students = nullptr;
	//courses->~SinglyLinkedList();
}
void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName) {
	bool found = false;
	Node<Student>* newNode = new Node<Student>;
	Student* newStudent = new Student(studentId, firstName, lastName);
	newNode->setItem(*newStudent);
	if (students->getCount() > 0) {
		Node<Student>* curNodePtr = students->getHeadPtr();
		while (curNodePtr != nullptr) {
			if (*newStudent == *(curNodePtr->getItem())) {
				found = true;
				break;
			}
			curNodePtr = curNodePtr->getNext();
		}
		if (!found) {
			students->addByOrder(*newStudent);
			cout << "Student " << studentId << " has been added" << endl;
		}
		else {
			cout << "Student " << studentId << " already exists"<<endl;
		}
	}
	else {
		students->addByOrder(*newStudent);
		cout << "Student " << studentId << " has been added" << endl;
	}
	delete newStudent;
	delete newNode;
}
void RegistrationSystem::deleteStudent(const int studentId) {
	bool found = false;
	Node<Student>* curNodePtr = students->getHeadPtr();
	while (curNodePtr != nullptr) {
		if (studentId == curNodePtr->getItem()->getId()) {
			found = true;
			curNodePtr->getItem()->~Student();
			students->removeWithData(*(curNodePtr->getItem()));
			cout << "Student " << studentId << " has been deleted"<<endl;
			break;
		}
		curNodePtr = curNodePtr->getNext();
	}
	if (!found) {
		cout << "Student " << studentId << " does not exist"<<endl;
	}
}
void RegistrationSystem::addCourse(const int studentId, const int courseId, const string
	courseName) {
	bool stu_found = false;
	Node<Student>* curNodePtr = students->getHeadPtr();
	while (curNodePtr != nullptr) {
		if (studentId == curNodePtr->getItem()->getId()) {
			stu_found = true;
			break;
		}
		curNodePtr = curNodePtr->getNext();
	}
	if (!stu_found) {
		cout << "Student " << studentId << " does not exist" << endl;
	}
	else {
		Node<Student>* stuSameCourseNamePtr = students->getHeadPtr();
		bool isDiffNameExist = false;
		while (stuSameCourseNamePtr != nullptr) {
			if (stuSameCourseNamePtr->getItem()->specifiedCoursePtr(courseId) != nullptr) {
				if (stuSameCourseNamePtr->getItem()->specifiedCoursePtr(courseId)->getItem()->getName() != courseName) {
					isDiffNameExist = true;
					break;
				}
			}
			stuSameCourseNamePtr = stuSameCourseNamePtr->getNext();
		}
		if (isDiffNameExist) {
			cout << "Course " << courseId << " already exists with another name" << endl;
		}
		if (curNodePtr->getItem()->specifiedCoursePtr(courseId) == nullptr) {
			
			if(!isDiffNameExist) {
				curNodePtr->getItem()->addCourseForStudent(courseId, courseName);
				stuSameCourseNamePtr = nullptr;
				curNodePtr = nullptr;
				cout << "Course " << courseId << " has been added to student " << studentId << endl;
			}

		}
		else if(!isDiffNameExist){
			cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
		}
	}

}
void RegistrationSystem::withdrawCourse(const int studentId, const int courseId) {
	bool stu_found = false;
	bool course_exist = false;
	Node<Student>* curNodePtr = students->getHeadPtr();
	while (curNodePtr != nullptr) {
		if (studentId == curNodePtr->getItem()->getId()) {
			stu_found = true;
			break;
		}
		curNodePtr = curNodePtr->getNext();
	}
	if (!stu_found) {
		cout << "Student " << studentId << " does not exist" << endl;
	}
	else {
		Node<Student>* studentCourseCheckPtr = students->getHeadPtr();
		while (studentCourseCheckPtr != nullptr&& course_exist==false) {
			if (studentCourseCheckPtr->getItem()->specifiedCoursePtr(courseId) != nullptr) {
				course_exist = true;
				
			}
			studentCourseCheckPtr = studentCourseCheckPtr->getNext();
		}
		
		if (curNodePtr->getItem()->specifiedCoursePtr(courseId) == nullptr) {
			if (course_exist) {
				cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
			}
			else {
				cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
			}
			
		}
		
		
		else {
			if (curNodePtr->getItem()->cancelCourseForStudent(courseId)) {
				cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
			}
			
		}

	}
}
void RegistrationSystem::cancelCourse(const int courseId) {
	int cancelCount = 0;
	Node<Student>* curNodePtr = students->getHeadPtr();
	while (curNodePtr != nullptr) {
		if (curNodePtr->getItem()->cancelCourseForStudent(courseId)) {
			cancelCount++;
		}
		curNodePtr = curNodePtr->getNext();
	}
	if (cancelCount == 0) {
		cout << "Course " << courseId << " does not exist"<<endl;
	}
	else {
		cout << "Course " << courseId << " has been cancelled"<<endl;
	}

}
void RegistrationSystem::showStudent(const int studentId) {
	bool stu_found = false;
	int courseCount = 0;
	Node<Student>* curNodePtr = students->getHeadPtr();
	while (curNodePtr != nullptr) {
		if (studentId == curNodePtr->getItem()->getId()) {
			stu_found = true;
			break;
		}
		curNodePtr = curNodePtr->getNext();
	}
	if (!stu_found) {
		cout << "Student " << studentId << " does not exist" << endl;
	}
	else {
		cout << "Student id First name Last name" << endl;
		cout << curNodePtr->getItem()->getId() << " " << curNodePtr->getItem()->getFirstName() << " " << curNodePtr->getItem()->getLastName()<<endl;
		
		Node<Course>* curCoursePtr = curNodePtr->getItem()->getCoursesHeadPtr();
		while (curCoursePtr != nullptr) {
			if (courseCount == 0) { cout << "Course id Course name" << endl; }
			cout << curCoursePtr->getItem()->getId() << " " << curCoursePtr->getItem()->getName()<<endl;
			curCoursePtr = curCoursePtr->getNext();
			courseCount++;
		}
		
	}
}
void RegistrationSystem::showCourse(const int courseId) {
	int courseCount = 0;
	Node<Student>* curNodePtr = students->getHeadPtr();
	while (curNodePtr != nullptr) 
	{
		Node<Course>* curCoursePtr = curNodePtr->getItem()->getCoursesHeadPtr();
		while (curCoursePtr != nullptr) 
		{
			if (curCoursePtr->getItem()->getId() == courseId) {
				courseCount++;
				if (courseCount == 1) {
					cout << "Course id Course name" << endl;
					cout << curCoursePtr->getItem()->getId() << " " << curCoursePtr->getItem()->getName()<<endl;
					cout << "Student id First name Last name" << endl;
					
				}
				cout << curNodePtr->getItem()->getId() << " " << curNodePtr->getItem()->getFirstName() << " " << curNodePtr->getItem()->getLastName() << endl;

			}
			curCoursePtr = curCoursePtr->getNext();
		}
		
		curNodePtr = curNodePtr->getNext();
	}
	if (courseCount == 0) {
		cout << "Course " << courseId << " does not exist"<<endl;
	}

}
void RegistrationSystem::showAllStudents() {
	int stuCount = 0;
	int courseCount = 0;
	Node<Student>* curNodePtr = students->getHeadPtr();
	while (curNodePtr != nullptr) 
	{
		courseCount = 0;
		if (stuCount == 0) {
			cout << "Student id First name Last name" << endl;
			}
			
			cout << curNodePtr->getItem()->getId() << " " << curNodePtr->getItem()->getFirstName() << " " << curNodePtr->getItem()->getLastName() << endl;
			stuCount++;
			Node<Course>* curCoursePtr = curNodePtr->getItem()->getCoursesHeadPtr();
			while (curCoursePtr != nullptr) {
				if (courseCount == 0) {
					cout << "Course id Course name" << endl;
				}
				
				cout << curCoursePtr->getItem()->getId() << " " << curCoursePtr->getItem()->getName() << endl;
				curCoursePtr = curCoursePtr->getNext();
				courseCount++;

			}
		
		curNodePtr = curNodePtr->getNext();
	}
	if (stuCount == 0) {
		cout << "There are no students in the system"<<endl;
	}
}