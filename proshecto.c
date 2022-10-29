#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
	int valor;
	char pregunta[70];
	struct nodo *izq;
	struct nodo *der;
} nodo;
nodo* pNodo(nodo*, int, char[]);
void corre(nodo *);
void corre(nodo* raiz) {
	int opc;
	if (raiz == NULL)
		printf("\n");
	while (raiz != NULL) {
		if (raiz->izq == NULL && raiz->der == NULL)
		{
			cout << raiz->pregunta;
			break;
		}
		cout << endl << raiz->pregunta;
		cout << "Para responder si, digite 1 y para responder no, digite 2";
		cin >> opc;
		if (opc == 2) {
			if (raiz->izq != NULL)
				raiz = raiz->izq;
		}
		else {
			if (raiz->der != NULL)
				raiz = raiz->der;
		}
	}
}

int main() {
	cout << "\t\t\t\t\tBienvenidos a Akinator, proyecto de parcial 2...\n\t\t\t\t\t\t Adivinador de ejercicios\n\n\t\t\t\t\tEjercicios \t\ta \t\tadivinar...\n\n";
	//Tren superior, tronco, barra, banco, inclinaciones
	cout << "\tPress de banca\t\t\t\tPress de banca inclinado\t\tPress de banca declinado\n";
	//Tren superior, tronco, poleas, direccion
	cout << "\tCruce de poleas medio\t\t\tCruce de poleas alto\t\t\tCruce de poleas bajo\n";
	//Tren inferior, ejercicio compuesto, maquina, posición y barra
	cout << "\tPrensa\t\t\t\t\tSentadilla smith\t\t\tSentadilla hack\n";
	//Tren inferior, ejercicio aislado, posicion
	cout << "\tCurl de femoral sentado\t\t\tCurl de femoral acostado\t\tExtension de cuadriceps\n";
	//Tren inferior, peso libre, barra, ejercicio compuesto/aislado
	cout << "\tSentadilla libre\t\t\tSentadilla bulgara\t\t\tSentadilla recta\n";
	//Tren superior, extremidades, cabeza larga/corta, barra, antebrazo
	cout << "\tCurl de biceps\t\t\t\tCurl de biceps martillo\t\t\tCurl de biceps zottman\n";
	//Tren superior, brazos, necesidad de banco, barra, inclinacion
	cout << "\tCurl de biceps spider\t\t\tCurl de biceps inclinado\t\tCurl de biceps predicador\n";
	//Tren superior, hombros, direccion, barra
	cout << "\tLevantamientos frontales\t\tLevantamientos laterales\t\tFlies en banco\n";
	//Tren superior, hombros, poleas, maquinas, barra
	cout << "\tJalon a la cara\t\t\t\tEncogimiento de hombros\t\t\tPeck flies invertidas\n";

	nodo* ar = NULL;

	ar = pNodo(ar, 2000, "Tu ejercicio es de tren superior?");
	ar = pNodo(ar, 2500, "Tu ejercicio trabaja el tronco?");
	corre(ar);
}
nodo* pNodo(nodo* raiz, int value, char pregunta[]) {
	nodo* nuevo, aux, * anterior;
	nuevo = (nodo*)malloc(sizeof(nodo));
	if (nuevo != NULL) {
		nuevo->value = value;
		strcpy(nuevo->pregunta, pregunta);
		nuevo->izq = NULL;
		nuevo->der = NULL;
		if (raiz == NULL) {
			raiz = nuevo;
		}
		else {
			aux = raiz;
			anterior = NULL;
			while (aux != NULL); {
				anterior = aux;
				if (value < aux->value)
					aux = aux->izq;
				else if (value > aux->value)
					aux = aux->der;
				else {
					return raiz;
				}
			}
			if (value < anterior->value)
				anterior->izq = nuevo;
			else anterior->der = nuevo;
		}
	}
	else{
	}
	return raiz;
}
