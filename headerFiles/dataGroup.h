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
	SMateria materia;
	float promedio;
} SAlumno;

//struct de grupo
typedef struct {
	char nombre[10];
	SAlumno alumno;
	float promedio;
} SGrupo;
/* --------------- estructuras --------------- */

/* --------------- variables --------------- */
//array de struct dinamicos
SMateria *materias = NULL;
SAlumno *alumnos = NULL;
SGrupo *grupos = NULL;

//cantidad de elementos
int tMaterias = 0, tAlumnos = 0, tGrupos = 0;
int masDatos, contG;
/* --------------- variables --------------- */

/* --------------- prototipos --------------- */
//asignacion de memoria
void materia_dm(int &);
void alumno_dm(int &);
void grupo_dm(int &);

//escritura de datos
void writeM();
void writeA();
void writeG();

//impresion de datos
void printG();
/* --------------- prototipos --------------- */

/* --------------- funciones --------------- */
void materia_dm(int &cantM) {
	++cantM;

	materias = new SMateria[cantM];
}

void alumno_dm(int &cantA) {
	++cantA;

	alumnos = new SAlumno[cantA];
}

void grupo_dm(int &cantG) {
	++cantG;

	grupos = new SGrupo[cantG];
}

void writeM() {
	materia_dm(tMaterias);

	cout<<"--- MATERIA ---"<<endl;
	cout<<"Nombre: ";
	cin.ignore();
	cin.getline(materias->nombre, 10, '\n');
	cout<<"Calificaión: ";
	cin>>materias->nota;
	cout<<"¿agregar otra materia? [1] si [2] no ";
	cin>>masDatos;
	
	if(masDatos == 1) {
		writeM();
	}
}

void writeA() {
	alumno_dm(tAlumnos);

	cout<<"--- ALUMNO ---"<<endl;
	cout<<"Nombre: ";
	cin.ignore();
	cin.getline(alumnos->nombre, 10, '\n');
	cout<<"agregar materias: [1] si [2] no ";
	cin>>masDatos;
	
	if(masDatos == 1) {
		writeA();
	}
}

void writeG() {
	grupo_dm(tGrupos);

	cout<<"---- GRUPO ----"<<endl;
	cout<<"Nombre: ";
	cin.ignore();
	fflush(stdin);
	cin.getline(grupos[contG].nombre, 10, '\n');

	contG++;

	cout<<"agregar alumnos: [1] si [2] no ";
	cin>>masDatos;
	
	if(masDatos == 1) {
		alumno_dm(tAlumnos);
	}
	
	cout<<"¿agregar otro grupo? [1] si [2] no ";
	cin>>masDatos;
	
	if(masDatos == 1) {
		writeG();
	}
}

void printG() {
	cout<<"--- GRUPOS REGISTRADOS ---"<<endl;

	for(int i = 0; i < tGrupos; i++) {
		cout<<"["<<i + 1<<"] "<<grupos[i].nombre<<endl;
	}
}
/* --------------- funciones --------------- */
