#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(String^ holder, double limit) : BankAccount(holder), overdraftLimit(limit) {

}

void CurrentAccount::ChangeOverdraftLimit(double newLimit) {
	overdraftLimit = newLimit;
}

double CurrentAccount::GetOverdraftLimit()
{
	return overdraftLimit;
}
