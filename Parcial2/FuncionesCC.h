#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#import <stdexcept>
#define COL 11  //Para asegurar que se pueda tener del piso 1 al 10, en vez de tener del 0 al 9
#define FIL 6
//Local
typedef enum disponibilidad{
    disp, noDisp
}disponibilidad_e;

typedef struct {
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
    disponibilidad_e dispo;
    int rating[2];							//[visitas, totalRatings]
    int metros2;
    

    
	// Completelo con lo que quiera
} local;



/*Agregar las funciones que necesite para satisfacer los requerimientos */
void mostrarLocal(local ** centroC, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso);

local** fill(int pisos, int numLoc);

void inicializarCC(local** centroC);

void contarLocales(local** centroC, int pisos, int numLoc);

void agregarLocal(local** centroC, int pisos, int numLoc);

int menu();

void dispLine(local** centroC, int col, int fil, int pisos, int numLoc);

void dispLocales(local** centroC, int pisos, int numLoc);

void mostrarLocales(local** centroC, int pisos, int numLoc);

void eliminarLocal(local** centroC, int pisos, int numLoc);

void cambiarNombreLocal(local** centroC, int pisos, int numLoc);

void buscarLocal(local** centroC, int pisos, int numLoc);

void rate(local** centroC, int pisos, int numLoc);
	
void save(local** centroC, int pisos, int numLoc, char* fileName);

void load(local** centroC, int pisos, int numLoc, char* fileName);




#endif /* FUNCIONESCC_H_ */
