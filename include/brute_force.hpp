#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <limits>
// Estratégia de força bruta
class Brute {
public:
    Brute();
    ~Brute();
    
    double calcularCustoRota(const std::map<std::string, std::map<std::string, double>>& grafo, const std::vector<std::string>& rota);

    // Função para gerar todas as permutações manualmente
    void permutacoes(std::vector<std::string>& perm, size_t l, size_t r, std::vector<std::vector<std::string>>& todasPerms);

    // Função para resolver o problema do Caixeiro Viajante por força bruta
    std::pair<std::vector<std::string>, double> forcaBrutaTSP(const std::map<std::string, std::map<std::string, double>>& grafo);

    void init_Brute();
};