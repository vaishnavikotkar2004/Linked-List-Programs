// singly linked list program...
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
};
struct node* create(struct node *head)
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
 struct node *temp;
 for(temp=head;temp!=NULL;temp=temp->next)
 printf("%d\t",temp->data);
}
struct node* insert(struct node *head,int pos,int num)
{
 struct node *newnode,*temp;
 int i;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=num;
 if(pos==1)
 {
  newnode->next=head;
  head=newnode;
 }
 else
 {
  for(i=1,temp=head;i<(pos-1)&&temp->next!=NULL;i++,temp=temp->next);
  newnode->next=temp->next;
  temp->next=newnode;
 }
 return head;
}
struct node* del(struct node *head,int pos)
{
 struct node *temp,*temp1;
 int i;
 if(pos==1)
 {
  temp=head;
  head=head->next;
  free(temp);
  }
  else
  {
   for(i=1,temp=head;i<(pos-1)&&temp->next!=NULL;temp=temp->next,i++);
   temp1=temp->next;
   temp->next=temp1->next;
   free(temp1);
  }
  return head;
}
struct node* search(struct node *head,int num)
{
  struct node *temp;
  for(temp=head;temp!=NULL;temp=temp->next)
  {
   if(temp->data==num)
      return temp;
   }
   return NULL;
}
int main()
{
 int ch,num,pos;
 struct node *head=NULL;
 do
 {
  printf("\n1=create \n2=display \n3=insert \n4=dele \n5=search");
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
            printf("enter position");
            scanf("%d",&pos);
            head=insert(head,pos,num);
            break;
    case 4: printf("enter position");
            scanf("%d",&pos);
            head=del(head,pos);
            break;
    case 5: printf("enter number");
            scanf("%d",&num);
            if(search(head,num)==NULL)
               printf("not found...");
            else
               printf("found...");
            break;
    default: printf("invalid choice");
             break;
  }
 }while(ch<6);
}
