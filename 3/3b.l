%{
    #include "y.tab.h"
    extern yylval;
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* {return ID;}
[\n] {return 0;}
[\t] {;}
. {return yytext[0];}
%%