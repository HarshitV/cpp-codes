#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//each node for the free list
typedef struct node
{
	int *ptr;
	int id;
	int value;
	struct node *next;
} node;

node *head=NULL;

//checks if the ptr's id and given id is same 
int check(node *ptr,int id)
	{
		if(ptr->id==id)
			return 1;
		else return 0;
	}

void main()
{	printf("Type 'quit' to quit\n\n");
	
	char c[100];
	node *temp;
	int count=0,value;
	while(1)
	{
		printf(">> ");
		scanf("%s",c);
		if(strcmp(c,"quit")==0)
			exit(0);
		else if (!strcmp(c,"malloc"))
		{	
			scanf("%d",&value);
			//when no memory has been allocated
			if(head == NULL)
			{	count++;
				head=(node*)malloc(sizeof(node));
				head->id=count;
				head->ptr=(int*)malloc(value*sizeof(int));
				head->next=NULL;
				head->value=value;
			}
			else 
			{	count++;
				temp=(node*)malloc(sizeof(node));
				temp->id=count;
				(*temp).ptr=(int*)malloc(value*sizeof(int));
				temp->next=NULL;
				temp->value=value;
				node *t;
				t=head;
				while(t->next!=NULL)	//finding the last malloc node
					t=t->next;
				t->next=temp;
			}
		}

		else if (!strcmp(c,"free"))
		{	int flag=0;

			scanf("%d",&value);
			if (head==NULL)
				flag=0;
			
			//checking if we need to remove head		
			else if(check(head,value)==1)
			{	temp=head;
				head=head->next;	//head is shifted forward
				free(temp);
				flag=1;
			}
			else
			{	temp=head;
				while(temp->next!=NULL)
					if(check(temp->next,value)==1)
					{
						node *temp2;
						temp2=temp->next;
						temp->next=temp2->next;
						free(temp2);
						flag=1;
					}
					else temp=temp->next;
			}

			if(flag==0)
				printf("No malloc with the given id found!!\n");
			else flag=0;
		}

		else if (!strcmp(c,"print"))
		{	
			temp=head;
			while(temp!=NULL)
			{
				printf("\tID: %d , Address: %ld , bytes:%d\n",temp->id,(long int)temp->ptr,temp->value);
				temp=temp->next;
			}
			if(head==NULL)
				printf("\tNo memory has been allocated!\n");
		}
		else printf("\tNot a valid command!\n");
	}
}