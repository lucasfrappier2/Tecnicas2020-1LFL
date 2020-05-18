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
	
	FILE *ff = fopen("output3.txt", "ab");
	
	fprintf(ff, "Archivo %s", FILENAME);
	
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);																							//FECHA ANTES
  	fprintf(ff, "\nantes: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);


	
    int key, j, n = ARRAYSIZE; 
    for (i = 0; i < n-1; i++) { 
    	numIt++;
        key = array[i]; 
        j = i - 1; 

        while (j >= 0 && array[j] > key) { 
        	numSw++;
        	numIt++;
            array[j + 1] = array[j]; 
            j = j - 1; 
        } 
        array[j + 1] = key; 
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
