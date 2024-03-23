#pragma once

ref class CreditCardAccount {
public:
	static int GetNumberOfAccounts();
	void SetCreditLimit(double amount);
	bool MakePurchase(double amount);
	void MakeRepayment(double amount);
	void PrintStatement();
	long GetAccountNumber();

private:
	static int numberOfAccounts;
	long accountNumber;
	double currentBalance;
	double creditLimit;
};