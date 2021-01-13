%{
#include<stdio.h>
#include "y.tab.h"
char arry[10][10];
int i=0;
%}
%%
int|float|char return TYPE;
"," return COMMA;
";" return SC;
[a-zA-Z][a-zA-Z0-9]* {  for(int i=0;i<10;i++) {
                            if(strcmp(arry[i],yytext)!=0) {
                                strcpy(arry[i++],yytext);
                                break;
                            }
                            else printf("%s ",arry[i]);
                        } return ID;    }
"\n" return NL;
. {;}
%%
