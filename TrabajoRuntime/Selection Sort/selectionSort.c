#include<stdio.h>
#include <time.h>

#define ARRAYSIZE 500000
#define FILENAME "sizeonehr.txt"

void selectionSort(int array[], int n, int *pNumIt, int *pNumSw);

 
int main(){
	
	int numIt = 0;
	int numSw = 0;
	int *pNumIt = &numIt;
	int *pNumSw = &numSw;

	FILE    *f;
    int     array[ARRAYSIZE];
    int     i, ctr = 0;

    f = fopen(FILENAME, "r");

    while((!feof(f)) && (ctr < ARRAYSIZE))
    {
        fscanf(f, "%d ", &array[ctr++]);
    }
    fclose(f); 

    //for(i=0; i<ARRAYSIZE; i++){
    //	printf("%d, ", array[i]);
	
	//}
	
	FILE *ff = fopen("output.txt", "ab");
	
	fprintf(ff, "Archivo %c", FILENAME);
	
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);																							//FECHA ANTES
  	fprintf(ff, "\nantes: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);



	//selectionSort(array, ARRAYSIZE, numIt, numSw);
	int  j;
  int min, temp;							//Declaracion de variables que se usaran

  for (i = 0; i < ARRAYSIZE-1; i++){
    min = i;
    for (j = i+1; j < ARRAYSIZE; j++){
    	numIt++;
      	if (array[j] < array[min]){
        	min = j;+
        	numSw++;
        }
    }
    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }

	
	fprintf(ff, "Arreglo sorteado:\n");
	for(i=0;i<ARRAYSIZE-1;i++){
		//printf("%d ",array[i]);
		fprintf(ff, "%d ", array[i]);
	}
	
	time_t t2 = time(NULL);
  	struct tm tm2 = *localtime(&t2);																						//FECHA DESPUES
  	fprintf(ff, "\ndespues: %d-%02d-%02d %02d:%02d:%02d\n", tm2.tm_year + 1900, tm2.tm_mon + 1, tm2.tm_mday, tm2.tm_hour, tm2.tm_min, tm2.tm_sec);
  	
	//fprintf(ff, "%d segundos\n", time_spent);
	fprintf(ff, "\nComparaciones: %d", numIt);
	fprintf(ff, "\nIntercambios: %d", numSw);
	
	fclose(ff);

	return 0;
}


void selectionSort(int array[], int n, int *pNumIt, int *pNumSw)
{
  int i, j;
  int min, temp;							//Declaracion de variables que se usaran

  for (i = 0; i < n-1; i++){
    min = i;
    for (j = i+1; j < n; j++){
    	*pNumIt++;
      	if (array[j] < array[min]){
        	min = j;+
        	*pNumSw++;
        }
    }
    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
}

