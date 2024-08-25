%{
#include "y.tab.h"
extern int yylval;
%}

%%
[0-9]+  { yylval = atoi(yytext); return num; }
[\+\-\*\/] { return yytext[0]; }
[()]   { return yytext[0]; }
[ \t]  { /* Ignore whitespace */ }
\n     { return 0; }
.      { /* Ignore any other character */ }

%%
