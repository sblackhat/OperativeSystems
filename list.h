/* 
	Autores: Sergio Valle Trillo / Adrian Haz Garcia
	Logins : s.valle 			/ adrian.haz
	DNI	   : 54159644A
*/

#define SIZE 4096

typedef enum typeOfAllocationE {Malloc,Shared,Mapped}tAlloc;

typedef struct tNode{
	//Common atributtes
	unsigned char memAddress;
	unsigned int size;
	char * allocTime;
	tAlloc typeOfAllocation;
	//Mmap
	unsigned int fileDecriptor;
	//Shared key_t key ?
	unsigned int key;
}tNode;

typedef struct 
{
	tNode nodes[SIZE-1];
	unsigned int lastpos;
}tList;

 typedef tList * ArrayList;

int createList(ArrayList * L );
int next(ArrayList L,int pos);
int previous(ArrayList L,int pos);
int lastPos(ArrayList L);
int insertItem(ArrayList L,unsigned char memAddress,unsigned int size,
			   char * allocTime, tAlloc typeOfAllocation,
			   unsigned int fileDecriptor,unsigned int key);
void deleteList(ArrayList * L);