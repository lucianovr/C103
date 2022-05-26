#include <iostream>
#include "Grafo.h"

using namespace std;

int main()
{
	const int V = 6;
	const bool eh_digrafo = true;

	Grafo G(eh_digrafo, V);

	G.insereAresta(0, 1, 10);
	G.insereAresta(0, 4, 5);
	G.insereAresta(1, 4, 2);
	G.insereAresta(4, 1, 3);
	G.insereAresta(1, 2, 1);
	G.insereAresta(2, 3, 4);
	G.insereAresta(3, 2, 6);
	G.insereAresta(3, 0, 7);
	G.insereAresta(4, 3, 2);
	G.insereAresta(4, 2, 9);

	G.mostraArestas();

	int dist[V];
	int pai[V];
	int origem = 0;
	G.dijkstra(origem, dist, pai, V);

	cout << "Menor custo de " << origem << " para os demais vertices\n";
	for (size_t v = 0; v < V; v++)
	{
		cout << "dist[" << v << "] = " << dist[v] << "\t\t pai[" << v << "] = " << pai[v] << endl;

	}

	return 0;
}
