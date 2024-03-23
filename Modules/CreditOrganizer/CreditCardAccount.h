#include "pch.h"
#include "LoyalityScheme.h"

using namespace System;

ref class CreditCardAccount
{
public:
	CreditCardAccount(long number, double limit);
	CreditCardAccount();
	static CreditCardAccount();

	// Class-wide constant (like static prop);
	literal String^ name = "Super Paltinum Card";

	void SetCreditLimit(double amount);
	bool MakePurchase(double amount);
	void MakeRepayment(double amount);
	void PrintStatement();
	long GetAccountNumber();

	static int GetNumberOfAccounts();

	void RedeemLoyalityPoints();

private:
	static int numberOfAccounts = 0;
	static double interestRate;
	// Can set the value in the constructor, but can't be modified after that;
	initonly long accountNumber;
	double currentBalance;
	double creditLimit;

	LoyalityScheme^ scheme;
};