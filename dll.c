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
 struct node *temp,*newnode;
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
   newnode->prev=temp;
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
struct node *insertbeg(struct node *list,int num)
{
 struct node *newnode;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=num;
 newnode->next=list;
 list->prev=newnode;
  list=newnode;
return list;
}
struct node *insertend(struct node *list,int num)
{
 struct node *newnode,*temp,*prev;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->next=NULL;
// for(temp=list;temp!=NULL;temp=temp->next);
 temp->next=newnode;
 newnode->prev=temp;
 return list;
}
int main()
{
 struct node *list=NULL;
 int ch,num;
 do
 {
  printf("\n1=create \n2=display \n3=insert beg \n4=insert end");
  printf("enter choice");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:list=create(list);break;
   case 2:disp(list);break;
   case 3:printf("enter number");
          scanf("%d",&num);
          list=insertbeg(list,num);break;
  case 4:printf("enter number");
         scanf("%d",&num);
         list=insertend(list,num);
         break;
  }
 }while(ch<5);
}
