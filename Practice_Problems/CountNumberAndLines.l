%{
int chars=0;
int lines=0;
%}

%%
\n {++lines;}
. {++chars;}
end {return 0;}
%%

int yywrap(){}
int main(){
    yylex();
    printf("Lines:%d || Characters:%d\n",lines,chars);
    return 0;
}