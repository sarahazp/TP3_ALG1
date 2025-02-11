#include "guloso.hpp"

// Construtor e destrutor
Greedy::Greedy() {}
Greedy::~Greedy() {}

// Função para resolver o TSP usando um algoritmo guloso
std::vector<int> Greedy::greedy_tsp(std::vector<std::vector<int>>& dist, int n) {
    std::vector<int> path;
    std::vector<bool> visited(n, false);
    int current = 0;
    path.push_back(current);
    visited[current] = true;
    int totalCost = 0;
    
    for (int i = 1; i < n; i++) {
        int nearest = -1;
        int minDist = INF;
        
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[current][j] < minDist) {
                minDist = dist[current][j];
                nearest = j;
            }
        }
        
        if (nearest != -1) {
            visited[nearest] = true;
            path.push_back(nearest);
            totalCost += minDist;
            current = nearest;
        }
    }
    
    // Retorna à cidade inicial
    path.push_back(0);
    totalCost += dist[current][0];
    
    std::cout << totalCost << std::endl;
    return path;
}

void Greedy::init_Greedy(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<std::string, std::map<std::string, int>> grafo;

    int V = 0, E = 0;

    std::cin >> V >> E;
    
    for(int i = 0; i < E; ++i) {
		std::string c1 = " ", c2 = " "; int tam = 0;
		std::cin >> c1 >> c2 >> tam;
        grafo[c1][c2] = tam;
        grafo[c2][c1] = tam;
    }

    std::map<int, std::string> cityIndex;
    int index = 0;
    std::vector<std::vector<int>> dist;

    for(const auto &[key, _] : grafo) {
        cityIndex[index] = key;
        ++index;
    }

    for(int y = 0; y < V; ++y) {
        std::vector<int> dis;
        for(int ks = 0; ks < V; ++ks) {
            if(ks == y) dis.push_back(0);
            else {
                dis.push_back(grafo[cityIndex[ks]][cityIndex[y]]);
            }
        }
        dist.push_back(dis);
    }

    std::vector<int> path = greedy_tsp(dist, V);
    
    for (int i = 0; i < int(path.size() - 1); ++i) {
        std::cout << cityIndex[path[i]];
        if (i < int(path.size() - 2)) std::cout << " ";
    }
    std::cout << std::endl;
  
}
