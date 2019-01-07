#include "pch.h"
#include "Register.h"
#include "Role.h"
#include "StudentRole.h"
#include "Person.h"
#include <vector>


Register* Register::mRegister;
std::vector<Person*> Register::mStudents;

Register* Register::instance()
{
	if (mRegister == NULL) {
		mRegister = new Register();
	}
	return mRegister;
}

void Register::addStudent(Person* newStudent)
{
	// check if person newStudent is 
	// actually a student and then add to the vector
	std::vector<Role*> newStudentRoles = newStudent->getRoles();
	for (int i = 0; i < newStudentRoles.size(); i++) {
		if (newStudentRoles[i]->getType() == Role::STUDENT_ROLE)
			mStudents.push_back(newStudent);
	}

}


std::vector<Grade*> Register::getStudentGradesByFullName(std::string firstName, std::string lastName)
{
	// first, find the person by name
	for (int i = 0; i < mStudents.size(); i++) {
	
		if (mStudents[i]->getLastName() == lastName && mStudents[i]->getFirstName() == firstName) {
			
			// after the person is found
			// check if he/she has a student role
			std::vector<Role*> personRoles = mStudents[i]->getRoles();
			
			for (int j = 0; j < personRoles.size(); j++) {
				
				// if so, return his/hers grades
				if (personRoles[j]->getType() == Role::STUDENT_ROLE) {
					StudentRole* studentRole = static_cast<StudentRole*>(personRoles[j]);
					return studentRole->getGrades();
				}
			}
		}
	}

	// return std::vector<Grade*>();
}





