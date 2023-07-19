// singly linked list program....
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node* create(struct node *head)
{
 struct node *newnode,*temp;
 int i,n;
 printf("enter limit");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  newnode=(struct newnode *)malloc(sizeof(struct node));
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
struct node* insertbeg(struct node *head,int num)
{
 struct node *newnode;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=num;
 newnode->next=head;
 head=newnode;
 return head;
}
struct node* insertend(struct node *head,int num)
{
 struct node *newnode,*temp;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=num;
 newnode->next=NULL;
 for(temp=head;temp->next!=NULL;temp=temp->next);
 temp->next=newnode;
 return head;
}
struct node* insertmid(struct node *head,int num,int position)
{
 int i;
 struct node *newnode,*temp;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=num;
 for(i=1,temp=head;i<(position-1)&&temp->next!=NULL;i++,temp=temp->next);
 newnode->next=temp->next;
 temp->next=newnode;
 return head;
}
struct node* delbeg(struct node *head)
{
 struct node *temp;
 temp=head;
 head=head->next;
 free(temp);
 return head;
}
struct node* delend(struct node *head)
{
 struct node *temp,*temp1;
 for(temp=head;temp->next->next!=NULL;temp=temp->next);
 temp1=temp->next;
 temp->next=NULL;
 free(temp1);
 return head;
}
struct node* delmid(struct node *head,int position)
{
 int i;
 struct node *temp,*temp1;
 for(i=1,temp=head;i<(position-1)&&temp->next!=NULL;i++,temp=temp->next);
 temp1=temp->next;
 temp->next=temp1->next;
 free(temp1);
 return head;
}
int main()
{
 int ch,num,position;
 struct node *head=NULL;
 do
 {
  printf("\n1=create \n2=display \n3=insert beg \n4=insert end \n5=insert mid \n6=delete beg \n7=delete end \n8=delete mid");
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
           head=insertbeg(head,num);
           break;
   case 4: printf("enter number");
           scanf("%d",&num);
           head=insertend(head,num);
           break;
   case 5: printf("enter number");
           scanf("%d",&num);
           printf("enter position");
           scanf("%d",&position);
           head=insertmid(head,position,num);
           break;
   case 6: head=delbeg(head);
           break;
   case 7: head=delend(head);
           break;
   case 8: printf("enter position");
           scanf("%d",&position);
           head=delmid(head,position);
           break;
   default: printf("invalid choice");
            break;
   }
 }while(ch<9);
}
