#pragma once
#include <cstdint>
#include <iostream>
#include <vector>

#include "Regra.h"
using namespace std;

struct Sorteio10
{
   public:
    size_t  fixos;      // fixados na regra
    bool    inicio;
    Amostra inicial;    // os numeros
    Amostra numero;     // os numeros
    int8_t  peso;       // 00,10,20,30,40
    size_t  possiveis;  // variaveis
    Regra   regra;      // define o sorteio
    size_t  size;       // tamanho vem da regra

    Sorteio10(Amostra& v, const Regra& R, int8_t P);
    friend ostream& operator<<(ostream& saida, const Sorteio10&);
    void            mostra_serie();
    bool            prox_serie();

   public:
    Amostra o_sorteio;
};
