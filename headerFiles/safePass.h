/* --------------- librerias c++ --------------- */
#include <iostream>
#include <conio.h>
/* --------------- librerias c++ --------------- */

using namespace std;

/* --------------- prototipos --------------- */
void leerPasw(char frase[]);
/* --------------- prototipos --------------- */

/* --------------- funciones --------------- */
void leerPasw(char frase[]) {
    int i = 0;

    cout.flush();

    do {
        frase[i] = (unsigned char)getch();

        if(frase[i] != 8) { //backspace
            cout<<'*';
            i++;
        }
        else if(i > 0) { //backspace, hay caracteres
            cout << (char)8 << (char)32 << (char)8;
            i--;  //caracter a borrar es backspace
        }

        cout.flush();
    } while(frase[i - 1] != 13); //ENTER

    frase[i - 1] = NULL;

    cout<<endl;
}
/* --------------- funciones --------------- */
