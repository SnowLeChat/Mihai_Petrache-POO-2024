#include "pch.h"

using namespace System;

ref class Carte {
public:
    Carte(String^ a, String^ e, int aa, int v);

    String^ getDetails();

private:
    String^ autor;
    String^ editura;
    int anAparitie;
    int vechime;
};