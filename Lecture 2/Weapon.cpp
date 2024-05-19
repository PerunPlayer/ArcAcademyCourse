#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon() : material(""), Equipment()
{
}

Weapon::Weapon(const std::string _name, const double _bonusPercentage, const std::string _material)
	: Equipment(_name, BonusType::Offensive, _bonusPercentage)
{
	material = _material;
}

Weapon::~Weapon()
{
	material = "";
}

const std::string& Weapon::GetName() const
{
	return "Weapon name: " + name;
}
