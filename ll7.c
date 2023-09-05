#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next,*prev;
};
struct node *create(struct node *list)
{
 int i,n;
 struct node *newnode,*temp;
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
   list=temp=newnode;
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
int findmax(struct node *list)
{
 struct node *temp;
 int max=list->data;
 for(temp=list;temp!=NULL;temp=temp->next)
 {
  if(temp->data>max)
  {
   max=temp->data;
  }
 }
 return max;
}
int main()
{
 struct node *list=NULL;
 list=create(list);
 printf("maximum number =%d",findmax(list));
}
