#pragma once
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include "Sorteio10.h"
using namespace std;

Sorteio10::Sorteio10(Amostra& vet, const Regra& R, int8_t P)
    : fixos(0),
      inicio(true),
      inicial(vet),
      numero({}),
      regra(R),
      peso(P),
      possiveis(0),
      size((int8_t)R.r.size())
{
    peso  = P;
    regra = R;
    // gera o vetor classificado: sorteaveis fixos excluidos
    int n_sort      = 0;
    int n_fixo      = 0;
    int n_excl      = 0;
    int prim_n_sort = -1;
    for (size_t i = 0; i < size; i += 1)
        if (regra.r[i] == 0)
        {
            n_sort += 1;
            numero.push_back(peso+inicial[i]);
        }
        else
        {
            if (prim_n_sort < 0) prim_n_sort = i;  // salva
        }

    possiveis = n_sort;

    if (n_sort != size)
    {  // nem todos vao para o sorteio
        int prim_n_fixo = -1;
        for (size_t i = prim_n_sort; i < size; i += 1)
            if (regra.r[i] == 1)
            {
                n_fixo += 1;
                numero.push_back(peso+inicial[i]);
            }
            else
            {
                if (prim_n_fixo < 0) prim_n_fixo = i;  // salva
            }
        this->fixos = n_fixo;
        // e os excluidos
        for (size_t i = prim_n_fixo; i < size; i += 1)
            if (regra.r[i] == -1)
            {
                n_excl += 1;
                numero.push_back(peso+inicial[i]);
            }
    };

    // agora arruma a regra
    int next = 0;
    for (next = 0; next < n_sort; next += 1) regra.r[next] = 0;
    for (int i = 0; i < n_fixo; i += 1) regra.r[next++] = 1;
    for (int i = 0; i < n_excl; i += 1) regra.r[next++] = -1;

    // prepara o primeiro sorteio
    for_each(
        numero.begin(), numero.begin() + fixos + possiveis,
        [&](auto& num) { o_sorteio.push_back(num); }
    );
}

void Sorteio10::mostra_serie()
{
    std::cout << *this;  // mostra o resumo
    int t = 0;
    while (prox_serie())
    {
        cout << "  " << setw(4) << ++t << " { ";
        for (auto&& n : o_sorteio)
            cout << setw(4) << (int)n << " ";
        cout << " }\n";
    };
}

bool Sorteio10::prox_serie()
{
    if (inicio)
    {   inicio = false;
        return true;
    }
    return next_permutation(
        o_sorteio.begin(),
        o_sorteio.begin() + possiveis);
}

ostream& operator<<(ostream& saida, const Sorteio10& S)
{
    //clang-format-off
    saida << "\n\tValores  iniciais:  {";
    for (auto&& num : S.inicial) saida << setw(2) << (int)num << " ";
    saida << "}\n" << S.regra << "\n";

    saida << "\n\tPeso = " << (int)S.peso << ", " <<
        S.size << " numeros, " <<
        S.possiveis << " no sorteio, " << 
        S.fixos << " fixos, " << 
        (S.size - S.fixos - S.possiveis) << " excluidos\n";

    //clang-format-on

    saida << "\tnumeros: ";
    saida << "{ ";
    for (auto&& num : S.numero) saida << (int)num << " ";
    saida << "}\n\n\tAs permutacoes:\n\n";
    return saida;
};
