#include<stdio.h>

#include<stdlib.h>





struct node{

	int data;

};



struct heap_t{

	struct node * array;	

};



struct heap_t * heap;



struct heap_t* build_heap(int);

void maxheap(struct heap_t *);

void heapify(struct heap_t *,int index);

void heap_insert(struct heap_t *,int);

void heap_delete(int);

void heap_extract();

void heap_top(struct heap_t*);

void heap_print();

int size = 0;



int main()

{

//	int j;

	int func;

	int value;

	char cmd[1024];

	printf("Please input the heap size : ");

	scanf("%d",&size);

	printf("\n");

	heap = build_heap(size);

	maxheap(heap);

	do{	

	    printf("1) Insert 2) Delete 3) Extract max 4) Top Value 5) Print Heap 6)Free:");

		for(func = 0; func<=0 || func > 7; sscanf(cmd,"%d",&func)){

		  scanf("%s",cmd);

		  printf("\n");

	      }

	    switch(func){

	    	

	      case 1:

	      	printf("please input new value for insert:");

		    scanf("%d ",&value);	

		    printf("\n");

	        heap_insert(heap,value);			     

		  break;	

	      

	      case 2:

		  printf("please input heap-index to delete:");

		    scanf("%d ",&value);	

		    printf("\n");	

	       heap_delete(value);

		  break;

		  

		  case 3:	

	       heap_extract();

		  break;

		  

		  case 4:	

	        heap_top(heap);

		  break;

		  

		  case 5:

		  	heap_print();

		  break;

		  

		  case 6:

		  	free(heap->array);

		  	//free(heap);

		  	size = 0;

		  	break;

		  

	    }  

	      

	}while(1);

	

	

	

	

	return 0;

}





struct heap_t* build_heap(int size)

{

	struct heap_t * HEAP;

	int i;

	HEAP = (struct heap_t*)malloc(sizeof(struct heap_t));

	HEAP->array = (struct node*)malloc(sizeof(struct node)*(size+1));

	

	for(i = 1; i <= size; i++){

		

		printf("Please input the Initial Heap Data : ");

		fflush(stdout); 

		scanf("%d",&(HEAP->array[i].data));

	}

	

	printf("\n\n");

	return HEAP;

	

}



void maxheap(struct heap_t * __heap) 

{  

    int i;

	for(i = size/2; i > 0; i--){

		heapify(__heap,i);

	}

}



void heapify(struct heap_t * __heap,int index) 

{

	if(index >= size)return; // If it's the last node.

	

	int child_index = index*2;

	int temp_value;

	int largest;

	largest = __heap->array[index].data;

	int largest_index = index;

	

	if(__heap->array[child_index].data >  largest){//left_node

	        largest_index = child_index;

	        largest = __heap->array[child_index].data;

												   }

	

	if( child_index+1 <= size){//right_node

		if(__heap->array[child_index+1].data >  largest){

			largest_index = child_index+1;

			largest = __heap->array[child_index+1].data;

		}

		

	}

	

	temp_value = __heap->array[index].data;

	__heap->array[index].data = largest;

	__heap->array[largest_index].data = temp_value;

	

	printf("index :%d , value: %d \n",index,__heap->array[index].data);

	printf("index :%d , value: %d \n",largest_index,__heap->array[largest_index].data);

	printf("\n\n");

	getchar();

	

	if(largest_index == index)return;//It's the last node value.

	

	heapify(__heap,largest_index);

	

}



void heap_insert(struct heap_t * __heap, int value){

	

	/*struct heap_t * HEAP;

	HEAP->array = (struct node*)malloc(sizeof(struct node)*(size+1));

	memcpy(HEAP->array,__heap->array,sizeof(struct node)*size); 

	HEAP->array[size+1].data = value;

	heapify(HEAP,size+1);

	free(__heap);*/

	//return HEAP;

	struct node * NODE = malloc(sizeof(struct node));

	NODE->data = value;

    memcpy(__heap->array+(size+1),NODE,sizeof(struct node));

	//NODE->data = value;

	size++;

	maxheap(__heap);

}



void heap_extract(struct  heap_t* __heap){

	int temp_value;

	struct node * temp_node;

   //printf("about to extract.\n");	

     printf("extracted :%d , replaces: %d\n",heap->array[1].data,heap->array[size].data);

  	temp_value = heap->array[1].data;

  	heap->array[1].data = heap->array[size].data;

  	heap->array[size].data = -1;

  	//printf("NONONONNO!\n");

  	temp_node = &(heap->array[size]);

  	free(temp_node);

  	size--;

  	printf("hihihi!\n");

  	heapify(heap,1);

  	//maxheap(__heap);

   printf("extract finished.\n");

}



void heap_delete(int index)

{

	if(index > size || index == 0){

		printf("the value doesn't exist.");

		return;

	}

	int temp_value;

	struct node * temp_node;

   //printf("about to extract.\n");	

     printf("deleted :%d , replaces: %d\n",heap->array[index].data,heap->array[size].data);

  	temp_value = heap->array[index].data;

  	heap->array[index].data = heap->array[size].data;

  	heap->array[size].data = -1;

  	//printf("NONONONNO!\n");

  	temp_node = &(heap->array[size]);

  	free(temp_node);

  	size--;

  	//printf("hihihi!\n");

  	if(index!=size)heapify(heap,index);

  	//maxheap(__heap);

   //printf("extract finished.\n");

	

	

}





void heap_top(struct heap_t* __heap)

{

	printf("The Top value: %d \n",__heap->array[1].data);

}



void heap_print()

{   

    int i;

    printf("Heap Size: %d\n",size);

	for(i = 1; i <= size; i++){

	printf("value %d : %d\n",i,heap->array[i].data);

    }

}
