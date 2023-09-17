#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node *next,*prev;
}NODE;
NODE *create(NODE *list)
{
 NODE *temp,*newnode;
 int i,n;
 printf("enter limit");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  newnode=(NODE *)malloc(sizeof(NODE));
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
void disp(NODE *list)
{
 NODE *temp;
 for(temp=list;temp!=NULL;temp=temp->next)
 {
  printf("%d\t",temp->data);
 }
}
NODE *insertmid(NODE *list,int num,int p)
{
 NODE *newnode,*temp;
 int i;
 newnode=(NODE *)malloc(sizeof(NODE));
 newnode->data=num;
 for(i=1,temp=list;i<(p-1)&&temp->next!=NULL;i++,temp=temp->next);
 newnode->next=temp->next;
 temp->next->prev=newnode;
 temp->next=newnode;
 newnode->prev=temp;
 return list;
}
NODE *insertend(NODE *list,int num)
{
 NODE *newnode,*temp;
 newnode=(NODE *)malloc(sizeof(NODE));
 newnode->data=num;
 newnode->next=NULL;
 for(temp=list;temp->next!=NULL;temp=temp->next);
 temp->next=newnode;
 newnode->prev=temp;
 return list;
}
NODE *delbeg(NODE *list)
{
 NODE *temp;
 temp=list;
 list=list->next;
 free(temp);
 return list;
}
NODE *delend(NODE *list)
{
 NODE *temp,*temp1;
 for(temp=list;temp->next->next!=NULL;temp=temp->next);
 temp1=temp->next;
 temp->next=NULL;
 free(temp1);
 return list;
}
NODE *delmid(NODE *list,int p)
{
 int i;
 NODE *temp,*temp1;
 for(i=1,temp=list;i<(p-1)&&temp->next!=NULL;i++,temp=temp->next);
 temp1=temp->next;
 temp->next=temp1->next;
 temp1->next->prev=temp;
 free(temp1);
 return list;
}
NODE *incommon(NODE *list,int num,int p)
{
 NODE *newnode,*temp;
 int i;
 newnode=(NODE *)malloc(sizeof(NODE));
 if(p==1)
 {
  newnode->data=num;
  newnode->next=list;
  list->prev=newnode;
  list=newnode;
 }
 else
 {
  newnode->data=num;
  for(i=1,temp=list;i<(p-1)&&temp->next!=NULL;i++,temp=temp->next);
  newnode->next=temp->next;
  temp->next->prev=newnode;
  temp->next=newnode;
  newnode->prev=temp;
 }
 return list;
}
NODE *delcommon(NODE *list,int p)
{
 NODE *temp,*temp1;
 int i;
 if(p==1)
 {
  temp=list;
  list=list->next;
  free(temp1);
  }
  else
  {
   for(i=1,temp=list;i<(p-1)&&temp->next!=NULL;i++,temp=temp->next);
   temp1=temp->next;
   temp->next=temp1->next;
   temp1->next->prev=temp;
   free(temp1);
  }
  return list;
}
NODE *append(NODE *list,int num)
{
 NODE *newnode,*temp;
 newnode=(NODE *)malloc(sizeof(NODE));
 newnode->data=num;
 newnode->next=NULL;
 if(list==NULL)
 {
  return newnode;
 }
 else
 {
  for(temp=list;temp->next!=NULL;temp=temp->next);
  temp->next=newnode;
  return list;
 }
}
NODE *merge(NODE *list1,NODE *list2)
{
 NODE *temp1=list1,*temp2=list2,*list3=NULL;
 while(temp1!=NULL&&temp2!=NULL)
 {
  if(temp1->data<temp2->data)
  {
   list3=append(list3,temp1->data);
   temp1=temp1->next;
  }
  else
  {
   list3=append(list3,temp1->data);
   temp1=temp1->next;
   }
 }
 while(temp2!=NULL)
 {
  list3=append(list3,temp2->data);
   temp2=temp2->next;
 }
 return list3;
}
int main()
{
 NODE *list=NULL;
 NODE *list1=NULL,*list2=NULL,*list3=NULL;
 int ch,num,p;
 do
 {
  printf("\n1=create \n2=display \n3=insert middle \n4=insert end \n5=delete beging \n6=delete end \n7=delete mid \n8=insert common \n9=delete common");
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
           printf("enter position");
           scanf("%d",&p);
           list=insertmid(list,num,p);
           break;
   case 4:printf("enter number");
          scanf("%d",&num);
          list=insertend(list,num);
          break;
   case 5:list=delbeg(list);
          break;
   case 6:list=delend(list);
          break;
   case 7:printf("enter position");
          scanf("%d",&p);
          list=delmid(list,p);
          break;
   case 8:printf("enter number");
          scanf("%d",&num);
          printf("enter position");
          scanf("%d",&p);
          list=incommon(list,num,p);
          break;
  case 9:printf("enter position");
         scanf("%d",&p);
         list=delcommon(list,p);
         break;
  case 10:list1=create(list1);
          list2=create(list2);
          list3=create(list3);
          disp(list3);
          break;
  }
 }while(ch<11);
}
