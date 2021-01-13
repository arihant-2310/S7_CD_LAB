%{
#include<stdio.h>
#include "y.tab.h"
%}
%%
[1] return ONE;
[0] return ZERO;
[\n] return(0);
[\t] {;}
. {return yytext[0];}
%%
