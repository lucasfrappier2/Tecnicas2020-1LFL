
void mergeSort(int array[],int i,int j);
void merge(int array[],int i1,int j1,int i2,int j2);
 
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



	mergeSort(array, 0, ARRAYSIZE);
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

 
void mergeSort(int array[],int i,int j)
{
	int mid;
		
	if(i<j)
	{
		mid=(i+j)/2;
		mergeSort(array,i,mid);				//recursion del lado izquierdo
		mergeSort(array,mid+1,j);			//luego recursion del lado derecho
		merge(array,i,mid,mid+1,j);			//junta los dos sub-arreglos sorteados
	}
}
 
void merge(int array[],int i1,int j1,int i2,int j2)
{
	int temp[15];	//arreglo temporal 
	int i,j,k;
	i=i1;			//el comienzo de la primera (izq) lista
	j=i2;			//el comienzo de la segunda (der) lista
	k=0;
	
	while(i<=j1 && j<=j2)	//mientras haya elementos aun en ambas listas
	{
		if(array[i]<array[j])
			temp[k++]=array[i++];
		else											
			temp[k++]=array[j++];
	}
	
	while(i<=j1)			//copia los elementos que quedan de la primera lista
		temp[k++]=array[i++];
		
	while(j<=j2)			//copia los elementos que quedan de la segunda lista
		temp[k++]=array[j++];
		
	for(i=i1,j=0;i<=j2;i++,j++)		//transfiere finalmente los elementos del arreglo temp al arreglo original "array"
		array[i]=temp[j];
}
