#include "FuncionesCC.h"
#include <string.h>
/* Funcion de ejemplo que imprimiria la informacion de un local */
/*void mostrarLocal(local ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso) {
	
	//Se valida si el numero ingresado esta en el rango
	if(numPiso<=numLocalxPiso && numLocalxPiso <= numLocalesxPiso)
	{
		printf("Nombre local : %s", centroC[numPiso][numLocalxPiso].nombreLocal);
		printf("Numero local : %d ", centroC[numPiso][numLocalxPiso].numeroLocal);
	}
	//TODO completarlo con los datos que le sirvan en su caso
}
*/
int menu(){
	int selec;
	printf("\nBienvenido al centro comercial PostCuarentena\n");
	printf("----------------------------------------------\n");
	printf("1. Agregar local\n");
	printf("2. Display disponibilidad de locales\n");
	printf("3. Mostrar locales\n");
	printf("4. Eliminar Local\n");
	printf("5. Modificar nombre local\n");
	printf("6. Encontrar local\n");
	printf("Para salir, ingrese cero (0)\n");
	printf("Seleccion: ");
	scanf("%d", &selec);
	return selec;
}

void inicializarCC(local centroC[COL][FIL]){					//Se usa para que el arreglo de locales no tenga asignacion de valores basura que ya existen en la memoria
	int c, j;
	for(c = 0; c<COL; c++){
		for(j = 0; j<FIL; j++){
			centroC[c][j].idLocal = c*j;						//ID "unico" pues es producto de el numero de fila*columna, el cual ser� distinto para cada celda
			centroC[c][j].pisoLocal = c;
			centroC[c][j].numLocalxPiso = j;
			centroC[c][j].dispo = disp;							//Se asigna el enum de disponibilidad de toda la matriz a DISP para que en cualquier celda se pueda asignar un local
		}
		
	}
}

void agregarLocal(local centroC[COL][FIL]){
	int piso=0, loc=0;
	

	printf("Piso: ");
	scanf("%d", &piso);
	printf("Numero Local: ");
	scanf("%d", &loc);
	if((piso>10 || piso<1) || (loc>5 || loc<1)){				//Asegura que los valores esten dentro de los rangos de tama�o de la matriz
		printf("Por favor digite un piso y un numero de local v�lidos\n");
		agregarLocal(centroC);
		return;
	}else if(centroC[piso][loc].dispo == noDisp){				//Verifica disponibilidad del espacio en la matriz
		printf("Local ocupado. Por favor intentar de nuevo\n");
		agregarLocal(centroC);									//Vuelve a correr la funcion hasta que el usuario digite valores validos.
		return;

	}else{
		printf("Nombre local: ");
		scanf("%s", centroC[piso][loc].nombreLocal);
		
		centroC[piso][loc].dispo = noDisp;
		printf("Local agregado exitosamente: \n");				//Confirma que se agrega un local y hace display de su informacion
		printf("Nombre: %s\nUbicacion: Piso %d, Local %d\nID Local: %d\n", centroC[piso][loc].nombreLocal, centroC[piso][loc].pisoLocal, centroC[piso][loc].numLocalxPiso, centroC[piso][loc].idLocal);
	}
	
}

void mostrarLocales(local centroC[COL][FIL]){					//Imprime todas las celdas "noDisp", es decir, que tienen un local presente. De no tener local, no imprime nada de esa celda
	int c, j;
	for(c = 0; c<COL; c++){
		for(j = 0; j<FIL; j++){
			if(centroC[c][j].dispo == noDisp){
				printf("%s\nPiso %d, Local %d\nID: %d", centroC[c][j].nombreLocal, centroC[c][j].pisoLocal, centroC[c][j].numLocalxPiso, centroC[c][j].idLocal);
				printf("\n---------\n");
			}
		}
	}
}

void dispLine(local centroC[COL][FIL], int col, int fil){		//Imprime de forma recursiva una matriz de O y X, donde O representa un espacio vacio, y X un local
	if(fil == FIL){								
		printf("]\n");
	}else{
		if(centroC[col][fil].dispo == disp){
			printf("O");
			dispLine(centroC, col, fil+1);
		}else{
			printf("X");
			dispLine(centroC, col, fil+1);
		}
	}
}

void dispLocales(local centroC[COL][FIL]){						//Utiliza la funcion anterior dispLine para imprimir cada fila de la "matriz" de X y O
	int i;
	for(i = 1; i<11; i++){
		printf("[");
		dispLine(centroC, i, 1);
	}
		
}

void eliminarLocal(local centroC[COL][FIL]){					//Elimina un local de la matriz
	int col, fil;
	printf("Ingrese el piso y el numero de local a borrar: \nPiso: ");
	scanf("%d", &col);
	printf("\nLocal: ");
	scanf("%d", &fil);
	centroC[col][fil].dispo = disp;								//Lo que hace es settear la disponibilidad de la celda a disp para que se pueda sobreescribir con otro nombre de local y no se haga display de el mientras tanto
	printf("\nSe ha eliminado %s del centro comercial\n", centroC[col][fil]);
	return;
	
}

void cambiarNombreLocal(local centroC[COL][FIL]){				//Cambia el nombre de un local luego de buscarlo con strcmp
	int c, j;
	char nameChange[25];											//Pide el nombre a buscar
	printf("Ingrese el nombre del local que desea cambiar: ");
	scanf("%s", nameChange);
	for(c = 1; c<COL; c++){
		for(j = 1; j<FIL; j++){
			if(!strcmp(centroC[c][j].nombreLocal, nameChange)){
				printf("Ingrese el nuevo nombre: ");
				scanf("%s", centroC[c][j].nombreLocal);			//Cambia el nombre previo por uno ingresado por el usuario
				printf("Nombre cambiado exitosamente\n");		//Confirma el cambio
				return;
			}
		}
	}
	printf("No se encontr� el local con ese nombre \nF\n");		//Si no encuentra el local, sale
	return;
}

void buscarLocal(local centroC[COL][FIL]){						//Busca la ubicacion de un local
	int c, j;
	char buscar[25];
	printf("Ingrese el nombre del local que desea encontrar: ");
	scanf("%s", buscar);
	for(c = 1; c<COL; c++){
		for(j = 1; j<FIL; j++){
			if(!strcmp(centroC[c][j].nombreLocal, buscar)){
				printf("Nombre encontrado en piso %d, local %d\n", centroC[c][j].pisoLocal, centroC[c][j].numLocalxPiso);
				return;
			}
		}
	}
	printf("No se encontr� el local con ese nombre \nF\n");
	return;
}


