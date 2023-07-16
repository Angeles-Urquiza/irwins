//DFINICION DE FUNCIONES

#include <iostream>
using namespace std;

#include<cstdlib>//para incluir la funcion rand
#include<iomanip> //
#include<ctime>//tiempo dados

#include<windows.h>//estetica
#define color SetConsoleTextAttribute//funcionalidad para darle color a x cosa
#include "funciones1.h"//
#include "rlutil.h"







int random(int limite)
{
    char tirarDado;

    cout<< "presione T para tirar";
    cin>>tirarDado;

    if(tirarDado=='t')
    {

        return(rand()%limite)+1;

    }
}

void dados(string jugador1, string jugador2, int cantDados,int limite,int &dado1, int &dado2, int &dado3, int &dado4, int &dado5)
{
    char tirarDado;


    if(jugador1== "lab1" || jugador2== "lab1" ){
        for(int i=0; i<cantDados; i++)
        {
            if(i==0)
            {   cout<<" "<<endl;

                cout<<"LANZAMIENTO"<<endl;
                cout<<" "<<endl;
                cout<<"ingrese dado: ";
                cin>>dado1;


            }

            else{
                if(i==1)
                {
                    cout<<"ingrese dado: ";
                    cin>>dado2;

                }
                else
                {
                    if(i==2){
                    cout<<"ingrese dado: ";
                    cin>>dado3;
                } else
                if(i==3){
                        cout<<"ingrese dado: ";
                        cin>>dado4;
                } else{
                    cout<<"ingrese dado: ";
                    cin>>dado5;
                }
                }
            }
        }
    }
        else
        {
            cout<<"LANZAMIENTO"<<endl;
            cout<<" "<<endl;

            cout<< "presione T para tirar";
            cin>>tirarDado;


            if(tirarDado=='t')
            {
                for(int i=0; i<cantDados; i++)
                {
                    if(i==0)
                    {
                        dado1=rand()%limite;
                    }
                    else
                    {
                        if(i==1)
                        {
                            dado2=rand()%limite;
                        }
                        else
                        { if(i==2){

                            dado3=rand()%limite;

                        } else
                        {
                            if(i==3){
                                dado4=rand()%limite;
                            }
                            else{
                                dado5=rand()%limite;
                            }
                        }

                        }

                    }
                }


            }
        }
    }

    void turnoJugador1(string jugador1)
    {
        cout<< jugador1<< " es tu turno."<<endl;

    }

    void turnoJugador2(string jugador2)
    {

        cout<< jugador2<< " es tu turno."<<endl;
    }

    void tituloExpedicion()
    {

        rlutil:: locate(50,3);
        cout<<"***************************"<<endl;
        rlutil:: locate(50,4);
        cout<<"     IRWIN'S REVENGE "<<endl;
        rlutil:: locate(50,5);
        cout<<"    FASE DE EXPEDICIÓN"<<endl;
        //rlutil:: locate(50,6);
        cout<<"***********************************************************************************************************************"<<endl;

    }
    void titulo(){
        cout<<endl;
        rlutil:: locate(50,3);
        cout<<"***************************"<<endl;
        rlutil:: locate(50,4);
        cout<<"     IRWIN'S REVENGE "<<endl;
        cout<<endl;
        cout<<"***********************************************************************************************************************"<<endl;



    }

    void tituloFinal(){
        rlutil:: locate(50,3);
        cout<<"***************************"<<endl;
        rlutil:: locate(50,4);
        cout<<"     IRWIN'S REVENGE "<<endl;
        rlutil:: locate(50,5);
        cout<<"        FASE FINAL"<<endl;
        //rlutil:: locate(50,6);
        cout<<"***********************************************************************************************************************"<<endl;



    }


    void estadisticas(int &opcion, int &opcionSalir){

        system("cls");
        titulo();
        cout<<"ESTADISTICAS"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;

        system("pause");
        system("cls");
        cout<<"1- "<< "JUGAR "<<endl;
        cout<<"2- "<<"ESTADISTICA "<<endl;
        cout<<"3- "<<"CRÉDITOS"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0-"<<"SALIR"<<endl;
        cin>>opcion;

         if( opcion== 0){
            system("cls");
            cout<<"seguro quiere abandonar el juego?"<<endl;
            cout<< "1- SI"<<endl;
            cout<< "2- NO"<<endl;
            cin>>opcionSalir;
            switch(opcionSalir){
                case 1:
                    system("cls");
                    cout<< "¡gracias por visitar nuestro juego!"<<endl;;
                    cout<<endl;
                    cout<< "            Hasta pronto";





                break;
                case 2:

        system("cls");
        cout<<"1- "<< "JUGAR "<<endl;
        cout<<"2- "<<"ESTADISTICA "<<endl;
        cout<<"3- "<<"CRÉDITOS"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0-"<<"SALIR"<<endl;
        cin>>opcion;

                    break;

        }



        }

    }

    void creditos(int &opcion, int &opcionSalir){
        system("cls");
        titulo();
        cout<<"CREADORES DEL JUEGO:"<<endl;
        cout<<endl;
        cout<<"Juego inventado por Gonzalo Ligero - gonzalo.ligero@alumnos.frgp.utn.edu.ar" <<endl;
        cout<<"Reglamento adaptado para TP por Gonzalo Ligero y Angel Simón"<<endl;
        cout<<endl;
        cout<<"DESARROLLADORES: "<<endl;
        cout<<endl;
        cout<<"Maria De Los Angeles Urquiza."<<endl;
        cout<< "legajo: 28847"<< endl;
        cout<<endl;
        cout<<"Martin Ale Garcia."<<endl;
        cout<<"legajo: 27920"<<endl;
        cout<<endl;
        cout<<"Ivan Alvarez."<<endl;
        cout <<"Legajo: 28107" << endl;
        cout<<endl;
        cout<<"Walter Camarotta."<<endl;
        cout<<endl;
        system("pause");
        system("cls");
        cout<<"1- "<< "JUGAR "<<endl;
        cout<<"2- "<<"ESTADISTICA "<<endl;
        cout<<"3- "<<"CRÉDITOS"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0-"<<"SALIR"<<endl;
        cin>>opcion;

        if( opcion== 0){
            system("cls");
            cout<<"seguro quiere abandonar el juego?"<<endl;
            cout<< "1- SI"<<endl;
            cout<< "2- NO"<<endl;
            cin>>opcionSalir;
            switch(opcionSalir){
                case 1:
                    system("cls");
                    cout<< "¡gracias por visitar nuestro juego!"<<endl;;
                    cout<<endl;
                    cout<< "            Hasta pronto";





                break;
                case 2:

        system("cls");
        cout<<"1- "<< "JUGAR "<<endl;
        cout<<"2- "<<"ESTADISTICA "<<endl;
        cout<<"3- "<<"CRÉDITOS"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0-"<<"SALIR"<<endl;
        cin>>opcion;


                    break;

        }



        }



    }




















