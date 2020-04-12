#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define COL 11  //Para asegurar que se pueda tener del piso 1 al 10, en vez de tener del 0 al 9
#define FIL 6
//Local
typedef enum disponibilidad{
    disp, noDisp
}disponibilidad;

typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
    disponibilidad dispo;

    
	// Completelo con lo que quiera
} local;



/*Agregar las funciones que necesite para satisfacer los requerimientos */
void mostrarLocal(local ** centroC, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso);

void inicializarCC(local centroC[COL][FIL]);

void agregarLocal(local centroC[COL][FIL]);

int menu();

void dispLine(local centroC[COL][FIL], int col, int fil);

void dispLocales(local centroC[COL][FIL]);

void mostrarLocales(local centroC[COL][FIL]);

void eliminarLocal(local centroC[COL][FIL]);

void cambiarNombreLocal(local centroC[COL][FIL]);

void buscarLocal(local centroC[COL][FIL]);




#endif /* FUNCIONESCC_H_ */
