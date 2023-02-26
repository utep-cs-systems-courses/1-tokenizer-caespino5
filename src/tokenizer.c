#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
   char c;
   if(c=='\t' || c== " "){
    return 1;
   }else{
       return 0;
   }
   }
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
    if(c=='\t'||c==" " && c!=0){
        return 1;
    }
    return 0;
}
/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
    for(int i; *(str+i) != '\0'; i++){
        if(non_space_char(*(str+i)))
        return str+i;
    }
}
/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
    for(int i =0; *(token+i); i++){
        if(space_char(*(token+i)))
        return token+i;
    }
}
/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
    int counter = 0;
    char *s = token_start(str);
        while(*s!='\0'){
            if(non_space_char(*s)){
                counter +=1;
            }
            s = token_terminator(s);
            s = token_start(s);
        }
    return counter;
}
/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
    int i;
    char *stringcopy = malloc((len+1)*sizeof(char));
    for(int i=0; i< len; i++){
        stringcopy[i] = inStr[i];
    }
    stringcopy[i] = '\0';
    return stringcopy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
    int num = 1;
    int numstoken = count_tokens(str);
    char **token = malloc((numstoken+num)*sizeof(char *));
    char *s = str;
    for(int i = 0; i<numstoken; i++){
        s = token_start(s);
        int leng = token_length(s);
        token[i] = copy_str(s,leng);
        s = token_terminator;
    }
    return token;
}
/* Prints all tokens. */
void print_tokens(char **tokens){
    for(int i =0; tokens[i]!=0;i++){
        printf("%s\n",tokens[i]);
    }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
    for(int i=0;tokens[i]!=0;i++){
        free(tokens[i]);
    }
}
    
int token_length(char *str)
{
  int length = 0;
  for (int i = 0; *(str+i) != '\0'; i++) { 
    if (non_space_char(*(str+i))) {
      length += 1; 
    }
    else {
      break; 
    }
  }
  return length;
}
#endif