#include<stdio.h>

#include<stdlib.h>



struct node{

	int data;

	struct node *next;

};





struct node * stack_TP;



void stack_push(int);

int stack_pop();

void stack_print();

void top();





int main(){

	

	

	int func;

        int value;

        int pop_value;

	printf("0 : Exit\n"

	       "1 : Push\n"

		   "2 : Pop\n"

		   "3 : Print\n"

		   "4 : See Top \n");

	printf("Input Num:");

	scanf("%d",&func);

	printf("\n");

	

	while(func!=0){

	     switch(func){

		   case 1: 	

		   

		   printf("please input the value you want to push:");

		   scanf("%d",&value);

		   printf("\n\n");

		 	stack_push(value);

		 

		 	break;

		 

		   case 2:

                	 pop_value = stack_pop();

		     break;  

		   case 3:	

		     stack_print();

			 break;

		   case 4:	

		      top();

		 	 break;

		 }	

			printf("0 : Exit\n"

	       "1 : Push\n"

		   "2 : Pop\n"

		   "3 : Print\n"

		   "4 : See Top \n");

	       printf("Input Num:");

	       scanf("%d",&func);

	       printf("\n");

	}

	

	return 0;

}



void stack_push(int value){

	struct node * temp;

	temp = (struct node*)malloc(sizeof(struct node));

	temp->next = stack_TP;

	temp->data = value;

	stack_TP = temp;

}



int stack_pop(){

	

	int value;

	struct node* temp;

    if(stack_TP == NULL)return -1;

	temp = stack_TP;

    stack_TP = stack_TP->next;

	 value = temp->data;

	 free(temp);

	return value; 

}



void stack_print(){

	

	struct node * stack_P;

	stack_P  = stack_TP;

	

	while(stack_P!=NULL){

	  printf("%d",stack_P->data);	

	   stack_P = stack_P->next;	

	}

   printf("\n\n");	

}



void top(){

	

	if(stack_TP!=NULL){

		printf("%d",stack_TP->data);

	}

   printf("\n\n");	

}
