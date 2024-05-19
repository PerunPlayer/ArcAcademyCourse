#include "stdafx.h"
#include "Equipment.h"

Equipment::Equipment()
{
	reset();
}

Equipment::Equipment(const std::string& _name, const BonusType _bonusType, const double _bonusPercentage)
	: name(_name), bonusType(_bonusType), bonusPercentage(_bonusPercentage)
{
}

Equipment::~Equipment()
{
	reset();
}

const BonusType Equipment::GetType() const
{
	return bonusType;
}

void Equipment::reset()
{
	name = "";
	bonusType = BonusType::Invalid;
	bonusPercentage = 0;
}
