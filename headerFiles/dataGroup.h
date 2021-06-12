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
typedef struct Grupo {
    char grupo[10];
    vector<string> alumnos{};
    vector<string> materias{};
	float media;
	Grupo *next;
};
/* --------------- estructuras --------------- */

/* --------------- variables --------------- */
//DM => struct
Grupo *grupos;					//auxiliar
static Grupo *start_gpr;		//inicio de nodo
static Grupo *end_gpr;			//fin de nodo

//matriz dinamica => notas
float **grades = NULL;

int contGrupo = 1;
bool new_gpr_bool = true;
static int a_, m_, new_gpr_int;
static float nota;
static size_t tGrupos, tAlumnos, tMaterias;
static string almn, gpr;
/* --------------- variables --------------- */

/* --------------- prototipos --------------- */
//cola
void startQueue(bool &);

//DM => matriz
void memoriaN(size_t &, size_t &);

//escritura de datos
void writeGrupo(int &, size_t &, size_t &);
void addA(string &);
void addM(string &);
void writeNotas(float, size_t &, size_t &);

//operaciones
float promedio();
/* --------------- prototipos --------------- */

/* --------------- funciones --------------- */
//inicializa la cola
void startQueue(bool &new_gpr_) {
	start_gpr = NULL;
	end_gpr = NULL;

	while(new_gpr_) {
		grupos = new Grupo;

		writeGrupo(contGrupo, tAlumnos, tMaterias);

		if(start_gpr == NULL) {
			start_gpr = grupos;
			end_gpr = grupos;
			grupos->next = NULL;
		}
		else {
			end_gpr->next = grupos;
			grupos->next = NULL;
			end_gpr = grupos;
		}
		cout<<"agregar otro grupo: [1] Si [2] No\n";
		cin>>new_gpr_int;

		(new_gpr_int == 1) ? new_gpr_ = true : new_gpr_ = false;
	}
}

//escritura de datos de struct Grupo
void writeGrupo(int &cont, size_t &mA, size_t &mM) {
	cout<<endl;
    cout<<"--- GRUPO ["<<cont<<"] ---"<<endl;
    cout<<"Nombre (grupo): ";
    fflush(stdin);
    cin.getline(grupos->grupo, 10, '\n');
	strupr(grupos->grupo);

	cout<<"\n--- "<<grupos->grupo<<": ALUMNOS ---"<<endl;
	cout<<"\nnumero de alumnos: ";
	fflush(stdin);
	cin>>a_;

	//llamada en bucle addA()
	for(int i = 0; i < a_; i++) {
		addA(almn);
	}

	//cout<<grupos->alumnos.size()<<endl;

	cout<<"\n--- "<<grupos->grupo<<": MATERIAS ---"<<endl;
	cout<<"\nnumero de materias: ";
	fflush(stdin);
	cin>>m_;

	//llamada en bucle addM()
	for(int i = 0; i < m_; i++) {
		addM(gpr);
	}

	//cout<<grupos->materias.size()<<endl;

	mA = grupos->alumnos.size();					//largo de vector alumnos
	mM = grupos->materias.size();					//largo de vector materias

	//reservacion de memoria
	memoriaN(mA, mM);

	//cout<<"\nta:"<<tAlumnos<<"\ntm:"<<tMaterias<<endl;

	cout<<"--- "<<grupos->grupo<<": CALIFICACIONES ---"<<endl;
	cin.sync();

	writeNotas(nota, mA, mM);

	cont++;
}

void addA(string &str) {
	cout<<"GRUPO ["<<contGrupo<<"] "<<"Nombre (alumno): ";
	fflush(stdin);
	cin>>str;

	cin.sync();

	grupos->alumnos.push_back(str);
}

void addM(string &str) {
	cout<<"GRUPO ["<<contGrupo<<"] "<<"Nombre (materia): ";
	fflush(stdin);
	cin>>str;

	cin.sync();

	grupos->materias.push_back(str);
}

void memoriaN(size_t &rows, size_t &columns) {
	grades = new float *[rows];

	for(int r = 0; r < rows; r++) {
		grades[r] = new float[columns];
	}
}

void writeNotas(float cal, size_t &tA, size_t &tM) {
	for(int a = 0; a < tA; a++) {
		for(int m = 0; m < tM; m++) {
			cout<<grupos->alumnos[a]<<": ";
			cout<<grupos->materias[m]<<endl;
			cout<<"Calificacion: ";
			fflush(stdin);
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin>>cal;

			grades[a][m] = cal;
		}
	}
}

//float promedio() {}
/* --------------- funciones --------------- */
