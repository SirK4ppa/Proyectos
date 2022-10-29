//Akinator para mamados >:)
#include <iostream>
#include <string.h>
using namespace std;

class Nodo {
public:
    int identificador;
    string pregunta;
    Nodo* y;
    Nodo* n;

    Nodo() {}
    ~Nodo()
    {
        delete n;
        delete y;
    }
};

class Akinator {

public:

    int posicion = 0, respuesta;
    Akinator() {}
    ~Akinator() {}

    //NODO PRINCIPAL (Se maneja por ai di)
    Nodo* cNodo(int id, string res) {
        Nodo* n_nodo = new Nodo();

        n_nodo->pregunta = res;
        n_nodo->y = NULL;
        n_nodo->n = NULL;
        n_nodo->identificador = id;
        return n_nodo;
    }

    //Metemos el identificador y punteros para los nodos 
    void iNodo(Nodo*& a, int id, string res) {
        if (a == NULL) {
            Nodo* n_nodo = cNodo(id, res);
            a = n_nodo;
        }
        else {
            if (a->identificador < id) {
                iNodo(a->y, id, res);
            }
            else if (a->identificador > id) {
                iNodo(a->n, id, res);
            }
        }
    }

    //Los movimientos que harán los nodos
    void mNodo(Nodo* nodo)
    {
        if (nodo == NULL)
            return;
        if (nodo->n != NULL)
        {
            posicion++;
            mNodo(nodo->n);
            posicion--;
        }
        for (int n = 0; n < posicion; n++)
        {
            cout << "";
        }

        if (nodo->y != NULL)
        {
            posicion++;
            mNodo(nodo->y);
            posicion--;
        }

    }

    void jNodo(Nodo* nodo)
    {
        if (nodo == NULL)
            return;
        //Preguntas y movimientos de Si y No
        if ((nodo->y != NULL) || (nodo->n != NULL))
        {
            cout << nodo->pregunta << endl;
            cout << endl << "1. SI" << endl;
            cout << "2. NO" << endl;
            cout << endl << "Ingrese la respuesta: ";
            cin >> respuesta;

            if (respuesta == 1)
            {
                posicion++;
                jNodo(nodo->y);
                posicion--;
            }
            if(respuesta == 2)
            {
                posicion++;
                jNodo(nodo->n);
                posicion--;
            }
        }
                //En caso de no encontrar el musculo...
        else
        {
            cout << nodo->pregunta << endl;
            int n;
            cout << endl << "Estabas pensando en este grupo muscular?:\n1. SI (Se reiniciara)\n2.- NO (Agregaras el grupo muscular)\nR: ";
            cin >> n;

            if (n != 1)
            {
                string nPersonaje, pregunta2;
                short position;

                cin.ignore();
                cout << endl << "En que grupo muscular estabas pensando? ";
                cin >> nPersonaje;
                cout << endl << endl << "Que pregunta puedo hacer para coincidir con tu respuesta? ";
                cin >> pregunta2;
                cout << endl << "Con que respuesta puedo tu grupo muscular?: ";
                cout << endl << "1. SI" << endl;
                cout << "2. NO" << endl;
                cin >> position;

                if (position == 2)
                {
                    nodo->n = cNodo(nodo->identificador - 1, nPersonaje);
                    nodo->y = cNodo(nodo->identificador + 1, nodo->pregunta);
                }

                else
                {
                    nodo->n = cNodo(nodo->identificador - 1, nodo->pregunta);
                    nodo->y = cNodo(nodo->identificador + 1, nPersonaje);
                }
                nodo->pregunta = pregunta2;
            }
        }
    }

};


int main() {
    cout << "\t\tBienvenido al Akinator de grupos musculares\n\t\tAquel que sabe que quieres ejercitar...";
    cout << "\n\n\t\t\tPosibles respuestas:\n\t\tPecho\t\tBiceps\t\tTriceps\n\t\tEspalda\t\tAbdomen\t\tHombros\n\t\t";
    cout << "Femoral\t\tCuadriceps\tPantorrilla\n\t\tIsquios\t\tGluteo\n\n\t\t| Empecemos con las preguntas |\n\n";
    system("pause");
    // opciones();
    Nodo* a = NULL;

    Akinator akinator = Akinator();
    a = akinator.cNodo(100, "Es de tren superior?");
    akinator.iNodo(a, 40, "Se necesita para empujar?");
    akinator.iNodo(a, 52, "Es para pierna?");
    akinator.iNodo(a, 60, "Extiendes la pierna?");
    akinator.iNodo(a, 30, "Beneficia mucho estimularlo con el peso muerto?");
    akinator.iNodo(a, 36, "El principal ejercicio para estimular es el hip thrust?");
    akinator.iNodo(a, 25, "Tu grupo muscular esta debajo de la pierna?");
    akinator.iNodo(a, 66, "Tu ejercicio es para cuadriceps");
    akinator.iNodo(a, 55, "Tu grupo muscular son los isquios");
    akinator.iNodo(a, 39, "Tu grupo muscular es el gluteo");
    akinator.iNodo(a, 33, "Tu grupo muscular es el femoral");
    akinator.iNodo(a, 28, "Tu grupo muscular es la pantorrilla");
    akinator.iNodo(a, 20, "Tu grupo muscular es el gluteo");


    akinator.iNodo(a, 160, "Trabajas el tronco?");
    akinator.iNodo(a, 170, "Empujas para estimular?");
    akinator.iNodo(a, 175, "Une a los brazos al cuerpo?");
    akinator.iNodo(a, 140, "Trabajas extremidades?");
    akinator.iNodo(a, 147, "Trabajas empujando?");
    akinator.iNodo(a, 130, "Contraes para ejercitar?");
    akinator.iNodo(a, 179, "Tu grupo muscular son los hombros");
    akinator.iNodo(a, 173, "Tu grupo muscular es el pecho");
    akinator.iNodo(a, 161, "Jalas para estimular?");
    akinator.iNodo(a, 162, "Tu grupo muscular es la espalda");
    akinator.iNodo(a, 150, "Tu grupo muscular son los triceps");
    akinator.iNodo(a, 144, "Tu grupo muscular son los biceps");
    akinator.iNodo(a, 135, "Tu grupo muscular es el abdomen");
    
    //Que limpie tras adivinar o no adivinar

    while (true)
    {
        system("cls");
        akinator.mNodo(a);
        akinator.jNodo(a);
    }
    system("pause");
    return 0;
}