#ifndef PEACHCOMPILER_H
#define PEACHCOMPILER_H
#include<stdio.h>
#include<stdbool.h>


struct pos{
  int line;
  int col;
  const char* filename;

};
struct lex_process;

typedef char (*LEX_PROCESS_NEXT_CHAR)(struct lex_process* process);

struct lex_process_functions{

   
};

struct lex_process{
  struct pos pos;
  struct vector* token;
  struct compile_process* compiler;

  int current_expression_count;

  struct buffer* parentheses_buffer;

  struct lex_process_functions* function;

  // This will be private data that the lexer doesn't understand
  // but the person using the lexer understand
  void* private;
};

enum{

    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_SYMBOL,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_COMMENT,
    TOKEN_TYPE_STRING,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_NEWLINE,
};

struct token{
    int type;
    int flags;

    union{
      char cval;
      const char* sval;
      unsigned int inum;
      unsigned long lnum;
      unsigned long long llnum;
      void* any;

    };

    // true if there is whitesapce between the token and the next token
    // * a => * fro toekn a

    bool whitespace;

    const char* between_brackets;
};

enum{
  COMPILER_FAILED_WITH_ERRORS,
  COMPILER_FILE_COMPLETED_OK,

};
struct compile_process
{
  //flags regards how the file should compiled
  int flags;
  
  struct compile_process_input_file{
    FILE* fp;
    const char* abs_path;
  } cfile;

  FILE* ofile;
};

int compile_file(const char* filename,const char* out_filename,int flags);
struct compile_process* compile_process_create(const char* filename,const char* filename_out,int flags);
#endif