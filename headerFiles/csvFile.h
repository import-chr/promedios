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
#include "dataGroup.h"
/* --------------- headers --------------- */

using namespace std;

/* --------------- prototipos --------------- */
bool writeFile(string);
/* --------------- prototipos --------------- */

/* --------------- variables --------------- */
string fileCSV = "promedioGrupos.csv";
/* --------------- variables --------------- */

/* --------------- funciones --------------- */
//escritura en archivo .csv
bool writeFile(string fileName) {
    bool err = false;
    int i, j;
    grupos = start_gpr;

    ofstream csv_file;
    csv_file.open(fileName.c_str());                    //apertura de archivo

    if(!csv_file) {
        err = true;
    }
    else {
        while(grupos != NULL) {
            csv_file<<grupos->grupo<<endl;                  //insercion nombre de grupo
            csv_file<<grupos->media<<endl;                  //inserccion promedio grupal
            csv_file<<"Materias"<<endl;

            //insercion de materias y sus promedios
            for(i = 0; i < grupos->cantM; i++) {
                csv_file<<grupos->materias[i]<<",";
                csv_file<<grupos->mediaMtr[i]<<endl;
            }

            csv_file<<"Alumnos"<<endl;

            //insercion de alumnos y sus promedios
            for(j = 0; j < grupos->cantA; j++) {
                csv_file<<grupos->alumnos[j]<<",";
                csv_file<<grupos->mediaAlmn[j]<<endl;
            }

            csv_file<<endl<<endl;

            grupos = grupos->next;
        }

        csv_file.close();                               //cierre de archivo
    }

    return err;
}
/* --------------- funciones --------------- */
