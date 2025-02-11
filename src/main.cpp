#include <iostream>
#include "guloso.hpp"
#include "brute_force.hpp"
#include "dinamic.hpp"

#include <chrono>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Brute b;
    Dinamic d;
    Greedy g;

    char tipo = ' ';
    std::cin >> tipo;
    
   /* switch (tipo)
    {
    case 'b':
        b.init_Brute();
        break;
    case 'd':*/
    	auto start = std::chrono::high_resolution_clock::now();
        d.init_Dinamico();
        //b.init_Brute();
        //g.init_Greedy();
        auto end = std::chrono::high_resolution_clock::now();
   /*     break;
    case 'd':
        g.init_Greedy();
        break;
    default:
        break;
    }*/
    std::chrono::duration<double, std::milli> duration = end - start;

    // Exibe o tempo gasto
    std::cout << duration.count() <<  std::endl;

}
