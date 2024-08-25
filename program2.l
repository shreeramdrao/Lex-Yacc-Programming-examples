%{
#include<stdio.h>
int s=0,m=0;
%}
%%
"/*"[a-zA-Z0-9' '\t\n]*"*/" m++;
 "//".* s++;
%%
int main(){ yyin=fopen("f1.txt","r"); 
yyout=fopen("f2.txt","w");
yylex();
fclose(yyin);
fclose(yyout);
printf("no of single line comments=%d\n",s); 
printf("no of multi line comments=%d\n",m);
}
int yywrap() {
return 1;
}