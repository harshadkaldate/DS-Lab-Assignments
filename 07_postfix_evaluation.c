#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define MAX 100

int stack[MAX],top=-1;

void push(int x)
{
 if(top<MAX-1) stack[++top]=x;
}

int pop()
{
 if(top>=0) return stack[top--];
 return 0;
}

int main()
{
 char exp[MAX],ch;
 int i,a,b,result;
 printf("Enter postfix expression (single-digit operands): ");
 scanf("%99s",exp);
 for(i=0;exp[i]!='\0';i++)
 {
  ch=exp[i];
  if(isdigit((unsigned char)ch)) push(ch-'0');
  else
  {
   b=pop();
   a=pop();
   switch(ch)
   {
    case '+': result=a+b; break;
    case '-': result=a-b; break;
    case '*': result=a*b; break;
    case '/':
     if(b==0) { printf("Division by zero\n"); return 0; }
     result=a/b; break;
    case '^': result=(int)pow(a,b); break;
    default: printf("Invalid operator\n"); return 0;
   }
   push(result);
  }
 }
 if(top==0) printf("Result = %d\n",pop());
 else printf("Invalid expression\n");
 return 0;
}
