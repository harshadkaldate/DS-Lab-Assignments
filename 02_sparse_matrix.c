#include<stdio.h>
#define MAX 20

void compact(int a[MAX][MAX],int r,int c,int b[MAX*MAX+1][3])
{
 int i,j,k=1;
 b[0][0]=r;
 b[0][1]=c;
 for(i=0;i<r;i++)
  for(j=0;j<c;j++)
   if(a[i][j]!=0)
   {
    b[k][0]=i;
    b[k][1]=j;
    b[k][2]=a[i][j];
    k++;
   }
 b[0][2]=k-1;
}

void display(int a[MAX*MAX+1][3])
{
 int i;
 printf("Row Col Value\n");
 for(i=0;i<=a[0][2];i++)
  printf("%d   %d   %d\n",a[i][0],a[i][1],a[i][2]);
}

void transpose(int a[MAX*MAX+1][3],int b[MAX*MAX+1][3])
{
 int m=a[0][0],n=a[0][1],terms=a[0][2],col,p,q=1;
 b[0][0]=n;
 b[0][1]=m;
 b[0][2]=terms;
 for(col=0;col<n;col++)
  for(p=1;p<=terms;p++)
   if(a[p][1]==col)
   {
    b[q][0]=a[p][1];
    b[q][1]=a[p][0];
    b[q][2]=a[p][2];
    q++;
   }
}

void fastTranspose(int a[MAX*MAX+1][3],int b[MAX*MAX+1][3])
{
 int s[MAX]={0},t[MAX]={0};
 int m=a[0][0],n=a[0][1],terms=a[0][2],i,j;
 b[0][0]=n;
 b[0][1]=m;
 b[0][2]=terms;
 if(terms==0) return;
 for(i=1;i<=terms;i++) s[a[i][1]]++;
 t[0]=1;
 for(i=1;i<n;i++) t[i]=t[i-1]+s[i-1];
 for(i=1;i<=terms;i++)
 {
  j=a[i][1];
  b[t[j]][0]=a[i][1];
  b[t[j]][1]=a[i][0];
  b[t[j]][2]=a[i][2];
  t[j]++;
 }
}

int main()
{
 int a[MAX][MAX],b[MAX*MAX+1][3],tr[MAX*MAX+1][3],ft[MAX*MAX+1][3];
 int r,c,i,j;
 printf("Enter rows and columns: ");
 scanf("%d%d",&r,&c);
 if(r<1||r>MAX||c<1||c>MAX)
 {
  printf("Invalid dimensions\n");
  return 0;
 }
 printf("Enter matrix:\n");
 for(i=0;i<r;i++) for(j=0;j<c;j++) scanf("%d",&a[i][j]);
 compact(a,r,c,b);
 printf("\nCompact representation:\n");
 display(b);
 transpose(b,tr);
 printf("\nSimple transpose:\n");
 display(tr);
 fastTranspose(b,ft);
 printf("\nFast transpose:\n");
 display(ft);
 return 0;
}
