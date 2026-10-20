#include<stdio.h>
#define MAX 20

void displayMatrix(int a[MAX][MAX],int r,int c)
{
 int i,j;
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++) printf("%d ",a[i][j]);
  printf("\n");
 }
}

void addMatrix(int a[MAX][MAX],int b[MAX][MAX],int r1,int r2,int c1,int c2)
{
 int s[MAX][MAX],i,j;
 if(r1==r2&&c1==c2)
 {
  printf("Addition:\n");
  for(i=0;i<r1;i++)
   for(j=0;j<c1;j++) s[i][j]=a[i][j]+b[i][j];
  displayMatrix(s,r1,c1);
 }
 else printf("Matrices cannot be added\n");
}

void subMatrix(int a[MAX][MAX],int b[MAX][MAX],int r1,int r2,int c1,int c2)
{
 int s[MAX][MAX],i,j;
 if(r1==r2&&c1==c2)
 {
  printf("Subtraction:\n");
  for(i=0;i<r1;i++)
   for(j=0;j<c1;j++) s[i][j]=a[i][j]-b[i][j];
  displayMatrix(s,r1,c1);
 }
 else printf("Matrices cannot be subtracted\n");
}

void transpose(int a[MAX][MAX],int r,int c)
{
 int t[MAX][MAX],i,j;
 for(i=0;i<c;i++)
  for(j=0;j<r;j++) t[i][j]=a[j][i];
 printf("Transpose:\n");
 displayMatrix(t,c,r);
}

void multiMatrix(int a[MAX][MAX],int b[MAX][MAX],int r1,int r2,int c1,int c2)
{
 int m[MAX][MAX],i,j,k,sum;
 if(c1==r2)
 {
  printf("Multiplication:\n");
  for(i=0;i<r1;i++)
   for(j=0;j<c2;j++)
   {
    sum=0;
    for(k=0;k<c1;k++) sum+=a[i][k]*b[k][j];
    m[i][j]=sum;
   }
  displayMatrix(m,r1,c2);
 }
 else printf("Matrices cannot be multiplied\n");
}

int main()
{
 int a[MAX][MAX],b[MAX][MAX],r1,c1,r2,c2,i,j;
 printf("Enter rows and columns of first matrix: ");
 scanf("%d%d",&r1,&c1);
 printf("Enter rows and columns of second matrix: ");
 scanf("%d%d",&r2,&c2);
 if(r1<1||r1>MAX||c1<1||c1>MAX||r2<1||r2>MAX||c2<1||c2>MAX)
 {
  printf("Invalid dimensions\n");
  return 0;
 }
 printf("Enter first matrix:\n");
 for(i=0;i<r1;i++) for(j=0;j<c1;j++) scanf("%d",&a[i][j]);
 printf("Enter second matrix:\n");
 for(i=0;i<r2;i++) for(j=0;j<c2;j++) scanf("%d",&b[i][j]);
 addMatrix(a,b,r1,r2,c1,c2);
 subMatrix(a,b,r1,r2,c1,c2);
 multiMatrix(a,b,r1,r2,c1,c2);
 transpose(a,r1,c1);
 return 0;
}
