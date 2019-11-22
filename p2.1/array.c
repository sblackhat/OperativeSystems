#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 4096



typedef struct tStruct{ char * command; }tElements;

typedef struct 
{
    tElements nodes[SIZE-1];
    int lastpos;
}tListH;

 typedef tListH * HistList; //now the HistList is the structure 'DATA'
                                 //L is a pointer to a 'HistList' data type

    /*check this, there must be an error in the data type because while compiling,
      it says that i´m not using the pointer*/
   
int createListH(HistList *L){
    *L = (HistList) malloc (SIZE*sizeof(HistList));
    if ( L != NULL){
    (*L)->lastpos = 0;
    return 1;
    }
    else{
     perror("Impossible to allocate memory while creating the list.");
    return 0;}
}   

int lastPosLH (HistList L){
    return (L -> lastpos);
}

int insertItemH(HistList L, char * input){
    /* We always insert in the last position as the list has to follow a 
    FIFO behaviour when printing */
    int a = lastPosLH(L);
    if (a < SIZE){
        strcpy(L -> nodes[a].command, input);
        return 1;
    }
    else {
        perror("The list if full.\n");
        return 0;
    }
}

void deleteListH(HistList * L){
    free(L);
    L = NULL;
}

void printHistList (HistList L){
    int a = 0;
    a = lastPosLH (L);
    if ( a != 0 ) {
        for (int i = 0; i < a; i++){
            printf("%s\n", L->nodes[i].command);
        }
    }
    return;
}
