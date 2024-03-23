#include "pch.h"
#include "CreditCardAccount.h"

#using <mscorlib.dll>
using namespace System;

CreditCardAccount::CreditCardAccount()
{
	accountNumber = 1234;
	currentBalance = 0;
	creditLimit = 3000;

	numberOfAccounts++;

	scheme = nullptr;
}

CreditCardAccount::CreditCardAccount(long number, double limit)
{
	accountNumber = number;
	currentBalance = 0;
	creditLimit = limit;

	numberOfAccounts++;

	scheme = nullptr;
}

static CreditCardAccount::CreditCardAccount()
{
	interestRate = 4.5;
	Console::WriteLine("Static constructor called");
}

int CreditCardAccount::GetNumberOfAccounts()
{
	return numberOfAccounts;
}

void CreditCardAccount::SetCreditLimit(double amount)
{
	creditLimit = amount;
}

bool CreditCardAccount::MakePurchase(double amount)
{
	if (currentBalance + amount > creditLimit)
	{
		return false;
	}

	currentBalance += amount;

	if (currentBalance >= creditLimit / 2)
	{
		if (scheme == nullptr)
		{
			scheme = gcnew LoyalityScheme();
		}
		else
		{
			scheme->EarnPointsOnAmount(amount);
		}
	}
	return true;
}

void CreditCardAccount::RedeemLoyalityPoints()
{
	if (scheme == nullptr)
	{
		Console::WriteLine("Sorry you do not have a loyality scheme yet.");
	}
	else
	{
		Console::WriteLine("Points available: {0}", scheme->GetPoints());
		Console::WriteLine("How mayn points do you want to redeem? ");
		String^ input = Console::ReadLine();

		int points = Convert::ToInt32(input);

		scheme->RedeemPoints(points);

		Console::WriteLine("Points remaining: {0}", scheme->GetPoints());
	}
}

void CreditCardAccount::MakeRepayment(double amount)
{
	currentBalance -= amount;
}

void CreditCardAccount::PrintStatement()
{
	Console::Write("Credit card balance: ");
	Console::WriteLine(CreditCardAccount::currentBalance);
}

long CreditCardAccount::GetAccountNumber()
{
	return accountNumber;
}