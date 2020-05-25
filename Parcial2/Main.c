#include "FuncionesCC.c"
#include "FuncionesCC.h"
#include <stdio.h>


int main(){
	int pisos, numLoc, carg;
	local **centroC;
	do{
		printf("1. Cargar archivo pre-existente\n2. Comenzar desde cero\n");
		scanf("%d", &carg);
		switch(carg){
			case 1: ;
				FILE *fpisr = fopen("pisos.txt", "r");
				FILE *flocr = fopen("numLoc.txt", "r");
				fscanf(fpisr, "%d", &pisos);															//Abre los archivos con las dimensiones pre-existentes
				fscanf(flocr, "%d", &numLoc);
				fclose(fpisr); fclose(flocr);
				centroC = fill(pisos, numLoc);															//Crea el centro comercial
				load(centroC, pisos, numLoc, "cc.bin");													//Carga locales previos
				break;
			case 2: ;
				FILE *borrbin = fopen("cc.bin", "wb"); fclose(borrbin);
				printf("Pisos: "); scanf("%d", &pisos);
				printf("Locales por piso: "); scanf("%d", &numLoc);
				FILE *fpisw = fopen("pisos.txt", "w");
				FILE *flocw = fopen("numLoc.txt", "w");
				fprintf(fpisw, "%d", pisos); fprintf(flocw, "%d", numLoc);
				fclose(fpisw); fclose(flocw);
				centroC = fill(pisos, numLoc);
				break;

 		}
	}while(carg>2 || carg<1);


    int choice;
    do{
    	choice = menu();
    	switch(choice){
    		case 1:
    			agregarLocal(centroC, pisos, numLoc);
    			break;
    		case 2:
    			dispLocales(centroC, pisos, numLoc);
    			break;
    		case 3:
    			mostrarLocales(centroC, pisos, numLoc);
    			break;
    		case 4:
    			eliminarLocal(centroC, pisos, numLoc);
    			break;
    		case 5:
    			cambiarNombreLocal(centroC, pisos, numLoc);
    			break;
    		case 6:
    			buscarLocal(centroC, pisos, numLoc);
    			break;
    		case 7:
    			rate(centroC, pisos, numLoc);
    			break;
    		case 8:
    			orderByRating(centroC, pisos, numLoc);
    			break;
    		case 15:
    			save(centroC, pisos, numLoc, "cc.bin");
    			break;
    		case 16:
    			break;
    			
		}
	}while(choice != 0);
    
	return 0;
}
