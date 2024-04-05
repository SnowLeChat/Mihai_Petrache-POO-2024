#include "CurrentAccount.h"
#include "SavingsAccount.h"

void main() {
	CurrentAccount acc("Me", 2000.0);
	acc.Credit(100.0);

	SavingsAccount::SetInterestRate(2.5);
	SavingsAccount sacc("You");
	
	double rate = sacc.GetInterestRate();
	double balance = acc.GetBalance();
	double overdraft = acc.GetOverdraftLimit();

	Console::WriteLine("Balance: {0}", balance);
	Console::WriteLine("Overdraft: {0}", overdraft);
	Console::WriteLine("Interest rate: {0}", rate);
}