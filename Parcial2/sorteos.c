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

void selectionSort(int array[], int n)
{
  int i, j;
  int min, temp;							//Declaracion de variables que se usaran

  for (i = 0; i < n-1; i++){
  
    min = i;
    for (j = i+1; j < n; j++){																													//SELECTION SORT
    
      if (array[j] < array[min])
        min = j;
    }
    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
}

//-------------------------------------------------------------------------------------------------------------------------------//


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

//-------------------------------------------------------------------------------------------------------------------------------//

int partition(int arr[], int low, int high){
    int i = low - 1;
    int j;
    for(j = low; j < high; j++){
        countIf++;
        if(arr[j] < arr[high]){
            i++;
            countSwaps++;
            swap(arr, i, j);
        }
    }
    countSwaps++;
    swap(arr, i + 1, high);
    return i + 1;																																//QUICK SORT
}

int pivot(int arr[], int low, int high){
    int random = low + rand() % (high - low);
    countSwaps++;
    swap(arr, random, high);
    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high){
    countIf++;
    if(low < high){
        int piv = pivot(arr, low, high);
        quickSort(arr, low, piv - 1);
        quickSort(arr, piv + 1, high);
    }
}


