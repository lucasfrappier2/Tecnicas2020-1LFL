#include<stdio.h>
 
void selectionSort(int array[], int n);
 
int main(){

	int array[8],i;							//Se define el arreglo de tamaño 8

	printf("Elementos del arreglo: \n");
	
	for(i=0;i<8;i++){
		
		printf("Elemento %d: ", i);			//El usuario digita cada elemento y se agrega al arreglo
		scanf("%d",&array[i]);
	}
	selectionSort(array, 8);
	
	printf("\nArreglo sorteado :");
	for(i=0;i<8;i++)
		printf("%d ",array[i]);
		
	return 0;
}
 

void selectionSort(int array[], int n)
{
  int i, j;
  int min, temp;							//Declaracion de variables que se usaran

  for (i = 0; i < n-1; i++){
  
    min = i;
    for (j = i+1; j < n; j++){
    
      if (array[j] < array[min])
        min = j;
    }
    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
}

