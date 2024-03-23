#include "pch.h"
#include "CreditCardAccount.h"

using namespace System;

int main(array<System::String^>^ args) {
	CreditCardAccount^ myAccount;
	myAccount = gcnew CreditCardAccount;
	myAccount->SetCreditLimit(1000);
	myAccount->MakePurchase(1000);
	myAccount->MakeRepayment(700);
	myAccount->PrintStatement();
	long num = myAccount->GetAccountNumber();
	Console::Write("Account Number: ");
	Console::WriteLine(num);
}