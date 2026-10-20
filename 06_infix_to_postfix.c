#include<stdio.h>
#define MAX 100

char stack[MAX];
int top=-1;

int isFull()
{
 return top==MAX-1;
}

int isEmpty()
{
 return top==-1;
}

void push(char x)
{
 if(!isFull()) stack[++top]=x;
}

char pop()
{
 if(!isEmpty()) return stack[top--];
 return '\0';
}

int icp(char ch)
{
 if(ch=='+'||ch=='-') return 1;
 if(ch=='*'||ch=='/') return 2;
 if(ch=='^') return 4;
 if(ch=='(') return 5;
 return 0;
}

int isp(char ch)
{
 if(ch=='+'||ch=='-') return 1;
 if(ch=='*'||ch=='/') return 2;
 if(ch=='^') return 3;
 return 0;
}

int operand(char ch)
{
 return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9');
}

int main()
{
 char infix[MAX],postfix[MAX],ch;
 int i=0,k=0;
 printf("Enter infix expression without spaces: ");
 scanf("%99s",infix);
 while((ch=infix[i++])!='\0')
 {
  if(operand(ch)) postfix[k++]=ch;
  else if(ch=='(') push(ch);
  else if(ch==')')
  {
   while(!isEmpty()&&stack[top]!='(') postfix[k++]=pop();
   if(!isEmpty()) pop();
  }
  else
  {
   while(!isEmpty()&&isp(stack[top])>=icp(ch)) postfix[k++]=pop();
   push(ch);
  }
 }
 while(!isEmpty()) postfix[k++]=pop();
 postfix[k]='\0';
 printf("Postfix expression: %s\n",postfix);
 return 0;
}
