#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
 int data;
 struct node *next;
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
  if(list==NULL)
  {
    list=temp=newnode;
    newnode->next=list;
  }
  else
  {
    temp->next=newnode;
    newnode->next=list;
    temp=newnode;
  }
 }
 return list;
}
void disp(NODE *list)
{
 NODE *temp=list;
 do
 {
  printf("%d\t",temp->data);
  temp=temp->next;
 }while(temp!=list);
}
NODE *insertbeg(NODE *list,int num)
{
 NODE *temp,*newnode;
 newnode=(NODE *)malloc(sizeof(NODE));
 newnode->data=num;
 for(temp=list;temp->next!=list;temp=temp->next);
 newnode->next=list;
 list=newnode;
 temp->next=list;
 return list;
}
NODE *insertmid(NODE *list,int num,int p)
{
 NODE *newnode,*temp;
 int i;
 newnode=(NODE *)malloc(sizeof(NODE));
 newnode->data=num;
 for(i=1,temp=list;i<(p-1)&&temp->next!=NULL;i++,temp=temp->next);
 newnode->next=temp->next;
 temp->next=newnode;
 return list;
}
NODE *insertcommon(NODE *list,int p)
{
 int num,i;
 NODE *temp,*newnode;
 newnode=(NODE *)malloc(sizeof(NODE));
 if(p==1)
 {
  newnode->data=num;
  for(temp=list;temp->next!=list;temp=temp->next);
  newnode->next=list;
  list=newnode;
  temp->next=list;
 }
 else
 {
  newnode->data=num;
  for(i=1,temp=list;i<(p-1)&&temp->next!=NULL;i++,temp=temp->next);
  newnode->next=temp->next;
  temp->next=newnode;
 }
 return list;
}
int main()
{
 NODE *list=NULL;
 int num,ch,i,p;
 do
 {
  printf("\n1=create \n2=disp \n3=insert beg \n4=insert middle \n5=insert common");
  printf("enter choice");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:list=create(list);
           break;
   case 2:disp(list);break;
   case 3:printf("enter number");
          scanf("%d",&num);
          list=insertbeg(list,num);
          break;
  case 4:printf("enter number");
         scanf("%d",&num);
         printf("enter position");
         scanf("%d",&p);
         list=insertmid(list,num,p);
         break;
  case 5:printf("enter position");
         scanf("%d",&p);
         list=insertcommon(list,p);
         break;
  }
 }while(ch<6);
}
