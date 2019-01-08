#pragma once
#include "Discipline.h"


class Grade {
public :
	
	Grade();
	Grade(float);
	Grade(float, Discipline*);

	float getGrade();
	void setGrade(float);
	Discipline* getDiscipline();
	void setDiscipline(Discipline*);

	friend std::ostream& operator << (std::ostream&, Grade&);

private:
	float mGrade;
	Discipline* mDiscipline;
};

