%{ 
#include <stdio.h>
#include<stdlib.h>
int flag = 0;
%} 

%% 
[a-z . 0-9]+@[a-z]+".com"|".in" {printf("Accepted\n");flag = 1;}
\n {return 0;}
. {flag = 0;}
%% 

int yywrap() {}

void yyerror() {
    printf("error\n");
}

int main() { 
  yylex(); 
  if (flag == 0)
 	printf("Not Accepted\n");
  return 0; 
} 




