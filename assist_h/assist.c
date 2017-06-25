/*                              */
/*    @kaushal_kishore          */
/* mailTo: kshr4kshl@gmail.com  */
/*                              */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "assist.h"

void resetColor(void) {
    printf(COLOR_RESET);
}

void switchColor(const char *colorVal) {
    printf(colorVal);
}

void print(const char * colorVal , const char * text) {
    printf("%s%s\n",colorVal, text );
    resetColor();
}

void error(const char * text) {
    printf("%sERROR: ", B_RED  );
    switchColor(B_CYAN);
    printf("%s\n", text );
    resetColor();
}


void warning(const char *text) {
    printf("%sWARNING: ", B_BLUE );
    switchColor(B_CYAN);
    printf("%s\n", text );
    resetColor();
}
/*
void getRawVal(const char *text) {
-----Need to complete-----
}
*/

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


/* OTHER FUNCTIONS */

char *getLine(void){
    char *line;
    int size;   /* how much space do I have in the line? */
    int length; /* how many characters have i used ?*/
    int c;
    size = INITIAL_LINE_LENGTH;
    line = malloc(size);
    if(line == 0) {
        /* malloc failed */
        error("getLine() : failed to allocate memory for the input.");
        return 0;
    }
    length = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        /* code */
        if(length >= size-1){
            /* need more space */
            size*=2;
            /* make length equal to new size*/
            /* copy contents if necessary */
            line = realloc(line , size);
        }
        line[length++] = c;
    }
    line[length] = '\0';
    return line;
}


/* free2d: frees a 2D array created by malloc2d */
void free2d(void **a){
    void **row;
    /*first free rows */
    for (row = a; *row !=0 ; row++){
        free(*row);
    }
    free(a);
}

/* malloc2d :
returns a two-dimensional array with numRows rows and
rowSize bytes per row, or 0 on allocation failure.
The caller is responsible for freeing the result with free2d.
Note: it returns a void** pointer on sucessfull allocation therefore one to typecast it explicitly for further usage.
*/

void **malloc2d(size_t numRows , size_t rowSize){
    void **a;
    size_t i;
    a = malloc(sizeof(void *) * (numRows+1));   /* one extra for sentinel */
    if (a==0){
        /* malloc failed */
        error("malloc2d(size_t numRows , size_t rowSize) : failed to allocate memory for the input.");
        return 0;
    }

    /* now allocate the actual rows */
    for (i=0; i<numRows ; ++i){
        a[i] = malloc(rowSize);
        if(a[i]==0){
            free2d(a);
            return 0;
        }
    }
    /* intialize the sentinel value */
    a[numRows] = 0;
    return a;
}

/* Read numbers from the terminal until an other type of data is entered */
/* I need to generalize this so as to handle any othe type of numbers, eg., float , long , etc. */
/* You need to supply an address of the variable which will count the the numbers of integer read. */
/* Return data will be a dynamically allocated array. You must free the data using saferFree() or free. */
int *readNumbers(int *count /* RETVAL */){
    int mycount=0;    /* number of numbers read */
    int size=1;       /* size of block allocated so far */
    int *a;         /* block */
    int n;          /* number read */

    a = malloc(sizeof(int)*size);   /* allocating zero bytes is tricky */
    if( a == 0 ) return 0;

    while(scanf("%d", &n) == 1){
        /* Do we have empty space? */
        while (mycount >= size) {
            size*=2 ;
            a = realloc(a, sizeof(int) * size);
            if(a==0) return 0;
        }

        /* put the new number in */
        a[mycount++] = n;
        printf("%d %d\n", a[mycount-1] , n );
    }
    /* trim off any excess space */
    printf("%s\n", "OK1");
    a = realloc(a, sizeof(int) * mycount);
    /* note: if a == 0 at this point we'll just return it anyway */
    /* save out to mycount */
    *count = mycount;
    *count++;
    return a;
}

/* Usage: safeFree(ptr); I have not misspelt the word safeFree. Its define as follows:
#define safeFree(p) saferFree((void**)&(p))
which eliminates the task of explicitly type casting the pointer to void**.
Happy Programming!..
 */

void saferFree(void **pp) {
    if (pp != NULL && *pp != NULL) {
        free(*pp);
        *pp = NULL;
    }
}

/* ----------------- DATA STRUCTURES ---------------- */

/* ---------- SINGLY LINKED LIST -------------------*/

void initializeList(_LINKED_LIST_ *list){
    list->head = NULL;
    list->current = NULL;
    list->tail = NULL;
}

int addHead(_LINKED_LIST_* list, void* data){
    _NODE_ *node = (_NODE_*)malloc(sizeof(_NODE_));
    if(node == NULL) return 0;
    node->data = data;
    if(list->head == NULL){
        list->tail = node;
        node->next = NULL;
    } else {
        node->next = list->head;
    }
    list->head = node;
    return 1;
}

int addTail(_LINKED_LIST_* list, void* data){
    _NODE_ *node = (_NODE_*)malloc(sizeof(_NODE_));
    if(node == NULL) return 0;
    node->data = data;
    node->next = NULL;
    if(list->head == NULL ){
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    return 1;
}


_NODE_ *getNode(const _LINKED_LIST_ *list, COMPARE compare, void *data){
    _NODE_ *node = list->head;
    while(node != NULL ){
        if(compare(node->data, data) == 0){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void displayLinkedList(const _LINKED_LIST_ *list , DISPLAY display){
    //printf("Linked List\n");
    _NODE_ *current = list->head;
    while(current != NULL){
        display(current->data);
        current = current->next;
    }
}


void removeNode(_LINKED_LIST_ *list, _NODE_ *node) {
    if (node == list->head) {
        if (list->head->next == NULL) {
            list->head = list->tail = NULL;
        } else {
            list->head = list->head->next;
        }
    } else {
        _NODE_ *tmp = list->head;
        while (tmp != NULL && tmp->next != node) {
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            tmp->next = node->next;
        }
    }
    free(node);
}

int listEmpty(const _LINKED_LIST_ *list) {
    return (list->head == NULL);
}

void freeList(_LINKED_LIST_ *list) {
    while(!listEmpty(list)){
        removeNode(list, list->head);
    }
}

/* --------------------- STACK --------------------- */

int stackEmpty(const _STACK_ *stack) {
    return (stack->head == NULL);
}

void initializeStack(_STACK_ *stack ) {
    stack->head = NULL;
    stack->current = NULL;
    stack->tail = NULL;
}


void *pop(_STACK_ *stack) {
    _NODE_ *node = stack->head;
    if(node == NULL ){
        return NULL;
    } else if (node == stack->tail ) {
        stack->head = stack->tail = NULL;
        void *data = node->data;
        free(node);
        return data;
    } else {
        stack->head = stack->head->next;
        void *data = node->data;
        free(node);
        return data;
    }
}

int push(_STACK_ *stack , void *data) {
    _NODE_ *newNode = (_NODE_*)malloc(sizeof(_NODE_));
    if (newNode == NULL ) return FAILED;
    newNode->data = data;
    if(stack->head==NULL) {
        newNode->next = NULL;
        stack->tail = newNode;
    } else {
        newNode->next = stack->head;
    }
    stack->head = newNode;
    return SUCCESS;
}

void displayStack(_STACK_ *stack, DISPLAY display) {
    _NODE_ *node;
    node = stack->head;
    //printf("\nSTACK: -head-TO-tail-\n");
    print(B_RED, "\nSTACK: -head-TO-tail-");
    while(node != NULL) {
        display(node->data);
        node = node->next;
    }
    printf("\n" );
}

void destroyStack(_STACK_ *stack){
    _NODE_ *node;
    node = stack->head;
    while (1) {
        if(node == NULL ) break;
        stack->head = stack->head->next;
        free(node);
        node = stack->head;
    }
}

/* -------------------- QUEUE ------------------------ */

int queueEmpty(const _QUEUE_ *queue) {
    return (queue->head == NULL);
}
void initializeQueue(_QUEUE_ *queue) {
    queue->current = NULL;
    queue->head = NULL;
    queue->tail = NULL;
}

int enqueue(_QUEUE_ *queue, void *data) {
    _NODE_ *newNode = (_NODE_*)malloc(sizeof(_NODE_));
    if(newNode==NULL) return FAILED;
    newNode->data = data;
    newNode->next = NULL;
    if(queue->head == NULL){
        queue->tail = newNode;
    } else {
        newNode->next = queue->head;
    }
    queue->head = newNode;
    return SUCCESS;
}

void *dequeue(_QUEUE_ *queue) {
    _NODE_ *tmp = queue->head;
    if(queue->head == NULL ) {
        return NULL;
    } else if(queue->head == queue->tail) {
        queue->head = queue->tail = NULL;
        void *data = tmp->data;
        free(tmp);
        return data;
    } else {
        while(tmp!=NULL && tmp->next->next != NULL){
            tmp = tmp->next;
        }
        if(tmp->next->next == NULL ) {
            void *data = queue->tail->data;
            _NODE_ *node = queue->tail;
            queue->tail = tmp;
            queue->tail->next= NULL;
            free(node);
            return data;
        }
    }
    return NULL;
}

void displayQueue(_QUEUE_ *queue, DISPLAY display) {
    _NODE_ *node = queue->head;
    //printf("\nQUEUE: -HEAD-TO-TAIL-\n" );
    while(node!=NULL) {
        display(node->data);
        node = node->next;
    }
    printf("\n");
}

void destroyQueue(_QUEUE_ *queue) {
    _NODE_ *node = queue->head;
    //printf("\n%s\n","Destroying queue..." );
    while(node!=NULL){
        queue->head = queue->head->next;
        free(node);
        node = queue->head;
    }
    //printf("%s\n", "Destroyed...");
}

/* ---------------- DOUBLY LINKED LIST ------------------ */


void initializeDList(_DLINKED_LIST_ *dlist) {
    dlist->tail = NULL;
    dlist->head = NULL;
    dlist->current = NULL;
}

int addDHead(_DLINKED_LIST_ *dlist, void *data) {

}

int addDTail(_DLINKED_LIST_ *dlist, void *data) {
}

void removeDNode(_DLINKED_LIST_ *dlist, _DNODE_ *dnode) {

}

_DNODE_ *getDNode(const _DLINKED_LIST_ *dlist, COMPARE compare, void *data) {

}

void displayDLinkedList(const _DLINKED_LIST_ *dlist, DISPLAY display) {

}

void DlistEmpty(const _DLINKED_LIST_ * dlist) {

}

void freeDList(_DLINKED_LIST_ *dlist) {
    while (!DlistEmpty(dlist)) {
        removeDNode(dlist,dlist->head);
    }
}
