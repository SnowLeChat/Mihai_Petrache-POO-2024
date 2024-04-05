#pragma once
#include "BankAccount.h"

ref class SavingsAccount : BankAccount {
public:
	SavingsAccount(String ^holder);
	static void SetInterestRate(double rate);
	static double GetInterestRate();
private:
	static double interestRate;
};