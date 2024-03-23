#include "pch.h";
#include "LoyalityScheme.h";

#using <mscorlib.dll>
using namespace System;

LoyalityScheme::LoyalityScheme()
{
	Console::WriteLine("Congrats! You now qualify for bonus points");

	totalPoints = 0;
}

void LoyalityScheme::EarnPointsOnAmount(double amountSpent)
{
	int points = (int)(amountSpent / 10);
	totalPoints += points;

	Console::WriteLine("New bonus points earned: {0}", points);
}

void LoyalityScheme::RedeemPoints(int points)
{
	if (points <= totalPoints)
	{
		totalPoints -= points;
	}
	else {
		totalPoints = 0;
	}
}

int LoyalityScheme::GetPoints()
{
	return totalPoints;
}