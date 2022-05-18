#pragma once

#include <list>

using namespace std;

class Grafo
{
private:
	int numVertices;
	bool digrafo;
	list<int>* listaAdj;

public:
	Grafo(bool _digrafo, int _numVertices);
	~Grafo();
	void insereAresta(int origem, int destino);
	void removeAresta(int origem, int destino);
	void mostraArestas(void);
};
