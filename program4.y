%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(const char *msg);
%}

%token num
%left '+' '-'
%left '*' '/'

%%
input: exp { printf("%d\n", $1); exit(0); }
     ;

exp: exp '+' exp { $$ = $1 + $3; }
   | exp '-' exp { $$ = $1 - $3; }
   | exp '*' exp { $$ = $1 * $3; }
   | exp '/' exp { if ($3 == 0) { printf("Division by zero\n"); exit(0); } else $$ = $1 / $3; }
   | '(' exp ')' { $$ = $2; }
   | num { $$ = $1; }
   ;

%%

int yyerror(const char *msg) {
    printf("Error: %s\n", msg);
    return 0;
}

int main() {
    printf("Enter the expression:\n");
    yyparse();
    return 0;
}
