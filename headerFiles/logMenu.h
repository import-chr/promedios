/* --------------- librerias c++ --------------- */
#include <iostream>
#include <locale.h>
#include <string.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
/* --------------- librerias c++ --------------- */

/* --------------- headers --------------- */
#include "safePass.h"
#include "csvFile.h"
/* --------------- headers --------------- */

using namespace std;

/* --------------- prototipos --------------- */
bool logIn(bool &);								//login
void start();									//inicializador
void invalidLog(int &);							//login fallido
void repAccess(int &, int &);					//reintentar login
void menu();									//menu principal
void sub_menu();								//menu secundario
void selected();								//seleccion ->menu_option
/* --------------- prototipos --------------- */

/* --------------- variables --------------- */
//unico administrador
static const char user_[] = "admin";
static const char pass_[] = "password";

static char user[10];							//nombre de usuario
static char passw[10];							//contrasena
static bool rLog = false;						//repuesta de login
static bool successfulLogIn;					//valor de retorno de func logIn()
static int rep, contador = 2;					//seleccion de menu, contador de intentos
int menu_option;
/* --------------- variables --------------- */

/* --------------- funciones --------------- */
//valida acceso
bool logIn(bool &sLog) {
	cout<<"Usuario: ";
	cin>>user;
	cout<<"Contrasena: ";
	//cin.getline(passw, 10);
	leerPasw(passw);

	//usuario y contrasena correctos
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

		cout<<"Limite de intentos excedido\nSaliendo..."<<endl;
	}
	else {
		cout<<"Usuario o contrasena incorrectos"<<endl;
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
	cout<<"-------------------- MENU --------------------"<<endl;
	cout<<"\n\t[1] Ver Grupos\n\t[2] Agregar Grupo\n\t[3] Abrir promedioGrupos.csv\n\t[4] Salir\n"<<endl;
	cout<<"----------------------------------------------"<<endl;
	cin>>menu_option;

	selected();
}

//evalua seleccion de menu
void selected() {
	switch(menu_option) {
		case 1:
			cout<<"------------ GRUPOS ------------"<<endl;
			printGrupos();
			//sub_menu();
		break;
		case 2:
			cout<<"------------ AGREGAR GRUPOS ------------"<<endl;

			new_gpr_bool = true;

			startQueue(new_gpr_bool);
			writeFile(fileCSV);
			system("cls");
			menu();
		break;
		case 3:
			cout<<"Abriendo..."<<endl;

			system("notepad promedioGrupos.csv");
			system("cls");
			menu();
		break;
		case 4:
			cout<<"Gracias por utilizar main.exe\nSaliendo..."<<endl;
		break;
	}
}

//sub menu de visualizacion
void sub_menu() {
	cout<<"\nSeleccione un grupo...";
	cin>>menu_option;
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
