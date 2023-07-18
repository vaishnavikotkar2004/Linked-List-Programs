// Menu driven program..using Singly linked list...
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node* create(struct node *head)
{
  struct node *newnode,*temp;
  int i,n;
  printf("enter limit");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
   newnode=(struct node *)malloc(sizeof(struct node));
   printf("enter value");
   scanf("%d",&newnode->data);
   newnode->next=NULL;
   if(head==NULL)
   {
     head=temp=newnode;
   }
   else
   {
    temp->next=newnode;
    temp=newnode;
   }
   }
   return head;
}
void disp(struct node *head)
{
  struct node *temp=head;
  while(temp!=NULL)
  {
   printf("%d\t",temp->data);
   temp=temp->next;
  }
}
struct node* insertbeg(struct node *head,int num)
{
 struct node *newnode;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=num;
 newnode->next=head;
 head=newnode;
 return head;
}
struct node* insertend(struct node *head,int num)
{
 struct node *newnode,*temp;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=num;
 newnode->next=NULL;
 for(temp=head;temp->next!=NULL;temp=temp->next);
 temp->next=newnode;
 return head;
}
int main()
{
 struct node *head=NULL;
 int ch,num;
 do
 {
   printf("\n1=create \n2=display \n3=insertbeg \n4=insertend");
   printf("enter choice");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1: head=create(head);
            break;
    case 2: disp(head);
            break;
    case 3: printf("enter number");
            scanf("%d",&num);
            head=insertbeg(head,num);
            break;
    case 4: printf("enter number");
            scanf("%d",&num);
            head=insertend(head,num);
            break;
    default: printf("invalid choice");
             break;
   }
  }while(ch<5);
}  
