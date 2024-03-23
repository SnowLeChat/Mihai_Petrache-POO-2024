#pragma once

ref class CreditCardAccount {
public:
	void SetCreditLimit(double amount);
	bool MakePurchase(double amount);
	void MakeRepayment(double amount);
	void PrintStatement();
	long GetAccountNumber();
private:
	static int numberOfAccounts = 0;
	long accountNumber;
	double currentBalance;
	double creditLimit;
};