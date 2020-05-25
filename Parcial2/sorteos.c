
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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
	k=0;																																		//MERGE SORT
	
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

//-------------------------------------------------------------------------------------------------------------------------------//
/*
void selectionSort(local** ordenados, int n)
{
  int i, j;
  local min, temp;							//Declaracion de variables que se usaran

  for (i = 0; i < n-1; i++){
  
    min = ordenados[i];
    for (j = i+1; j < n; j++){																													//SELECTION SORT
      if (((float)ordenados[j].rating[1]/ordenados[j].rating[0]) < ((float)min.rating[1]/min.rating[0])){
      	min = j;
	  }   
    }
    temp = ordenados[i];
    ordenados[i] = min;
    min = temp;
  }
  for(c = 0; c<pisos; c++){
		printf("Name: %s\nRating: %0.1f\n---------\n", ordenados[c].nombreLocal, float(ordenados[c].rating[1]/ordenados[c].rating[0));
			
		}
	}
*/

//-------------------------------------------------------------------------------------------------------------------------------//

/*
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 

        while (j >= 0 && arr[j] > key) { 																										//INSERTION SORT
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    }
}
*/
//-------------------------------------------------------------------------------------------------------------------------------//

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 																																				//QUICK SORT
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 


