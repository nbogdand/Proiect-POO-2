#pragma once
#include "Repository.h"
#include "Activity.h"

class ActivityRepository : public Repository<Activity> {

public:
	std::vector<Activity*> findActivitiesByOwner(Person*);
	std::vector<Activity*> findActivitiesByRoom(Room*);

};

std::vector<Activity*> ActivityRepository::findActivitiesByOwner(Person* owner) {

	std::vector<Activity*> activities;

	for (int i = 0; i < mEntities.size(); i++) {
		
		if (mEntities[i]->getOwner()->getFirstName() == owner->getFirstName() &&
			mEntities[i]->getOwner()->getLastName() == owner->getLastName()) {

			activities.push_back(mEntities[i]);

		}

	}

	return activities;
}


std::vector<Activity*> ActivityRepository::findActivitiesByRoom(Room* room) {

	std::vector<Activity*> activities;

	for (int i = 0; i < mEntities.size(); i++) {

		if (mEntities[i]->getLocation() == room)
			activities.push_back(mEntities[i]);

	}

	return activities;
}

