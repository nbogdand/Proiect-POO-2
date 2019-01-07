#pragma once
#include "Role.h"
#include "Grade.h"

class StudentRole : public Role{
public:
	StudentRole();
	std::vector<Grade*> getGrades();
	void addGrade(Grade* grade);

private:
	std::vector<Grade*> mGrades;
	int mStudyGroup;
};
