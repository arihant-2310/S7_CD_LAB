%{
#include <stdio.h>
#include<stdlib.h>
int ch=0, bl=0, ln=0, wr=0;
%}

%%
[\n] {ln++;wr++;}
[\t] {bl++;wr++;}
[" "] {bl++;wr++;}
[^\n\t] {ch++;}
%%

int yywrap() {}

int yyerror( char *s) {
    printf("error\n");
}

int main()
{
yyin = fopen("input.txt", "r");
if(yyin == NULL){
	printf("error while opening the file\n");
	exit(0);
	}
printf("\n");
yylex();
printf("Character=%d\nWords=%d\nSpace=%d\nLines=%d\n", ch, wr, bl, ln);
fclose(yyin);
return 0;
}




