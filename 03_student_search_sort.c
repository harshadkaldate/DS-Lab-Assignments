#include<stdio.h>
#define MAX 100

struct Student
{
 int roll;
 char name[50];
};

void display(struct Student a[],int n)
{
 int i;
 for(i=0;i<n;i++) printf("%d\t%s\n",a[i].roll,a[i].name);
}

int linearSearch(struct Student a[],int n,int key)
{
 int i;
 for(i=0;i<n;i++)
  if(a[i].roll==key) return i;
 return -1;
}

int binarySearch(struct Student a[],int low,int high,int key)
{
 int mid;
 while(low<=high)
 {
  mid=(low+high)/2;
  if(a[mid].roll==key) return mid;
  if(key<a[mid].roll) high=mid-1;
  else low=mid+1;
 }
 return -1;
}

void selectionSort(struct Student a[],int n)
{
 int i,j,min;
 struct Student temp;
 for(i=0;i<n-1;i++)
 {
  min=i;
  for(j=i+1;j<n;j++)
   if(a[j].roll<a[min].roll) min=j;
  if(min!=i)
  {
   temp=a[i]; a[i]=a[min]; a[min]=temp;
  }
 }
}

void insertionSort(struct Student a[],int n)
{
 int i,j;
 struct Student key;
 for(i=1;i<n;i++)
 {
  key=a[i];
  j=i-1;
  while(j>=0&&a[j].roll>key.roll)
  {
   a[j+1]=a[j];
   j--;
  }
  a[j+1]=key;
 }
}

void shellSort(struct Student a[],int n)
{
 int gap,i,swapped;
 struct Student temp;
 for(gap=n/2;gap>=1;gap/=2)
 {
  do
  {
   swapped=0;
   for(i=0;i<n-gap;i++)
    if(a[i].roll>a[i+gap].roll)
    {
     temp=a[i]; a[i]=a[i+gap]; a[i+gap]=temp;
     swapped=1;
    }
  }while(swapped);
 }
}

int main()
{
 struct Student a[MAX],temp;
 int n,i,ch,key,pos;
 printf("Enter number of students: ");
 scanf("%d",&n);
 if(n<1||n>MAX) return 0;
 for(i=0;i<n;i++)
 {
  printf("Enter roll number and name: ");
  scanf("%d %49s",&a[i].roll,a[i].name);
 }
 do
 {
  printf("\n1.Display 2.Linear Search 3.Binary Search\n");
  printf("4.Selection Sort 5.Insertion Sort 6.Shell Sort 7.Exit\n");
  printf("Choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: display(a,n); break;
   case 2:
    printf("Enter roll number: "); scanf("%d",&key);
    pos=linearSearch(a,n,key);
    if(pos==-1) printf("Student not found\n");
    else printf("Found: %d %s\n",a[pos].roll,a[pos].name);
    break;
   case 3:
    insertionSort(a,n);
    printf("Enter roll number: "); scanf("%d",&key);
    pos=binarySearch(a,0,n-1,key);
    if(pos==-1) printf("Student not found\n");
    else printf("Found: %d %s\n",a[pos].roll,a[pos].name);
    break;
   case 4: selectionSort(a,n); printf("Sorted by selection sort\n"); display(a,n); break;
   case 5: insertionSort(a,n); printf("Sorted by insertion sort\n"); display(a,n); break;
   case 6: shellSort(a,n); printf("Sorted by shell sort\n"); display(a,n); break;
   case 7: break;
   default: printf("Invalid choice\n");
  }
 }while(ch!=7);
 return 0;
}
