#include "pch.h"
#include "Role.h"



Role::Role(RoleType type):mType(type){

}

Role::RoleType Role::getType()
{
	return mType;
}



