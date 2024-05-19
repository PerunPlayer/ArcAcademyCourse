#pragma once
#include <string>

enum BonusType
{
	Invalid = -1,
	Offensive,
	Defensive,
	Magical,
	Count
};

class Equipment
{
public:
	Equipment();
	explicit Equipment(const std::string& _name, const BonusType _bonusType, const double _bonusPercentage);
	virtual ~Equipment();

	virtual const std::string& GetName() const = 0;
	const BonusType GetType() const;

protected:
	std::string name;
	BonusType bonusType;
	double bonusPercentage;

	void reset();
};