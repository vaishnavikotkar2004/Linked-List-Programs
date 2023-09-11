//write a cprogram to sort linked list using any sorting techniques...
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
struct node *sort(struct node *list)
{
 int t;
 struct node *i,*j;
 for(i=list;i!=NULL;i=i->next)
 {
  for(j=list;j!=i;j=j->next)
  {
   if(i->data<j->data)
   {
    t=i->data;
    i->data=j->data;
    j->data=t;
    }
   }
 }
 return list;
}
int main()
{
 struct node *list=NULL;
 list=create(list);
 printf("\n display linked list");
 disp(list);
 list=sort(list);
 printf("\n display sorted linked list");
 disp(list);
}
