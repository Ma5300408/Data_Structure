#include<stdio.h>

#include<stdlib.h>



struct node{

  int data;

  struct node * next;

  struct node * prev;	

};



struct disjoint_Set{

	struct node* parent;

	struct disjoint_Set * next;

	struct disjoint_Set * prev;

};



struct disjoint_Set * Set_array  = NULL;

//Set_array = NULL;



struct node * find_set(int);

int same_set(int,int);

int union_set(int,int);

int build_set();

int insert_value_for_disjoint_set(struct disjoint_Set *);

int  num_set(int);

int size = 0;

int main()

{

	int func;

        int ret;

	char cmd[1024];

	int value1;

	int value2;

	

	do{		

	  printf("1)build new set  2)find set  3)same set  4)union set\n" 

                  "5)insert member of disjoint-set 6)num of disjoint-set:");

	  for(func = 0; func <= 0 || func > 6; sscanf(cmd,"%d",&func)){

	   scanf("%s",cmd);	

	   printf("\n");

      }

	  switch(func){

		 case 1: 	

	   	  	 ret = build_set();

                         if(ret)printf("build Success.\n");

	   	 break;

		 

		 case 2:

                       printf("Please Input the Disj-set member value:");

                       scanf("%d",&value1);

                       printf("\n");

                       find_set(value1);

	   	 break;

		 

		 case 3:

                    printf("Please Input the Disj-set member value to Group: value: (value1) (value2) ");

                        scanf(" %d  %d:",&value1,&value2);

                        printf("\n"); 	

	   	   ret = same_set(value1,value2);	

                   if(ret)printf("Same Set!\n");

                   else printf("different Set!\n");

	   	 break;

		 

		 case 4:

		    printf("Please Input the Disj-set member value to Group: value: (value1) (value2) ");

			scanf(" %d  %d:",&value1,&value2); 	

			printf("\n");

	   	  	ret = union_set(value1,value2);

                      if(ret)printf("union Success.\n");

                      else printf("union fail.\n");

	   	 break;	

	   	 

	   	 case 5:

	   	   insert_value_for_disjoint_set(Set_array);

                  break;

	   	 case 6: 	

	   	  	printf("disj Size : %d \n",num_set(size));

	   	 break;	

	   	 

	   }

          value1 = 0;

          value2 = 0;

	} while(func >= 0);

	return 0;

}





struct node * find_set(int value){

	

	if(Set_array==NULL)return NULL;

	

	else{

	      

		struct disjoint_Set * Set_P;

		struct node* NODE_P;

		Set_P = Set_array;

		

		while(Set_P!=NULL){

		  	

		  NODE_P = Set_P->parent;

		  while(NODE_P!=NULL && NODE_P->data!=value){

                        //printf("NODE_P!=NULL && NODE_P->data!=value\n");

		  	/*if(NODE_P->next!=NULL)*/NODE_P = NODE_P->next;

		  	//else break;

                       // printf("hey!\n");

		  }	

		

		  if(NODE_P!=NULL && NODE_P->data == value){

		  	 printf("In this Set and Father value : %d\n",Set_P->parent->data);

		  	 return Set_P->parent;

		  }

		

		  else if(NODE_P==NULL){

                         //printf("hey!!!!\n");

		  	 if(Set_P->next!=NULL){ Set_P = Set_P->next;}

                         else break;

                         

		  }

		}

		

		//printf("hihi\n");

		if(Set_P == NULL||Set_P->next==NULL){

                 char sentence[30]="can't find this value.\n";

                puts(sentence); 

                return NULL;}

		

	}

	

}





int same_set(int value1,int value2){

	

	if(Set_array==NULL)return 0;

	struct node * NODE_1;

	struct node * NODE_2;

	NODE_1 = find_set(value1);

	NODE_2 = find_set(value2);

	if(NODE_1 == NODE_2)return 1;

	else return 0;

}



int union_set(int value1,int value2){

	

	if(Set_array==NULL)return 0;

	

	struct node * NODE_1;

	struct node * NODE_2;

	

	NODE_1 = find_set(value1);

        printf("NODE_1 found\n");

	NODE_2 = find_set(value2);

        printf("NODE_2 found\n");

	if(NODE_1 == NULL|| NODE_2 == NULL){printf("Only one Set,can't union'!!!\n"); return 0;}

	else{

	   	

	   	if(Set_array!=NULL){

		struct disjoint_Set * Ds_P1;

		struct disjoint_Set * Ds_P2;

                struct disjoint_Set * Ds_P2_Prev;		



		Ds_P1 = Set_array;

		Ds_P2 = Set_array;

		

		while(Ds_P1->next!=NULL && Ds_P1->parent->data != NODE_1->data)Ds_P1 = Ds_P1->next;

		

			struct node * NODE1_tail;

			NODE1_tail = Ds_P1->parent;

			while(NODE1_tail->next!=NULL)NODE1_tail = NODE1_tail->next;

		

		

		while(Ds_P2->next!=NULL && Ds_P2->parent->data != NODE_2->data)

               { Ds_P2_Prev = Ds_P2;

                 Ds_P2 = Ds_P2->next;

	        }

		/*if(Ds_P->next == NULL){

		}*/  //one of the Disj_Set can't find.

	   	if( Ds_P1->parent->data == NODE_1->data && Ds_P2->parent->data == NODE_2->data){

	   		Ds_P2_Prev->next = Ds_P2->next;

	   	//if(Ds_P2_Prev->next!=NULL)printf("Ds_P2_Prev->next->parent->data : %d\n",Ds_P2_Prev->next->parent->data);

                        NODE1_tail->next = NODE_2;

			NODE_2->prev = NODE1_tail; 

	   		Ds_P2 = NULL;

	   	}

		

	   size--;	

	 }

	 return 1;

   }

}



int build_set(){

	

	if(Set_array==NULL){

		Set_array = (struct disjoint_Set*)malloc(sizeof(struct disjoint_Set));

                Set_array->parent = (struct node*)malloc(sizeof(struct node));

		printf("please input the set father value:");

        scanf("%d",&(Set_array->parent->data));

        printf("\n");

		Set_array->parent->prev = NULL;

        Set_array->parent->next = NULL;

		Set_array->next = NULL;				

		Set_array->prev = NULL;

              size++;

              return 1;

	}

	else if(Set_array!=NULL){

		

		struct disjoint_Set * Ds_P;

		Ds_P = Set_array;

                  printf("Ds_P->parent: %d\n",Ds_P->parent->data);

		while(Ds_P->next!=NULL){

                  //printf("Ds_P->parent: %d\n",Ds_P->parent->data);  

                  Ds_P = Ds_P->next;

                  printf("Ds_P->parent: %d\n",Ds_P->parent->data);

		}

		if(Ds_P->next == NULL){

			

			struct  disjoint_Set * new_DS;

			new_DS = (struct disjoint_Set *)malloc(sizeof(struct disjoint_Set));

                  new_DS->parent = (struct node*)malloc(sizeof(struct node));

			Ds_P->next = new_DS;

            new_DS->next = NULL;

            new_DS->prev = Ds_P;

            printf("please input the set father value:");

        	scanf("%d",&(new_DS->parent->data));

        	printf("\n");

			new_DS->parent->prev = NULL;

            new_DS->parent->next = NULL;

			Ds_P = Ds_P->next; //need the step??

			new_DS = NULL;

		}

	 size++; 

         return 2; 	

	}

	

}



int insert_value_for_disjoint_set(struct disjoint_Set * Set_P){

	

	if(Set_array==NULL)return 0;



	//struct disjoint_Set * Set_P;

        struct node * NODE_P;

        struct node * NODE_PREV;

        int Set_num;

        int select_num;

        Set_P = Set_array;

        Set_num = 0;



        while(Set_P!=NULL){

          printf("Set Num: %d Parent Data: %d\n",Set_num++,Set_P->parent->data);

          Set_P = Set_P->next;

        }



        printf("Which Set you want to insert?(by Set Num):");

        scanf("%d",&select_num);

	printf("\n");



        Set_P = Set_array;

        Set_num = 0;

        while(Set_num < select_num){

        Set_P = Set_P->next;

         Set_num++;

        }

        NODE_P = Set_P->parent;

        while(NODE_P!=NULL){

           NODE_PREV = NODE_P;

           NODE_P = NODE_P->next;

         }

        if(NODE_P == NULL){

             NODE_P = (struct node*)malloc(sizeof(struct node));

             printf("Input the New value for this Set member:");

             scanf("%d",&(NODE_P->data));

             printf("\n");

             NODE_P->next = NULL;

             NODE_P->prev = NODE_PREV;

             NODE_PREV->next = NODE_P;

            // size++;

             return 1;

        }

	

}





int num_set(int size){

	

	//printf("Current Number of disjoint-sets : %d\n",size);

	return size;;

}
