#include "pch.h"
#include "StudentRole.h"
#include "Register.h"


StudentRole::StudentRole() :Role(Role::STUDENT_ROLE) {
}

std::vector<Grade*> StudentRole::getGrades()
{
	return mGrades;
}

void StudentRole::addGrade(Grade * grade)
{
	mGrades.push_back(grade);

	//	std::cout << "am adaugat grade" << std::endl;
}
