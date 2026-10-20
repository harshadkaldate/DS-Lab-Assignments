#include<stdio.h>
#define MAX 5

struct PrintJob
{
 int id;
 char title[50];
};

struct PrintJob q[MAX];
int front=-1,rear=-1;

int isFull()
{
 return rear==MAX-1;
}

int isEmpty()
{
 return front==-1||front>rear;
}

void addQ()
{
 if(isFull())
 {
  printf("Queue is full\n");
  return;
 }
 struct PrintJob job;
 printf("Enter job ID and document title (one word): ");
 scanf("%d %49s",&job.id,job.title);
 if(front==-1) front=0;
 q[++rear]=job;
 printf("Print job added\n");
}

void delQ()
{
 if(isEmpty())
 {
  printf("Queue is empty\n");
  return;
 }
 printf("Processing job: %d %s\n",q[front].id,q[front].title);
 front++;
 if(front>rear) front=rear=-1;
}

void display()
{
 int i;
 if(isEmpty()) { printf("Queue is empty\n"); return; }
 for(i=front;i<=rear;i++)
  printf("Job ID: %d, Title: %s\n",q[i].id,q[i].title);
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
   case 1: addQ(); break;
   case 2: delQ(); break;
   case 3: display(); break;
   case 4: break;
   default: printf("Invalid choice\n");
  }
 }while(ch!=4);
 return 0;
}
