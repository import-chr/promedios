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

/* --------------- estructuras --------------- */
//struct de grupo
typedef struct Grupo {
    char grupo[10];
    vector<string> alumnos{};
    vector<string> materias{};
	float media;
	vector<float> mediaAlmn{};
	vector<float> mediaMtr{};
	int cantA, cantM;
	Grupo *next;
};
/* --------------- estructuras --------------- */

//prototipos matriz
//DM => matriz
float **memoriaN(size_t &, size_t &);

//free => matriz
void freeN(float **, size_t);

/* --------------- variables --------------- */
int contGrupo = 1;
int a_, m_;
bool new_gpr_bool = true;
size_t tGrupos, tAlumnos, tMaterias, tPromedios, tMedia;
static int new_gpr_int;
static float nota, prom;
static string almn, gpr;

//DM => struct
Grupo *grupos;					//auxiliar
static Grupo *start_gpr;		//inicio de nodo
static Grupo *end_gpr;			//fin de nodo

//matriz dinamica => notas
float **grades = memoriaN(tAlumnos, tMaterias);
/* --------------- variables --------------- */

/* --------------- prototipos --------------- */
//cola
void startQueue(bool &);

//escritura de datos
void writeGrupo(int &, int , int , size_t &, size_t &, size_t &, size_t &);
void addA(string &);
void addM(string &);
void writeNotas(float **, float, size_t, size_t);
void addN(float);
void addNm(float);

//lectura de datos
void printGrupos(int, int);

//operaciones
float promG(float **, size_t, size_t);
float promA(float **, size_t, int &);
float promM(float **, size_t, int &);
/* --------------- prototipos --------------- */

/* --------------- funciones --------------- */
//inicializa la cola
void startQueue(bool &new_gpr_) {
	start_gpr = NULL;
	end_gpr = NULL;

	while(new_gpr_) {
		grupos = new Grupo;

		writeGrupo(contGrupo, a_, m_, tAlumnos, tMaterias, tPromedios, tMedia);

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
void writeGrupo(int &cont, int ca, int cm, size_t &mA, size_t &mM, size_t &mP, size_t &mtM) {
	float aux_nota_a, aux_nota_g;

	cout<<endl;
    cout<<"--- GRUPO ["<<cont<<"] ---"<<endl;
    cout<<"Nombre (grupo): ";
    fflush(stdin);
    cin.getline(grupos->grupo, 10, '\n');
	strupr(grupos->grupo);

	cout<<"\n--- "<<grupos->grupo<<": ALUMNOS ---"<<endl;
	cout<<"\nnumero de alumnos: ";
	fflush(stdin);
	cin>>ca;

	//llamada en bucle addA()
	for(int i = 0; i < ca; i++) {
		addA(almn);
	}

	cout<<"\n--- "<<grupos->grupo<<": MATERIAS ---"<<endl;
	cout<<"\nnumero de materias: ";
	fflush(stdin);
	cin>>cm;

	//llamada en bucle addM()
	for(int i = 0; i < cm; i++) {
		addM(gpr);
	}

	mA = grupos->alumnos.size();					//largo de vector alumnos
	mM = grupos->materias.size();					//largo de vector materias
	grupos->cantA = ca;
	grupos->cantM = cm;

	//reservacion de memoria
	memoriaN(mA, mM);

	cout<<"\n--- "<<grupos->grupo<<": CALIFICACIONES ---"<<endl;
	cin.sync();

	fflush(stdin);

	writeNotas(grades, nota, mA, mM);

	cout<<"\n--- "<<grupos->grupo<<": PORMEDIO GRUPAL ---"<<endl;

	aux_nota_g = promG(grades, mA, mM);
	grupos->media = aux_nota_g;

	cout<<grupos->media<<endl;

	cout<<"\n--- "<<grupos->grupo<<": PORMEDIO ALUMNO ---"<<endl;

	for(int i = 0; i < mA; i++) {
		aux_nota_a = promA(grades, mM, i);

		addN(aux_nota_a);
	}

	mP = grupos->mediaAlmn.size();					//largo de vector promedios

	//imprime promedio alumno
	for(int i = 0; i < mP; i++) {
		cout<<grupos->alumnos[i]<<": ";
		cout<<grupos->mediaAlmn[i]<<endl;
	}

	cout<<"\n--- "<<grupos->grupo<<": PORMEDIO MATERIA ---"<<endl;

	for(int i = 0; i < mM; i++) {
		aux_nota_a = promM(grades, mA, i);

		addNm(aux_nota_a);
	}

	mtM = grupos->mediaMtr.size();					//largo de vector promedios

	//imprime promedio materia
	for(int i = 0; i < mtM; i++) {
		cout<<grupos->materias[i]<<": ";
		cout<<grupos->mediaMtr[i]<<endl;
	}

	freeN(grades, mA);

	cont++;
}

//escribe el vector alumnos
void addA(string &str) {
	cout<<"GRUPO ["<<contGrupo<<"] "<<"Nombre (alumno): ";
	fflush(stdin);
	cin>>str;

	cin.sync();

	grupos->alumnos.push_back(str);
}

//escribe el vector materias
void addM(string &str) {
	cout<<"GRUPO ["<<contGrupo<<"] "<<"Nombre (materia): ";
	fflush(stdin);
	cin>>str;

	cin.sync();

	grupos->materias.push_back(str);
}

//escribe el vector notas
void addN(float aux_nota) {
	grupos->mediaAlmn.push_back(aux_nota);
}

//escribe el vector notas materia
void addNm(float aux_nota) {
	grupos->mediaMtr.push_back(aux_nota);
}

//reserva memoria para grades[][]
float **memoriaN(size_t &rows, size_t &columns) {
	grades = new float *[rows];

	for(size_t r = 0; r < rows; r++) {
		grades[r] = new float[columns];
	}

	return grades;
}

//libera memoria reservada por grades[][]
void freeN(float **matriz, size_t rows) {
	for(size_t r = 0; r < rows; r++) {
		delete[] matriz[r];
	}

	delete[] matriz;
}

//escritura de la matriz grades[][]
void writeNotas(float **matriz, float cal, size_t tA, size_t tM) {
	for(size_t a(0); a < tA; a++) {
		for(size_t m(0); m < tM; m++) {
			cin.sync();
			cout<<grupos->alumnos[a]<<": ";
			cout<<grupos->materias[m]<<endl;
			cout<<"Calificacion: ";
			fflush(stdin);
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.sync();
			cin>>cal;

			matriz[a][m] = cal;
		}
	}
}

//promedio total de la matriz grades[][]
float promG(float **matriz, size_t r, size_t c) {
	size_t rm, cm;
	float aux_suma, aux_prom;

	for(rm = 0; rm < r; rm++) {
		for(cm = 0; cm < c; cm++) {
			aux_suma += matriz[rm][cm];
		}
	}

	aux_prom = aux_suma / (r * c);

	return aux_prom;
}

//promedio por alumno de la matriz grades[][]
float promA(float **matriz, size_t c, int &iter) {
	size_t cm;
	float aux_suma, aux_prom;

	for(cm = 0; cm < c; cm++) {
		aux_suma += matriz[iter][cm];
	}

	aux_prom = aux_suma / c;
	aux_suma = 0;

	return aux_prom;
}

//promedio por materia de la matriz grades[][]
float promM(float **matriz, size_t r, int &iter) {
	size_t rm;
	float aux_suma, aux_prom;

	for(rm = 0; rm < r; rm++) {
		aux_suma += matriz[rm][iter];
	}

	aux_prom = aux_suma / r;
	aux_suma = 0;

	return aux_prom;
}

//impresion de grupos capturados
void printGrupos() {
	grupos = start_gpr;

	while(grupos != NULL) {
		int ta = grupos->cantA;
		int tm = grupos->cantM;

		cout<<endl<<"---------- "<<grupos->grupo<<" ----------"<<endl;
		cout<<"Promedio Grupal: ";
		cout<<grupos->media<<endl;

		cout<<endl<<"--- Materias ---"<<endl;
		cout<<"Nombre: Promedio"<<endl;

		for(int i = 0; i < tm; i++) {
			cout<<grupos->materias[i];
			cout<<": ";
			cout<<grupos->mediaMtr[i]<<endl;
		}

		cout<<endl<<"--- Alumnos ---"<<endl;
		cout<<"Nombre: Promedio"<<endl;

		for(int i = 0; i < ta; i++) {
			cout<<grupos->alumnos[i];
			cout<<": ";
			cout<<grupos->mediaAlmn[i]<<endl;
		}

		grupos = grupos->next;
	}
}
/* --------------- funciones --------------- */
