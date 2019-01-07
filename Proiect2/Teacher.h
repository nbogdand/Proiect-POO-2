#pragma once
#include <string>
#include "Person.h"

class Teacher : public Person {

public:
	Teacher(std::string,std::string,std::string);

private:
	std::string Birthdate;
};