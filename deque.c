#include<stdio.h>

#include<stdlib.h>





struct node{

	

	int data;

	struct node * prev;

	struct node * next;

};



struct node * head;

struct node * tail;

//struct node * deque_p;

int Size;



void create(int);

void free_deque();

void push_front();

void push_back();

void pop_front();

void pop_back();

void insert_by_pos(struct node*,int, int);

void insert_by_value(struct node*,int, int);

void print_front();

void print_back();

void print_deque_size();

void print();



int main()

{

	int value;

	int pos_value;

	int pos;

	printf("Input the Deque Size for Data:");

	scanf("%d",&Size);

	create(Size); 

	/*printf("0: Exit\n"

	       "1: push_front\n"

		   "2: push_back\n"

		   "3: pop_front\n"

		   "4: pop_back\n"

		   "5: insert data at position\n"

		   "6: print the deque\n"

		   "7: free deque\n");

	printf("Please input function num : ");

	scanf("%d",&value);

	printf("\n\n");*/

	

	do{

		

		printf("0: Exit\n"

	       "1: push_front\n"

		   "2: push_back\n"

		   "3: pop_front\n"

		   "4: pop_back\n"

		   "5: insert data at position\n"

		   "6: insert data by Pos Value\n"

		   "7: print the deque\n"

                   "8: print the front\n"

                   "9: print the back\n"

                   "10 print the deque size\n"

		   "11: free deque\n");

	    printf("Please input function num : ");

	    scanf("%d",&value);

	    printf("\n\n");

		

		

	

		 switch(value){

		   	

		   case 0:

		     continue;

		   break;	

		 	

		   case 1:

		     push_front();

		   break;

		   

		   case 2:

		     push_back();

		   break;

		   

		   case 3:

		    pop_front();

		   break;	

		 	

		   case 4:

		    pop_back();

		   break;

		   

		   case 5:

		     printf("Please assign value to which position(0-%d) : ",Size-1);

		     scanf("%d\n",&pos);

		     insert_by_pos(head,pos,Size);

		   break;

		   

		   case 6:

		   	printf("Please input position value to place new data : ");

		    scanf("%d\n",&pos_value);

		   	insert_by_value(head,pos_value, Size);

		   	break;

		   

		   case 7:

		   	print();

		   	break;

                   

                   case 8:

                       print_front();

                       break;



                   case 9:

                       print_back();

                       break;



                   case 10:

                       print_deque_size();

                     break;                  

		   

		   case 11:

		   free_deque();

		   break;		

		 }

	

	

    }while(value > 0);

	

	

	return 0;

}



void create(int value)

{

	struct node * space;

	

	

	while(value > 0){

		

		space = (struct node*)malloc(sizeof(struct node));

		space->data = 0;

		space->next = head;

		space->prev = NULL;

		if(head!=NULL){head->prev = space;}

	    else if(head == NULL){tail = space;}

		head = space;

		space = NULL;

		value--;

	}

	

	

}



void free_deque()

{

	

	struct node* temp;

	int free_size = 0;

	

	while(head!=NULL)

	{

	   //	printf("free the node & data: %d\n",head->data);

	   	head->prev = NULL;

        temp = head;		

		head = head->next;

		free(temp);

		//printf("%d\n",++free_size);

	}

	head = tail = NULL;

	Size = 0;

	printf("Free Space finished!\n");

}



void push_front(){

	

	struct node* temp;

	

	temp = (struct node*)malloc(sizeof(struct node));

	

	if(head == NULL){

	  head = temp;

      tail = temp;

      printf("Please input the Data for new head : ");

		scanf("%d\n",&(temp->data));

		

	  }

  else {

	

		temp->prev = NULL;

		temp->next = head;

		printf("Please input the Data for new head : ");

		scanf("%d\n",&(temp->data));

		head->prev = temp;

		head = temp;

	}

	Size++;

}





void push_back(){

	

	struct node* temp;

	

	temp = (struct node*)malloc(sizeof(struct node));

    

	if(tail == NULL){

		head = temp;

        tail = temp;

        printf("Please input the Data for new tail : ");

		scanf("%d\n",&(temp->data));

			

	}

    else {

	

		temp->prev = tail;

		temp->next = NULL;

		printf("Please input the Data for new tail : ");

		scanf("%d\n",&(temp->data));

		tail->next = temp;

		tail = temp;

		

   }

   Size++;

}





void pop_front(){

	

	struct node* temp;

	if(head == NULL || head == tail){

		printf("Nothing to Pop!!!\n");

		head = tail;

		return;

	}

	temp = head;

	printf("about to delete node value : %d\n",temp->data);

	head = head->next;

	head->prev = NULL;

	free(temp);

	Size--;

}





void pop_back(){

	

	struct node* temp;

	if(tail == NULL || head == tail){

		printf("Nothing to Pop!!!\n");

		head = tail;

		return;

	}

	

	temp = tail;

	printf("about to delete node value : %d\n",temp->data);

	tail = tail->prev;

	tail->next = NULL;

	free(temp);

	Size--;

}



void insert_by_pos(struct node* head,int pos,int size)

{

	struct node* deque_p;

	deque_p = head;

	int pos_p = 0;

	while(pos_p < pos && deque_p!=NULL){

	   deque_p = deque_p->next;

	   pos_p++;

    }

    

    

    if(pos_p == pos){

    	printf("Please input this node new value : ");

    	scanf("%d",&(deque_p->data));

    	printf("\n");

    }

    else if(deque_p == NULL){

    	printf("position over the deque size!!!\n");

    }

	return;

}



void insert_by_value(struct node* head,int pos_value, int size){

	

	struct node * p;

	//struct node * p_next;

	struct node * temp;

	p = head;

	while(p!=NULL){

		if(p->data == pos_value)break;

		p = p->next;

	}

	

	if(p == NULL){

		printf("the Pos Value didn't found!!!\n");

		return;

	}

	else if(p->data == pos_value){

	//	p_next; = p->next;

		temp = (struct node*)malloc(sizeof(struct node));

		printf("Please input this node new value : ");

    	scanf("%d",&(temp->data));

    	printf("\n");

    	

    	p->next->prev = temp;

    	temp->next = p->next; 

    	p->next = temp;

    	temp->prev  = p;

	}

	Size++;

}



void print(){

	

	if(head == NULL && tail == NULL){

		printf("Nothing to read!!!\n");

		return;

	}

	

	struct node * deque_p;

	deque_p = head;

	while(deque_p!=NULL){

	  printf("%d ->",deque_p->data);	

	  deque_p = deque_p->next;	

	}

	printf("\n");

}



void print_front(){



 if(head==NULL){print("Empty deque!\n"); return;}



 else printf("The Head node Value : %d\n",head->data);

 return;

}



void print_back(){

  if(tail == NULL){print("Empty deque!\n"); return;}



  else printf("The tail node Value : %d\n",tail->data);

  return;

}



void print_deque_size(){



  if(Size == 0){printf("Empty deque!!!\n");return;}

  else printf("The deque size : %d\n",Size);

  return;

}
