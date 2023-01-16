#include<stdio.h>
#include<stdlib.h>
#include "compiler.h"
struct compile_process* compile_process_create(const char *filename,const char *filename_out,int flags)
{
  FILE *file=fopen(filename,"r");
  if(!file){
    return NULL;

  }
FILE *outfile=NULL;
if(filename_out){
outfile=fopen(filename_out,"w");
  if(!outfile){
    return NULL;
  }
}

    struct compile_process* process=calloc(1,sizeof(struct compile_process));
    process->flags=flags;
    process->cfile.fp=file;
    process->ofile=outfile;
    return process;
}
