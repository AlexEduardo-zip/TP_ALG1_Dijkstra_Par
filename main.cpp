#include <iostream>
#include "graph.hpp"

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    std::cin >> n >> m;

    Graph g(n);

    g.populaGrafo(m);

    g.calculaDistancia(n);

    return 0;
}