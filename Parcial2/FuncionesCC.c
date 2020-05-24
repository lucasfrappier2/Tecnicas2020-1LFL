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
	printf("7. Calificar Local\n");
	
	printf("15. Guardar CC\n");
	printf("Para salir, ingrese cero (0)\n");
	printf("Seleccion: ");
	scanf("%d", &selec);
	return selec;
}

local** fill(int pisos, int numLoc){
	local** centroC = malloc(sizeof(local*)*pisos);

	
	int c, j;
	for(c = 0; c<pisos; c++){
		centroC[c] = malloc(sizeof(local) * numLoc);
		for(j = 0; j<numLoc; j++){
			centroC[c][j].dispo = disp;							//Se asigna el enum de disponibilidad de toda la matriz a DISP para que en cualquier celda se pueda asignar un local
			centroC[c][j].idLocal = c*j;						//ID "unico" pues es producto de el numero de fila*columna, el cual será distinto para cada celda
			centroC[c][j].pisoLocal = c;
			centroC[c][j].numLocalxPiso = j;
			centroC[c][j].rating[0] = 0;
			centroC[c][j].rating[1] = 0;
			centroC[c][j].metros2 = 0;


		}
		
	}
	return centroC;
}

void inicializarCC(local** centroC){					//Se usa para que el arreglo de locales no tenga asignacion de valores basura que ya existen en la memoria
	int c, j;
	for(c = 0; c<COL; c++){
		for(j = 0; j<FIL; j++){
			centroC[c][j].idLocal = c*j;						//ID "unico" pues es producto de el numero de fila*columna, el cual será distinto para cada celda
			centroC[c][j].pisoLocal = c;
			centroC[c][j].numLocalxPiso = j;
			centroC[c][j].dispo = disp;							//Se asigna el enum de disponibilidad de toda la matriz a DISP para que en cualquier celda se pueda asignar un local
		}
		
	}
}

void agregarLocal(local** centroC, int pisos, int numLoc){
	
	int piso=0, loc=0;
	
	do{
		printf("Piso: ");
		scanf("%d", &piso);
		if(piso>pisos){
	    	//throw std::out_of_range;
	    }
		printf("Numero Local: ");
		scanf("%d", &loc);
		if(piso>pisos){
	    	//throw std::out_of_range;
	    }	
	}while(piso>pisos-1 || loc > numLoc-1);
	
/*
	if((piso>pisos || piso<1) || (loc>numLoc || loc<1)){				//Asegura que los valores esten dentro de los rangos de tamaño de la matriz
		printf("Por favor digite un piso y un numero de local válidos\n");
		agregarLocal(centroC);
		return;
	}else if(centroC[piso][loc].dispo == noDisp){				//Verifica disponibilidad del espacio en la matriz
		printf("Local ocupado. Por favor intentar de nuevo\n");
		agregarLocal(centroC);									//Vuelve a correr la funcion hasta que el usuario digite valores validos.
		return;
*/
//	}else{
		if(centroC[piso][loc].dispo == disp){
			printf("Nombre local: ");
			scanf("%s", centroC[piso][loc].nombreLocal);
			
			centroC[piso][loc].dispo = noDisp;
			printf("Local agregado exitosamente: \n");				//Confirma que se agrega un local y hace display de su informacion
			printf("Nombre: %s\nUbicacion: Piso %d, Local %d\nID Local: %d\n", centroC[piso][loc].nombreLocal, centroC[piso][loc].pisoLocal, centroC[piso][loc].numLocalxPiso, centroC[piso][loc].idLocal);	
		}else{
			printf("Local ocupado\n");
		}

//	}
	
}

void mostrarLocales(local** centroC, int pisos, int numLoc){					//Imprime todas las celdas "noDisp", es decir, que tienen un local presente. De no tener local, no imprime nada de esa celda
	int c, j;
	for(c = 0; c<pisos; c++){
		for(j = 0; j<numLoc; j++){
			if(centroC[c][j].dispo == noDisp){
				printf("%s\nPiso %d, Local %d\nID: %d\nRating: %0.1f", centroC[c][j].nombreLocal, centroC[c][j].pisoLocal, centroC[c][j].numLocalxPiso, centroC[c][j].idLocal, (float)centroC[c][j].rating[1]/centroC[c][j].rating[0]);
				printf("\n---------\n");
			}
		}
	}
}

void dispLine(local** centroC, int col, int fil, int pisos, int numLoc){		//Imprime de forma recursiva una matriz de O y X, donde O representa un espacio vacio, y X un local
	if(fil == numLoc){								
		printf("]\n");
	}else{
		if(centroC[col][fil].dispo == disp){
			printf("O");
			dispLine(centroC, col, fil+1, pisos, numLoc);
		}else{
			printf("X");
			dispLine(centroC, col, fil+1, pisos, numLoc);
		}
	}
}

void dispLocales(local** centroC, int pisos, int numLoc){						//Utiliza la funcion anterior dispLine para imprimir cada fila de la "matriz" de X y O
	int i;
	for(i = 1; i<pisos; i++){
		printf("[");
		dispLine(centroC, i, 1, pisos, numLoc);
	}
		
}

void eliminarLocal(local** centroC, int pisos, int numLoc){					//Elimina un local de la matriz
	int col, fil;
	printf("Ingrese el piso y el numero de local a borrar: \nPiso: ");
	scanf("%d", &col);
	printf("\nLocal: ");
	scanf("%d", &fil);
	centroC[col][fil].dispo = disp;								//Lo que hace es settear la disponibilidad de la celda a disp para que se pueda sobreescribir con otro nombre de local y no se haga display de el mientras tanto
	printf("\nSe ha eliminado %s del centro comercial\n", centroC[col][fil]);
	return;
	
}

void cambiarNombreLocal(local** centroC, int pisos, int numLoc){				//Cambia el nombre de un local luego de buscarlo con strcmp
	int c, j;
	char nameChange[25];											//Pide el nombre a buscar
	printf("Ingrese el nombre del local que desea cambiar: ");
	scanf("%s", nameChange);
	for(c = 1; c<pisos; c++){
		for(j = 1; j<numLoc; j++){
			if(!strcmp(centroC[c][j].nombreLocal, nameChange)){
				printf("Ingrese el nuevo nombre: ");
				scanf("%s", centroC[c][j].nombreLocal);			//Cambia el nombre previo por uno ingresado por el usuario
				printf("Nombre cambiado exitosamente\n");		//Confirma el cambio
				return;
			}
		}
	}
	printf("No se encontró el local con ese nombre \nF\n");		//Si no encuentra el local, sale
	return;
}

void buscarLocal(local** centroC, int pisos, int numLoc){						//Busca la ubicacion de un local
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
	printf("No se encontró el local con ese nombre \nF\n");
	return;
}

void rate(local** centroC, int pisos, int numLoc){					//Elimina un local de la matriz
	int col, fil, rating;
	printf("Ingrese el piso y el numero de local a calificar: \nPiso: ");
	scanf("%d", &col);
	printf("\nLocal: ");
	scanf("%d", &fil);
	do{
		printf("Califique a '%s' de 1 a 5: ", centroC[col][fil].nombreLocal);
		scanf("%d", &rating);				//err
	}while(rating < 1 || rating > 5);
	
	centroC[col][fil].rating[0] += 1;
	centroC[col][fil].rating[1] += rating;
	printf("Se suma");
	printf("\nSe ha calificado a %s\nSu rating promedio ahora es de %0.1f", centroC[col][fil].nombreLocal, (float)centroC[col][fil].rating[1]/centroC[col][fil].rating[0]);
	return;
	
}

void save(local** centroC, int pisos, int numLoc, char* fileName){
	int i, j;
	local currentLoc;
	FILE *fptr = fopen(fileName ,"wb");

	if (fptr == NULL){
    	printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       	exit(1);
   }

   for(i = 0; i < pisos; i++){
	   	for(j = 0; j < numLoc; j++){
	   		if(centroC[i][j].dispo == noDisp){
	   			currentLoc = centroC[i][j];
   				fwrite(&currentLoc, sizeof(local), 1, fptr); 
   				printf("Guardado: %s\n", currentLoc.nombreLocal);
			}

	   	}

      
   }
   fclose(fptr); 
   printf("Se ha guardado todo el CC");
   
}

void load(local** centroC, int pisos, int numLoc, char* fileName){
	int i, j;
	FILE *fpt = fopen(fileName ,"rb");
	local currentLoc;
   	if (fpt == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }printf("ESTOY DESPUES DEL IF Y ANTES DEL GUAIL");
	while(fread(&currentLoc, sizeof(local), 1, fpt) == sizeof(local)){
		fread(&currentLoc, sizeof(local), 1, fpt); 
	   	centroC[currentLoc.pisoLocal][currentLoc.numLocalxPiso] = currentLoc;
		printf("%s", currentLoc.nombreLocal);
	}
	fclose(fpt);	   		
	   		
}

      
	



















