/*
    Proyecto de Figuras Parcial 1
    Medina Moreno Jonathan Martin || 22110166
    2P
*/

#include <iostream>
#include <conio.h>
#include "iomanip"

using namespace std;

    class FG
    {
    public:
        int Longitud;
        int CoordX;
        int CoordY;

    };

    class Triangulo : public FG
    {
    public:
        void drawTriangulo(int, int, int );
    };

    class Rectangulo : public FG 
    {
    public:
        int ancho;
        void drawRectangulo(int, int, int, int);
    };
    class Cuadrado : public FG
    {
    public:
        int Vacio;
        void drawCuadrado(int, int, int, int);

    };

    class Menu 
    {
    public:
        int opcion;
        void iniciarMenu();
    };


    Menu InputManager;
    Cuadrado objCuadrado;
    Triangulo objTriangulo;
    Rectangulo objRect;

    int main()
    {
    
        for (size_t i = 0; i < 1000000; i++)
        {
            InputManager.iniciarMenu();
        }
    
    
    }

void Menu::iniciarMenu() 
{
    system("cls");
    cout<<"Escoja una figura geometrica (Valor numerico)"<<endl<<endl<<"1.- Cuadrado"<<endl<<"2.- Triangulo"<<endl<<"3.- Rectangulo"<<endl<<"\nR = ";

    cin>>opcion; 

    if (opcion == 1)
    {
        system("cls");
        cout<<"Ingrese la longitud de su cuadrado a continuacion\n\nR = ";
        cin>>objCuadrado.Longitud;

        system("cls");
        cout<<"1.- Vacio"<<endl<<"2.- Lleno"<<endl;
        cin>>objCuadrado.Vacio;

        system("cls");
        cout<<"Ingrese una coordenada X"<<endl;
        cin>>objCuadrado.CoordX;

        system("cls");
        cout<<"Ingrese una coordenada Y"<<endl;
        cin>>objCuadrado.CoordY;

        objCuadrado.drawCuadrado(objCuadrado.Longitud, objCuadrado.Vacio, objCuadrado.CoordX, objCuadrado.CoordY);

    }

    if (opcion == 2)
    {
        system("cls");
        cout<<"Ingrese la longitud de su Triangulo a continuacion\n\nR = ";
        cin>>objTriangulo.Longitud;

        system("cls");
        cout<<"Ingrese una coordenada X"<<endl;
        cin>>objTriangulo.CoordX;

        system("cls");
        cout<<"Ingrese una coordenada Y"<<endl;
        cin>>objTriangulo.CoordY;

        objTriangulo.drawTriangulo(objTriangulo.Longitud, objTriangulo.CoordX, objTriangulo.CoordY);

    }
    if (opcion == 3)
    {
        system("cls");
        cout<<"Ingrese el largo de su rectangulo a continuacion\n\nR = ";
        cin>>objRect.Longitud;

        system("cls");
        cout<<"Ingrese el alto de su rectangulo a continuacion\n\nR = ";
        cin>>objRect.ancho;

        system("cls");
        cout<<"Ingrese una coordenada X"<<endl;
        cin>>objRect.CoordX;

        system("cls");
        cout<<"Ingrese una coordenada Y"<<endl;
        cin>>objRect.CoordY;

        objRect.drawRectangulo(objRect.Longitud, objRect.ancho, objRect.CoordX, objRect.CoordY);

    }
             

}

void Cuadrado::drawCuadrado(int Longitud, int Vacio, int CoordX, int CoordY) 
{
    for (size_t i = 0; i < 1000000; i++)
    { 
        
        system("cls");

        
        if (CoordX < 0)
        {
            CoordX = 0;
        }

        if (CoordY < 0)
        {
            CoordY = 0;
        }

        if (CoordX > 30)
        {
            CoordX = 30;
        }

        if (CoordY > 20)
        {
            CoordY = 20;
        }

        if (Vacio == 1)
        {
            for (size_t a = 0; a < Longitud + CoordY; a++)
            {
                if (a < CoordY)
                {
                    cout<<"    ";
                }
                else
                {
                    for (size_t b = 0; b < Longitud + CoordX; b++)
                    {
                        if (b < CoordX )
                        {
                            cout<<"   ";
                        }
                        else if ( b > CoordX && b != CoordX && a != CoordY && b != CoordX + Longitud -1   && a !=CoordY + Longitud -1 && a > CoordY )
                        {

                            cout<<"   ";
                        }
                        else cout<<" * ";

                    }
                }
                cout<<endl;
            }
        }

        if (Vacio == 2)
        {
            for (size_t i = 0; i < Longitud + CoordY; i++)
            {
                if (i < CoordY)
                {
                    cout<<"   ";
                }
                else
                {
                    for (size_t i = 0; i < Longitud + CoordX; i++)
                    {
                        if (i < CoordX)
                        {
                            cout<<"   ";
                        }
                        else cout<<" * ";

                    }
                }

                cout<<endl;
            }

        }

        for (size_t i = 0; i < 1000000; i++)
        {   
            char KeyWord = _getch();

            if (KeyWord == 'A' || KeyWord == 'a')
            {
                CoordX = CoordX - 1;
                objCuadrado.drawCuadrado(Longitud, Vacio, CoordX, CoordY);
            }
            if (KeyWord == 'S' || KeyWord == 's')
            {
                CoordY = CoordY + 1;
                objCuadrado.drawCuadrado(Longitud, Vacio, CoordX, CoordY);
            }
            if (KeyWord == 'D'|| KeyWord == 'd')
            {
                CoordX = CoordX + 1;
                objCuadrado.drawCuadrado(Longitud, Vacio, CoordX, CoordY);
            }
            if (KeyWord == 'W' || KeyWord == 'w')
            {   
                CoordY = CoordY - 1;
                objCuadrado.drawCuadrado(Longitud, Vacio, CoordX, CoordY);
            }

            if (KeyWord == 'L' || KeyWord == 'l')
            {

                InputManager.iniciarMenu();
            }
        }
 
    }

}

void Triangulo::drawTriangulo(int Longitud, int CoordX, int CoordY)
{

    int contador = 0;
    for (size_t i = 0; i < 1000000; i++)
    {

        system("cls");

        if (CoordX < 0)
        {
            CoordX = 0;
        }

        if (CoordY < 0)
        {
            CoordY = 0;
        }
        if (CoordX > 30)
        {
            CoordX = 30;
        }

        if (CoordY > 20)
        {
            CoordY = 20;
        }

        contador = 0;

        for (size_t a = 0; a < Longitud + CoordY; a++)
        {
            if (a < CoordY)
            {
                cout<<"    ";
            }
            else
            {
                for (size_t b = 0; b < Longitud + CoordX; b++)
                {
                    if (b < CoordX)
                    {
                        cout<<"   ";
                    }
                    else if (b > CoordX + contador)
                    {
                        cout<<"  ";
                    }
                    else
                        cout<<" * ";

                }
                contador = contador + 1;
            } 
            if (contador >= Longitud)
            {
                contador == Longitud;
            }
            cout<<endl;
        }

            

        for (size_t i = 0; i < 1000000; i++)
        {
            char KeyWord = _getch();

            if (KeyWord == 'A' || KeyWord == 'a')
            {
                CoordX = CoordX - 1;
                objTriangulo.drawTriangulo(Longitud, CoordX, CoordY);
            }
            if (KeyWord == 'S' || KeyWord == 's')
            {
                CoordY = CoordY + 1;
                objTriangulo.drawTriangulo(Longitud, CoordX, CoordY);
            }
            if (KeyWord == 'D' || KeyWord == 'd')
            {
                CoordX = CoordX + 1;
                objTriangulo.drawTriangulo(Longitud, CoordX, CoordY);
            }
            if (KeyWord == 'W' || KeyWord == 'w')
            {
                CoordY = CoordY - 1;
                objTriangulo.drawTriangulo(Longitud, CoordX, CoordY);
            }

            if (KeyWord == 'L'|| KeyWord == 'l')
            {

                InputManager.iniciarMenu();
            }
        }

    }

}

void Rectangulo::drawRectangulo(int Longitud, int ancho, int CoordX, int CoordY)
{
    for (size_t i = 0; i < 1000000; i++)
    {

        system("cls");

        if (CoordX < 0)
        {
            CoordX = 0;
        }

        if (CoordY < 0)
        {
            CoordY = 0;
        }

        if (CoordX > 30)
        {
            CoordX = 30;
        }

        if (CoordY > 20)
        {
            CoordY = 20;
        }

            for (size_t i = 0; i < ancho + CoordY; i++)
            {
                if (i < CoordY)
                {
                    cout<<"   ";
                }
                else
                {
                    for (size_t i = 0; i < Longitud + CoordX; i++)
                    {
                        if (i < CoordX)
                        {
                            cout<<"   ";
                        }
                        else cout<<" * ";

                    }
                }

                cout<<endl;
            }

        

        for (size_t i = 0; i < 1000000; i++)
        {
            
            char KeyWord = _getch();

            if (KeyWord == 'A' || KeyWord == 'a')
            {
                CoordX = CoordX - 1;
                objRect.drawRectangulo(Longitud, ancho, CoordX, CoordY);
            }
            if (KeyWord == 'S' || KeyWord == 's')
            {
                CoordY = CoordY + 1;
                objRect.drawRectangulo(Longitud, ancho, CoordX, CoordY);
            }
            if (KeyWord == 'D' || KeyWord == 'd')
            {
                CoordX = CoordX + 1;
                objRect.drawRectangulo(Longitud, ancho, CoordX, CoordY);
            }
            if (KeyWord == 'W' || KeyWord == 'w')
            {
                CoordY = CoordY - 1;
                objRect.drawRectangulo(Longitud, ancho, CoordX, CoordY);
            }

            if (KeyWord == 'L' || KeyWord == 'l')
            {
                InputManager.iniciarMenu();
            }
        }

    }

}