/*                              */
/*    @kaushal_kishore          */
/* mailTo: kshr4kshl@gmail.com  */
/*                              */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "dataStructures.h"



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



/* ---------------- DOUBLY LINKED LIST ------------------ */


void initializeDList(_DLINKED_LIST_ *dlist) {
    dlist->tail = NULL;
    dlist->head = NULL;
    dlist->current = NULL;
}

int addDHead(_DLINKED_LIST_ *dlist, void *data) {
    _DNODE_ *dnode = (_DNODE_*)malloc(sizeof(_DNODE_));
    if(dnode == NULL) return 0;
    dnode->data = data;
    dnode->prev = NULL;
    if(dlist->head == NULL){
        dlist->tail = dnode;
        dnode->next = NULL;
    } else {
        dnode->next = dlist->head;
        dlist->head->prev = dnode;
    }
    dlist->head = dnode;
    return 1;
}

int addDTail(_DLINKED_LIST_ *dlist, void *data) {
    _DNODE_ *dnode = (_DNODE_*)malloc(sizeof(_DNODE_));
    if(dnode==NULL) return 0;
    dnode->data = data;
    dnode->next = NULL;
    dnode->prev = dlist->tail;
    if(dlist->head == NULL){
        dlist->head = dnode;
    }
    dlist->tail->next = dnode;
    dlist->tail = dnode;
    return 1;
}

void removeDNode(_DLINKED_LIST_ *dlist, _DNODE_ *dnode) {
    if (dnode == dlist->head) {
        if (dlist->head->next == NULL) {
            dlist->head = dlist->tail = NULL;
        } else {
            dlist->head->next->prev = NULL;
            dlist->head = dlist->head->next;
        }
    } else {
        dnode->prev->next = dnode->next;
        dnode->next->prev = dnode->prev;
    }
    free(dnode);
}

_DNODE_ *getDNode(const _DLINKED_LIST_ *dlist, COMPARE compare, void *data) {
    _DNODE_ *dnode = dlist->head;
    while(dnode != NULL ){
        if(compare(dnode->data, data) == 0){
            return dnode;
        }
        dnode = dnode->next;
    }
    return NULL;
}

void displayDLinkedList(const _DLINKED_LIST_ *dlist, DISPLAY display) {
    //printf("Doubly Linked List\n");
    _DNODE_ *current = dlist->head;
    while(current != NULL){
        display(current->data);
        current = current->next;
    }
}

int DlistEmpty(const _DLINKED_LIST_ * dlist) {
    return (dlist->head == NULL);
}

void freeDList(_DLINKED_LIST_ *dlist) {
    while (!DlistEmpty(dlist)) {
        removeDNode(dlist,dlist->head);
    }
}
