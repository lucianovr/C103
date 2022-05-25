#include "Grafo.h"
#include "Fila.h"
#include <iostream>
#include <algorithm>

using namespace std;

Grafo::Grafo(bool _digrafo, int _numVertices)
{
	cout << "\nConstruindo o grafo\n";
	cout << "  Vertices = " << _numVertices << endl;
	cout << "  digrafo  = " << _digrafo << endl;

	digrafo = _digrafo;
	numVertices = _numVertices;
	listaAdj = new list<Aresta>[numVertices];
}

Grafo::~Grafo()
{
	cout << "\nDeletando o grafo\n";
	for (int v = 0; v < numVertices; v++)
	{
		listaAdj[v].clear();
	}
	delete[] listaAdj;
	digrafo = false;
	numVertices = 0;
}

void Grafo::insereAresta(int origem, int destino, int custo)
{
	cout << "\nInserindo aresta " << origem << " - " << destino << endl;

	if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices)
	{
		cout << "ERROR: argumentos invalidos\n";
		return;
	}

	listaAdj[origem].push_back( Aresta(destino, custo) );

	if ((digrafo == false) && (origem != destino))
	{
		listaAdj[destino].push_back( Aresta(origem, custo) );
	}
}

void Grafo::removeAresta(int origem, int destino, bool removeArestaInversa=false)
{
	cout << "\nRemovendo aresta " << origem << "-" << destino << endl;

	for (list<Aresta>::iterator it = listaAdj[origem].begin(); it != listaAdj[origem].end(); )
	{
		if (it->v == destino)
		{
			it = listaAdj[origem].erase(it);
		}
		else
		{
			it++;
		}
	}

	if (digrafo == false && removeArestaInversa == true)
	{
		removeAresta(destino, origem);
	}
}

void Grafo::mostraArestas(void)
{
	cout << "\nLista de Adjacencias\n";

	for (int v = 0; v < numVertices; v++)
	{
		cout << v << ": ";
		for (list<Aresta>::iterator it = listaAdj[v].begin(); it != listaAdj[v].end(); it++)
		{
			cout << "(" << it->v << "," << it->peso << ") ";
		}
		cout << endl;
	}
}

void Grafo::dijkstra(int vInicio, int* dist, size_t dist_tam)
{
	cout << "\n\n INICIO Dijkstra" << endl;
	if (dist_tam < numVertices)
	{
		cout << "ERROR: tamanho do vetor distancia eh incompativel com a quantidade de vertices do Grafo";
		return;
	}

	bool* visitado = new bool[numVertices];

	for (int v = 0; v < numVertices; v++)
	{
		dist[v] = INT32_MAX;
		visitado[v] = false;
	}

	dist[vInicio] = 0;

	int counter = 1;
	while ( true )
	{
		// Procura um vertice ainda nao visitado que possua a menor distancia atual.
		cout << "\nIteracao: " << counter++ << endl;
		cout << "Procurando um vertice ainda nao visitado e que tenha a menor distancia\n";
		int v = -1;
		int min_dist = INT32_MAX;
		for (int x = 0; x < numVertices; x++)
		{
			if (visitado[x] == false && dist[x] < min_dist)
			{
				min_dist = dist[x];
				v = x;
			}
		}

		if (min_dist == INT32_MAX)
		{
			cout << "Todos os vertices ja foram processados\n";
			break;
		}

		cout << "Encontrado " << v << endl;
		visitado[v] = true;

		// Atualizando distancias
		for (list<Aresta>::iterator it = listaAdj[v].begin(); it != listaAdj[v].end(); it++)
		{
			int w = it->v;
			int custo_vw = it->peso;

			cout << "  Aresta: " << v << " -> " << w << " com custo " << custo_vw << endl;

			if (dist[w] > dist[v] + custo_vw)
			{
				dist[w] = dist[v] + custo_vw;
				cout << "Atualizado a distancia de " << w << " para " << dist[w] << endl;
			}
		}
	}
	delete[] visitado;

	cout << "\nFIM Dijkstra\n\n";
}
