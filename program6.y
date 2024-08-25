%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(const char *s);
%}
%token A B

%%
Str: S '\n' { return 0; }
   ;
S  : A S B
   | /* empty */
   ;

%%
int main()
{
    printf("Type the string:\n");
    if (!yyparse())
        printf("Valid String\n");
    return 0;
}

int yyerror(const char *s)
{
    printf("Invalid String\n");
    exit(0);
}
