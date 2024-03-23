#include "pch.h"
#include "CreditCardAccount.h"

using namespace System;

int main(array<System::String^>^ args) {
	Console::WriteLine("Creating first object");
	CreditCardAccount^ account1;
	account1 = gcnew CreditCardAccount(12345, 2000);
	account1->MakePurchase(300);
	account1->PrintStatement();
	Console::WriteLine("\nCreating second object");
	CreditCardAccount^ account2;
	account2 = gcnew CreditCardAccount(67890, 5000);
	account2->MakePurchase(750);
	account2->PrintStatement();
}