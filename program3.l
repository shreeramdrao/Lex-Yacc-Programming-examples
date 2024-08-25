%{
#include <stdio.h>
#include <stdlib.h>
int pi = 0, ni = 0, pf = 0, nf = 0;
%}

%%

[-][0-9]+ {ni++;} 
[+]?[0-9]+ {pi++;} 
[-][0-9]*\.[0-9]+ {nf++;} 
[+]?[0-9]*\.[0-9]+ {pf++;}

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./a.out in.txt\n"); 
        exit(0);
    }
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    yylex();
    fclose(yyin);
    printf("Number of positive integers: %d\n", pi); 
    printf("Number of negative integers: %d\n", ni); 
    printf("Number of positive fractions: %d\n", pf); 
    printf("Number of negative fractions: %d\n", nf); 
    return 0;
}

int yywrap() {
    return 1;
}
