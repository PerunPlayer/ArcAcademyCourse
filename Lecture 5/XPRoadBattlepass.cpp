#pragma once
#include "stdafx.h"
#include <iostream>

#include "LinkedList.h"

using namespace std;

// XP road - Linked list
//		-> each node has required xp and reward
//		-> validation for bigger amount of XP for next node
// algorithm generating the XP road by 2 parameters - number of levels and step (amount of XP needed for next level)
//		-> will set by default only gold as reward and each n-th (for example 5-th) level gives a health potion
// XP is collected by defeating enemies and looting treasures and completing map
// 
// BONUS: add a new item type Pickaxe that can be used to remove/dig obstacles from the map.
// When doing so, the player will receive XP and a specific resourse that could be obtained to a trader for armor, weapons, spells and potions
//

ListNode* GenerateXPRoad(int levels, double xpIncrease, double goldIncrease);
bool ValidateXPRoad(ListNode* xpRoad);
void ModifyXPRoadRewards(ListNode* xpRoad, int nthLv, double prizeBoost);
void UpdateLevel(ListNode*& currLevel, int playerXP);

int main() 
{
	ListNode* xpRoad = GenerateXPRoad(10, 1.25, 1.25);
	std::cout << std::boolalpha << ValidateXPRoad(xpRoad) << std::endl;
	printWithArrows(xpRoad);

	// simulation of game loop and update function of game engine (1) and update with events + listeners (2)
	ListNode* currLevel = xpRoad;
	int xp = 0;
	UpdateLevel(currLevel, xp); // first update
	
	UpdateLevel(currLevel, xp); // (1) if xp is checked per frames/time

	std::cout << "50xp added\n";
	xp += 50;
	UpdateLevel(currLevel, xp); // (2) if xp is checked after event
	
	std::cout << "50xp added\n";
	xp += 50;
	UpdateLevel(currLevel, xp);

	std::cout << "20xp added\n";
	xp += 20;
	UpdateLevel(currLevel, xp);

	std::cout << "1000xp added\n";
	xp += 1000;
	UpdateLevel(currLevel, xp);
	// ---------------------------------------------------------

	ModifyXPRoadRewards(xpRoad, 5, 1.5);
	printWithArrows(xpRoad);

	destroy(xpRoad);
	return 0;
}

ListNode* GenerateXPRoad(int levels, double xpIncrease, double goldIncrease)
{
	if (levels < 1)
	{
		return nullptr;
	}

	bool isFirstIteration = true;
	ListNode* xpRoad = new ListNode(0, 0, nullptr);
	levels--;
	double lastXPMilestone = 100;
	double lastgoldReward = 50;

	while (levels)
	{
		if (isFirstIteration)
		{
			pushBack(xpRoad, lastXPMilestone, lastgoldReward);
			isFirstIteration = false;
			levels--;
			continue;
		}

		lastXPMilestone *= xpIncrease;
		lastgoldReward *= goldIncrease;
		pushBack(xpRoad, lastXPMilestone, lastgoldReward);
		levels--;
	}

	return xpRoad;
}

bool ValidateXPRoad(ListNode* xpRoadNode)
{
	if (!xpRoadNode)
	{
		std::cout << "XP road not created\n";
		return false;
	}

	while (xpRoadNode->next)
	{
		if ((xpRoadNode->requiredXP >= xpRoadNode->next->requiredXP) || (xpRoadNode->goldPrize >= xpRoadNode->next->goldPrize))
		{
			return false;
		}
		xpRoadNode = xpRoadNode->next;
	}

	return true;
}

void ModifyXPRoadRewards(ListNode* xpRoadNode, int nthLv, double prizeBoost)
{
	if (!xpRoadNode)
	{
		std::cout << "XP road not created\n";
		return;
	}

	int remainingLevels = nthLv - 1;
	while (xpRoadNode)
	{
		if (!remainingLevels)
		{
			remainingLevels = nthLv;
			xpRoadNode->goldPrize *= prizeBoost;
		}
		xpRoadNode = xpRoadNode->next;
		remainingLevels--;
	}
}

void UpdateLevel(ListNode*& currLevel, int playerXP)
{
	if (!currLevel)
	{
		return;
	}

	while (playerXP >= currLevel->requiredXP)
	{
		if (currLevel->requiredXP == 0)
		{
			currLevel = currLevel->next;
			continue;
		}

		if (!currLevel->next)
		{
			std::cout << "Max level reached!\n";
			return;
		}
		currLevel = currLevel->next;
		std::cout << "Level up!\n";
		std::cout << "You received " << currLevel->goldPrize << " gold!\n";
	}
}
