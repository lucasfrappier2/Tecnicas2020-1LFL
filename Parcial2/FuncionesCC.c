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
	printf("8. Ordenar por rating (SelectionSort)\n");
	printf("9. Ordenar por fecha de llegada (InsertionSort)\n");
	printf("10. Ordenar por tama�o (MergeSort)\n");
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
			centroC[c][j].idLocal = c*j;						//ID "unico" pues es producto de el numero de fila*columna, el cual ser� distinto para cada celda
			centroC[c][j].pisoLocal = c;
			centroC[c][j].numLocalxPiso = j;
			centroC[c][j].rating[0] = 0;
			centroC[c][j].rating[1] = 0;
			centroC[c][j].metros2 = 0;
			centroC[c][j].empleados = 0;
			centroC[c][j].added = 0;


		}
		
	}
	return centroC;
}
/*
void inicializarCC(local** centroC){					//Se usa para que el arreglo de locales no tenga asignacion de valores basura que ya existen en la memoria
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
*/
void contarLocales(local** centroC, int pisos, int numLoc){
	int count = 0, c, j;
	FILE *fnum = fopen("cantLocales.txt", "w");
	for(c = 0; c<pisos; c++){
		for(j = 0; j<numLoc; j++){
			if(centroC[c][j].dispo == noDisp){
				count++;
			}
		}
	}
	fprintf(fnum, "%d", count);
	fclose(fnum);
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
	
		if(centroC[piso][loc].dispo == disp){
			printf("Nombre local: ");
			scanf("%s", centroC[piso][loc].nombreLocal);
			printf("Tama�o del local en metros cuadrados: ");
			scanf("%d", &centroC[piso][loc].metros2);
			printf("Metros: %d\n", centroC[piso][loc].metros2);
			int maxEmp = centroC[piso][loc].metros2 / 4;

			do{
				printf("Se debe dejar un espacio de 4 m2 por persona (CORONA), y dejar espacio para almenos un cliente.\nCapacidad maxima de empleados para %s: %d\n", centroC[piso][loc].nombreLocal, maxEmp-1 );
				printf("Cantidad de empleados: ");
				scanf("%d", &centroC[piso][loc].empleados);
			}while(centroC[piso][loc].empleados > maxEmp-1);

			
			
			centroC[piso][loc].dispo = noDisp;
			printf("Local agregado exitosamente: \n");				//Confirma que se agrega un local y hace display de su informacion
			printf("Nombre: %s\nUbicacion: Piso %d, Local %d\nID Local: %d\n", centroC[piso][loc].nombreLocal, centroC[piso][loc].pisoLocal, centroC[piso][loc].numLocalxPiso, centroC[piso][loc].idLocal);	
			contarLocales(centroC, pisos, numLoc);
			FILE *add = fopen("cantLocales.txt", "r");
			fscanf(add, "%d", &centroC[piso][loc].added);
			fclose(add);
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
				if(centroC[c][j].rating[0] > 0){
					printf("%s\nPiso %d, Local %d\nID: %d\nEmpleados: %d\nRating: %0.1f", centroC[c][j].nombreLocal, centroC[c][j].pisoLocal, centroC[c][j].numLocalxPiso, centroC[c][j].idLocal, centroC[c][j].empleados, (float)centroC[c][j].rating[1]/centroC[c][j].rating[0]);
					printf("\n---------\n");
				}else{
			printf("%s\nPiso %d, Local %d\nID: %d\nEmpleados: %d\nRating: N/A", centroC[c][j].nombreLocal, centroC[c][j].pisoLocal, centroC[c][j].numLocalxPiso, centroC[c][j].idLocal, centroC[c][j].empleados);
					printf("\n---------\n");
				}
				
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
	contarLocales(centroC, pisos, numLoc);
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
	printf("No se encontr� el local con ese nombre \nF\n");		//Si no encuentra el local, sale
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
	printf("No se encontr� el local con ese nombre \nF\n");
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
	int i, localesEx;
	FILE *fpt = fopen(fileName ,"rb");
	FILE *cantL = fopen("cantLocales.txt", "r");
	local currentLoc;
   	if (fpt == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   fscanf(cantL, "%d", &localesEx);
   printf("Locales a cargar: %d\n", localesEx);
	for(i = 0; i < localesEx; i++){
		fread(&currentLoc, sizeof(local), 1, fpt); 
	   	centroC[currentLoc.pisoLocal][currentLoc.numLocalxPiso] = currentLoc;
		printf("Cargando %s\n", currentLoc.nombreLocal);
	}
	fclose(fpt);	   		
	   		
}

void orderByRating(local** centroC, int pisos, int numLoc){
	int localNum, c, j, ordCt = 0;
	contarLocales(centroC, pisos, numLoc);
	FILE *cantl = fopen("cantLocales.txt", "r");
	fscanf(cantl, "%d", &localNum);
	fclose(cantl);
	local ordenados[localNum];
	printf("%d locales\n", localNum);
	for(c = 0; c<pisos; c++){
		for(j = 0; j<numLoc; j++){
			if(centroC[c][j].dispo == noDisp){
				ordenados[ordCt] = centroC[c][j];
				ordCt++;
			}
		}
	}
	
	//printf("1. %s\n2. %s\n3. %s\n4. %s\n", ordenados[0].nombreLocal, ordenados[1].nombreLocal,ordenados[2].nombreLocal,ordenados[3].nombreLocal);
	selectionSort(ordenados, localNum);
	
}

void selectionSort(local ordenados[], int n){
	
  int i, j, c, swapLoc;
  local min, temp;							//Declaracion de variables que se usaran

  for (i = 0; i < n-1; i++){
  
    min = ordenados[i];
    for (j = i+1; j < n; j++){																													//SELECTION SORT
      	if (((float)(ordenados[j].rating[1])/(ordenados[j].rating[0])) < ((float)min.rating[1]/min.rating[0])){
      		min = ordenados[j];
      		swapLoc = j;
	  	}   
    }
    temp = ordenados[i];
    ordenados[i] = min;
    ordenados[swapLoc] = temp;
 	}
 	//printf("LOWEST: %s\n", ordenados[0].nombreLocal);
  	for(c = 0; c < n; c++){
		printf("Name: %s\nRating: %0.1f\n---------\n", ordenados[c].nombreLocal, (float)ordenados[c].rating[1]/ordenados[c].rating[0]);
			
	}
	return;
}


void orderByArrival(local** centroC, int pisos, int numLoc){
	int localNum, c, j, ordCt = 0;
	contarLocales(centroC, pisos, numLoc);
	FILE *cantl = fopen("cantLocales.txt", "r");
	fscanf(cantl, "%d", &localNum);
	fclose(cantl);
	local ordenados[localNum];
	printf("%d locales\n", localNum);
	for(c = 0; c<pisos; c++){
		for(j = 0; j<numLoc; j++){
			if(centroC[c][j].dispo == noDisp){
				ordenados[ordCt] = centroC[c][j];
				ordCt++;
			}
		}
	}
	

	insertionSort(ordenados, localNum);
	
}

void insertionSort(local ordenados[], int n){
 
    int i, j, c;
	local key; 
    for (i = 0; i < n; i++) { 
        key = ordenados[i]; 
        j = i - 1; 

        while (j >= 0 && ordenados[j].added > key.added) { 																										//INSERTION SORT
            ordenados[j + 1] = ordenados[j]; 
            ordenados[j] = key;
            j--; 
        } 
        //arr[j + 1] = key; 
    }
    for(c = 0; c < n; c++){
		printf("\n%d. %s\n", ordenados[c].added, ordenados[c].nombreLocal);
			
	}
}

void orderBySize(local** centroC, int pisos, int numLoc){
	int localNum, c, j, ordCt = 0;
	contarLocales(centroC, pisos, numLoc);
	FILE *cantl = fopen("cantLocales.txt", "r");
	fscanf(cantl, "%d", &localNum);
	fclose(cantl);
	local ordenados[localNum];
	printf("%d locales\n", localNum);
	for(c = 0; c<pisos; c++){
		for(j = 0; j<numLoc; j++){
			if(centroC[c][j].dispo == noDisp){
				ordenados[ordCt] = centroC[c][j];
				ordCt++;
			}
		}
	}
	

	mergeSort(ordenados, 0, localNum-1);
	
	for(c = 0; c < localNum; c++){
		printf("Name: %s\nSize: %d\n---------\n", ordenados[c].nombreLocal, ordenados[c].metros2);
			
	}
	
}

void merge(local ordenados[], int l, int m, int r){
 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    local L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = ordenados[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = ordenados[m + 1+ j]; 
  
   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i].metros2 <= R[j].metros2) 
        { 
            ordenados[k] = L[i]; 
            i++; 
        } 
        else{ 
            ordenados[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1){ 
        ordenados[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2){ 
        ordenados[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(local ordenados[], int l, int r){

    if (l < r){ 

        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(ordenados, l, m); 
        mergeSort(ordenados, m+1, r); 
  
        merge(ordenados, l, m, r); 
    } 
    
} 




      
	



















