#include "FuncionesCC.c"
#include "FuncionesCC.h"
#include <stdio.h>


int main(){
	int pisos, numLoc;



	printf("Pisos: "); scanf("%d", &pisos);
	printf("Locales por piso: "); scanf("%d", &numLoc);
	local **centroC = fill(pisos, numLoc);
	load(centroC, pisos, numLoc, "cc.bin");

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
    		case 15:
    			save(centroC, pisos, numLoc, "cc.bin");
    			break;
    		case 16:
    			break;
    			
		}
	}while(choice != 0);
    
	return 0;
}
