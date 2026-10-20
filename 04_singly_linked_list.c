#include<stdio.h>
#include<stdlib.h>

struct node
{
 int reg;
 char name[50];
 struct node *next;
};

int length(struct node *head)
{
 int n=0;
 struct node *p=head->next;
 while(p!=NULL) { n++; p=p->next; }
 return n;
}

void create(struct node *head)
{
 struct node *temp=head,*curr;
 char ch='y';
 while(ch=='y'||ch=='Y')
 {
  curr=(struct node*)malloc(sizeof(struct node));
  if(curr==NULL) return;
  printf("Enter registration number and name: ");
  scanf("%d %49s",&curr->reg,curr->name);
  curr->next=NULL;
  temp->next=curr;
  temp=curr;
  printf("Add another student? (y/n): ");
  scanf(" %c",&ch);
 }
}

void display(struct node *head)
{
 struct node *curr=head->next;
 if(curr==NULL) { printf("List is empty\n"); return; }
 printf("RegNo\tName\n");
 while(curr!=NULL)
 {
  printf("%d\t%s\n",curr->reg,curr->name);
  curr=curr->next;
 }
}

void insertByPos(struct node *head)
{
 struct node *curr=head,*nnode;
 int pos,i=1,k=length(head);
 printf("Enter registration number and name: ");
 nnode=(struct node*)malloc(sizeof(struct node));
 if(nnode==NULL) return;
 scanf("%d %49s",&nnode->reg,nnode->name);
 printf("Enter position (1 to %d): ",k+1);
 scanf("%d",&pos);
 if(pos<1||pos>k+1)
 {
  printf("Data can't be inserted\n");
  free(nnode);
  return;
 }
 while(i<pos) { curr=curr->next; i++; }
 nnode->next=curr->next;
 curr->next=nnode;
}

void deleteByPos(struct node *head)
{
 struct node *prev=head,*curr=head->next;
 int pos,i=1,k=length(head);
 printf("Enter position to delete: ");
 scanf("%d",&pos);
 if(pos<1||pos>k) { printf("Data can't be deleted\n"); return; }
 while(i<pos) { prev=curr; curr=curr->next; i++; }
 prev->next=curr->next;
 free(curr);
}

void reverse(struct node *head)
{
 struct node *prev=NULL,*curr=head->next,*future;
 while(curr!=NULL)
 {
  future=curr->next;
  curr->next=prev;
  prev=curr;
  curr=future;
 }
 head->next=prev;
}

void sort(struct node *head)
{
 int i,j,k=length(head);
 struct node *prev,*curr,*temp;
 for(i=1;i<k;i++)
 {
  prev=head;
  curr=head->next;
  for(j=0;j<k-i;j++)
  {
   temp=curr->next;
   if(curr->reg>temp->reg)
   {
    prev->next=temp;
    curr->next=temp->next;
    temp->next=curr;
    prev=temp;
   }
   else
   {
    prev=curr;
    curr=curr->next;
   }
  }
 }
}

void freeList(struct node *head)
{
 struct node *p=head->next,*temp;
 while(p!=NULL) { temp=p; p=p->next; free(temp); }
 free(head);
}

int main()
{
 struct node *head=(struct node*)malloc(sizeof(struct node));
 int ch;
 if(head==NULL) return 0;
 head->next=NULL;
 do
 {
  printf("\n1.Create list 2.Display 3.Length 4.Insert by position\n");
  printf("5.Delete by position 6.Sort by RegNo 7.Reverse 8.Exit\nChoice: ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
    while(head->next!=NULL)
    {
     struct node *p=head->next;
     head->next=p->next;
     free(p);
    }
    create(head); break;
   case 2: display(head); break;
   case 3: printf("Length = %d\n",length(head)); break;
   case 4: insertByPos(head); break;
   case 5: deleteByPos(head); break;
   case 6: sort(head); printf("List sorted\n"); break;
   case 7: reverse(head); printf("List reversed\n"); break;
   case 8: break;
   default: printf("Invalid choice\n");
  }
 }while(ch!=8);
 freeList(head);
 return 0;
}
