/*                              */
/*    @kaushal_kishore          */
/* mailTo: kshr4kshl@gmail.com  */
/*                              */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "dataStructures.h"

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
