#pragma once
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
using Amostra = std::vector<int8_t>;

struct Regra
{
    Amostra r;

   public:
    Regra(initializer_list<int8_t> n) : r(n){};
    Regra() : Regra({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}){};

    friend ostream& operator<<(ostream& saida, const Regra& R)
    {
        saida << "\tRegra (" << R.r.size() << ") numeros: {";
        for (auto&& num : R.r) saida << setw(2) << (int)num << " ";
        saida << "}\n";
        return saida;
    };
};