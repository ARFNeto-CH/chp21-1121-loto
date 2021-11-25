#include <iomanip>
#include <iostream>
#include "Sorteio10.h"

int main()
{   // -1 excluido 0 sorteio 1 fixo
    //clang-format-off
    //Regra     regra_teste({-1, -1, -1, -1, 0, 1, 1, 1, 0, 0});
    Regra     regra_teste({ 1, 1, 1,-1,-1, 0, 0, 0, 0, -1});
    Amostra   numeros =   { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // clang-format-on
    int8_t    peso    = 40;  // soma a cada numero do grupo
    Sorteio10 simples = Sorteio10(numeros, regra_teste, peso);
    simples.mostra_serie(); // e as permutacoes
    return 0; // nada mais
}