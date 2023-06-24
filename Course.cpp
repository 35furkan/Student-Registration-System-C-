//Emre Furkan Akyol Section2  22103352
#include "Course.h"
#include <string>
#include <iostream>
using namespace std;

Course::Course() {
	id = -1;
	course_name = " ";
}
Course::Course(int id, string courseName) {
	this->course_name = courseName;
	this->id = id;
}
void Course::setId(int id) {
	this->id = id;
}

void Course::setName(string courseName) {
	this->course_name = courseName;
}
int Course::getId() {
	return id;
}
string Course::getName() {
	return course_name;
}
bool Course::operator<(const Course& other) const {
	return this->id < other.id;
}
bool Course::operator==(const Course& other) const {
	return this->id == other.id;
}