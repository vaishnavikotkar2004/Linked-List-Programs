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
struct node *insertbeg(struct node *list,int num)
{
 struct node *newnode;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=num;
 newnode->next=list;
 list=newnode;
 return list;
}
void disp(struct node *list)
{
 struct node *temp;
 temp=list;
 while(temp!=NULL)
 {
  printf("%d\t",temp->data);
  temp=temp->next;
 }
}
int main()
{
 struct node *list=NULL;
 int ch,num;
 do
 {
  printf("\n1=create \n2=display \n3=insert begining");
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
          list=insertbeg(list,num);
          break;
   default:printf("invalid choice");
           break;
  }
 }while(ch<4);
}
