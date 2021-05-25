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
//#include "dataGroup.h"
/* --------------- headers --------------- */

using namespace std;

/* --------------- prototipos --------------- */
void makeFile();
/* --------------- prototipos --------------- */

/* --------------- estructuras --------------- */
/* --------------- estructuras --------------- */

/* --------------- variables --------------- */
/* --------------- variables --------------- */

/* --------------- funciones --------------- */
void makeFile() {
	fstream dataFile;
	fstream read_dataFile("promedioGrupos.csv", ios::in);
	
	if(!read_dataFile) {
		cout<<"Creando archivo..."<<endl;
		fstream make_dataFile("promedioGrupos.csv", ios::out);
		make_dataFile<<"alumnos/materias"<<endl;
	}
}
/* --------------- funciones --------------- */
