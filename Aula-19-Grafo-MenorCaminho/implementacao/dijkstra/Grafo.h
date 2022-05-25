#pragma once

#include <list>

using namespace std;

#define BRANCO	(0)	// Vértice não descoberto
#define CINZA	(1)	// Vértice em processamento
#define PRETO	(2)	// Vértice processado

struct Aresta {
	int v;
	int peso;
	Aresta();
	Aresta(int _v, int _peso) {
		v  = _v;
		peso = _peso;
	}
};

class Grafo
{
private:
	int numVertices;
	bool digrafo;
	list<Aresta>* listaAdj;

	// Lista auxiliar para armazenar o vertice anterior do atual durante uma busca
	int* pai; 

public:
	Grafo(bool _digrafo, int _numVertices);
	~Grafo();
	void insereAresta(int origem, int destino, int custo);
	void removeAresta(int origem, int destino, bool removeArestaInversa);
	void mostraArestas(void);

	void dijkstra(int vInicio, int* dist, size_t dist_tam);
	void getMinPath(int destino, int* caminho, int* caminho_tam);
};

