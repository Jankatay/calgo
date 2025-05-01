#ifndef _CALGO_LLIST
#define _CALGO_LLIST

#include <stdlib.h>

// you can define higher or smaller values
#ifndef _CALGO_DEFAULT_BUFSIZE
#define _CALGO_DEFAULT_BUFSIZE 255
#endif

// automatically make a structure for forward linked list 
#define STRUCT_LIST_FORWARD(name, type, defaultVal) \
	struct calgoFList ## name { \
		struct name* next; \
		type data = defaultVal; \
		int len = 0; \
	}

// cast custom fList to default fList.
#define CALGO_FLIST(fList) (struct calgoFList*)&fList

// automatically make a structure for double linked list
#define STRUCT_LIST_DOUBLE(name, type, defaultVal) \
	struct calgoDList ## name { \
		struct name* next = NULL; \
		struct name* prev = NULL; \
		type data = defaultVal; \
		int len = 0; \
	}
// cast custom dList to default dList.
#define CALGO_DLIST(dList) (struct calgoDList*)dList

// automatically make a structure for forward linked list of array types
#define STRUCT_LIST_FORWARD_ARR(name, type, size) \
	struct calgoFListArr ## name { \
		struct name* next; \
		type data[size]; \
	}

// cast custom fListArr to default fListArr.
#define CALGO_FLIST_ARR(fListArr) (struct calgoFListArr*)fListArr

// automatically make a structure for double linked list of array types
#define STRUCT_LIST_DOUBLE_ARR(name, type, size) \
	struct calgoDListArr ## name { \
		struct calgoDList ## name* next = NULL; \
		struct calgoDList ## name* prev = NULL; \
		type data[size]; \
	}

// cast custom dListArr to default dListArr.
#define CALGO_DLIST_ARR(fDistArr) (struct calgoFDistArr*)fDistArr

// forward linked int for int types
STRUCT_LIST_FORWARD(Int, int, 0);

// forward linked int for int types
STRUCT_LIST_DOUBLE(Int, int, 0);

// forward linked int for arrays of int types
STRUCT_LIST_FORWARD_ARR(ArrInt, int, _CALGO_DEFAULT_BUFSIZE);

// forward linked int for arrays of int types
STRUCT_LIST_DOUBLE_ARR(ArrInt, int, _CALGO_DEFAULT_BUFSIZE);

// forward linked list for double types
STRUCT_LIST_FORWARD(Double, double, 0);

// double linked list for double types
STRUCT_LIST_DOUBLE(Double, double, 0);

// forward linked list for arrays of chars
STRUCT_LIST_FORWARD_ARR(ArrDouble, double, _CALGO_DEFAULT_BUFSIZE);

// forward linked list for array of chars
STRUCT_LIST_DOUBLE_ARR(ArrDouble, double, _CALGO_DEFAULT_BUFSIZE);

// forward linked list for char types
STRUCT_LIST_FORWARD(Char, char, 0);

// double linked list for char types
STRUCT_LIST_DOUBLE(Char, char, 0);

// forward linked list for an array of char types
STRUCT_LIST_FORWARD_ARR(StrArr, char, _CALGO_DEFAULT_BUFSIZE);

// double linked list for an array of char types
STRUCT_LIST_DOUBLE_ARR(StrArr, char, _CALGO_DEFAULT_BUFSIZE);

// forward linked list for char* types
STRUCT_LIST_FORWARD(StrPtr, char*, (char*)NULL);

// double linked list for char* types
STRUCT_LIST_DOUBLE(StrPtr, char*, (char*)NULL);

// forward linked list for voidptr types
STRUCT_LIST_FORWARD(Void, void*, NULL);

// double linked list for voidptr types
STRUCT_LIST_DOUBLE(Void, void*, NULL);

// forward linked list for an array of voidptr types
STRUCT_LIST_FORWARD_ARR(ArrVoid, void*, _CALGO_DEFAULT_BUFSIZE);

// double linked list for an array of voidptr types
STRUCT_LIST_DOUBLE_ARR(ArrVoid, void*, _CALGO_DEFAULT_BUFSIZE);

// default forward linked list of array types
struct calgoFListArr {
	struct calgoFListArr* next = NULL;
	int data = 0;
	int len = 0;
};

// default double linked list of array types
struct calgoDListArr {
	struct calgoDListArr* next = NULL;
	struct calgoDListArr* prev = NULL;
	int data = 0;
	int len = 0;
};

// default double linked list
struct calgoDList {
	struct name* next = NULL;
	struct name* prev = NULL;
	int data = 0;
	int len = 0;
};

// default forward linked list
struct calgoFList {
	struct name* next = NULL;
	int data = 0;
	int len = 0;
};

// returns index of max number in the calgoFList fList.
int calgoFListMax(struct calgoFList* fList);

// returns index of max number in the calgoFList fList using bigger function.
int calgoFListMaxFunc(struct calgoFList* fList, int(*bigger)(void* elemA, void* elemB));

// returns index of min number in the calgoFList fList.
int calgoFListMin(struct calgoFList* fList);

// returns index of min number in the calgoFList fList using smaller function.
int calgoFListMinFunc(struct calgoFList* fList, int(*smaller)(void* elemA, void* elemB));

// get index of max number in the calgoDList dList.
int calgoDListMax(struct calgoDList* dlist);

// returns index of max number in the calgoDList dList using smaller function.
int calgoDListMaxFunc(struct calgoFList* dList, int(*bigger)(void* elemA, void* elemB));

// get index of min number in the calgoDList dList.
int calgoDListMin(struct calgoDList* dlist);

// returns index of min number in the calgoDList dList using smaller function.
int calgoDListMinFunc(struct calgoFList* dList, int(*smaller)(void* elemA, void* elemB));

#endif
