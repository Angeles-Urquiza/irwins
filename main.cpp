#include <iostream>
using namespace std;
#include "funciones1.h"
#include <ctime>
#include <cstdlib>
#include "rlutil.h"


#include <locale.h>//tildes?





//ver turnos


int main()
{
    setlocale(LC_ALL,"Spanish");
    srand(time(0));

    string jugador1,jugador2;
    int dado1,dado2,dado3,dado4,dado5;
    int j1=0,j2=1,turno=0,jugadorActual;
    int opcion;
    int opcionSalir;
    int numero;
//ACA SE USA UN SOLO VECTOR DE 5 Y SE INICIALIZA EN 0(FALSE)
//UNA VEZ GANADA SE CAMBIA A TRUE
//NO SON 5 VECTORES
    //bool vecHormiga[2]= {};
    //bool vectMedusa[2]= {};
    bool vecObtencion1[5]= {} ;
    bool vecObtencion2[5]= {} ;
    string vecNombreEstatuilla[5]= {"hormiga","cangrejo","medusa","aguila","salamandra"};
    string vecEstatuillasGanadas[5]= {"hormiga","cangrejo","medusa","aguila","salamandra"};
    string estatuilla;
    int i,suma1,suma2,suma3;
    int estatuillaContador=5;
    int estatuillaContadorJ1=0;
    int estatuillaContadorJ2=0;
    bool banderaMedusa=0;
    bool banderaHormiga=0;
    int contadorMedusa=0;
    int otroJugador=0;
    int resultadoHormiga=0;
    int cantDados;
    int auxDados;
    int vecJ1[5]= {};
    int vecJ2[5]= {};
    bool faseFinal=0;
    int vecPuntosJ1[6]= {};
    int vecPuntosJ2[6]= {};
    string vecHito[6]= {"estatuilla","estatuilla++","ganador","ganador++","estatuilla--","lanzamiento"};
    int cangrejoMaldicion=0;
    int numeroElejido1, numeroElejido2;
    int numeroAmodificar;
    int contadorLanzamientoj1=0, contadorLanzamientoj2=0;



//MENUUUUUUUUUUUUU

    titulo();
    cout<<"1- "<< "JUGAR "<<endl;
    cout<<"2- "<<"ESTADISTICA "<<endl;
    cout<<"3- "<<"CRÉDITOS"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"0-"<<"SALIR"<<endl;
    cin>>opcion;

    do
    {

        switch(opcion)
        {
        case 1:

            system("cls");
            titulo();
            cout<<"jugador 1, ingrese su nombre"<<endl;
            cin>> jugador1;//nombre1
            cout<<endl;

            cout<< "jugador 2, ingrese su nombre"<<endl,
                cin>> jugador2; //nombre2


            system("cls");
            titulo();
            cout<< "Hola " <<jugador1<<"!"<<endl;

            cout<< "Hola " <<jugador2<<"!"<<endl;
            cout<<endl;
            cout<< "Deben tirar un dado de diez caras, quien obtenga el menor comienza."<< endl;
            cout<<endl;
            cout<<"********************************************************************"<<endl;

            turnoJugador1(jugador1);
            cout<<endl;
            dados(jugador1,jugador2,1,10,dado1,dado2,dado3,dado4,dado5);
            cout<<endl;
            cout<<"DADO= "<<dado1<<endl;
            auxDados = dado1;
            cout<<endl;
            cout<<"********************************************************************"<<endl;

            turnoJugador2(jugador2);
            cantDados=1;
            dados(jugador1,jugador2,cantDados,10,dado1,dado2,dado3,dado4,dado5);
            cout<<endl;
            cout<< "DADO= "<<dado1<<endl;
            cout<<endl;
            cout<<"********************************************************************"<<endl;

            if(auxDados<dado1)
            {
                cout<< "¡Felicitaciones "<<jugador1<<" tu comienzas el juego!"<<endl;
                jugadorActual=j1;
                otroJugador=j2;
            }
            else
            {
                cout<< "¡Felicitaciones "<<jugador2<<" tu comienzas el juego!"<<endl;
                jugadorActual=j2;
                otroJugador=j1;

            }

            turno=jugadorActual;

            system("pause");
            system("cls");


            estatuillaContador=0;//borrar

//while expedicion
            while(estatuillaContador >0)
            {


                system("cls");
                turno++;


                if(turno%2==0)
                {
                    jugadorActual=j1;
                    otroJugador=j2;


                }
                else
                {
                    jugadorActual=j2;
                    otroJugador=j1;

                }




                tituloExpedicion();

//FOR PARA MOSTRAR ESTATUILLAS
                cout<< "Estatullias disponibles:"<<endl;
                cout<<endl;
                for (i=0; i<5; i++)
                {
                    if(vecNombreEstatuilla[i]!=" " )
                    {

                        cout<< vecNombreEstatuilla[i]<<endl;
                    }
                }

                cout<<endl;
                cout<<"¿Que estatuilla deseas obtener?"<<endl;
                cin>> estatuilla;//SE GUARDA LA ESTATUILLA QUE ELIGIO



                while(estatuilla!= "hormiga" &&  estatuilla!="medusa" && estatuilla!="aguila" && estatuilla!="salamandra" && estatuilla!="cangrejo")

                {

                    cout<< "estatuilla incorrecta, vuelva ingresar"<< endl;
                    cin>>estatuilla;
                }
                //cout<<"***********************************************************************************************************************"<<endl;


//EN LOS IF BUSCA LA ESTATUILLA

//HORMIGA
                if(estatuilla == "hormiga")
                {

//muestra estatuillas ganadas por jugador.
                    system("cls");
                    tituloExpedicion();
                    cout<< "estatuillas ganadas por ";
                    cout<<jugador1<<":";
                    for(int i=0; i<5; i++)
                    {
                        if(vecObtencion1[i]==1)
                        {
                            cout<<vecEstatuillasGanadas[i]<<" ";


                        }
                    }

                    cout<<endl;
                    cout<<endl;
                    cout<<"Estatuillas ganadas por ";
                    cout<< jugador2<<":";
                    for(int i=0; i<5; i++)
                    {
                        if(vecObtencion2[i]==1)
                        {
                            cout<<vecEstatuillasGanadas[i];

                        }
                    }
                    cout<<endl;
                    cout<<"***********************************************************************************************************************"<<endl;




//muestra el turno
                    if(jugadorActual==j1)
                    {
                        cout<< "Turno: "<< jugador1<<endl;
                    }
                    else
                    {
                        cout<<"Turno: "<< jugador2<<endl;
                    }
                    cout<<"***********************************************************************************************************************"<<endl;
//

//condicion hormiga

                    cout<<endl<<"Estas jugando por la estatuilla hormiga."<<endl;
                    cout<<endl;
                    cout<<"para su obtención al menos dos dados deben ser menores a 5."<<endl;


                    if(jugadorActual==j1)
                    {
                        if(vecObtencion1[4]== 1 && vecNombreEstatuilla[4]== "salamandra")
                        {
                            cantDados=3;
                        }
                        else
                        {
                            cantDados=2;
                        }
                    }

                    else
                    {
                        if(vecObtencion2[4]== 1 && vecNombreEstatuilla[4]== "salamandra")
                        {
                            cantDados=3;
                        }
                        else
                        {
                            cantDados=2;
                        }
                    }

                    dados(jugador1,jugador2,cantDados,10,dado1,dado2,dado3,dado4,dado5);
                    cout<< "DADO1= "<<dado1<<endl;
                    cout<< "DADO2= "<<dado2<<endl;
                    if(dado3!=0)

                    {

                        cout<< "DADO3= "<<dado3<<endl;
                    }

//
                    system("pause");
                    system("cls");
//condicion de obtencion
                    if (dado1<5 && dado2<5 )
                    {
                        tituloExpedicion();
                        cout<<endl;
                        cout<< "Ganaste la estatuilla hormiga"<<endl;
                        cout<<endl;

                        if(jugadorActual==0)
                        {
                            vecObtencion1[0]=1;
                            estatuillaContadorJ1++;

                            vecPuntosJ1[0]+=5;
                            vecPuntosJ2[4];//-3
                        }
                        else
                        {
                            vecObtencion2[0]=1;
                            estatuillaContadorJ2++;

                            vecPuntosJ2[0]+=5;
                            vecPuntosJ1[4];//-3
                        }
                        cout<<"***********************************************************************************************************************"<<endl;
                        vecNombreEstatuilla[0]=" ";//ACA BORRA LA ESTATUILLA
                        estatuillaContador--;
                        cout<<endl;
                        cout<< "Tu rival tendra que tirar dos dados de diez caras y el valor obtenido son los puntos que se le descuenta al portador de la estatuilla en la fase fnial. "<<endl;


                        dados(jugador1,jugador2,2,10,dado1,dado2,dado3,dado4,dado5);
                        resultadoHormiga=dado1+dado2;
                        //se le descuenta al portador.

                        cout<< "DADO1= "<<dado1<<endl;
                        cout<< "DADO2= "<<dado2<<endl;
                        cout<< "suma: " <<resultadoHormiga<<" puntos que se le descontaran al portador de la estatuilla en la fase final"<< endl;
                        system("pause");
                        system("cls");

                    }
                    else
                    {
                        tituloExpedicion();
                        cout<<endl;
                        cout<<"¡No ganaste la estatuilla!"<<endl;
                        cout<<endl;
                        cout<<"***********************************************************************************************************************"<<endl;
                        system("pause");


                    }

                }

//CANGREJO
                else
                {
                    system("cls");
                    tituloExpedicion();
                    if(estatuilla == "cangrejo")
                    {
                        cout<<jugador1<<endl;
                        cout<< "estatuillas:";
                        for(int i=0; i<5; i++)
                        {
                            if(vecObtencion1[i]==1)
                            {
                                cout<<vecEstatuillasGanadas[i];

                            }
                        }
                        cout<<endl;
                        cout<<endl;
                        cout<< jugador2<<endl;
                        cout<<"estatuillas:";
                        for(int i=0; i<5; i++)
                        {
                            if(vecObtencion2[i]==1)
                            {
                                cout<<vecEstatuillasGanadas[i];

                            }
                        }
                        cout<<endl;
                        cout<<"************************************************************************************************************************"<<endl;
                        if(jugadorActual==0)
                        {
                            cout<< "Turno: "<< jugador1<<endl;
                        }
                        else
                        {

                            cout<<"Turno: "<< jugador2<<endl;
                        }
                        cout<<"***********************************************************************************************************************"<<endl;
                        cout<<endl;

                        cout<< "Estas jugando por la estatuilla cangrejo"<<endl;
                        cout<<endl;
                        cout<<"para obtener la estatuilla uno de sus dados debe ser par y el otro impar."<<endl;


                        if(jugadorActual==j1)
                        {
                            if(vecObtencion1[4]== 1 && vecNombreEstatuilla[4]== "salamandra")
                            {
                                cantDados=3;
                            }
                            else
                            {
                                cantDados=2;
                            }
                        }

                        else
                        {
                            if(vecObtencion2[4]== 1 && vecNombreEstatuilla[4]== "salamandra")
                            {
                                cantDados=3;
                            }
                            else
                            {
                                cantDados=2;
                            }
                        }
                        dados(jugador1,jugador2,cantDados,10,dado1,dado2,dado3,dado4,dado5);
                        cout<< "DADO1= "<<dado1<<endl;
                        cout<< "DADO2= "<<dado2<<endl;
                        if(dado3!=0)
                        {

                            cout<< "DADO3= "<<dado3<<endl;
                        }
                        system("pause");
                        system("cls");


                        if((dado1 % 2 == 0 && dado2 %2 != 0) || (dado2 % 2 == 0  && dado1 % 2 != 0) || (dado2 % 2 == 0 && dado3  % 2 != 0) || (dado3 % 2 ==  0  && dado2 % 2 != 0) || (dado1 % 2 == 0 && dado3 % 2 != 0) || (dado3 % 2 == 0 && dado1 %2 != 0))
                        {
                            cout<<endl;
                            cout<<"¡Ganaste la estatuilla cangrejo!"<<endl;
                            cout<< endl;
                            if(jugadorActual==0)
                            {
                                vecObtencion1[0]=1;
                                estatuillaContadorJ1++;

                                vecPuntosJ1[0]+=5;
                                vecPuntosJ2[3];//-3
                            }
                            else
                            {
                                vecObtencion2[0]=1;
                                estatuillaContadorJ2++;

                                vecPuntosJ2[0]+=5;
                                vecPuntosJ1[3];//-3
                            }
                            cout<<"***********************************************************************************************************************"<<endl;
                            vecNombreEstatuilla[1]=" ";//ACA BORRA LA ESTATUILLA
                            estatuillaContador--;

                            cout<<endl;
                            cout<< "El rival tira un dado de diez caras y el valor obtenido son los puntos de victoria que le descuenta al portador"<<endl;
                            cout<<"de la estatuilla al final de la partida."<<endl;
                            cantDados=1;
                            dados(jugador1,jugador2,cantDados,10,dado1,dado2,dado3,dado4,dado5);
                            cout<<"DADO= "<<dado1<<endl;
                            cout<<endl;
                            cout<<dado1<<" puntos se le descontaran al portador de la estatuilla"<<endl;
                            cangrejoMaldicion=dado1;//se descuenta en la fase final;
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            tituloExpedicion();
                            cout<<"¡No ganaste la estatuilla!"<<endl;
                            cout<<endl;
                            cout<<"***********************************************************************************************************************"<<endl;
                            system("pause");
                        }
                    }



//MEDUSA
                    else
                    {

                        if(estatuilla == "medusa")
                        {
                            system("cls");
                            tituloExpedicion();
                            cout<< "Estatuillas ganadas por ";
                            cout<<jugador1<<":";

                            for(int i=0; i<5; i++)
                            {
                                if(vecObtencion1[i]==1)
                                {
                                    cout<<vecEstatuillasGanadas[i];


                                }
                            }

                            cout<<endl;
                            cout<<endl;
                            cout<<"Estatuillas ganadas por ";
                            cout<< jugador2<<":";
                            for(int i=0; i<5; i++)
                            {
                                if(vecObtencion2[i]==1)
                                {
                                    cout<<vecEstatuillasGanadas[i];

                                }
                            }
                            cout<<endl;

                            cout<<"************************************************************************************************************************"<<endl;
                            if(jugadorActual==0)
                            {
                                cout<< "Turno: "<< jugador1<<endl;
                            }
                            else
                            {

                                cout<<"Turno: "<< jugador2<<endl;
                            }
                            cout<<"***********************************************************************************************************************"<<endl;

                            cout<<endl;
                            cout<<"Estas jugando por la estatuilla medusa"<<endl;
                            cout<<endl;
                            cout<<"Para obtener la estatuilla la suma de dos de sus dados debe ser 7"<<endl;

                            if(jugadorActual==j1)
                            {
                                if(vecObtencion1[4]== 1 && vecNombreEstatuilla[4]== "salamandra")
                                {
                                    cantDados=3;
                                }
                                else
                                {
                                    cantDados=2;
                                }
                            }

                            else
                            {
                                if(vecObtencion2[4]== 1 && vecNombreEstatuilla[4]== "salamandra")
                                {
                                    cantDados=3;
                                }
                                else
                                {
                                    cantDados=2;
                                }
                            }
                            dados(jugador1,jugador2,cantDados,10,dado1,dado2,dado3,dado4,dado5);
                            cout<< "DADO1= "<<dado1<<endl;
                            cout<< "DADO2= "<<dado2<<endl;
                            if(dado3!=0)
                            {

                                cout<< "DADO3= "<<dado3<<endl;
                            }


                            suma1=dado1+dado2;
                            suma2=dado1+dado3;
                            suma3=dado2+dado3;

                            system("pause");
                            system("cls");

                            if(suma1 == 7 || suma2 == 7 || suma3 == 7)
                            {


                                tituloExpedicion();
                                cout<<endl;
                                cout<< "¡Ganaste la estatuilla medusa! "<<endl;
                                cout<<endl;
                                cout<<"***********************************************************************************************************************"<<endl;
                                cout<<endl;
                                cout<<"El portador de la estatuilla debe esperar 3 turnos sin lanzar dados para seguir la Fase de Expedición."<<endl;


                                if(jugadorActual==0)
                                {
                                    vecObtencion1[2]=1;
                                    estatuillaContadorJ1++;

                                    vecPuntosJ1[0]+=5;
                                    vecPuntosJ2[4];//-3
                                }
                                else
                                {
                                    vecObtencion2[2]=1;
                                    estatuillaContadorJ2++;

                                    vecPuntosJ2[0]+=5;
                                    vecPuntosJ1[4];//-3
                                }
                                vecNombreEstatuilla[2]=" ";
                                estatuillaContador--;


                                system("pause");
                                system("cls");

                            }
                            else
                            {
                                tituloExpedicion();
                                cout<<endl;
                                cout<<"No ganaste la estatuilla"<<endl;
                                cout<<endl;
                                cout<<"***********************************************************************************************************************"<<endl;


                                system("pause");

                            }
                        }


//AGUILA
                        else
                        {
                            if(estatuilla == "aguila")
                            {
                                system("cls");
                                tituloExpedicion();
                                cout<<jugador1<<endl;
                                cout<< "estatuillas:";
                                for(int i=0; i<5; i++)
                                {
                                    if(vecObtencion1[i]==1)
                                    {
                                        cout<<vecEstatuillasGanadas[i];

                                    }
                                }
                                cout<<endl;
                                cout<<endl;
                                cout<< jugador2<<endl;
                                cout<<"estatuillas:";
                                for(int i=0; i<5; i++)
                                {
                                    if(vecObtencion2[i]==1)
                                    {
                                        cout<<vecEstatuillasGanadas[i];

                                    }
                                }

                                cout<<endl;
                                cout<<"***********************************************************************************************************************"<<endl;

                                if(jugadorActual==0)
                                {
                                    cout<< "Turno: "<< jugador1<<endl;
                                }
                                else
                                {

                                    cout<<"Turno: "<< jugador2<<endl;
                                }
                                cout<<"************************************************************************************************************************"<<endl;
                                cout<<endl;
                                cout<<"Estas jugando por la estatuilla aguila"<<endl;
                                cout<<endl;
                                cout<<"Para obtenerla dos de los dados lanzados deberán devolver los números 1 y 10."<<endl;
                                cout<<endl;



                                if(jugadorActual==j1)
                                {
                                    if(vecObtencion1[4]== 1 && vecNombreEstatuilla[4]== "salamandra")
                                    {
                                        cantDados=3;
                                    }
                                    else
                                    {
                                        cantDados=2;
                                    }
                                }

                                else
                                {
                                    if(vecObtencion2[4]== 1 && vecNombreEstatuilla[4]== "salamandra")
                                    {
                                        cantDados=3;
                                    }
                                    else
                                    {
                                        cantDados=2;
                                    }
                                }
                                dados(jugador1,jugador2,cantDados,10,dado1,dado2,dado3,dado4,dado5);
                                cout<< "DADO1= "<<dado1<<endl;
                                cout<< "DADO2= "<<dado2<<endl;
                                system("pause");
                                system("cls");
                                if((dado1 == 1 && dado2 == 10) || (dado2 == 1 && dado1 == 10) || (dado2 == 1 && dado3 == 10) || (dado3 ==  1  && dado2 == 10) || (dado1 == 1 && dado3 == 10) || (dado3 == 1 && dado1 == 10))
                                {
                                    tituloExpedicion();
                                    cout<<endl;
                                    cout<< "¡Ganaste la estatuilla aguila!"<<endl;
                                    cout<<endl;
                                    if(jugadorActual==0)
                                    {
                                        vecObtencion1[0]=1;
                                        estatuillaContadorJ1++;

                                        vecPuntosJ1[0]+=5;
                                        vecPuntosJ2[4];//-3
                                    }
                                    else
                                    {
                                        vecObtencion2[0]=1;
                                        estatuillaContadorJ2++;

                                        vecPuntosJ2[0]+=5;
                                        vecPuntosJ1[4];//-3
                                    }
                                    cout<<"***********************************************************************************************************************"<<endl;
                                    vecNombreEstatuilla[3]=" ";
                                    estatuillaContador--;
                                    cout<<endl;
                                    cout<< "El rival tira dos veces por turno durante el resto de la Fase de Expedición."<<endl;
                                    system("pause");
                                    system("cls");
                                }
                                else
                                {
                                    tituloExpedicion();
                                    cout<<endl;
                                    cout<<"¡No ganaste la estatuilla!"<<endl;
                                    cout<<endl;
                                    cout<<"***********************************************************************************************************************"<<endl;
                                    system("pause");
                                }
                            }


//SALAMANDRA
                            else
                            {
                                system("cls");
                                tituloExpedicion();
                                cout<<jugador1<<endl;
                                cout<< "estatuillas:";
                                for(int i=0; i<5; i++)
                                {
                                    if(vecObtencion1[i]==1)
                                    {
                                        cout<<vecEstatuillasGanadas[i];

                                    }
                                }
                                cout<<endl;
                                cout<<endl;
                                cout<< jugador2<<endl;
                                cout<<"estatuillas:";
                                for(int i=0; i<5; i++)
                                {
                                    if(vecObtencion2[i]==1)
                                    {
                                        cout<<vecEstatuillasGanadas[i];

                                    }
                                }
                                cout<<endl;
                                cout<<"************************************************************************************************************"<<endl;

                                if(jugadorActual==0)
                                {
                                    cout<< "Turno: "<< jugador1<<endl;
                                }
                                else
                                {

                                    cout<<"Turno: "<< jugador2<<endl;
                                }
                                cout<<"***********************************************************************************************************************"<<endl;
                                cout<<endl;
                                cout<<"Estas jugando por la estatuilla salamandra."<<endl;
                                cout<<endl;
                                cout<<"Para obtener la estatuilla los dados lanzados deben ser consecutivos. Por ejemplo: (1 y 2) (2 y 3) (9 y 10)."<<endl;


                                if(jugadorActual==j1)
                                {
                                    if(vecObtencion1[4]== 1 && vecNombreEstatuilla[4]== "salamandra")
                                    {
                                        cantDados=3;
                                    }
                                    else
                                    {
                                        cantDados=2;
                                    }
                                }

                                else
                                {
                                    if(vecObtencion2[4]== 1 && vecNombreEstatuilla[4]== "salamandra")
                                    {
                                        cantDados=3;
                                    }
                                    else
                                    {
                                        cantDados=2;
                                    }
                                }
                                dados(jugador1,jugador2,2,10,dado1,dado2,dado3,dado4,dado5);
                                cout<< "DADO1= "<<dado1<<endl;
                                cout<< "DADO2= "<<dado2<<endl;
                                system("cls");
                                system("cls");



                                if(dado1+1==dado2||dado1-1==dado2||dado2+1==dado3||dado2-1==dado3||dado3+1==dado1||dado3-1==dado1)
                                {
                                    tituloExpedicion();
                                    cout<<endl;
                                    cout<< "¡Ganaste la estatuilla salamandra!"<<endl;
                                    cout<<endl;

                                    if(jugadorActual==0)
                                    {
                                        vecObtencion1[4]=1;
                                        estatuillaContadorJ1++;

                                        vecPuntosJ1[0]+=5;
                                        vecPuntosJ2[4];//-3
                                    }
                                    else
                                    {
                                        vecObtencion2[4]=1;
                                        estatuillaContadorJ2++;

                                        vecPuntosJ2[0]+=5;
                                        vecPuntosJ1[4];//-3
                                    }

                                    cout<<"***********************************************************************************************************************"<<endl;
                                    cout<<endl;
                                    vecNombreEstatuilla[4]=" ";
                                    estatuillaContador--;
                                    cout<< "El rival juega con tres dados durante el resto de la Fase de Expedición."<<endl;
                                    system("pause");
                                    system("cls");
                                }
                                else
                                {
                                    tituloExpedicion();
                                    cout<<endl;
                                    cout<<"¡No ganaste la estatuilla!"<<endl;
                                    cout<<endl;
                                    cout<<"***********************************************************************************************************************"<<endl;
                                    system("pause");
                                    system("cls");
                                }

                            }

                        }

                    }

                }
            }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//termina fase expedicion
//comienza FASE FINAAAAAAAAAL
            estatuillaContadorJ1=3;//borrar
            estatuillaContadorJ2=1;//
            j1=0;
            j2=1;

            tituloFinal();
            cout<<endl;
            cout<<"                  Bienvenidos a la fase final."<<endl;
            cout<<"En esta fase comienza el jugador que haya obtenido mas estatatuillas"<<endl;
            cout<<endl;
            cout<<"***********************************************************************************************************************"<<endl;

            if(estatuillaContadorJ1>estatuillaContadorJ2)
            {
                cout<< "¡Felicitaciones "<<jugador1<<" tu comienzas el juego!"<<endl;
                jugadorActual=j1;

            }
            else
            {
                cout<< "¡Felicitaciones "<<jugador2<<" tu comienzas el juego!"<<endl;
                jugadorActual=j2;


            }




            cout<<endl;
            cout<< "Ganara aquel jugador que obtenga una escalera, sin importar el orden de los dados."<<endl;
            cout<<"Las unicas dos excepciones son:"<<endl;
            cout<<endl;
            cout<<"*Quien tenga la estatuilla de la medusa podrá ganar también con la obtención de 5 dados iguales."<<endl;
            cout<<"Por ejemplo:"<<endl;
            cout<<" (1, 1, 1, 1, 1); (3, 3, 3, 3, 3); etc. "<<endl;
            cout<<endl;
            cout<<"*Quien tenga la estatuilla de la salamandra podrá ganar con una escalera más corta."<<endl;
            cout<<"Sólo 4 de los 5 dados deberán ser correlativos."<<endl;
            cout<<"Ejemplos de lanzamientos exitosos podrían ser:"<<endl;
            cout<<"(1, 2, 3, 4, 1); (2, 3, 4, 5, 2); (3, 4, 5, 6, 1); etc."<<endl;


            system("pause");
            system("cls");

//pre-fase final

            vecObtencion1[0]=1;//borrar
            vecObtencion1[1]=1;//borrar

            tituloFinal();
            if(jugadorActual==0 && vecObtencion1[0] == 1 )
            {
                cout<<jugador1;
                cout<<" antes de empezar la fase final, elija un numero del 1 al 6. Luego, en cada tiro puede optar por"<<endl;
                cout<<"elegir uno de los cinco dados del lanzamiento y reemplazarlo por el número elegido."<<endl;
                cin>>numeroElejido1;

            }
            else
            {
                if(jugadorActual==1 && vecObtencion2[0] == 1 )
                {

                    cout<<jugador2;
                    cout<<" antes de empezar la fase final, elija un numero del 1 al 6. Luego, en cada tiro puede optar por"<<endl;
                    cout<<"elegir uno de los cinco dados del lanzamiento y reemplazarlo por el número elegido."<<endl;
                    cin>>numeroElejido2;

                }

            }
            system("pause");
            system("cls");

            while(faseFinal==0)
            {
                //while
                int aux;
                bool gano=0;
                bool primerTiro=0;


                if(jugadorActual==0)
                {
                    contadorLanzamientoj1++;//se resta (poner en la posicion [5]
                    tituloFinal();
                    cout<<endl;
                    cout<<"Turno: "<<jugador1<<endl;
                    cout<<endl;
                    cout<<"***********************************************************************************************************************"<<endl;
//jugado j1

                    dados(jugador1,jugador2,5,6,dado1,dado2,dado3,dado4,dado5);
                    vecJ1[0]=dado1;
                    vecJ1[1]=dado2;
                    vecJ1[2]=dado3;
                    vecJ1[3]=dado4;
                    vecJ1[4]=dado5;
//estatuilla hormiga (cambiar un dado)
                    if(vecObtencion1[0]==1)
                    {
                        cout<<"elija el numero que desea reemplazar por el numero: "<<numeroElejido1<< " que ah elejido anteriormente"<<endl;
                        cin>>numero;

                        for(int i=0; i<5; i++)
                        {
                            if(numero==vecJ1[i])
                            {
                                vecJ1[i]=numeroElejido1;
                            }
                        }
                        cout<<endl;
                        cout<< "DADOS:"<<endl;
                        for(int i=0; i<5; i++)
                        {
                            cout<<vecJ1[i];
                        }


                    }
                    else
                    {
//estatuilla aguila
                        if(vecObtencion1[3]==1)
                        {
                            cout<<"elija el numero que desea reemplazar"<<endl;
                            cin>>numero;

                            cout<<"elija el numero por el que remplazaremos en numero que elijio"<<endl;
                            cin>> numeroElejido1;

                            for(int i=0; i<5; i++)
                            {
                                if(numero==vecJ1[i])
                                {
                                    vecJ1[i]=numeroElejido1;
                                }
                            }
                            cout<<endl;
                            cout<< "DADOS:"<<endl;
                            for(int i=0; i<5; i++)
                            {
                                cout<<vecJ1[i];
                            }
                        }
                    }

                    for(int i=0; i<5; i++)
                    {
                        for(int x=0; x<4; x++)
                        {
                            if(vecJ1[x]>vecJ1[x+1])
                            {
                                aux=vecJ1[x+1];
                                vecJ1[x+1]=vecJ1[x];
                                vecJ1[x]=aux;
                            }
                        }

                    }


                    dado1=vecJ1[0];
                    dado2=vecJ1[1];
                    dado3=vecJ1[2];
                    dado4=vecJ1[3];
                    dado5=vecJ1[4];



                    if(dado2==dado1+1 && dado3==dado2+1 && dado4==dado3+1 && dado5==dado4+1)
                    {
                        cout<<endl;
                        cout<<"Felicitacones "<<jugador1<<" ganaste la fase final!"<<endl;
                        faseFinal=1;
                        //puntos por ganar fase final
                        if(estatuillaContadorJ1==0 )
                        {
                            vecPuntosJ1[3]=50;
                        }
                        else
                        {
                            vecPuntosJ1[2]=15;
                        }
                        system("pause");
                    }
                    else
                    {
//estatuilla medusa (dados iguales)
                        if(vecObtencion1[2]==1 && dado1==dado2 && dado2==dado3 && dado3==dado4 && dado4==dado5)
                        {
                            cout<<endl;
                            cout<<"Felicitacones "<<jugador1<<" ganaste la fase final!"<<endl;
                            faseFinal=1;
                            //puntos por ganar face final
                            if(estatuillaContadorJ1==0 )
                            {
                                vecPuntosJ1[3]=50;
                            }
                            else
                            {
                                vecPuntosJ1[2]=15;
                            }
                            system("pause");

                        }
                        else
                        {
//estatulla salamandra (escalera corta)
                            if(vecObtencion1[4]==1 && dado2==dado1+1 && dado3==dado2+1 && dado4==dado3+1 || vecObtencion1[4]==1  && dado3==dado2+1 && dado4==dado3+1 && dado5==dado4+1 )
                            {
                                cout<<endl;
                                cout<<"Felicitacones "<<jugador1<<" ganaste la fase final!"<<endl;
                                faseFinal=1;
                                //puntos por ganar face final
                                if(estatuillaContadorJ1==0 )
                                {
                                    vecPuntosJ1[3]=50;
                                }
                                else
                                {
                                    vecPuntosJ1[2]=15;
                                }
                                system("pause");
                            }
                            else
                            {

                                cout<<endl;
                                cout<<"Tus dados no cumplen ninguna de las condiciones para ganar esta fase"<<endl;
//estatuilla cangrejo
                                if(vecObtencion1[1]==1 && primerTiro==0)
                                {
                                    cout<<"Turno: "<<jugador1<<endl;
                                    cout<<endl;
                                    cout<<"***********************************************************************************************************************"<<endl;
                                    cout<<jugador1<< " solo en esta ocacion puedes volver a lanzar los dados, por haber obtenido en la fase de expedicion la estatuilla CANGREJO ";
                                    primerTiro==1;

                                    //TERMINAR

                                }
                            }

                        }
                    }
                }
                else
                {
                    tituloFinal();

                    cout<<endl;
                    cout<<"Turno: "<<jugador2<<endl;
                    cout<<endl;
                    cout<<"***********************************************************************************************************************"<<endl;
//jugado j1
                    system("pause");
                    system("cls");
                }


                if(jugadorActual==j1)
                {
                    jugadorActual=j2;
                }
                else
                {
                    jugadorActual=j1;
                }
                system("cls");
            }//cierra while

            titulo();
            cout<<endl;
            cout<<"PUNTOS DE VITORIA"<<endl;
            cout<<endl;
            cout<<"***********************************************************************************************************************"<<endl;
            cout<<"  HITO      "<<jugador1<<"          "<< jugador2<<endl;
            cout<<"_______________________________________________________________________________________________________________________"<<endl;
            for(int i=0; i<6; i++)
            {
                cout<<vecHito[i]<<"        "<<vecPuntosJ1<<"           "<<vecPuntosJ2<<endl;
            }
            system("pause");

            break;
//menu
        case 2:
            estadisticas(opcion, opcionSalir);




            break;
        case 3:

            creditos(opcion, opcionSalir);


            break;
        case 0:

            cout<<"seguro quiere abandonar el juego?"<<endl;
            cout<< "1- SI"<<endl;
            cout<< "2- NO"<<endl;
            cin>>opcionSalir;
            switch(opcionSalir)
            {
            case 1:

                cout<< "¡gracias por visitar nuestro juego!"<<endl;;
                cout<<endl;
                cout<< "            Hasta pronto";





                break;
            case 2:


                break;


            }


            break;

        }

    }
    while(opcion!=0);




    return 0;
}




//PARA TIRAR DADO
//cout<< random(6);
//    dosDados(6, dado1, dado2);

//  cout<<"DADO1= " <<dado1<<endl;
//cout<< "DADO2= " <<dado2<<endl;

