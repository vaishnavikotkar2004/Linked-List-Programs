// Accept n numbers and display using..Singly linked list...
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
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter value");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(head==NULL)
  {
    head=newnode;
    temp=newnode;
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
  {
    printf("%d\t",temp->data);
  }
}
int main()
{
  struct node *head=NULL;
  head=create(head);
  disp(head);
}
