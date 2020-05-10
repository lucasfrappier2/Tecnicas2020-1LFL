#include<stdio.h>
#include <time.h>

#define ARRAYSIZE 500000
#define FILENAME "sizeonehr.txt"

void mergeSort(int array[],int i,int j, int* numIt, int* numSw);
void merge(int array[],int i1,int j1,int i2,int j2, int* numIt, int* numSw);

 
int main(){


	int numIt = 0;
	int numSw = 0;
	


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
	
	FILE *ff = fopen("output2.txt", "ab");
	
	fprintf(ff, "Archivo %c", FILENAME);
	
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);																							//FECHA ANTES
  	fprintf(ff, "\nantes: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);



	mergeSort(array, 0, ARRAYSIZE-1, &numIt, &numSw);

	
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


 
void mergeSort(int array[],int i,int j, int* numIt, int* numSw)
{
	int mid;
		
	if(i<j)
	{
		mid=(i+j)/2;
		mergeSort(array,i,mid, numIt, numSw);				//recursion del lado izquierdo
		mergeSort(array,mid+1,j, numIt, numSw);			//luego recursion del lado derecho
		merge(array,i,mid,mid+1,j, numIt, numSw);			//junta los dos sub-arreglos sorteados
	}
}
 
void merge(int array[],int i1,int j1,int i2,int j2, int* numIt, int* numSw)
{
	int temp[ARRAYSIZE];	//arreglo temporal 
	int i,j,k;
	i=i1;			//el comienzo de la primera (izq) lista
	j=i2;			//el comienzo de la segunda (der) lista
	k=0;
	
	while(i<=j1 && j<=j2)	//mientras haya elementos aun en ambas listas
	{
		*numIt +=1;
		if(array[i]<array[j]){
			*numSw += 1;
			temp[k++]=array[i++];
		}
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
