#include <string.h>
#include <ctype.h>
#include <stdio.h>

int keyword(char str[10])
{
    if (strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 || strcmp("double", str) == 0 )
        return 1;
    else
        return 0;
}

void main()
{
    FILE *f1;
    char c, str[10];
    int i = 0;
    f1 = fopen("input", "r");
    while ((c = getc(f1)) != EOF)
    {
        if (c != ' ' && isalpha(c))
        {
            str[i++]=c;
            c = getc(f1);
            while(c != ' ' && isalpha(c))
            {
                str[i++]=c;
                c = getc(f1);
            }
            str[i]='\0';
            if(keyword(str)==1){
                c = getc(f1);
                while(c != ';'){
                    if(isdigit(c) || isalpha(c) || c == '_' || c == '$'|| c == '=' || c == '[' || c == ']' || c == '"'){
                        printf("%c",c);
                    }
                    else if(c == ',' ){
                        printf("\n");
                    }
                    c = getc(f1);
                }
                printf("\n");
            }
        }
        i=0;
    }

    fclose(f1);
    printf("\n");
}