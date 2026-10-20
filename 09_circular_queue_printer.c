#include<stdio.h>
#define MAX 6

struct PrintJob
{
 int id;
 char title[50];
};

struct PrintJob q[MAX];
int front=0,rear=0;

int isFull()
{
 return (rear+1)%MAX==front;
}

int isEmpty()
{
 return front==rear;
}

void addCQ()
{
 if(isFull())
 {
  printf("Queue is full\n");
  return;
 }
 struct PrintJob job;
 printf("Enter job ID and document title (one word): ");
 scanf("%d %49s",&job.id,job.title);
 rear=(rear+1)%MAX;
 q[rear]=job;
 printf("Print job added\n");
}

void delCQ()
{
 if(isEmpty())
 {
  printf("Queue is empty\n");
  return;
 }
 front=(front+1)%MAX;
 printf("Processing job: %d %s\n",q[front].id,q[front].title);
}

void display()
{
 int i;
 if(isEmpty()) { printf("Queue is empty\n"); return; }
 i=(front+1)%MAX;
 while(1)
 {
  printf("Job ID: %d, Title: %s\n",q[i].id,q[i].title);
  if(i==rear) break;
  i=(i+1)%MAX;
 }
}

int main()
{
 int ch;
 do
 {
  printf("\n1.Add print job 2.Process print job 3.Display jobs 4.Exit\nChoice: ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: addCQ(); break;
   case 2: delCQ(); break;
   case 3: display(); break;
   case 4: break;
   default: printf("Invalid choice\n");
  }
 }while(ch!=4);
 return 0;
}
