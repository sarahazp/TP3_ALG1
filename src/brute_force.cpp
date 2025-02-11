#include "brute_force.hpp"
// Estratégia de força bruta

// Construtor e destrutor
Brute::Brute() {}
Brute::~Brute() {}

// Função para calcular o custo de uma rota
double Brute::calcularCustoRota(const std::map<std::string, std::map<std::string, double>>& grafo, const std::vector<std::string>& rota) {
    double custo = 0.0;
    for (size_t i = 0; i < rota.size() - 1; i++) {
        custo += grafo.at(rota[i]).at(rota[i + 1]);
    }
    // Retorno à cidade de origem
    custo += grafo.at(rota.back()).at(rota[0]);
    return custo;
}

// Função para gerar todas as permutações manualmente
void Brute::permutacoes(std::vector<std::string>& perm, size_t l, size_t r, std::vector<std::vector<std::string>>& todasPerms) {
    if (l == r) {
        todasPerms.push_back(perm);
    } else {
        for (size_t i = l; i <= r; i++) {
            swap(perm[l], perm[i]);
            permutacoes(perm, l + 1, r, todasPerms);
            swap(perm[l], perm[i]); // backtrack
        }
    }
}

// Função para resolver o problema do Caixeiro Viajante por força bruta
std::pair<std::vector<std::string>, double> Brute::forcaBrutaTSP(const std::map<std::string, std::map<std::string, double>>& grafo) {
    std::vector<std::string> cidades;
    for (const auto& par : grafo) {
        cidades.push_back(par.first);
    }

    std::string cidadeInicial = cidades[0];
    std::vector<std::string> melhorRota;
    double menorCusto = std::numeric_limits<double>::infinity();
    
    std::vector<std::string> permutacao(cidades.begin() + 1, cidades.end()); // Fixamos a cidade inicial
    std::vector<std::vector<std::string>> todasPerms;
    permutacoes(permutacao, 0, permutacao.size() - 1, todasPerms);
    
    for (const auto& perm : todasPerms) { // vai procurando entre todas as permutações possíveis
        std::vector<std::string> rota = {cidadeInicial};
        rota.insert(rota.end(), perm.begin(), perm.end());
        double custo = calcularCustoRota(grafo, rota);
        
        if (custo < menorCusto) { // se for menor, atualiza tudo:
            menorCusto = custo;
            melhorRota = rota;
        }
    }

    return {melhorRota, menorCusto}; // retorna o par desejado
}

void Brute::init_Brute() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<std::string, std::map<std::string, double>> grafo;

    int V = 0, E = 0;

    std::cin >> V >> E;
    
    for(int i = 0; i < E; ++i) {
		std::string c1 = " ", c2 = " "; double tam = 0;
		std::cin >> c1 >> c2 >> tam;
        grafo[c1][c2] = tam;
        grafo[c2][c1] = tam;
    }

    auto [rotaOtima, custoMinimo] = forcaBrutaTSP(grafo);

    std::cout << custoMinimo << std::endl;
    for (size_t i = 0; i < rotaOtima.size(); i++) {
        std::cout << rotaOtima[i];
        if (i < rotaOtima.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
}
