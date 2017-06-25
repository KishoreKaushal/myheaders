/*                              */
/*    @kaushal_kishore          */
/* mailTo: kshr4kshl@gmail.com  */
/*                              */
#include<stdio.h>

#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#define FAILED 0
#define SUCCESS 1


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
void freeList(_LINKED_LIST_*); /* Free the allocated linked list from the memory.*/


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
void freeDList(_DLINKED_LIST_ *); /*Free the allocated doubly linked list from the memory*/

#endif // DATASTRUCTURES_H
