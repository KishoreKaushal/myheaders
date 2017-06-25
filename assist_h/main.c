#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "assist.h"

typedef struct _employee {
    char name[32];
    unsigned char age;
}   Employee;

int compareEmployee(Employee *e1, Employee *e2) {
    if(strcmp(e1->name, e2->name)==0) { return SUCCESS; }
    else return FAILED;
}

void displayEmployee(Employee *e) {
    printf("Name: %s\tAge: %d\n", e->name, e->age);
}

int main(int argc, char const *argv[]) {
    {/* code */
        print(B_GREEN, "kaushal_kishore" );
        warning("ITS A WARNING...");
        error("Its an error...");
        switchColor(U_YELLOW);
        printf("Switch color..\n" );
        print(B_GREEN, "kaushal_kishore" );
        warning("ITS A WARNING...");
        error("Its an error...");

        switchColor(CYAN);
        printf("Switched color..Again..\n" );
        resetColor();
        printf("Color Reset\n\n\n" );
        //    error("getLine() : failed to allocate memory for the input.");
    }
    _STACK_ stack;
    initializeStack(&stack);
    displayStack(&stack, (DISPLAY)displayEmployee); //type casting is must

    printf("stackEmpty: %d\n", stackEmpty(&stack));

    Employee *samuel = (Employee*) malloc(sizeof(Employee));
    strcpy(samuel->name, "Samuel");
    samuel->age = 32;
    Employee *sally = (Employee*) malloc(sizeof(Employee));
    strcpy(sally->name, "Sally");
    sally->age = 28;
    Employee *susan = (Employee*) malloc(sizeof(Employee));
    strcpy(susan->name, "Susan");
    susan->age = 45;

    push(&stack, samuel);
    push(&stack, sally);
    push(&stack, susan);

    push(&stack, samuel);
    push(&stack, sally);
    push(&stack, susan);
    displayStack(&stack, (DISPLAY)displayEmployee);

    printf("stackEmpty: %d\n", stackEmpty(&stack));

    Employee *employee;

    for(int i=0; i<4; i++) {
        employee = (Employee*) pop(&stack);
        printf("Popped %s\n", employee->name );
        displayStack(&stack, (DISPLAY)displayEmployee);
    }
    displayStack(&stack, (DISPLAY)displayEmployee);
    destroyStack(&stack);
    displayStack(&stack, (DISPLAY)displayEmployee);
    printf("stackEmpty: %d\n", stackEmpty(&stack));


    return 0;
}
