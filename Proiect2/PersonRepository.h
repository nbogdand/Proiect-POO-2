#pragma once
#include "Repository.h"
#include "Person.h"
#include <string>

class PersonRepository : public Repository<Person> {
public:
	Person* findByCNP(std::string);
	Person* findByFullName(std::string, std::string);
};

Person* PersonRepository::findByCNP(std::string CNP) {

	// Go through whole vector of Persons and 
	// find the person with matching CNP
	for (int i = 0; i < mEntities.size(); i++) {
		
		//if found return it 
		if (mEntities[i]->getCNP() == CNP)
			return mEntities[i];
	}

	//if not found 
	return NULL;
}


Person* PersonRepository::findByFullName(std::string lastName, std::string firstName) {
	
	// Go through whole vector of Persons and 
	// find the person with matching full name
	for (int i = 0; i < mEntities.size(); i++) {

		//if found 
		if (mEntities[i]->getLastName() == lastName && mEntities[i]->getFirstName() == firstName)
			return mEntities[i];
	}

	//if not found 
	return NULL;

}


