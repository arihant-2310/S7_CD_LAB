#include <string.h>
#include <ctype.h>
#include <stdio.h>

void keyword(char str[10])
{
    if (str[0] == '"' || str[strlen(str)-1] == '"' )
        printf("\n%s is a literal", str);
    else if (strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 || strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 || strcmp("printf", str) == 0 || strcmp("static", str) == 0 || strcmp("switch", str) == 0 || strcmp("case", str) == 0)
        printf("\n%s is a keyword", str);
    else
        printf("\n%s is an identifier", str);
}

void main()
{
    FILE *f1, *f2;
    char c, str[10], st1[10], op[10];
    int num[100], lineno = 0, tokenvalue = 0, i = 0, j = 0, k = 0;
    num[0] = 0;
    printf("\nEnter the c program :\n");
    f1 = fopen("input", "w");
    while ((c = getchar()) != EOF)
        putc(c, f1);
    fclose(f1);
    f1 = fopen("input", "r");
    f2 = fopen("identifier", "w");
    while ((c = getc(f1)) != EOF)
    {
        if (isdigit(c))
        {
            tokenvalue = c - '0';
            c = getc(f1);
            while (isdigit(c))
            {
                tokenvalue *= 10 + c - '0';
                c = getc(f1);
            }
            num[i++] = tokenvalue;
            ungetc(c, f1);
        }
        else if (isalpha(c) || c == '"')
        {
            putc(c, f2);
            c = getc(f1);
            while (isdigit(c) || isalpha(c) || c == '_' || c == '$' || c == '"' )
            {
                putc(c, f2);
                c = getc(f1);
            }
            putc('\n', f2);
            ungetc(c, f1);
        }
        else if (c == '+' || c == '-'|| c == '*'|| c == '/' ||  c == '=')
            printf("\n%c is a operator", c);
        else
            printf(" ");
    }
    fclose(f2);
    fclose(f1);
    for (k = 0; k < i; k++)
        printf("\n%d is a constant", num[k]);
    printf("\n");
    f2 = fopen("identifier", "r");
    k = 0;
    while ((c = getc(f2)) != EOF)
    {
        if (c != '\n')
            str[k++] = c;
        else
        {
            str[k] = '\0';
            keyword(str);
            k = 0;
        }
    }
    fclose(f2);
    printf("\n");
}