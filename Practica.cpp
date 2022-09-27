#include <iostream>
#include <string.h>
#include <stdlib.h>

class Fecha{        //El constructor inicializa la clase
    private:
    int dia, mes, anio, bisiesto;
    std::string cadenaFecha, transformFecha;

    public:

    void Validar()
{
    std::string ocupoFecha = cadenaFecha;
    //  Función stoi: Genera un cambio de variables tipo cadena a entero.
    transformFecha = ocupoFecha.substr(8, 9);
    dia = stoi(transformFecha);

    transformFecha = ocupoFecha.substr(5, 6);
    mes = stoi(transformFecha);

    transformFecha = ocupoFecha.substr(0, 4);
    anio = stoi(transformFecha);

    validarDias();
    validarMes();
    validarAnio();
}

    Fecha(std::string fecha)/* <- Esto es el constructor*/ {
        cadenaFecha = fecha; //Se igualan los valores del main a la clase
    }

    std::string getCadenaFecha(){
        return cadenaFecha;
    }
/*
    Primero tendré que convetir una cadena (La cadena de la fecha) a entero y separarlo en día, mes y año
*/
    void validarAnio(){     /*   Mediante una operación de residuo, verificamos si el año es bisiesto o no   */
        if(anio % 4 == 0 && anio % 100 != 0 || anio % 4 == 0 && anio % 100 == 0 && anio % 400 == 0){
                std::cout<<"El anio que escogio es bisiesto."<<std::endl;
                bisiesto = 1;
            }
            else{
                std::cout<<"El anio que escogio no es bisiesto."<<std::endl;
                bisiesto = 0;
            }

            std::cout<<"El anio que digito es: "<<anio<<std::endl;
            std::cout<<anio<<std::endl;
    }

    void validarMes(){      /*  Acá más de lo mismo, pero en cuanto a meses del año */
        if(mes < 1 || mes > 12){
            std::cout<<"El mes que digito, esta fuera del limite. Se le pondra ";
                if(mes > 12){
                    std::cout<<"el ultimo mes del anio.";
                    if(mes > 12){
                        mes = 12;
                    }
                }
                if(mes < 1){
                    std::cout<<"el primer mes del anio.";
                    if(mes < 1){
                        mes = 1;
                    }
                }
            std::cout<<"El mes que digito es: "<<mes<<std::endl;
        }
    }

    void validarDias(){      /*   Aquí pondremos los límites de días de algunos meses, por separado (Meses de 30, 31 y pocos menos días)   */

    /*   Febrero, cuando solo tiene 28 días   */
        if(mes == 2 && dia < 1 || dia > 28 && bisiesto == 0){
                std::cout<<"El dia que digito, esta fuera del limite. Se le pondra ";
                if(dia < 1){
                    std::cout<<"el primer dia del mes."<<std::endl;
                    dia = 1;
                }
                if(dia > 28){
                    std::cout<<"el ultimo dia del mes."<<std::endl;
                    dia = 28;
                }
        /*   Febrero, pero cuando tiene 29 dias   */
            else if (mes == 2 && bisiesto == 1 && dia < 1 || dia > 29){
                std::cout<<"El dia que digito, esta fuera del limite. Se le pondra ";
                if(dia < 1){
                    std::cout<<"el primer dia del mes.";
                    dia = 1;
                }
                if(dia > 29){
                    std::cout<<"el ultimo dia del mes.";
                    dia = 29;
                }
            }
        }

        //Abril, junio, septiembre, noviembre, meses que portan 30 días en ellos.
            if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia < 1 || dia > 30)){
                std::cout<<"El dia que digito, esta fuera del limite. Se le pondra ";    
                if(dia < 1){
                    std::cout<<"el primer dia del mes.";
                    dia = 1;
                }
                if(dia > 30){
                    std::cout<<"el ultimo dia del mes.";
                    dia = 30;
                }
            }

        //Enero, marzo, mayo, julio, agosto, octubre y diciembre, meses que portan 31 días en ellos.
        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12 && dia < 1 || dia > 31){
            std::cout<<"El dia que digito, esta fuera del limite. Se lo pondra ";
            if(dia < 1){
                std::cout<<"el primer dia del mes."<<std::endl;
                dia = 1;
            }
            if(dia > 31){
                std::cout<<"el ultimo dia del mes."<<std::endl;
                dia = 31;
            }
        }
        //  Mostramos los resultados a continuación...
            std::cout<<"El dia que digito o resulto ser, es: "<<dia<<std::endl;
    }

}; //En clases se necesita ';'

    //ora sí, a lo que vinimos, la prueba de fuego



int main(){
    std::string fecha;

    std::cout<<"Digite una fecha en el orden de anio, mes y dias (XXXX/XX/XX): ";
    std::cin>>fecha;

    Fecha objFecha = Fecha(fecha); //Está creando un objeto por medio del constructor
        
    std::cout<<objFecha.getCadenaFecha()<<std::endl; //Esta parte llama a los datos del objeto
    objFecha.Validar();

    system("pause");
        return 0;
} //Dentro de este main se crea el objeto