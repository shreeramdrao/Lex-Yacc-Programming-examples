%{
#include<stdio.h>
int c=0;
%}
%%
[a-zA-Z]*[ ](and|or|but|yet|so)[ ][a-zA-Z]* {c=1;
}
.|[\n];
%%
int yywrap()
{
return 1;
}
int main(){
printf("enter the text\n");
yylex();
if(c)
{
printf("The given statement is compound\n"); }
else
{
printf("The given statement is simple\n"); }
}