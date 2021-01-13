%{
#include <stdio.h>
#include <stdlib.h>
%}
%token ZERO ONE

%%
start : ZERO rep {printf("Vaild");return(0);}
	| ZERO {printf("Vaild");return(0);};
rep : ZERO rep
	| ONE rep
	| ZERO ;
%%

int main(){
    printf("Enter exp : ");
    yyparse();
    return(0);
}

int yyerror(char *s){
    printf("Invaild");
    exit(0);
}

int yywrap(){}