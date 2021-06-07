/* --------------- librerias c++ --------------- */
#include <iostream>
#include <locale.h>
#include <string.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
/* --------------- librerias c++ --------------- */

using namespace std;

/* --------------- headers --------------- */
/* --------------- headers --------------- */

/* --------------- estructuras --------------- */
//struct de materia
typedef struct {
	char nombre[10];
	float nota;
	float promedio;
} SMateria;

//struct de alumno
typedef struct {
	char nombre[10];
	SMateria *materia;
	float promedio;
} SAlumno;

//struct de grupo
typedef struct {
	char nombre[10];
	SAlumno *alumno;
	float promedio;
} SGrupo;
/* --------------- estructuras --------------- */

/* --------------- variables --------------- */
//array de struct dinamicos
SMateria *materias = NULL;
SAlumno *alumnos = NULL;
SGrupo *grupos = NULL;

//cantidad de elementos
int tMaterias, tAlumnos, tGrupos;
/* --------------- variables --------------- */

/* --------------- prototipos --------------- */
//asignacion de memoria
void memoriaG(int &, int &);
void memoriaA(int &, int &);
void memoriaM(int &, int&);

//escritura de datos
void writeM(int &);
void writeA(int &);
void writeG(int &, int &);

void getData();
void printData();
/* --------------- prototipos --------------- */

/* --------------- funciones --------------- */
//memoria dinamica -> grupos
void memoriaG(int &cG) {
	cout<<"¿cuantos grupos desea agregar? ";
	cin>>cG;

	grupos = new SGrupo[cG];
}

//peticion de datos -> struct grupo
void writeG(int &tG, int &pG) {
	cout<<"---- GRUPO ----"<<endl;
	cout<<"Nombre: ";
	cin.ignore();
	fflush(stdin);
	cin.getline(grupos[pG].nombre, 10, '\n');
	
	memoriaA(tAlumnos, pG);

    for(int i = 0; i < tAlumnos; i++) {
        writeA(tAlumnos);
    }

    memoriaM(tMaterias, pG);

    for(int i = 0; i < tMaterias; i++) {
        writeM(tMaterias);
    }
}

void printData() {
	for(int i = 0; i < tGrupos; i++) {
		cout<<"["<<i + 1<<"] "<<grupos[i].nombre<<endl;
	}
}

//memoria dinamica -> alumnos
void memoriaA(int &cA, int &pA) {
	cout<<"número de alumnos: ";
	cin>>cA;

	grupos[pA].alumno = new SAlumno[cA];
}

//peticion de datos -> struct alumno
void writeA(int &pA) {
	cout<<"--- ALUMNO ---"<<endl;
	cout<<"Nombre: ";
	cin.ignore();
	fflush(stdin);
	cin.getline(alumnos[pA].nombre, 10, '\n');
}


//memoria dinamica -> materias
void memoriaM(int &cM, int &pM) {
	cout<<"número de materias: ";
	cin>>cM;

    grupos[pM].alumno->materia = new SMateria[cM];
}

//peticion de datos -> struct materia
void writeM(int &pM) {
	cout<<"--- MATERIA ---"<<endl;
	cout<<"Nombre: ";
	cin.ignore();
	fflush(stdin);
	cin.getline(materias[pM].nombre, 10, '\n');
	cout<<"Calificaión: ";
	cin>>materias[pM].nota;
	fflush(stdin);
}

//llamada func:write
void getData() {
    memoriaG(tGrupos);

    for(int i = 0; i < tGrupos; i++) {
        writeG(tGrupos, i);
    }
}
/* --------------- funciones --------------- */
