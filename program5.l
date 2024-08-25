%{
#include "y.tab.h"
%}

%%
[a-zA-Z]   { return L; }
[0-9]      { return D; }
\n         { /* Ignore newline */ }
[ \t]      { /* Ignore whitespace */ }
.          { /* Ignore any other characters */ }

%%

int yywrap() {
    return 1; // Indicate end of input
}
