#include "Grafo.h"
#include "Fila.h"

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
	cor = new int[numVertices];
	dist = new int[numVertices];
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

void Grafo::insereAresta(int origem, int destino)
{
	cout << "\nInserindo aresta " << origem << " - " << destino << endl;
	listaAdj[origem].push_back(destino);

	if ((digrafo == false) && (origem != destino))
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

void Grafo::buscaProfundidade_interna(int v) {
	cout << "Inicio DFS v: " << v << endl;
	cor[v] = CINZA;

	for (list<int>::iterator it = listaAdj[v].begin(); it != listaAdj[v].end(); it++)
	{
		int w = *it;
		cout << "  Aresta: " << v << " - " << w << endl;
		if (cor[w] == BRANCO)
		{
			cout << "  Vertice " << w << " eh BRANCO, chamando DFS para ele" << endl;
			buscaProfundidade_interna(w);
		}
		// Apenas logs
		else if (cor[w] == CINZA)
		{
			cout << "  Vertice " << w << " eh CINZA, em processamento\n";
		}
		else // PRETO
		{
			cout << "  Vertice " << w << " eh PRETO, ja foi processado\n";
		}
	}

	cor[v] = PRETO;
	cout << "Fim DFS v: " << v << endl;
}

void Grafo::buscaProfundidade()
{
	for (int v = 0; v < numVertices; v++)
	{
		cor[v] = BRANCO;
	}

	for (int v = 0; v < numVertices; v++)
	{
		if (cor[v] == BRANCO)
		{
			cout << "Chamando DFS para " << v << endl;
			buscaProfundidade_interna(v);

			cout << endl << endl;
		}
	}
}


void Grafo::buscaLargura(int vInicio)
{
	cout << "Busca em largura a partir do vertice " << vInicio << endl;

	Fila fila(numVertices); // Crio uma fila com a quantidade de vértices do Grafo.
	
	for (int v = 0; v < numVertices; v++)
	{
		cor[v] = BRANCO;
	}

	fila.enqueue(vInicio);
	cor[vInicio] = PRETO;
	dist[vInicio] = 0;

	while (fila.filaVazia() == false)
	{
		int v = fila.dequeue();
		cout << "Processando vertice " << v << endl;

		for (list<int>::iterator it = listaAdj[v].begin(); it != listaAdj[v].end(); it++)
		{
			int w = *it;

			cout << "  Aresta: " << v << " - " << w << endl;
			if (cor[w] == BRANCO)
			{
				fila.enqueue(w);
				cor[w] = PRETO;
				dist[w] = dist[v] + 1;
				cout << "  Vertice " << w << " eh BRANCO, adicionando na Fila" << endl;
			}
		}
	}


	cout << "Menor caminho, em numero de arestas, partindo de " << vInicio << " para os demais\n";
	for (int v = 0; v < numVertices; v++)
	{
		cout << "dist[" << v << "] = " << dist[v] << endl;
	}
}

