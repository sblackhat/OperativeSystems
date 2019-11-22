/* 
	Autores: Sergio Valle Trillo / Adrian Haz Garcia
	Logins : s.valle 			/ adrian.haz
	DNI	   : 54159644A
*/

#define SIZE 4096



typedef struct tNode{
	//Common atributtes
	void * memAddress;
	unsigned int size;
	char * allocTime;
	char * typeOfAllocation;
	//Mmap
	char * fileName;
	unsigned int fileDecriptor;
	//Shared key_t key ?
	unsigned int key;
}tNode;

typedef struct 
{
	tNode nodes[SIZE-1];
	int lastpos;
}tList;

 typedef tList * ArrayList;

int createList(ArrayList *L);
int next(ArrayList L,int pos);
int previous(ArrayList L,int pos);
int lastPos(ArrayList L);
int insertItem(ArrayList L,void * memAddress,unsigned int size, char * allocTime, char * typeOfAllocation,
			    unsigned int fileDecriptor, char * filename, unsigned int key);
void deleteList(ArrayList * L);
void printList (ArrayList L, char * filter);
int findAddress (ArrayList L, void * add);
int deleteElement (ArrayList L,unsigned int size, char * file, unsigned int key, char * filter);