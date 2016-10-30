#include "first.h"

void print(Node* tmp,char* word, int pc, FILE* op, int len);
void prefSearch(Node* tmp);

Node* root[26];

void freeNode(Node* tmp){
  int x;
  
  for(x = 0; x < 26; x++){
    
    if(tmp->next[x] != NULL){
      freeNode(tmp->next[x]);
    }
  }  

  free(tmp);

}

void freetrie(){
  int x;

  for(x = 0; x < 26; x++){
    if(root[x] != NULL){
    freeNode(root[x]);
    }
    root[x] = NULL;
  }

  return;
}

int main(int argc, char** argv){
  
  FILE* mpf = fopen(argv[1],"r");         /*mapfile ptr to read dict and data file names*/
  char dict[10];
  char data[10];
  int out = 1;
  FILE* op;  

  while(!feof(mpf)){    
    fscanf(mpf, "%s %s\n", dict, data);
    tokenizeFile(dict,out);
    out++;
    tokenizeFile(data,out);
    out--;

    char tok[100];
  int z;
  char c;
  int pc = 0;
  char num[3];

  num[0] = dict[5];
  if(dict[6] != '\0'){
    num[1] = dict[6];
    num[2] = '\0';
  }else{
    num[1] = '\0';
  }

  char file[10] = "out";
  
  strcat(file,num);
  strcat(file,".txt");

  op = fopen(file, "w");

  for(z =0; z < 26; z++){
    if(root[z] != NULL){
      c = z + 'a';
      tok[0] = c;
      tok[1] = '\0';
      print(root[z],tok,pc,op,1);
    }
    pc = 0;
    
  }
  fclose(op); 
  freetrie();
  }
  fclose(mpf);
  return 0;
}

void print(Node* tmp,char* word,int pc, FILE* op, int len){
  int x ;
   
  if( tmp->end == 1){
    
    fprintf(op,"%s %d %d\n", word, tmp->count, tmp->prefix);
  }

  char* t = word;
  for(x = 0; x < 26; x++){
    t = word;
    if(tmp->next[x] != NULL){
      t[len] = tmp->next[x]->c;
      len++;
      t[len] = '\0';
      print(tmp->next[x], t,pc,op,len);
      len--;
      t[len] = '\0';
    }
  }
}

Node* nNode(char c){
  Node* newnode = (Node*)malloc(sizeof(Node));
  newnode->c = c;
  newnode->end = 0;
  newnode->count = 0;
  newnode->prefix = 0;
  int x;  
  for(x = 0; x < 26; x++){
    newnode->next[x] = NULL;
  }
  return newnode;
}

void store(char* word){

  int count = 0;
  char c = word[count];
  int x = c - 'a';
  Node* tmp;

  if(root[x] == NULL){
    Node* newnode = nNode(word[count]);
    root[x] = newnode;
    tmp = root[x];
    count++;
  }else{
    tmp = root[x];
    count++;
  }

  while( word[count] != '\0'){

    c = word[count];
    x = c - 'a';


    if(tmp->next[x] == NULL){
      Node* newnode = nNode(word[count]);
      tmp->next[x] = newnode;
      tmp = tmp->next[x];
    }else{
      tmp = tmp->next[x];
      
    }
    count++;
  }
  tmp->end = 1;
}

void tokenizeFile (char* filepath, int out) {
  
    FILE* fp;
    fp = fopen(filepath, "r");
    if (fp == NULL) {
        return;
    }
    char ch = '\0';
    char* entirefile = (char*) malloc (sizeof(char) * 3000);
    int currlength = 3000;
    int numofchars = 0;
    int index = 0;
    for (index = 0; index < 3000; index++) {
        entirefile[index] = '\0';
    }
    index = 0;
    ch = fgetc(fp);
    
    while ( ch != EOF ) {
        if (numofchars == (currlength - 1)) {
            entirefile = (char*) realloc ( entirefile, (sizeof(char)*(2*currlength)) );
            currlength = 2*currlength;
            int temp = index;
            int y = temp;
            for (temp = y; temp < currlength; temp++) {
                entirefile[temp] = '\0';
            }
        }
        numofchars++;
        entirefile[index] = tolower(ch);
        index++;
        ch = fgetc(fp);
    }
    
    index = 0;
    int size = 0;
    for (index = 0; index < currlength; index++) {
        if (entirefile[index] == '\0') {
            break;
        }
        size++;
    }
    
    entirefile = (char*) realloc ( entirefile, (sizeof(char) * (size+1)) );
    
    index = 0;
    int currpos = 0;
    ch = entirefile[index];
    
    while (ch != '\0') {
        if (isalpha(ch)) {
            currpos = index;
            int wordsize = 0;
            while (isalpha(ch)) {
                wordsize++;
                index++;
                ch = entirefile[index];
            }
            char* wordtosend = (char*) malloc ( sizeof(char) * (wordsize+1) );
            int k = 0;
            for (k = 0; k < wordsize+1; k++) {
                wordtosend[k] = '\0';
            }
            k = 0;
            int x = currpos;
            for (currpos = x; currpos < index; currpos++) {
                wordtosend[k] = entirefile[currpos];
                k++;
            }
           
	    if( out == 1){
	      store(wordtosend);
	    }else{
	      search(wordtosend);
	    }

        } else {
            index++;
            ch = entirefile[index];
        }
    }
    free(entirefile);
    fclose(fp);
    return;
}


void search(char* s){

  int y = 0;
  char c;
  int count = 0;
  Node* tmp;

  c = s[count];

  y = c - 'a';
  tmp = root[y];

  if(tmp == NULL){
    return;
  }

  count++;

  while(s[count] != '\0'){
    c = s[count];

    y = c- 'a';

    if(tmp->end == 1){
      tmp->prefix++;
    }

    if(tmp->next[y] != NULL){
      tmp = tmp->next[y];
    }else{
      return;
    }
    count++;
  } 

  if(tmp->end == 1){
    tmp->count++;
  }
  

}



