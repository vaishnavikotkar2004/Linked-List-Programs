#include<stdio.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
};
struct node *create(struct node *head)
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
 {
   printf("%d\t",temp->data);
 }
}
int main()
{
 struct node *head=NULL;
 int ch,num;
 do
 {
  printf("\n1=create \n2=display \n enter choice");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1 : head=create(head);
             break;
    case 2 : disp(head);
             break;
    default : printf("invalid choice");
              break;
  }
 }while(ch<3);
}
