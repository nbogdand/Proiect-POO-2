#pragma once
#include <string>
#include <iostream>

class Room {

public:
	Room(std::string mName);
	std::string getName();
	void setName(std::string);

	friend std::ostream& operator << (std::ostream&, Room);
protected:
	std::string mName;
};