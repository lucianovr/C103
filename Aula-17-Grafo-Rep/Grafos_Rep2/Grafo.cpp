#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(bool _digrafo, int _numVertices)
{
	cout << "\nConstruindo o grafo\n";
	cout << "  Vertices = " << _numVertices << endl;
	cout << "  digrafo  = " << _digrafo << endl;

	digrafo = _digrafo;
	numVertices = _numVertices;
	listaAdj = new list<int>[numVertices];
}

Grafo::~Grafo()
{
	cout << "\nDeletando o grafo\n";
	for (int v = 0; v < numVertices; v++)
	{
		listaAdj[v].clear();
	}
	delete [] listaAdj;
	digrafo = false;
	numVertices = 0;
}

void Grafo::insereAresta(int origem, int destino)
{
	cout << "\nInserindo aresta " << origem << " - " << destino << endl;
	listaAdj[origem].push_back(destino);

	if ( (digrafo == false) && (origem != destino))
	{
		listaAdj[destino].push_back(origem);
	}
}

void Grafo::removeAresta(int origem, int destino)
{
	cout << "\nRemovendo aresta " << origem << "-" << destino << endl;

	listaAdj[origem].remove(destino);

	if (digrafo == false)
	{
		listaAdj[destino].remove(origem);
	}
}

void Grafo::mostraArestas(void)
{
	cout << "\nLista de Adjacencias\n";

	for (int v = 0; v < numVertices; v++)
	{
		cout << v << ": ";
		for (list<int>::iterator it = listaAdj[v].begin(); it != listaAdj[v].end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}
