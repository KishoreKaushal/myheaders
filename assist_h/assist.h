/*                              */
/*    @kaushal_kishore          */
/* mailTo: kshr4kshl@gmail.com  */
/*                              */
#include<stdio.h>

#ifndef ASSIST_H
#define ASSIST_H

#define FAILED 0
#define SUCCESS 1

#define COLOR_RESET "\033[0m"       /* SWITCH BACK TO DEFAULT SETTINGS */

/* REGULAR COLORS */
#define BLACK  "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

/* BOLD COLOR */

#define B_BLACK "\033[1;30m"
#define B_RED "\033[1;31m"
#define B_GREEN "\033[1;32m"
#define B_YELLOW "\033[1;33m"
#define B_BLUE "\033[1;34m"
#define B_PURPLE "\033[1;35m"
#define B_CYAN "\033[1;36m"
#define B_WHITE "\033[1;37m"

/* UNDERLINED TEXT */
#define U_BLACK "\033[4;30m"
#define U_RED "\033[4;31m"
#define U_GREEN "\033[4;32m"
#define U_YELLOW "\033[4;33m"
#define U_BLUE "\033[4;34m"
#define U_PURPLE "\033[4;35m"
#define U_CYAN "\033[4;36m"
#define U_WHITE "\033[4;37m"
/*
                            +------------------------------------------+
x---------------------------+          X                               |
+  X     X                            XXXX                             +----+
|  X    XX       XXX                 X   XX             XXXXXXXXX    X      |
|  X    X      XXX XXXXX            XX                  X        XX  XX     |
|  X   XX     XX     X XX           XX          X    X  X XXXXX   X  XX     |
|  X  XX      X  XXXXX   X  X        XXXXXXXX   X    X XX X   X   X  XX     |
|  X XXX      X  X   X   X  X    X          XX  X    X X  XX  X   X  XX     |
|  XXX XX     X  X   X   X  X    XX          X  XXXXXX X   XXXXXXXX  XX     |
|  XX   XX    X  XXXXXX  X  X    XX          X  X    X XX            XX     |
|  X     XX   XXX     XXX   X    XX   XXXXXXXX  X    X  XXXXXXXX     XX     |
|  X      X     XXXXXXX     X    XX      XXX    X    X               XXXX   |
|  X      XX                XX   XX             X    XX             XX  XX  |
|  X       X                 XXXXXX             X     X                  XX |
|  X       X                      XXXX                                      |
|          XX     +-------------------------------------------------->      |
|           XXXXX                                                           |
+---------------------------------------->  +----> +------------------------>

*/

/* --------------- COLOR FUNCTIONS ---------------- */

void switchColor(const char *colorVal) ;                /* Switch the color for the subsequent text */
void print(const char *colorVal , const char *text);    /* print any text in the color specified */
void error(const char *text) ;                          /* Prints an error message on the output screen */
void warning(const char *text) ;                        /* Prints a warning on the output screen */
void getRawVal(const char *text) ;                      /* Get raw val of the escape sequence we are
                                                        using for a particular color */

/* --------------- OTHER FUNCTIONS ---------------- */


#define NAME_LENGTH (2)
#define INITIAL_LINE_LENGTH (2)
#define safeFree(p) saferFree((void**)&(p))

char *getLine(void);                                    /* return a freshly malloc'd line with
                                                        next line of  input from stdin */
void free2d(void **twoDarray);                          /* free a 2D-aray */
void** malloc2d(size_t numRows, size_t rowSize);        /* create a 2D-array */
int *readNumbers(int *count /* RETVAL */);              /* read Numbers from stdin and return a
                                                        pointer to the array*/
void saferFree(void **p);                               /* Free the memory safely */


/* ------------- DATA STRUCTURES ----------------- */

typedef void (*DISPLAY)(void*);         /* DISPLAY: type cast a function to void(*)(void*) */
typedef int (*COMPARE)(void* , void*);  /* COMPARE: type cast a function to int(*)(void*, void*) */

/* ---------- SINGLY LINKED LIST -------------------*/


typedef struct _NODE_{
    void *data;
    struct _NODE_ *next;
} _NODE_;

typedef struct _SINGLY_LINKED_LIST_{
    _NODE_ *head;
    _NODE_ *tail;
    _NODE_ *current;
} _LINKED_LIST_;

void initializeList(_LINKED_LIST_*);                /* Initializes the linked list */
int addHead(_LINKED_LIST_*, void*);                 /* Adds data to the linked lists's head */
int addTail(_LINKED_LIST_*, void*);                 /* Adds data to the linked list's tail */
void removeNode(_LINKED_LIST_*, _NODE_*);               /* Removes a node from the linked list */
_NODE_ *getNode(const _LINKED_LIST_*, COMPARE , void*);   /* Returns a pointer to the node containing a specific data item */
void displayLinkedList(const _LINKED_LIST_*, DISPLAY);    /* Displays the linked list */
int listEmpty(const _LINKED_LIST_*); /*Returns 1 if list is empty */

/* --------------------- STACK --------------------- */

typedef _LINKED_LIST_  _STACK_ ;

void initializeStack(_STACK_ *) ;               /* Initializes Stack */
void *pop(_STACK_ *);                           /* Pops an element out of the stack from the head */
int push(_STACK_ *, void *);                    /* Pushes an element on the head of the stack */
void displayStack(_STACK_ *, DISPLAY );         /* Displays the whole stack from head to tail */
void destroyStack(_STACK_ *);                   /* Silently destroy the whole stack */
int stackEmpty(const _STACK_ *);                /* returns 1 if stack is empty */

/* ------------------- QUEUE ------------------------ */

typedef _LINKED_LIST_   _QUEUE_ ;

void initializeQueue(_QUEUE_ *);                /* Initializes Queue*/
int enqueue(_QUEUE_ *, void *);                 /* Adds an element in the queue(FIFO) */
void *dequeue(_QUEUE_ *);                       /* Removes an element from the queue at tail position*/
void displayQueue(_QUEUE_ *, DISPLAY  );        /* Displays the whole queue */
void destroyQueue(_QUEUE_ *);                   /* Destroy the whole queue */
int queueEmpty(const _QUEUE_ *);                /* returns 1 if the queue is empty. */

/* ---------------- DOUBLY LINKED LIST ------------------ */

typedef struct _DNODE_{
    void *data;
    struct _DNODE_ *next;
    struct _DNODE_ *prev;
} _DNODE_;

typedef struct _DOUBLY_LINKED_LIST_{
    _DNODE_ *head;
    _DNODE_ *tail;
    _DNODE_ *current;
} _DLINKED_LIST_;


void initializeDList(_DLINKED_LIST_*);                /* Initializes the doubly linked list */
int addDHead(_DLINKED_LIST_*, void*);                 /* Adds data to the doubly linked lists's head */
int addDTail(_DLINKED_LIST_*, void*);                 /* Adds data to the doubly linked list's tail */
void removeDNode(_DLINKED_LIST_*, _DNODE_*);               /* Removes a node from the doubly linked list */
_DNODE_ *getDNode(const _DLINKED_LIST_*, COMPARE , void*);   /* Returns a pointer to the node containing a specific data item */
void displayDLinkedList(const _DLINKED_LIST_*, DISPLAY);    /* Displays the doubly linked list */
int DlistEmpty(const _DLINKED_LIST_*);



/* ---------------- ----------------------- */
#endif // ASSIST_H
