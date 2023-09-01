
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *create(struct node *list)
{
 int n,i;
 struct node *temp,*newnode;
 printf("enter limit");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("enter value");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(list==NULL)
  {
   list=newnode;
   temp=newnode;
  }
  else
  {
   temp->next=newnode;
   temp=newnode;
  }
 }
 return list;
}
void disp(struct node *list)
{
 struct node *temp;
 for(temp=list;temp!=NULL;temp=temp->next)
{
 printf("%d\t",temp->data);
}
}
struct node *insertend(struct node *list,int num)
{
 struct node *newnode,*temp;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->next=NULL;
 newnode->data=num;
 for(temp=list;temp->next!=NULL;temp=temp->next);
 temp->next=newnode;
 return list;
}
int main()
{
 int i,num,ch;
 struct node *list=NULL;
 do
 {
  printf("\n1=create \n2=disp \n3=insert end");
  printf("enter choice");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:list=create(list);
          break;
   case 2:disp(list);
          break;
  case 3:printf("enter number");
         scanf("%d",&num);
         list=insertend(list,num);
         break;
  }
 }while(ch<4);
}
