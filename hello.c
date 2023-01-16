#include<stdlib.h> 
#include<stdio.h>

int main(){

  char *str=malloc(4);
  str[0]='h';
  str[1]='e';
  str[2]='y';
  str[3]='\n';
 

  printf("%s",str);
  free(str);

}