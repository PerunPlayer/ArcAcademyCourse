#pragma once
#include "Equipment.h"

class Weapon : public Equipment
{
public:
	Weapon();
	explicit Weapon(const std::string _name, const double _bonusPercentage, const std::string _material);
	~Weapon();

	const std::string& GetName() const override;

private:
	std::string material;
};