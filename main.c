#include<stdio.h>
#include "compiler.h"
#include "helpers/vector.h"

void minMax(int arr[],int len,int *min,int *max){


*min=*max=arr[0];

for(int i=0;i<len;i++){
  if(*min>arr[i]){
    *min=arr[i];
    continue;
  }
  if(*max<arr[i]){
    *max=arr[i];
    continue;
  }
}



}
int main(){

int res=compile_file("./inputfile.c","./inputfile",0);

if(res==COMPILER_FILE_COMPLETED_OK){
  printf("Compiled Success!!!\n");
}else if(res==COMPILER_FAILED_WITH_ERRORS){
  printf("error lmao \n");
}else{
  printf("no medicine for your dumbness \n");
}
// struct vector* vec=vector_create(sizeof(int));
// int x=50;
// vector_push(vec,&x);
// x=20;
// vector_push(vec,&x);
// vector_set_peek_pointer(vec,0);
// int* ptr=vector_peek(vec);
// while(ptr){

//   printf("%i\n",*ptr);
//   ptr=vector_peek(vec);
// }


int array[]={23,1,2,4,2,35,5,7,8,44,2,3,23,18,-100,-1};

int min,max;
int len=sizeof(array)/sizeof(array[0]);
  
  minMax(array,len,&min,&max);

printf("min is %d and max is %d ",min,max);


return 0;
}
