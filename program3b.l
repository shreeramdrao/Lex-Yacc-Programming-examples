%{
#include<stdio.h>
int sf=0,pf=0;
%}
%%
"scanf" {sf++; 
fprintf(yyout,"readf");} 
"printf" {pf++; 
fprintf(yyout,"writef");} 
%%
int main()
{
yyin=fopen("f1.c","r");
yyout=fopen("f2.c","w");
yylex();
printf("no of scanf =%d\n no of printf =%d\n",sf,pf); 
return 0;
}