/*                              */
/*    @kaushal_kishore          */
/* mailTo: kshr4kshl@gmail.com  */
/*                              */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "dataStructures.h"

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
