#include "pch.h"

using namespace System;

ref class Animal {
public:
	int limbs;

	void SetName(String^ nm) {
		name = nm;
	}

	String^ GetName() {
		return name; 
	}

private:
	String^ name;
};

int main(array<System::String^>^ args) {
	Animal cat, spider;
	cat.SetName("Cat");
	cat.limbs = 4;
	spider.SetName("Spider");
	spider.limbs = 6;

	Console::WriteLine("Animal  1 - name: {0}, legs: {1}", cat.GetName(), cat.limbs);
	Console::WriteLine("Animal  2 - name: {0}, legs: {1}", spider.GetName(), spider.limbs);
	Console::WriteLine();
	return 0;
}