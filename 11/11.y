%{
#include<stdio.h>
#include<stdlib.h>
%}
%token ID TYPE SC NL COMMA
%%
start:TYPE rep SC NL {printf("valid");return(0);};
rep: ID | rep COMMA ID;
%%
void yyerror(const char *str){printf("error");exit(0);}
int yywrap(){return 0;}
main(){printf("enter code : ");yyparse();}