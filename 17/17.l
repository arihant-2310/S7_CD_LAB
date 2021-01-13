%{ 
#include <stdio.h>
#include<stdlib.h>
int vcount = 0;
int ccount = 0;
%} 

%% 
[a|e|i|o|u|A|E|I|O|U] { vcount ++; }
[a-z A-Z (^a|i|e|o|u|E|A|I|O|U) ] { ccount++; }
\n {return 0;}
%% 

int yywrap() {}

void yyerror() {
    printf("error\n");
}

int main() { 
  yylex(); 
  printf("vowels : %d\t consonants : %d\n",vcount,ccount);
  return 0; 
} 




