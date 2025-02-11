#include <iostream>
#include "guloso.hpp"
#include "brute_force.hpp"
#include "dinamic.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Brute b;
    Dinamic d;
    Greedy g;

    char tipo = ' ';
    std::cin >> tipo;
    
    switch (tipo)
    {
    case 'b':
        b.init_Brute();
        break;
    case 'd':
        d.init_Dinamico();
        break;
    case 'g':
        g.init_Greedy();
        break;
    default:
        break;
    }

}
