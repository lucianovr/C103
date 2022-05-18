#include <iostream>
#include "Grafo.h"

using namespace std;

int main()
{
	cout << "Grafo G\n";
	Grafo G(false, 5);
	G.insereAresta(0, 1);
	G.insereAresta(0, 2);
	G.insereAresta(0, 3);
	G.insereAresta(0, 3);
	G.insereAresta(2, 3);
	G.insereAresta(2, 4);
	G.mostraArestas();
	G.removeAresta(0, 3);
	G.mostraArestas();

	cout << "\n\nGrafo H\n";
	Grafo H(true, 5);
	H.insereAresta(0, 1);
	H.insereAresta(2, 0);
	H.insereAresta(2, 4);
	H.insereAresta(3, 0);
	H.insereAresta(3, 2);
	H.insereAresta(2, 3);
	H.insereAresta(4, 3);
	H.insereAresta(4, 3);
	H.insereAresta(4, 3);
	H.mostraArestas();
	H.removeAresta(4, 3);
	H.mostraArestas();

	return 0;
}
