#include<stdio.h>
#include<ctype.h>
int main()
{
    char eq,a,b,c,symb;
    int T;
    printf("\nEnter the number of test cases");
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("\nEnter the equation\n");
        scanf(" %c%c%c%c%c",&c,&eq,&a,&symb,&b);
        printf("\nThe machine code equivalent to C code:");
        c=toupper(c);
        a=toupper(a);
        b=toupper(b);
        switch(symb)
        {
            case '+':
                     printf("\nMOV AX,%c",a);
                     printf("\nADD AX,%c",b);
                     printf("\nMOV %c,AX",c);
                     break;
            case '-':
                     printf("\nMOV AX,%c",a);
                     printf("\nSUB AX,%c",b);
                     printf("\nMOV %c,AX",c);
                     break;
            case '*':
                     printf("\nMOV AL,%c",a);
                     printf("\nMUL %c",b);
                     printf("\nMOV %c,DX",c);
                     break;
            case '/':
                     printf("\nMOV AL,%c",a);
                     printf("\nDIV %c",b);
                     printf("\nMOV %c,DX",c);
                     break;
        }
    }
    return 0;
}