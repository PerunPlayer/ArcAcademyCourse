#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>

#include "Armor.h"
#include "Weapon.h"

using namespace std;

int main()
{
	//Equipment(); - it's an abstract class

	Armor shield("Shield", 0.7, Rarity::Epic);
	Weapon sword("Sword", 0.3, "Wood");

	std::vector<Armor*> shields;
	shields.push_back(&shield);

	std::vector<Weapon*> weapons;
	weapons.push_back(&sword);

	//polymorphism - different objects but same treatment
	std::vector<Equipment*> inventory;
	inventory.push_back(&shield);
	inventory.push_back(&sword);

	for (size_t i = 0; i < inventory.size(); i++)
	{
		std::cout << inventory[i]->GetName() << std::endl;
		if (inventory[i]->GetType() == BonusType::Offensive)
		{
			//.... do some offensive work
		}
	}

	return 0;
}