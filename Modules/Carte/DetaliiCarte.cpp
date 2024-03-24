#include "pch.h"
#include "Carte.h"

using namespace System;

int main() {
    String^ input;

    Console::WriteLine("Introdu nr de carti");
    input = Console::ReadLine();

    int nr_carti = Convert::ToUInt32(input);

    array<Carte^>^ carti = gcnew array<Carte^>(nr_carti);

    for (int i = 0; i < nr_carti; i++){
        Console::WriteLine("\nPentru cartea {0}", i + 1);

        Console::WriteLine("Introdu autorul: ");
        String^ autor = Console::ReadLine();

        Console::WriteLine("Introdu editura: ");
        String^ editura = Console::ReadLine();

        Console::WriteLine("Introdu anul aparitiei: ");
        input = Console::ReadLine();

        unsigned anAparitie = Convert::ToUInt32(input);

        Console::WriteLine("Introdu vechimea: ");
        input = Console::ReadLine();

        unsigned vechime = Convert::ToUInt32(input);

        carti[i] = gcnew Carte(autor, editura, anAparitie, vechime);
    }

    Console::WriteLine("\nAfisam detalii carti: ");

    for (int i = 0; i < nr_carti; i++) {
        Console::WriteLine("\nDetalii carte: {0}", carti[i]->getDetails());
    }

    return 0;
}