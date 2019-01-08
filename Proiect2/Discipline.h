#pragma once
#include <string>
#include "Activity.h"
#include <vector>

class Discipline {
public:

	Discipline();
	Discipline(std::string);

	std::string getName();
	void setName(std::string);
	std::vector<Activity*> getAllActivities();
	void addActivity(Activity*);
	void removeActivity(std::string);

	friend std::ostream& operator << (std::ostream& out, Discipline&);

private:
	std::string mName;
	std::vector<Activity*> mActivities;
};