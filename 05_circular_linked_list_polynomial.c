#include<stdio.h>
#include<stdlib.h>

struct node
{
 int coef,exp;
 struct node *next;
};

struct node *getnode()
{
 struct node *p=(struct node*)malloc(sizeof(struct node));
 if(p==NULL) exit(1);
 return p;
}

void insert(struct node *head,struct node *newnode)
{
 struct node *p=head->next,*prev=head;
 while(p!=head&&p->exp>newnode->exp)
 {
  prev=p;
  p=p->next;
 }
 if(p!=head&&p->exp==newnode->exp)
 {
  p->coef+=newnode->coef;
  if(p->coef==0)
  {
   prev->next=p->next;
   free(p);
  }
  free(newnode);
 }
 else
 {
  newnode->next=p;
  prev->next=newnode;
 }
}

struct node *create()
{
 struct node *head=getnode(),*newnode;
 int n,i;
 head->exp=-1;
 head->next=head;
 printf("Enter number of terms: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  newnode=getnode();
  printf("Enter coefficient and exponent: ");
  scanf("%d%d",&newnode->coef,&newnode->exp);
  insert(head,newnode);
 }
 return head;
}

void display(struct node *head)
{
 struct node *p=head->next;
 if(p==head) { printf("0\n"); return; }
 while(p!=head)
 {
  printf("%dx^%d",p->coef,p->exp);
  p=p->next;
  if(p!=head&&p->coef>0) printf("+");
 }
 printf("\n");
}

struct node *addPoly(struct node *a,struct node *b)
{
 struct node *h=getnode(),*tail,*p=a->next,*q=b->next,*curr;
 h->exp=-1;
 h->next=h;
 tail=h;
 while(p!=a||q!=b)
 {
  curr=getnode();
  if(p!=a&&q!=b&&p->exp==q->exp)
  {
   curr->exp=p->exp;
   curr->coef=p->coef+q->coef;
   p=p->next;
   q=q->next;
  }
  else if(q==b||(p!=a&&p->exp>q->exp))
  {
   curr->exp=p->exp;
   curr->coef=p->coef;
   p=p->next;
  }
  else
  {
   curr->exp=q->exp;
   curr->coef=q->coef;
   q=q->next;
  }
  if(curr->coef==0) free(curr);
  else
  {
   tail->next=curr;
   curr->next=h;
   tail=curr;
  }
 }
 return h;
}

void freePoly(struct node *h)
{
 struct node *p=h->next,*temp;
 while(p!=h) { temp=p; p=p->next; free(temp); }
 free(h);
}

int main()
{
 struct node *p1,*p2,*sum;
 printf("First polynomial\n");
 p1=create();
 printf("Second polynomial\n");
 p2=create();
 printf("P1 = "); display(p1);
 printf("P2 = "); display(p2);
 sum=addPoly(p1,p2);
 printf("Sum = "); display(sum);
 freePoly(p1);
 freePoly(p2);
 freePoly(sum);
 return 0;
}
