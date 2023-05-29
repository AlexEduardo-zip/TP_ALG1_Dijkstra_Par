#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <limits.h>

class Graph
{
public:
    Graph(int num_vertices);
    void adicionarAresta(int a, int b, int custo); // Adiciona arestas não direcionadas ao grafo de a para b com peso "custo".
    int dijkstra(int destino);                     // Encontra o menor caminho do vertice 1 ao vertice destino utilizando o algoritmo dijkstra
    const int INF = INT_MAX;
    void calculaDistancia(int destino);      // Retorna distancia minima do vertice 1 ao vertice n
    void populaGrafo(int quantidadeArestas); // popula o grafo com n(quantidadeArestas) arestas.

private:
    std::vector<std::vector<std::pair<int, int>>> listaAdjacencia; // lista de adjacência
    std::vector<int> distancias;                                   // vetor de distâncias mínimas
};

#endif // GRAPH_HPP