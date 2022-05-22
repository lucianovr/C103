#pragma once

#include <list>

using namespace std;

#define BRANCO	(0)	// Vértice não descoberto
#define CINZA	(1)	// Vértice em processamento
#define PRETO	(2)	// Vértice processado

class Grafo
{
private:
	int numVertices;
	bool digrafo;
	list<int>* listaAdj;

	// Função usada internamente pela DFS
	void buscaProfundidade_interna(int v);
	
	// Ponteiro para um vetor que será usado internamente pela DFS e BFS
	// representando o estado do vértice durante a busca.
	int* cor;

	// Ponteiro para um vetor que irá armazenar as distâncias de um vértice
	// para os outros do Grafo.
	int* dist;

public:
	Grafo(bool _digrafo, int _numVertices);
	~Grafo();
	void insereAresta(int origem, int destino);
	void removeAresta(int origem, int destino);
	void mostraArestas(void);

	void buscaProfundidade();
	void buscaLargura(int vInicio);
};

