#include "graph.hpp"

#include <iostream>
#include <queue>

using namespace std;

// contrutor do grafo. tamanho do grafo redimensionado e
// atribuido distancias infinitas a todos os vertices.
Graph::Graph(int num_vertices)
{
    num_vertices = num_vertices * 2 + 2;
    listaAdjacencia.resize(num_vertices);
    distancias.assign(num_vertices, INF);
}

// Adiciona as arestas no grafo de forma que a construção do grafo obtenha um
// caminho minimo com quantidade par de arestas ao rodar Dijkstra
void Graph::adicionarAresta(int a, int b, int custo)
{
    if ((custo % 2) != 0)
        return;
    listaAdjacencia[2 * a + 1].push_back({2 * b, custo});
    listaAdjacencia[2 * a].push_back({2 * b + 1, custo});
    listaAdjacencia[2 * b + 1].push_back({2 * a, custo});
    listaAdjacencia[2 * b].push_back({2 * a + 1, custo});
}

// Algoritmo Dijktra que descobre o menor caminho entre o vertice 1 e o vertice
// n(Argumento da função), utiliza-se uma fila de prioridade e um vetor de
// distancias minimas de cada vertice.
int Graph::dijkstra(int destino)
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        filaPrioridade;
    filaPrioridade.push({0, 2});
    distancias[2] = 0;

    while (!filaPrioridade.empty())
    {
        int u = filaPrioridade.top().second;
        filaPrioridade.pop();

        for (auto p : listaAdjacencia[u])
        {
            int vertice = p.first;
            int custo = p.second;

            if (distancias[u] + custo < distancias[vertice])
            {
                distancias[vertice] = distancias[u] + custo;
                filaPrioridade.push({distancias[vertice], vertice});
            }
        }
    }
    int distancia = distancias[2 * destino];
    return distancia;
}

// Calcula e imprime a distancia do vertice 1 ao vertice n, passado como
// argumento da função, recusando arestas com peso impar e utilizando o menor
// caminho com quantidade par de arestas(o grafo foi modificado ao adicionar as
// arestas para permitir essa propriedade). O algoritmo utilizado é Dijkistra
// com modificações na construção do grafo. Complexidade 0(log n + m)
void Graph::calculaDistancia(int destino)
{
    int distancia = this->dijkstra(destino);
    if (distancia == this->INF)
        std::cout << "-1" << std::endl;
    else
        std::cout << distancia << std::endl;
}

// Popula o grafo adicionando a quantidade de arestas que é passada como
// argumento da função
void Graph::populaGrafo(int quantidadeArestas)
{
    int i = 0;
    while (i < quantidadeArestas)
    {
        int u, v, custo;
        std::cin >> u >> v >> custo;
        this->adicionarAresta(u, v, custo);
        i++;
    }
}
