#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <limits>

class Greedy {
public:
    Greedy();
    ~Greedy();

    const int INF = std::numeric_limits<int>::max();

    // Função para resolver o TSP usando um algoritmo guloso
    std::vector<int> greedy_tsp(std::vector<std::vector<int>>& dist, int n);

    void init_Greedy();
};