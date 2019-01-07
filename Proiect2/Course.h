#pragma once
#include "pch.h"
#include <string>

class Person {
public:
	Person(std::string FirstName, std::string LastName, std::string CNP, std::string Email = "");
protected:
	std::string FirstName;
	std::string LastName;
	std::string CNP;
	std::string Email;
};