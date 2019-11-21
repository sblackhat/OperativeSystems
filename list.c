#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "list.h"



int createList(ArrayList * L ){
	*L = (ArrayList) malloc (SIZE * sizeof(ArrayList));
	if (L != NULL){
	(*L)->lastpos = 0;
	return 1;
	}
	else{
	 perror("Impossible to allocate memory while creating the list.");
	return 0;}
}

int next(ArrayList L,int pos){
	if (pos < L -> lastpos){
		return pos++;
	}
	return -1;
}

int previous(ArrayList L,int pos){
	if ((pos < L -> lastpos) && (pos > 0)){
		return pos-1;
	}return -1;
}

int lastPos(ArrayList L){
	return L->lastpos;
}


int insertItem(ArrayList L,unsigned char memAddress,unsigned int size, char * allocTime, tAlloc typeOfAllocation,
			    unsigned int fileDescriptor,unsigned int key){
	/* We always insert in the last position as the list has to follow a 
	FIFO behaviour when printing */
	int a = L-> lastpos;
	if (a < SIZE){
		L -> nodes[a].memAddress = memAddress;
		L -> nodes[a].size = size;
		L -> nodes[a].typeOfAllocation = typeOfAllocation;
		strcpy(L->nodes[a].allocTime,allocTime);
		L -> nodes[a].fileDescriptor = fileDescriptor;
		L -> nodes[a].key = key;
		L -> lastpos++; 
		return 1;
	}
	else {
		perror("The list if full.\n");
        return 0;
	}
}

void deleteList(ArrayList * L){
	free(L);
	L = NULL;
}

char * solveTypeOfAlloc(int a){
	switch (a){
		case 0 : return "malloc";
		case 1 : return "mmap";
		case 2 : return "shared memory";
		default : return "unknown type";
	}
}

void printSimple(ArrayList L){
	char * tAlloc;
	tNode actualNode;
	for (int i = 0; i < L-> lastpos; ++i)
	{   actualNode = L->nodes[i];
		tAlloc = solveTypeOfAlloc(actualNode.typeOfAllocation);
		printf("0x%18d: size:%d %s %s\n", L->nodes[i].memAddress,L->nodes[i].size
								, tAlloc,L->nodes[i].allocTime);
	}
}

void printMalloc(ArrayList L){
	tNode actualNode;
	for (int i = 0; i < L-> lastpos; ++i)
	{   actualNode = L->nodes[i];
		if (actualNode.typeOfAllocation == 0){
		printf("0x%18d: size:%d %s %s \n", actualNode.memAddress,actualNode.size
								, "malloc",actualNode.allocTime);
		}
	}
}

void printMmap(ArrayList L){
	tNode actualNode;
	for (int i = 0; i < L-> lastpos; ++i)
	{   actualNode = L->nodes[i];
		if (actualNode.typeOfAllocation == 1){
		printf("0x%18d: size:%d %s %s %d %s\n", actualNode.memAddress,actualNode.size
								, "mmap",actualNode.fileName,actualNode.fileDescriptor,actualNode.allocTime);
		}
	}
}

