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


/* ---------------- ----------------------- */
#endif // ASSIST_H
