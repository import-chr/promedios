/* --------------- librerias c++ --------------- */
#include <iostream>
#include <locale.h>
#include <string.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <limits>
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
	vector<int> notas{};
} Grupo;
/* --------------- estructuras --------------- */

/* --------------- variables --------------- */
//array dinamico => struct
Grupo *grupos = NULL;

//matriz dinamica => notas
float **grades = NULL;

static int tGrupos, tAlumnos, tMaterias;
static float nota;
static string almn, gpr;
/* --------------- variables --------------- */

/* --------------- prototipos --------------- */
//asignancion de memoria
void memoriaG(int &);
void memoriaN(int &, int &);

//escritura de datos
void writeGrupo(int &);
void addA(string &, int);
void addM(string &, int);
void writeNotas(float, int &, int &, int &);
void getData();

//impresion de datos
void printGrupos();
void printAlumnos(int &); //int => grupo seleccionado
/* --------------- prototipos --------------- */

/* --------------- funciones --------------- */
//asignacion de memoria a struct Grupo
void memoriaG(int &tG) {
    cout<<"cuantos grupos desea agregar? ";
    cin>>tG;

    grupos = new Grupo[tG];
}

//asignacion de memoria a struct Grupo => notas
void memoriaN(int &filas, int &columnas) {
	grades = new float *[filas];

	for(int f = 0; f < filas; f++) {
		grades[f] = new float[columnas];
	}
}

//escritura de datos de struct Grupo
void writeGrupo(int &iter) {
	cout<<endl;
    cout<<"--- GRUPO ["<<iter + 1<<"] ---"<<endl;
    cout<<"Nombre: ";
    fflush(stdin);
    cin.getline(grupos[iter].grupo, 10, '\n');
	strupr(grupos[iter].grupo);
	cout<<"--- "<<grupos[iter].grupo<<": ALUMNOS ---"<<endl;
	cout<<"\nnumero de alumnos: ";
	fflush(stdin);
	cin>>tAlumnos;

	//llamada en bucle a añadir alumno
	for(int i = 0; i < tAlumnos; i++) {
		addA(almn, iter);
	}

	cout<<"--- "<<grupos[iter].grupo<<": MATERIAS ---"<<endl;
	cout<<"\nnumero de materias: ";
	fflush(stdin);
	cin>>tMaterias;

	//llamada en bucle a añadir materia
	for(int i = 0; i < tMaterias; i++) {
		addM(gpr, iter);
	}

	//cout<<"m: "<<tMaterias<<" a: "<<tAlumnos;
	//reservacion de memoria matriz => grades[][]
	memoriaN(tAlumnos, tMaterias);

	cout<<"--- "<<grupos[iter].grupo<<": CALIFICAIONES ---"<<endl;
	cin.sync();

	writeNotas(nota, tAlumnos, tMaterias, iter);
}

//agrega alumno al vector alumnos en struct Grupo
void addA(string &str, int p) {
	cout<<"["<<p + 1<<"] "<<"Nombre: ";
	fflush(stdin);
	cin>>str;

	cin.sync();

	grupos[p].alumnos.push_back(str);
}

//agrega materia al vector materias en struct Grupo
void addM(string &str, int p) {
	cout<<"["<<p + 1<<"] "<<"Nombre: ";
	fflush(stdin);
	cin>>str;

	cin.sync();

	grupos[p].materias.push_back(str);
}

//escritura de matriz => grades[][];
void writeNotas(float calif, int &tA, int &tM, int &posG) {
	//peticion de cada calificaion
	for(int a = 0; a < tA; a++) {
		for(int m = 0; m < tM; m++) {
			cout<<grupos[posG].alumnos[a]<<": ";
			cout<<grupos[posG].materias[m]<<endl;
			cout<<"Calificion: ";
			fflush(stdin);
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin>>calif;

			//asignacion de valores => grades[][] => alumno[materia * tMaterias]
			grades[a][m] = calif;
		}
	}

	//impresion de valores => grades[][] => alumno[materia * tMaterias]
	/* for(int f = 0; f < tA; f++) {
		for(int c = 0; c < tM; c++) {
			cout<<"cal: "<<grades[f][c]<<endl;
		}
	} */
}

//peticion general de datos
void getData() {
	memoriaG(tGrupos);

	//memoriaG => cantidad de memoria reservada para grupos
	for(int i = 0; i < tGrupos; i++){
		writeGrupo(i);
	}
}

//impresion de grupos
void printGrupos() {
	for(int i = 0; i < tGrupos; i++) {
		cout<<"["<<i + 1<<"] "<<grupos[i].grupo<<endl;
	}
}

//impresion de alumnos
void printAlumnos(int &s) {
	cout<<"--- "<<grupos[s - 1].grupo<<" ---"<<endl;

	for(int j = 0; j < grupos[s - 1].alumnos.size(); j++) {
		cout<<"["<<j + 1<<"] "<<grupos[s - 1].alumnos[j]<<endl;
	}
}
/* --------------- funciones --------------- */
