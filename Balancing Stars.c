#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

char stack[1000];
int top=-1;

void push(char ele)
{
    stack[++top]=ele;
}

void pop()
{
    top=top-1;
}

int main()
{
    int n;
    int i;
    int k;
    int no=0;
    char s[1000];
    int starcount=0;
    int ans=0;

    scanf("%s",s);

    n=strlen(s);

    for(k=0;k<n;k++)
    {
        if(s[k]=='}' || s[k]==']' || s[k]==')' )
        {
            no=1;
        }

        else if(s[k]=='{' || s[k]=='[' || s[k]=='(')
            break;
    }


    for(i=k;i<n;i++)
    {
        //starcount=0;
        if(top<0)
            top=-1;
       // printf("\n%c",s[i]);
        //printf("top = %d ",top);
        if(s[i]=='{' || s[i]=='[' || s[i]=='(' || s[i]=='*')
        {
            push(s[i]);
        }

        else if( s[i]=='}' )
        {
            while(s[top]!= '{')
            {
                if(s[top]=='*')
                    starcount++;
                pop();
            }
            pop();

            if(starcount >= 2)
                ans++;

        }

         else if( s[i]==']' )
        {
            while(s[top]!= '[')
            {
                if(s[top]=='*')
                    starcount++;
                pop();
            }
            pop();


            if(starcount >= 2)
                ans++;
        }

         else if( s[i]==')' )
        {
            while(s[top]!= '(')
            {
                if(s[top]=='*')
                    starcount++;
                pop();
            }
            pop();

            if(starcount >= 2)
                ans++;
        }

        else if(s[i]=='a' || s[i]=='d' || s[i]=='s' || s[i]=='2' || s[i]=='3' || s[i]=='1')
        {
            push(s[i]);
        }

    }//close of for loop

    for(i=0;i<=top;i++)
    {
        if(s[i]=='{' || s[i]=='[' || s[i]=='(' )
            no=1;
    }

    if(no==1)
        printf("NO %d",ans);
    else
        printf("YES %d",ans);


}//close of main
