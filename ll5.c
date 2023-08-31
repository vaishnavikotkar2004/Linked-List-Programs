#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
};
struct node *create(struct node *list)
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
struct node *insertsingly(struct node *list,int p,int num)
{
 int i;
 struct node *temp,*newnode;
 if(p==1)
 {
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=num;
  newnode->next=list;
  list=newnode;
 }
 else
 {
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=num;
  for(i=1,temp=list;i<(p-1)&&temp->next!=NULL;i++,temp=temp->next);
  newnode->next=temp->next;
  temp->next=newnode;
 }
 return list;
}
struct node *delmid(struct node *list,int p)
{
 int i;
 struct node *temp1,*temp;
 for(i=1,temp=list;i<(p-1)&&temp->next!=NULL;i++,temp=temp->next);
 temp1=temp->next;
 temp->next=temp1->next;
 free(temp1);
 return list;
}
int main()
{
 struct node *list=NULL;
 int ch,num,p;
 do
 {
  printf("\n1=create \n2=display \n3=insert common \n4=delete middle");
  printf("enter choice");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:list=create(list);
          break;
   case 2:disp(list);
          break;
   case 3:printf("enter num ");
          scanf("%d",&num);
          printf("enter position");
          scanf("%d",&p);
          list=insertsingly(list,p,num);
          break;
  case 4:printf("enter position");
         scanf("%d",&p);
         list=delmid(list,p);
         break;
  }
 }while(ch<5);
}
