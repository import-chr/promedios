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

/* --------------- prototipos --------------- */
//asignacion de memoria
void asignaMemMateria(int *);
void asignaMemAlumno(int *);
void asignaMemGrupo(int *);

//escritura de datos
void writeMateria(int);
void writeAlumno(int);
void writeGrupo(int);

void printGrupos();
/* --------------- prototipos --------------- */

/* --------------- estructuras --------------- */
//Materia
typedef struct m {
	char nombreM[10];
	float calificacion;
	float promedioM;
} Materias;

//Alumno
typedef struct a {
	char nombresA[10];
	char apellidos[10];
	m unidadesA;
	float promedioA;
} Alumnos;

//Grupo
typedef struct g {
	char nombreG[10];
	a discentes;
	float promedioG;
} Grupos;
/* --------------- estructuras --------------- */

/* --------------- variables --------------- */
Materias *materias;
Alumnos *alumnos;
Grupos *grupos;

int tMaterias = 0, tAlumnos = 0, tGrupos = 0, masDatos;				//tamaño de los vectores
/* --------------- variables --------------- */

/* --------------- funciones --------------- */
//asiganacion de memoria a las materias
void asignaMemMateria(int *cantM) {
	materias = (Materias*) malloc((*cantM + 1) * sizeof(Materias));
	
	writeMateria(*cantM);
	
	(*cantM)++;
	//tMaterias++;
}

//asignacion de memoria a los alumnos
void asignaMemAlumno(int *cantA) {
	alumnos = (Alumnos*) malloc((*cantA + 1) * sizeof(Alumnos));
	
	writeAlumno(*cantA);
	
	(*cantA)++;
	//tAlumnos++;
}

//asignacion de memoria a los grupos
void asignaMemGrupo(int *cantG) {
	grupos = (Grupos*) malloc((*cantG + 1) * sizeof(Grupos));
	
	writeGrupo(*cantG);
	
	(*cantG)++;
	//tGrupos++;
}

//escritura de datos de la materia
void writeMateria(int cantm) {
	cout<<"\t --- Materia ---"<<endl;
	cout<<"Nombre: ";
	cin.ignore();
	cin.getline(materias -> nombreM, 10, '\n');
	cout<<"Calificación: ";
	cin>>materias -> calificacion;
	cout<<"¿agregar otra materia? [1] si [2] no ";
	cin>>masDatos;
	
	if(masDatos == 1) {
		asignaMemMateria(&cantm);
	}
}

//escritura de datos del alumno
void writeAlumno(int canta) {
	cout<<"\t --- Alumno ---"<<endl;
	cout<<"Nombre: ";
	cin.ignore();
	cin.getline(alumnos -> nombresA, 10, '\n');
	cout<<"Apellidos: ";
	cin.getline(alumnos -> apellidos, 10, '\n');
	cout<<"agregar materias: [1] si [2] no ";
	cin>>masDatos;
	
	if(masDatos == 1) {
		asignaMemMateria(&canta);
	}
}

//escritura de datos del grupo
void writeGrupo(int cantg) {
	cout<<"\t ---- Grupo ----"<<endl;
	cout<<"Nombre: ";
	cin.ignore();
	fflush(stdin);
	cin.getline(grupos -> nombreG, 10, '\n');
	cout<<"Grupo: "<<grupos -> nombreG<<endl;
	cout<<"agregar alumnos: [1] si [2] no ";
	cin>>masDatos;
	
	if(masDatos == 1) {
		asignaMemAlumno(&cantg);
	}
	
	cout<<"¿agregar otro grupo? [1] si [2] no ";
	cin>>masDatos;
	cout<<"Cantidad de grupos: "<<tGrupos<<endl;
	
	if(masDatos == 1) {
		asignaMemGrupo(&tGrupos);
	}
}

//imprime grupos
void printGrupos() {
	cout<<"   --- GRUPOS REGISTRADOS ---"<<endl;

	for(int i = 0; i < tGrupos; i++) {
		cout<<"["<<i + 1<<"] "<<grupos -> nombreG[i]<<endl;
	}
}
/* --------------- funciones --------------- */
