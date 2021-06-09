/* --------------- librerias c++ --------------- */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <locale.h>
#include <ctime>
/* --------------- librerias c++ --------------- */

/* --------------- headers --------------- */
#include "headerFiles/logMenu.h"
/* --------------- headers --------------- */

using namespace std;

/* --------------- prototipos --------------- */
/* --------------- prototipos --------------- */

/* --------------- estructuras --------------- */
/* --------------- estructuras --------------- */

/* --------------- variables --------------- */
int bucle; 				//retorno a menu
/* --------------- variables --------------- */

int main() {
	setlocale(LC_ALL, "");

	//inicializador
	start();
	
	if(menu_option != 3) {
		do {
			cout<<"\n[1] Volver al menu [2] Salir"<<endl;
			cin>>bucle;
			
			if(bucle == 1) {
				system("cls");
				
				menu();
				
				if(menu_option == 3) {
					break;
				}
			}
		} while(bucle == 1);
	}

	getch();

	return 0;
}

/* --------------- funciones --------------- */
/* --------------- funciones --------------- */
