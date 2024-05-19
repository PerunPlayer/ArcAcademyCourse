#pragma once
#include "Equipment.h"

enum class Rarity
{
	Invalid = -1,
	Common,
	Rare,
	Epic,
	Legendary,
	Mythic,
	Count
};

class Armor : public Equipment
{
public:
	Armor();
	explicit Armor(const std::string _name, const double _bonusPercentage, const Rarity _rarity);
	~Armor();

	const std::string& GetName() const override;

private:
	Rarity rarity;
};