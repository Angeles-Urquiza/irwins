//DECLARACIONES
#ifndef FUNCIONES1_H_INCLUDED
#define FUNCIONES1_H_INCLUDED



int random(int limite);

void dados(string jugador1, string jugador2, int cantDados,int limite,int &dado1, int &dado2, int &dado3, int &dado4, int &dado5);



void titulo();
void tituloExpedicion();
void tituloFinal();

void turnoJugador1(string jugador1);

void turnoJugador2(string jugador2);



void opcionesEstatuillas();

void estadisticas(int &opcion, int &opcionSalir);

void creditos(int &opcion, int &opcionSalir);


#endif // FUNCIONES1_H_INCLUDED
