#ifndef MALLOC_H_
#define MALLOC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{

  char c;
  struct node* next[26];/*possible chars that  we are storing in this array*/
  int end;     /*boolean int.. need this bc  boo book and booking can be diff words but with same tree pattern*/
  int count;    /*how many times this word appears*/
  int prefix; 
 
}Node;

void tokenizeFile(char* filename, int x);
void store(char* s);
void search(char*s);
Node* create( char c);
void storeLvlHelp(Node* tmp, char c);
#endif
