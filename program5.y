%{
#include <stdio.h>
#include <stdlib.h>
int yyerror();
int yylex();
%}

%token L D

%%

var : L E {
        printf("Valid Variable\n");
        return 0;
      }
    ;

E : E L
  | E D
  | /* empty */
  ;

%%

int main() {
    printf("Type the variable\n");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    printf("Error: %s\n", s);
    exit(1);
}
