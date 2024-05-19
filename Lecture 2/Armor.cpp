#include "stdafx.h"
#include "Armor.h"

Armor::Armor() : rarity(Rarity::Invalid), Equipment()
{
}

Armor::Armor(const std::string _name, const double _bonusPercentage, const Rarity _rarity)
	: Equipment(_name, BonusType::Defensive, _bonusPercentage)
{
	rarity = _rarity;
}

Armor::~Armor()
{
	rarity = Rarity::Invalid;
}

const std::string& Armor::GetName() const
{
	return "Armor name: " + name;
}
