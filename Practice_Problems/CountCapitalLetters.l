%{
int count = 0;
%}

%%
[A-Z] {count++; printf("%s is the capital letter.\n",yytext);}
. {printf("%s is not a capital letter.\n",yytext);}
\n {return 0;}
%%

int yywrap(){}

int main()
{
    FILE *fp;
    fp = fopen("input.txt","r");
    yyin = fp;
    yylex();
    printf("The total number of capital letters are:%d\n",count);
    return 0;
}