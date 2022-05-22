#include <iostream>
#include "Grafo.h"

using namespace std;

int main()
{

	Grafo G(false, 10);

	G.insereAresta(0, 1);
	G.insereAresta(0, 0);
	G.insereAresta(0, 2);
	G.insereAresta(1, 2);
	G.insereAresta(1, 3);
	G.insereAresta(2, 4);
	G.insereAresta(3, 5);
	G.insereAresta(5, 6);
	G.insereAresta(6, 7);
	G.insereAresta(2, 7);

	G.mostraArestas();

	G.buscaProfundidade();
	
	G.buscaLargura(0);

	return 0;
}