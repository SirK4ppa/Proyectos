#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#define Max 100
using namespace std;

void Menu();
int MatrizAdyacente[Max][Max];

class NodoA {
public:
    int ady;
    int peso;
    NodoA* siguiente;
    NodoA(int v, int p, NodoA* sig = NULL)
    {
        ady = v;
        peso = p;
        siguiente = sig;
    }
};

struct Nodo {
public:
    int vertice;
    string Texto;
    NodoA* puntero;
    Nodo* siguiente;
    Nodo(int v, string TEXTO_h, Nodo* sig = NULL, NodoA* punt = NULL)
    {
        vertice = v;
        Texto = TEXTO_h;
        siguiente = sig;
        puntero = punt;
    }

    class Lista;
};

typedef Nodo* PNodo; //NUEVO PUNTERO

class Lista {
public:
    PNodo primero, NodoAct, NAux;

    Lista() { primero = NULL; }

    void InsertarV(int v, string TEXTO_h);
    bool ListaVacia();
    PNodo Buscarv(int v);
    bool listavexistente(int i, int f);
    void creararco(int i, int f, int peso);
    void CrearMatriz();
    void mostrarmatriz();
    int CantidadVertices();
    int ExisteArco(int i, int f);
    bool BuscarAdy(PNodo aux, int ad);
};

void Lista::creararco(int i, int f, int peso) {
    PNodo pos;
    pos = primero;
    if (listavexistente(i, f))
    {
        while (pos != NULL)
        {
            if (i == pos->vertice)
            {
                if (pos->puntero == NULL)
                {
                    pos->puntero = new NodoA(f, peso);
                }
                else
                {
                    NodoA* temp = pos->puntero;
                    while (temp->siguiente != NULL)
                    {
                        temp = temp->siguiente;
                    }
                    temp->siguiente = new NodoA(f, peso);
                    temp = NULL;
                    delete temp;
                }
            }
            pos = pos->siguiente;
        }
    }
}

bool Lista::listavexistente(int i, int f)
{
    if (Buscarv(i) != NULL && Buscarv(f) != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Lista::InsertarV(int v, string TEXTO_h)
{
    PNodo anterior;
    if (ListaVacia())
    {
        primero = new Nodo(v, TEXTO_h, primero);
    }
    else
    {
        if (v <= primero->vertice)
        {
            primero = new Nodo(v, TEXTO_h, primero);
        }
        else
        {
            anterior = primero;
            while ((anterior->siguiente) && (anterior->siguiente->vertice <= v))
            {
                anterior = anterior->siguiente;
            }
            anterior->siguiente = new Nodo(v, TEXTO_h, anterior->siguiente);
        }
    }
}

bool Lista::ListaVacia()
{
    return primero == NULL;
}

int Lista::CantidadVertices()
{
    PNodo Nodo = primero;
    int i = 0;
    while (Nodo != NULL)
    {
        i++;
        Nodo = Nodo->siguiente;
    }
    return i;
}

int Lista::ExisteArco(int i, int f)
{
    PNodo Nodo;
    int a = 1;
    Nodo = Buscarv(i);
    if (Nodo)
    {
        if (BuscarAdy(Nodo, f))
        {
            return a;
        }
        else
        {
            return a = 0;
        }
    }
}

bool Lista::BuscarAdy(PNodo aux, int ad)
{
    NodoA* temp = aux->puntero;
    bool a;
    while (temp)
    {
        if (ad == temp->ady)
        {
            return a = true;
        }
        temp = temp->siguiente;
    }
    return a = false;
}

PNodo Lista::Buscarv(int valor)
{
    int z = 0;
    PNodo indice, n = NULL;
    indice = primero;
    while (indice != NULL)
    {
        if (valor == indice->vertice)
        {
            //cout<<endl<<"Valor encontrado"<<endl;
            return indice;
        }
        indice = indice->siguiente;
    }
    cout << endl << "Valor NO encontrado" << endl;
    return n;
}

void Lista::CrearMatriz()
{
    PNodo Nodo = primero, Nodotemp;
    int i, j, inicio = 0, fin = 0;
    int cant = CantidadVertices();

    for (i = 0; i < cant; i++)
    {
        Nodotemp = primero;
        for (j = 0; j < cant; j++)
        {
            MatrizAdyacente[i][j] = ExisteArco(Nodo->vertice, Nodotemp->vertice);
            Nodotemp = Nodotemp->siguiente;
        }
        Nodo = Nodo->siguiente;
    }
    delete Nodo;
    delete Nodotemp;
}

void Lista::mostrarmatriz()
{
    int i, j, cant;
    PNodo Nodo = primero;
    cant = CantidadVertices();
    cout << "   ";

    for (i = 0; i < cant; i++)
    {
        cout << "\t" << Nodo->vertice << " ";
        Nodo = Nodo->siguiente;
    }
    Nodo = primero;
    cout << "\n\n";

    for (i = 0; i < cant; i++)
    {
        cout << Nodo->vertice;
        for (j = 0; j < cant; j++)
        {
            cout << "\t" << MatrizAdyacente[i][j] << " ";

        }
        Nodo = Nodo->siguiente;
        cout << "\n";
    }
}

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile("icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    int grafoRecorrido = 0;
    Lista L;
    L.InsertarV(1, "Tu dia");
    L.InsertarV(2, "Ves que puedes hacer en tu dia de vacaciones");
    L.InsertarV(3, "Puedes salir a la calle o jugar videojuegos");
    L.InsertarV(4, "Quieres jugar pero al mismo tiempo salir a la calle");
    L.InsertarV(5, "Pensando si completar al 100% tus juegos, es viable");
    L.InsertarV(6, "Pensando seriamente que comprar para desayunar");
    L.InsertarV(7, "Cuestionandote si deberias de perder el tiempo jugando videojuegos");
    L.InsertarV(8, "Finalmente llegaste a jugar videojuegos sin haber comprado mas videojuegos");
    L.InsertarV(9, "Cuestionandote si deberias de perder el tiempo jugando videojuegos");
    L.InsertarV(10, "En GamePlanet hay una buena cantidad, de juegos, pero no sabes que comprar...");
    L.InsertarV(11, "FIN, \n\nIngrese 12 para regresar al menú");
    L.InsertarV(12, "...");
    L.creararco(1, 2, 1);
    L.creararco(2, 1, 1);
    L.creararco(1, 6, 2);
    L.creararco(6, 1, 2);
    L.creararco(2, 3, 3);
    L.creararco(3, 2, 3);
    L.creararco(2, 4, 4);
    L.creararco(4, 2, 4);
    L.creararco(4, 5, 5);
    //L.creararco(5,4,5);
    L.creararco(3, 5, 6);
    //L.creararco(5,3,6);
    L.creararco(5, 10, 7);
    //L.creararco(10,5,7);
    L.creararco(6, 7, 8);
    L.creararco(7, 6, 8);
    L.creararco(6, 8, 9);
    L.creararco(8, 6, 9);
    L.creararco(7, 9, 10);
    //L.creararco(9,7,10);
    L.creararco(8, 9, 11);
    //L.creararco(9,8,11);
    L.creararco(9, 10, 12);
    //L.creararco(10,9,12);
    L.creararco(10, 11, 13);
    L.creararco(11, 10, 13);
    L.creararco(11, 12, 14);
    L.creararco(12, 11, 14);
    L.CrearMatriz();
    L.mostrarmatriz();

    L.NodoAct = L.primero;

    // Load a sprite to display
    sf::Font font;
    if (!font.loadFromFile("Sansation_Regular.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text opciones(L.NodoAct->Texto, font);
    opciones.setCharacterSize(20);
    opciones.setStyle(sf::Text::Bold);
    opciones.setFillColor(sf::Color::White);
    opciones.setPosition(0, 0);

    sf::Texture Background;
    Background.loadFromFile("1.jpeg");
    sf::Sprite historia(Background);
    sf::Vector2u Size1 = Background.getSize();
    historia.setPosition(0, 30);





    struct Botones
    {
        sf::Texture btnOpcion_7;
        sf::Sprite Opcion_7;
        sf::Vector2u Size7;

    };

    int nivel = 0;
    bool desicion = false;

    Botones Buttons[12];
    Buttons[0].btnOpcion_7.loadFromFile("boton1.jpeg");
    Buttons[0].Opcion_7.setTexture(Buttons[0].btnOpcion_7);
    Buttons[0].Size7 = Buttons[0].btnOpcion_7.getSize();
    Buttons[0].Opcion_7.setPosition(170, 100);

    Buttons[1].btnOpcion_7.loadFromFile("boton2.jpeg");
    Buttons[1].Opcion_7.setTexture(Buttons[1].btnOpcion_7);
    Buttons[1].Size7 = Buttons[1].btnOpcion_7.getSize();
    Buttons[1].Opcion_7.setPosition(170, 200);

    Buttons[2].btnOpcion_7.loadFromFile("boton3.jpeg");
    Buttons[2].Opcion_7.setTexture(Buttons[2].btnOpcion_7);
    Buttons[2].Size7 = Buttons[2].btnOpcion_7.getSize();
    Buttons[2].Opcion_7.setPosition(670, 200);

    Buttons[3].btnOpcion_7.loadFromFile("boton4.jpeg");
    Buttons[3].Opcion_7.setTexture(Buttons[3].btnOpcion_7);
    Buttons[3].Size7 = Buttons[3].btnOpcion_7.getSize();
    Buttons[3].Opcion_7.setPosition(550, 400);

    Buttons[4].btnOpcion_7.loadFromFile("boton5.jpeg");
    Buttons[4].Opcion_7.setTexture(Buttons[4].btnOpcion_7);
    Buttons[4].Size7 = Buttons[4].btnOpcion_7.getSize();
    Buttons[4].Opcion_7.setPosition(670, 100);

    Buttons[5].btnOpcion_7.loadFromFile("boton6.jpeg");
    Buttons[5].Opcion_7.setTexture(Buttons[5].btnOpcion_7);
    Buttons[5].Size7 = Buttons[5].btnOpcion_7.getSize();
    Buttons[5].Opcion_7.setPosition(340, 200);

    Buttons[6].btnOpcion_7.loadFromFile("boton7.jpeg");
    Buttons[6].Opcion_7.setTexture(Buttons[6].btnOpcion_7);
    Buttons[6].Size7 = Buttons[6].btnOpcion_7.getSize();
    Buttons[6].Opcion_7.setPosition(550, 200);

    Buttons[7].btnOpcion_7.loadFromFile("boton8.jpeg");
    Buttons[7].Opcion_7.setTexture(Buttons[7].btnOpcion_7);
    Buttons[7].Size7 = Buttons[7].btnOpcion_7.getSize();
    Buttons[7].Opcion_7.setPosition(150, 300);

    Buttons[8].btnOpcion_7.loadFromFile("boton9.jpeg");
    Buttons[8].Opcion_7.setTexture(Buttons[8].btnOpcion_7);
    Buttons[8].Size7 = Buttons[8].btnOpcion_7.getSize();
    Buttons[8].Opcion_7.setPosition(500, 400);

    Buttons[9].btnOpcion_7.loadFromFile("boton10.jpeg");
    Buttons[9].Opcion_7.setTexture(Buttons[9].btnOpcion_7);
    Buttons[9].Size7 = Buttons[9].btnOpcion_7.getSize();
    Buttons[9].Opcion_7.setPosition(340, 400);

    Buttons[10].btnOpcion_7.loadFromFile("boton11.jpeg");
    Buttons[10].Opcion_7.setTexture(Buttons[10].btnOpcion_7);
    Buttons[10].Size7 = Buttons[10].btnOpcion_7.getSize();
    Buttons[10].Opcion_7.setPosition(500, 500);

    Buttons[11].btnOpcion_7.loadFromFile("boton12.jpeg");
    Buttons[11].Opcion_7.setTexture(Buttons[11].btnOpcion_7);
    Buttons[11].Size7 = Buttons[11].btnOpcion_7.getSize();
    Buttons[11].Opcion_7.setPosition(340, 400);

    for (int i = 0; i < L.CantidadVertices(); i++) {
        if (MatrizAdyacente[L.NodoAct->vertice - 1][i] == 1) {
            L.NAux = L.primero;
            for (int j = 0; j < i; j++)
            {
                L.NAux = L.NAux->siguiente;
            }


            cout << "\n" << L.NAux->Texto;
        }
    }

    string texto = "Tu dia";
    while (window.isOpen())
    {

        opciones.setString(texto);
        cout << L.NodoAct->Texto;
        system("pause");


        for (int i = 0; i < L.CantidadVertices(); i++) {
            MatrizAdyacente[i][L.NodoAct->vertice - 1] = 0;
        }

        /*if (grafoRecorrido == 5) {
            delay(4);
            opciones.setString("");
            Background.loadFromFile("FIN.jpg");
            historia.setPosition(80, 60);
        }*/

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i position;
                    position = sf::Mouse::getPosition(window);

                    //corresponde nodo 2
                    if (Buttons[0].Opcion_7.getGlobalBounds().contains(position.x, position.y) && nivel == 0)
                    {
                        grafoRecorrido++;

                        L.NodoAct = L.primero;

                        L.NodoAct = L.NodoAct->siguiente;
                        cout << L.NodoAct->vertice;


                        Background.loadFromFile("2.jpeg");
                        cout << L.NodoAct->Texto;
                        cout << "boton 0";
                        system("pause");
                        texto = "Pensando que hacer en tu primer dia de vacas";
                        nivel = 1;
                        desicion = true;




                    }

                    if (Buttons[1].Opcion_7.getGlobalBounds().contains(position.x, position.y))
                    {
                        grafoRecorrido++;
                        L.NodoAct = L.primero;

                        for (int i = 0; i < 2; i++) {
                            L.NodoAct = L.NodoAct->siguiente;
                        }

                        cout << L.NodoAct->vertice;

                        Background.loadFromFile("3.jpeg");
                        cout << L.NodoAct->Texto;
                        cout << "Agusto";
                        texto = "Estas de vacaciones";
                        nivel = 2;
                        system("pause");




                    }

                    if (Buttons[2].Opcion_7.getGlobalBounds().contains(position.x, position.y))
                    {
                        grafoRecorrido++;
                        L.NodoAct = L.primero;

                        for (int i = 0; i < 3; i++) {
                            L.NodoAct = L.NodoAct->siguiente;
                        }

                        cout << L.NodoAct->vertice;

                        Background.loadFromFile("3.jpeg");
                        cout << "En tu casa";
                        texto = "Quieres jugar, pero al mismo tiempo salir a la calle";
                        nivel = 2;




                    }

                    if (Buttons[3].Opcion_7.getGlobalBounds().contains(position.x, position.y))
                    {
                        grafoRecorrido++;
                        L.NodoAct = L.primero;

                        for (int i = 0; i < 4; i++) {
                            L.NodoAct = L.NodoAct->siguiente;
                        }

                        cout << L.NodoAct->vertice;

                        Background.loadFromFile("5.jpeg");

                    }

                    //corresponde al nodo 6
                    if (Buttons[4].Opcion_7.getGlobalBounds().contains(position.x, position.y))
                    {
                        grafoRecorrido++;
                        L.NodoAct = L.primero;

                        for (int i = 0; i < 5; i++) {
                            L.NodoAct = L.NodoAct->siguiente;
                        }

                        cout << L.NodoAct->vertice;

                        Background.loadFromFile("5.jpeg");
                        texto = "Pensando seriamente que comprar para desayunar";
                        nivel = 1;


                    }

                    if (Buttons[5].Opcion_7.getGlobalBounds().contains(position.x, position.y))
                    {
                        grafoRecorrido++;
                        L.NodoAct = L.primero;

                        for (int i = 0; i < 5; i++) {
                            L.NodoAct = L.NodoAct->siguiente;
                        }

                        cout << L.NodoAct->vertice;

                        Background.loadFromFile("6.jpeg");
                        texto = "Pensando si completar al 100% tus juegos, es viable";
                        cout << "LEGOS";
                        nivel = 2;


                    }

                    if (Buttons[6].Opcion_7.getGlobalBounds().contains(position.x, position.y))
                    {
                        grafoRecorrido++;
                        L.NodoAct = L.primero;

                        for (int i = 0; i < 5; i++) {
                            L.NodoAct = L.NodoAct->siguiente;
                        }

                        cout << L.NodoAct->vertice;

                        Background.loadFromFile("6.jpeg");
                        texto = "Cuestionandote si deberias de perder el tiempo jugando videojuegos";
                        cout << "CoD MW 2.0";
                        nivel = 2;


                    }

                    if (Buttons[7].Opcion_7.getGlobalBounds().contains(position.x, position.y))
                    {
                        grafoRecorrido++;
                        L.NodoAct = L.primero;

                        for (int i = 0; i < 5; i++) {
                            L.NodoAct = L.NodoAct->siguiente;
                        }

                        cout << L.NodoAct->vertice;

                        Background.loadFromFile("4.jpeg");
                        texto = "En GamePlanet hay una buena cantidad, de juegos, pero no sabes que comprar...";
                        nivel = 3;

                    }

                    if (Buttons[8].Opcion_7.getGlobalBounds().contains(position.x, position.y))
                    {
                        grafoRecorrido++;
                        L.NodoAct = L.primero;

                        for (int i = 0; i < 5; i++) {
                            L.NodoAct = L.NodoAct->siguiente;
                        }

                        cout << L.NodoAct->vertice;

                        Background.loadFromFile("7.jpeg");
                        texto = "Finalmente llegaste a jugar videojuegos sin haber comprado mas videojuegos";
                        nivel = 4;

                    }

                }
            }
        }

        window.clear();

        window.draw(historia);

        /* for (int i = 0; i < L.CantidadVertices(); i++) {
             if (MatrizAdyacente[L.NodoAct->vertice - 1][i] == 1) {
                 window.draw(Buttons[i-1].Opcion_7);

             }
         }*/
        switch (nivel)
        {
        case 0:
            window.draw(Buttons[0].Opcion_7);
            window.draw(Buttons[4].Opcion_7);
            break;
        case 1:
            if (desicion == true) {
                window.draw(Buttons[1].Opcion_7);
                window.draw(Buttons[2].Opcion_7);
                cout << "Nivel 1 Verdadero";
            }
            else {
                window.draw(Buttons[5].Opcion_7);
                window.draw(Buttons[6].Opcion_7);
                cout << "Nivel 1 falso";
            }
            break;
        case 2:
            window.draw(Buttons[7].Opcion_7);
            break;
        case 3:
            window.draw(Buttons[8].Opcion_7);
            break;
        }

        window.draw(opciones);



        window.display();
    }



    return 0;
    return EXIT_SUCCESS;
}