#include<stdlib.h>
#include<stdio.h>


struct node{
      int data;
    struct node * next;
};

//typedef struct node NODE;
struct node* head;
struct node* this_node;


void Insert_head();
void Insert_body();
void Insert_tail(); 
void Delete_head();
void Delete_body();
void Delete_tail();
void find(int);
void Print();


int main()
{
	int func;
	printf("Please Input a valid value\n"
	       "0: Exit.\n "
		   "1: add data to head.\n"
		   "2: insert data to body.\n"
		   "3: add data to tail.\n"
		   "4: delete data from head.\n"
		   "5: delete data by value.\n"
		   "6: delete data from tail.\n"
		   "7: Print the data in Link-List\n\n Input Value:");
	scanf("%d",&func);
	printf("\n");
	
	
	while(func!=0){
	    
		switch(func){
	  	  
	  	 case 1:
	  	   Insert_head();
	  	 break;
	  	 
	  	 case 2:
	  	  Insert_body(); 
	  	 break;
	  	 
	  	 case 3:
	  	  Insert_tail(); 
	  	 break;
	  	 
	  	 case 4:
	  	  Delete_head();
	  	 break;
	  	 
	  	 case 5:
	  	  Delete_body();
	  	 break;
	  	 
	  	 case 6:
	  	  Delete_tail();
	  	 break;
	  	 
	  	 case 7:
	  	 	Print();
	  	  break;
	    } 	
	    
	  	printf("Please Input a valid value\n"
	       "0: Exit.\n "
		   "1: add data to head.\n"
		   "2: insert data to body.\n"
		   "3: add data to tail.\n"
		   "4: delete data from head.\n"
		   "5: delete data by value.\n"
		   "6: delete data from tail.\n"
		   "7: Print the data in Link-List\n\n Input Value:"); 
		scanf("%d",&func);
                printf("\n");	
	}
	
	
	return 0;
}



void Insert_head(){
	struct node * temp;
        printf("before malloc!\n");
	temp = (struct node*)malloc(sizeof(struct node));
        printf("after malloc!\n");
	int value;
	printf("Input new head value:");
	scanf("%d",&value);
	temp->data = value;
	temp->next = head;
	head = temp;
}


void Insert_body(){
	
   struct node* new_temp;
   struct node* temp;
   
   int value;
   int new_data;
   
   printf("Please input a Link-List Data to represent the parent to insert back.\n Parent Value:");	
   scanf("%d",&value);
   
     find(value);
   
   new_temp =(struct node*)malloc(sizeof(struct node));
   
   printf("Input the new insert value:");
   scanf("%d",&new_temp->data);
   
   if(this_node!=NULL){
   temp = this_node->next;
   this_node->next = new_temp;
   new_temp->next = temp;
   }
    else {
    
	 head = new_temp; 
   
    }
}


void Insert_tail(){	
	
	struct node* tail;
	struct node* new_temp;
	tail = head;
    new_temp =(struct node*)malloc(sizeof(struct node));

   	if(tail == NULL){
   	 tail = new_temp;
   	 head = new_temp;
    printf("Input the new Node value:");
	scanf("%d",&new_temp->data);
    return;
   }   

	while(tail->next!=NULL){
	  //cout<<tail->data<<endl;
	  tail = tail->next;
    }
	if(tail!=NULL && tail->next==NULL){
		tail->next = new_temp; 
	    printf("Input the new Node value:");
    	scanf("%d",&new_temp->data);
	
	}
	
	
}


void Delete_head(){
     struct node * temp;
     if(head == NULL)return;
     temp = head->next;	
     free(head); 	
     head = temp;
}


void Delete_body(){
   int value; 
   struct node * NodeP;
   struct node * prev;
   struct node * temp; 
   NodeP = head;   

   printf("Input the Node Value you want to delete:");
   scanf("%d",&value);
   
   while(NodeP!=NULL){
     if(NodeP->data!=value){
           prev = NodeP;  
           NodeP = NodeP->next;
        }
     else if(NodeP->data == value){
         printf("Node found!\n");
         temp = NodeP;
         prev->next = NodeP->next;
         free(temp);
         printf("already free!\n");
         return;
        }
    } 	
   if(NodeP==NULL && prev!=NULL){

     printf("No found!!!!\n");
     return;
   }	
}


void Delete_tail(){
    struct node * NodeP;
    struct node * prev;
    NodeP = head;
    if(NodeP == NULL)return;
    
    while(NodeP->next!=NULL){
        prev = NodeP;  
        NodeP = NodeP->next;
     }
    prev->next = NULL;
    free(NodeP);
}

void find(int value){
	
	struct node* NodeP;
	
	NodeP = head;
	
	if(NodeP == NULL){
		printf("Empty List!!!\n");
		this_node = head;
		return;
	}
	
	while(NodeP!=NULL){
		
		if(NodeP->data!=value){
	    printf("%d\n",NodeP->data);
	    getchar();
		NodeP = NodeP->next;
	   }
		else{
			this_node = NodeP;
			break;
		}
	}
	
}

void Print(){
	
	struct node* NodeP;
	NodeP = head;
	
	printf("----------------Link-List------------------\n");
	while( NodeP!=NULL ){
		printf("%d -> ",NodeP->data);
		NodeP = NodeP->next;
        
	}
	printf("\n");
	printf("-------------------------------------------\n");
	printf("\n\n");
}
