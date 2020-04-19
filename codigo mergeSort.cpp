#include<stdio.h>
 
void mergesort(int array[],int i,int j);
void merge(int array[],int i1,int j1,int i2,int j2);
 
int main(){

	int array[8],i;							//Se define el arreglo de tamaño 8

	printf("Elementos del arreglo:");
	
	for(i=0;i<8;i++){
		
		printf("Elemento %d: ", i);			//El usuario digita cada elemento y se agrega al arreglo
		scanf("%d",&array[i]);
	}
	mergeSort(array,0,7);
	
	printf("\nArreglo sorteado :");
	for(i=0;i<8;i++)
		printf("%d ",array[i]);
		
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
