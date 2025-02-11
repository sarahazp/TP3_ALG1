#pragma once 

#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <cmath>

class Dinamic {
public:
    Dinamic();
    ~Dinamic();
    
    const int INF = std::numeric_limits<int>::max();

    // Função para resolver o TSP usando programação dinâmica com bitmask e recuperar a rota
    int tsp(int mask, int pos, std::vector<std::vector<int>>& dist, std::vector<std::vector<int>>& dp, std::vector<std::vector<int>>& parent, int n);

    // Função para reconstruir a rota
    std::vector<int> getPath(std::vector<std::vector<int>>& parent);

    void init_Dinamico(); 
};