/* --------------- librerias c++ --------------- */
#include <iostream>
#include <locale.h>
#include <string.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
/* --------------- librerias c++ --------------- */

/* --------------- headers --------------- */
#include "dataGroup.h"
#include "safePass.h"
/* --------------- headers --------------- */

using namespace std;

/* --------------- prototipos --------------- */
bool logIn(bool &);								//login
void start();									//inicializador
void invalidLog(int &);							//login fallido
void repAccess(int &, int &);					//reintentar login
void menu();									//menu principal
/* --------------- prototipos --------------- */

/* --------------- estructuras --------------- */
/* --------------- estructuras --------------- */

/* --------------- variables --------------- */
//unico administrador
static const char user_[] = "admin";
static const char pass_[] = "password";

static char user[10];							//nombre de usuario
static char passw[10];							//contraseña
static bool rLog = false;						//repuesta de login
static bool successfulLogIn;					//valor de retorno de func logIn()
static int menu_option, rep, contador = 2;		//seleccion de munu, contador de intentos
/* --------------- variables --------------- */

/* --------------- funciones --------------- */
//valida acceso
bool logIn(bool &sLog) {
	cout<<"Usuario: ";
	cin>>user;
	cout<<"Contraseña: ";
	leerPasw(passw);

	//usuario y contrase? correctos
	int uu = strcmp(user, user_);
	int pp =  strcmp(passw, pass_);

	(uu == 0 && pp == 0) ? sLog =  true : sLog = false;

	return sLog;
}

//acceso denegado
void invalidLog(int &r0) {
	//limite de 3 intentos
	if(contador == 0) {
		r0 = 2;

		cout<<"Límite de intentos excedido\nSaliendo..."<<endl;
	}
	else {
		cout<<"Usuario o contraseña incorrectos"<<endl;
		cout<<"Intentar nuevamente...\n[1] si\n[2] no"<<endl;
		cin>>r0;
		
		if(r0 == 2) {
			cout<<"Saliendo..."<<endl;
		}
	
		repAccess(r0, contador);
	}
}

//bucle de login
void repAccess(int &r1, int &c) {
	while(r1 == 1) {
		c--;

		start();	
	
		r1 = 0;
	}
}

//menu
void menu() {
	cout<<"------------ MENU ------------"<<endl;
	cout<<"\n\t[1] Ver Grupos\n\t[2] Agregar Grupos\n\t[3] Salir\n"<<endl;
	cout<<"------------------------------"<<endl;
	cin>>menu_option;

	switch(menu_option) {
		case 1:
			cout<<"------------ GRUPOS ------------"<<endl;
			cout<<"no disponible por le momento..."<<endl;
			break;
		case 2:
			cout<<"------------ AGREGAR GRUPO ------------"<<endl;
			llamadas(nGrupos);
			break;
		case 3:
			cout<<"Gracias por utilizar main.exe\nSaliendo..."<<endl;
			break;
	}
}

//inicializa menu
void start() {
	successfulLogIn = logIn(rLog);

	if(successfulLogIn) {
		system("color 0F");
		system("cls");
		menu();
	}
	else {
		system("color 04");
		system("cls");
		invalidLog(rep);
	}
}
/* --------------- funciones --------------- */
