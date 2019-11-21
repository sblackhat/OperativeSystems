#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIMENSION 4096

/*array: Elements in the list are stored in a statically allocated
array of nodes, so the list type is a pointer to a structure containing
the array of nodes and optionally one or more integers (depending
on the implementation: nextin and nextout indexes, counter . . . ).
For the purpose of this lab assigment, we can assume the array
dimension to be 4096 (which should be declared a named constant,
and thus easily modiable).*/

    //so, it´s a structure that contain the array of all the elements, and some other values
    //then, the list type is a type which points to that structure.

    //typedef helps us to rename the data types, so we´ll use it to create a 'tListh' data type
    
    struct NODE 
    { const char * line;
    };
    struct DATA
    {
        struct NODE elements[DIMENSION];
        int lastPosLH;
    } ;
    
    typedef struct DATA * tListh; //now the tListh is the structure 'DATA'
                                 //L is a pointer to a 'tListh' data type

    /*check this, there must be an error in the data type because while compiling,
      it says that i´m not using the pointer*/
   
void createListH (tListh * L){
   *L=(tListh) malloc (DIMENSION * sizeof (tList));
    if ( L != NULL){
    
    (*L) -> lastPos = 0;
    
    return 1;
    }
    else {
        perror("Impossible to allocate memory while creating the list.");
        return 0;
    }
}   

int lastPosLH (tListh L){
    int i = 0;
    i = (L -> lastPosLH);
    return i;
}

int insertItemH (tListh *L, char * input){    //i think that this fails
    int a = lastPosLH (*L);
    
    if (a < DIMENSION){
        
        strcpy ((*L) -> elements[a].line, input);
        (*L) -> lastPosLH = a + 1; 
        
        return 1;
    }
    else{
        perror("The list if full.\n");
        return 0;
    }
}

void deleteListH (tListh *L){
    (*L) -> lastPosLH = 0;
    free(*L);     //memset(*s, int cnt, int size) sets the array pointed by s, to the position size, the constant cnt
    createListH (L);
    
    return ;
}

void printListH (tListh L){
    int a = 0;
    a = lastPosLH (L);
    if ( a != 0 ) {
        for (int i = 0; i <= a; i++){
            printf("%s\n", L->elements[i].line);
        }
    }
    return;
}
