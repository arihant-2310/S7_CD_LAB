%{
#include <stdio.h>
#include <stdlib.h>
%}
%token ID

%%
E : ID {printf("Vaild identifer");return(0);}
%%

int main(){
    printf("Enter name : ");
    yyparse();
    return(0);
}

int yyerror(char *s){
    printf("Invaild identifer");
    exit(0);
}

int yywrap(){}