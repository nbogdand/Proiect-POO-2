#pragma once
#include "Student.h"
#include "Person.h"
#include "Grade.h"
#include <vector>

class Register {

public:
	static Register* instance();
	static void addStudent(Person*);
	static std::vector<Grade*> getStudentGradesByFullName(std::string,std::string);

private:
	Register() {};
	static Register* mRegister;
	static std::vector<Person*> mStudents;
};




