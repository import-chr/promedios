/* --------------- librerias c++ --------------- */
#include <iostream>
#include <locale.h>
#include <string.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
/* --------------- librerias c++ --------------- */

using namespace std;

/* --------------- headers --------------- */
#include "csvFile.h"
/* --------------- headers --------------- */

/* --------------- prototipos --------------- */
void writeMateria(struct materia_datos);					//escritura de materias
void writeAlumno(struct alumno_datos, int &);				//escritura de alumnos
void writeGrupo(struct grupo_datos, int &);					//escritura de grupos
void llamadas(int &);										//llamada de func
/* --------------- prototipos --------------- */

/* --------------- variables --------------- */
int nDiscentes = 2, nMaterias = 3, nGrupos = 2, answer;		//memoria estatica
/* --------------- variables --------------- */

/* --------------- estructuras --------------- */
//datos por materia
struct materia_datos {
	char unidadA[10];
	float calificaion;
	float promedio;
} materia_[3];

//datos por alumno
struct alumno_datos {
	char nombres[15];
	char apellidos[15];
	materia_datos unidadAprendizaje;
	float promedio;
} alumno_[2];

//datos por grupo
struct grupo_datos {
	char nombre[10];
	alumno_datos discente;
	float promedio;
} grupo_[2];
/* --------------- estructuras --------------- */

/* --------------- funciones --------------- */
//escribe datos para materias
void writeMateria(struct materia_datos materia) {
	cout<<"Datos de la materia"<<endl;
	cout<<"Unidad de aprendizaje: ";
	cin.ignore();
	cin.getline(materia.unidadA, 10);
	cout<<"Calificaión obtenida: ";
	cin>>materia.calificaion;
	fflush(stdin);
}

//escribe datos para alumnos
void writeAlumno(struct alumno_datos alumno, int &nM) {
	cout<<"Datos del alumno"<<endl;
	cout<<"Nombres: ";
	cin.ignore();
	cin.getline(alumno.nombres, 15);
	cout<<"Apellidos: ";
	cin.getline(alumno.apellidos, 15);
	fflush(stdin);

	cout<<"¿Desea agregar materias ahora?\n[1] si\n[2] no\n";
	cin>>answer;
	
	if(answer == 1) {		
		//writeMateria(-) por cada materia del alumno
		for(int i = 0; i < nM; i++) {
			writeMateria(materia_[i]);
		}
	}
}

//escribe datos para grupos
void writeGrupo(struct grupo_datos grupo, int &nA) {
	cout<<"Grupo: ";
	cin.ignore();
	cin.getline(grupo.nombre, 10);
	fflush(stdin);
	
	cout<<"¿Desea agregar alumnos ahora?\n[1] si\n[2] no\n";
	cin>>answer;
	
	if(answer == 1) {
		//writeAlumno(-) por cada alumno del grupo
		for(int i = 0; i < nA; i++) {
			writeAlumno(alumno_[i], nMaterias);
		}
	}
}

//llamadas generales
void llamadas(int &nG) {
	for(int i = 0; i < nG; i++) {
		writeGrupo(grupo_[i], nDiscentes);
	}
	//makeFile();
}
/* --------------- funciones --------------- */
