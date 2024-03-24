#include "pch.h"
#include "Carte.h"

using namespace System;

Carte::Carte(String^ aut, String^ edit, int anApar, int vechi) {
    autor = aut;
    editura = edit;
    anAparitie = anApar;
    vechime = vechi;
}

String^ Carte::getDetails() {
    return String::Format("\nNume: {0}, Editura: {1}, An aparitie: {2}, Vechime: {3}", autor, editura, anAparitie, vechime);
}