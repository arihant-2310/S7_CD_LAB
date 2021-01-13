%{
int words = 0;
%}
%%
([a-zA-Z0-9])* {words++;}
"\n" {printf("\t\tThe words are:%d\n\n",words); words=0;}
%%
int yywrap(){}
int main(){
    yylex();
    return 0;
}