#include "FuncionesCC.c"
#include "FuncionesCC.h"
#include <stdio.h>


int main(){
	int pisos, numLoc;
	printf("Pisos: "); scanf("%d", &pisos);
	printf("Locales por piso: "); scanf("%d", &numLoc);
	local **centroC = fill(pisos, numLoc);
    //inicializarCC(centroC);
    
    int choice;
    do{
    	choice = menu();
    	switch(choice){
    		case 1:
    			agregarLocal(centroC);
    			break;
    		case 2:
    			dispLocales(centroC);
    			break;
    		case 3:
    			mostrarLocales(centroC);
    			break;
    		case 4:
    			eliminarLocal(centroC);
    			break;
    		case 5:
    			cambiarNombreLocal(centroC);
    			break;
    		case 6:
    			buscarLocal(centroC);
    			break;
		}
	}while(choice != 0);
    
	return 0;
}
