#include "pch.h"
#include "Discipline.h"
#include <string>

Discipline::Discipline()
{
}

Discipline::Discipline(std::string name) : mName(name)
{

}

std::string Discipline::getName() {
	return mName;
}

void Discipline::setName(std::string disciplineName) {
	mName = disciplineName;
}

std::vector<Activity*> Discipline::getAllActivities()
{
	return mActivities;
}

void Discipline::addActivity(Activity *act)
{
	mActivities.push_back(act);
}

void Discipline::removeActivity(std::string name)
{
	for (int i = 0; i < mActivities.size(); i++) {
		if (mActivities[i]->getDescription() == name)
			mActivities.erase(mActivities.begin() + i);
	}
}

std::ostream & operator<<(std::ostream & out, Discipline &ob)
{
	out << ob.mName << " ";
	for (int i = 0; i < ob.mActivities.size(); i++) {
		out << *(ob.mActivities[i]) << " ";
	}

	return out;
}
