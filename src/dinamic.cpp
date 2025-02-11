#include "dinamic.hpp"

// Construtor e destrutor
Dinamic::Dinamic() {}
Dinamic::~Dinamic() {}

// Função para resolver o TSP usando programação dinâmica com bitmask
int Dinamic::tsp(int mask, int pos, std::vector<std::vector<int>>& dist, std::vector<std::vector<int>>& dp, std::vector<std::vector<int>>& parent, int n) {
    if (mask == (1 << n) - 1) return dist[pos][0]; // Retorna à cidade inicial
    
    if (dp[mask][pos] != -1) return dp[mask][pos]; // Retorna valor já computado
    
    int minCost = INF, bestCity = -1;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // Se a cidade ainda não foi visitada
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp, parent, n); // atualiza o custo
            if (newCost < minCost) { // se for menor que o atual, atualiza tudo
                minCost = newCost;
                bestCity = city;
            }
        }
    }
    
    parent[mask][pos] = bestCity;
    return dp[mask][pos] = minCost;
}

// Função para reconstruir a rota que queremos visualizar
std::vector<int> Dinamic::getPath(std::vector<std::vector<int>>& parent) {
    std::vector<int> path;
    int mask = 1, pos = 0;
    while (true) {
        path.push_back(pos);
        int nextPos = parent[mask][pos];
        if (nextPos == -1) break;
        mask |= (1 << nextPos);
        pos = nextPos;
    }
    path.push_back(0); // Retorno à cidade inicial
    return path;
}

void Dinamic::init_Dinamico() {
    // Função para inicializar as estruturas que vamos precisar
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
    
    std::vector<std::vector<int>> dp(1 << V, std::vector<int>(V, -1));
    std::vector<std::vector<int>> parent(1 << V, std::vector<int>(V, -1));
    tsp(1, 0, dist, dp, parent, V);
    //int custoMinimo = tsp(1, 0, dist, dp, parent, V);
    //std::vector<int> path = getPath(parent);
    
    // Printa o menor custo
    //std::cout << custoMinimo << std::endl;
    // Printa o caminho
    /*
    for (size_t i = 0; i < path.size()-1; i++) {
        std::cout << cityIndex[path[i]];
        if (i < path.size() - 2) std::cout << " ";
    }*/
    std::cout << std::endl;
    
}
