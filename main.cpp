/* --------------- librerias c++ --------------- */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <locale.h>
#include <limits>
#include <ctime>
/* --------------- librerias c++ --------------- */

/* --------------- headers --------------- */
#include "headerFiles/logMenu.h"
/* --------------- headers --------------- */

using namespace std;

/* --------------- prototipos --------------- */
void b();
/* --------------- prototipos --------------- */

/* --------------- variables --------------- */
static int bucle;				//retorno a menu
/* --------------- variables --------------- */

int main() {
	setlocale(LC_ALL, "");

	//inicializador
	start();
	b();
	//freeN(grades, tAlumnos);

	getch();

	return 0;
}

/* --------------- funciones --------------- */
void b() {
	if(menu_option != 4) {
		do {
			if(cin.fail()) {
				cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				
				cout<<"\ningrese opcion valida: "<<endl;
				cin>>menu_option;
				
				selected();
			}
			else {
				cout<<"\n[1] Volver al menu [2] Salir"<<endl;
				cin>>bucle;

				if(bucle == 1) {
					system("cls");
				
					menu();
				
					if(menu_option == 3) {
						break;
					}
				}
			}
		} while(cin.fail());
	}
}
/* --------------- funciones --------------- */
