#include <iostream>

using namespace std;

void merge(int *V, int inicio, int meio, int fim)
{
	int *temp;
	int p1, p2, tamanho;

	tamanho = fim - inicio + 1;
	temp = new int[tamanho]; // Cria vetor temporario para receber os vetores sendo combinado

	p1 = inicio;
	p2 = meio + 1;

	if (temp != NULL)
	{
		int i = 0;
		// Faz a mesclagem entre os dois subvetores [inicio, meio] e [meio+1, fim]
		while (p1 <= meio && p2 <= fim)
		{
			if (V[p1] < V[p2])
			{
				temp[i] = V[p1];
				i++;
				p1++;
			}
			else
			{
				temp[i] = V[p2];
				i++;
				p2++;
			}
		}

		// Copia os valores que sobraram do subvetor da esquerda, caso ainda tenha...
		while (p1 <= meio)
		{
			temp[i] = V[p1];
			i++;
			p1++;
		}

		// Copia os valores que sobraram do subvetor da direita, caso ainda tenha...
		while (p2 <= fim)
		{
			temp[i] = V[p2];
			i++;
			p2++;
		}

		// Transfere os elementos de Temp para o Vetor original
		for (int j = 0, k = inicio; j < tamanho; j++, k++)
		{
			V[k] = temp[j];
		}
	}

	delete[] temp;
}

void mergeSort(int *V, int inicio, int fim)
{
	int meio;

	if (inicio < fim)
	{
		meio = (inicio + fim) / 2;
		mergeSort(V, inicio, meio);
		mergeSort(V, meio + 1, fim);
		merge(V, inicio, meio, fim);
	}
}

int main()
{

	int vetor[] = {67, 72, 13, 1, 2, 91, 23, 97};

	int tam = sizeof(vetor) / sizeof(int);

	cout << "Valor do array antes da ordenacao." << endl;
	for (int i = 0; i < tam; i++)
	{
		cout << vetor[i] << " ";
	}
	cout << endl;

	mergeSort(vetor, 0, tam - 1);

	cout << "Valor do array apos a ordenacao." << endl;
	for (int i = 0; i < tam; i++)
	{
		cout << vetor[i] << " ";
	}
	cout << endl; 

	return 0;
}
