#ifndef _CALGO_LLIST
#define _CALGO_LLIST

#include <stdlib.h>

// automatically make a structure for forward linked list 
#define STRUCT_LIST_FORWARD(name, type, defaultVal) \
	struct calgoFList ## name { \
		struct name* next; \
		type data = defaultVal; \
		int len = 0; \
	}

// automatically make a structure for double linked list
#define STRUCT_LIST_DOUBLE(name, type, defaultVal) \
	struct calgoDList ## name { \
		struct name* next = NULL; \
		struct name* prev = NULL; \
		type data = defaultVal; \
		int len = 0; \
	}

// automatically make a structure for forward linked list of array types
#define STRUCT_LIST_FORWARD_ARR(name, type) \
	struct calgoFListArr ## name { \
		struct name* next; \
		type* data = (type*)NULL; \
	}

// automatically make a structure for double linked list of array types
#define STRUCT_LIST_DOUBLE_ARR(name, type) \
	struct calgoDListArr ## name { \
		struct calgoDList ## name* next = NULL; \
		struct calgoDList ## name* prev = NULL; \
		type* data = (type*)NULL; \
	}

// forward linked list for int types
STRUCT_LIST_FORWARD(Int, int, 0);

// double linked list for int types
STRUCT_LIST_DOUBLE(Int, int, 0);

// forward linked list for arrays of int types
STRUCT_LIST_FORWARD_ARR(Int, int);

// forward linked list for arrays of int types
STRUCT_LIST_DOUBLE_ARR(Int, int);

// forward linked list for double types
STRUCT_LIST_FORWARD(Double, double, 0);

// double linked list for double types
STRUCT_LIST_DOUBLE(Double, double, 0);

// forward linked list for arrays of chars
STRUCT_LIST_FORWARD_ARR(Double, double);

// forward linked list for array of chars
STRUCT_LIST_DOUBLE_ARR(Double, double);

// forward linked list for char types
STRUCT_LIST_FORWARD(Char, char, 0);

// double linked list for char types
STRUCT_LIST_DOUBLE(Char, char, 0);

// forward linked list for an array of char types
STRUCT_LIST_FORWARD_ARR(Str, char);

// double linked list for an array of char types
STRUCT_LIST_DOUBLE_ARR(Str, char);

// forward linked list for char* types
STRUCT_LIST_FORWARD(StrPtr, char*, (char*)NULL);

// double linked list for char* types
STRUCT_LIST_DOUBLE(StrPtr, char*, (char*)NULL);

// forward linked list for voidptr types
STRUCT_LIST_FORWARD(Void, void*, NULL);

// double linked list for voidptr types
STRUCT_LIST_DOUBLE(Void, void*, NULL);

// forward linked list for an array of voidptr types
STRUCT_LIST_FORWARD_ARR(Void, void*);

// double linked list for an array of voidptr types
STRUCT_LIST_DOUBLE_ARR(Void, void*);

// default forward linked list of array types
struct calgoFListArr {
	struct calgoFListArr* next = NULL;
	int* data = (int*)NULL;
	int len = 0;
};

// default double linked list of array types
struct calgoDListArr {
	struct calgoDListArr* next = NULL;
	struct calgoDListArr* prev = NULL;
	int* data = (int*)NULL;
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

// forward list of int type (default)
struct calgoFList;

// double list of int type (default)
struct calgoDList;

// returns index of max number in the calgoFList fList.
int calgoFListMax(struct calgoFList* fList);

// returns index of min number in the calgoFList fList.
int calgoFListMin(struct calgoFList* fList);

// get index of max number in the calgoDList dList.
int calgoDListMax(struct calgoDList* dlist);

// get index of min number in the calgoDList dList.
int calgoDListMin(struct calgoDList* dlist);

#ifndef DEV_MODE
	#undef STRUCT_LIST_DOUBLE
	#undef STRUCT_LIST_FORWARD
	#undef STRUCT_LIST_FORWARD_ARR
	#undef STRUCT_LIST_DOUBLE_ARR
#endif 

#endif
