/* --------------- librerias c++ --------------- */
#include <iostream>
#include <locale.h>
#include <string.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
/* --------------- librerias c++ --------------- */

using namespace std;

/* --------------- headers --------------- */
/* --------------- headers --------------- */

/* --------------- estructuras --------------- */
//struct de grupo
typedef struct {
    char grupo[10];
    vector<string> alumnos{};
    vector<string> materias{};
    //vector<int> notas{};
} Grupo;
/* --------------- estructuras --------------- */

/* --------------- variables --------------- */
//array dinamico de struct
Grupo *grupos = NULL;

int tGrupos, tAlumnos, tMaterias;
string almn, gpr;
/* --------------- variables --------------- */

/* --------------- prototipos --------------- */
//asignancion de memoria
void memoriaG(int &);

//escritura de datos
void writeGrupo(int &);
void addA(string &, int);
void addM(string &, int);
void getData();
/* --------------- prototipos --------------- */

/* --------------- funciones --------------- */
void memoriaG(int &tG) {
    cout<<"¿cuántos grupos desea agregar? ";
    cin>>tG;

    grupos = new Grupo[tG];
}

void writeGrupo(int &iter) {
	cout<<endl;
    cout<<"--- GRUPO ["<<iter + 1<<"] ---"<<endl;
    cout<<"Nombre: ";
    fflush(stdin);
    cin.getline(grupos[iter].grupo, 10, '\n');
	strupr(grupos[iter].grupo);
	cout<<"--- "<<grupos[iter].grupo<<": ALUMNOS ---"<<endl;
	cout<<"\nnúmero de alumnos: ";
	fflush(stdin);
	cin>>tAlumnos;

	for(int i = 0; i < tAlumnos; i++) {
		addA(almn, i);
	}

	cout<<"--- "<<grupos[iter].grupo<<": MATERIAS ---"<<endl;
	cout<<"\nnúmero de materias: ";
	fflush(stdin);
	cin>>tMaterias;

	for(int i = 0; i < tMaterias; i++) {
		addM(gpr, i);
	}
}

void addA(string &str, int p) {
	cout<<"["<<p + 1<<"]"<<"Nombre: ";
	fflush(stdin);
	cin>>str;

	grupos->alumnos.push_back(str);
}

void addM(string &str, int p) {
	cout<<"["<<p + 1<<"]"<<"Nombre: ";
	fflush(stdin);
	cin>>str;

	grupos->materias.push_back(str);
}

void getData() {
	memoriaG(tGrupos);

	for(int i = 0; i < tGrupos; i++){
		writeGrupo(i);
	}
}
/* --------------- funciones --------------- */
