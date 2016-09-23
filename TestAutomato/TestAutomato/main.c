//
//  main.c
//  TestAutomato
//
//  Created by Kaique Damato on 9/19/16.
//  Copyright © 2016 Kaique Damato. All rights reserved.
//

#include <stdio.h>

// ----------------------
// PONTUATION

#define PONT_PARENTESES 100
#define STMT_X          200
// ----------------------
// LETERS

#define a 'a'
#define b 'b'
#define c 'c'
#define d 'd'
#define e 'e'
#define f 'f'
#define g 'g'
#define h 'h'
#define i 'i'
#define j 'j'
#define k 'k'
#define l 'l'
#define m 'm'
#define n 'n'
#define o 'o'
#define p 'p'
#define q 'q'
#define r 'r'

/*
 
 Matriz:
            PONT_PARENTESES     STMT_X      NAO_SEI_QUE
        1           4
        2
        3
        4
        5
        6
        7
 
 */

// Functions
int check(char, int); // function declaration

// Global Variables
int ninputs = 18; // number of input symbols
char symbols[100] = {b, o, l, e, a, n}; // input symbols

int nfinals = 1; // number of final states
int finalStates[100] = {7}; // final states

int dfa[1000][1000]; // matrix of transition functions
char string[100]; // character flow
int s = 0; // current state

int lexemes[100]; // The state where the lexema was recognized
int currentLexema = 0; // The current index position of the lexemes array

int main(void) {
    
    int it; // iterator
    
    dfa[0][b] = 1;
    dfa[1][o] = 2;
    dfa[2][o] = 3;
    dfa[3][l] = 4;
    dfa[4][e] = 5;
    dfa[5][a] = 6;
    dfa[6][n] = 7;
    
    do {
        it=0;
        printf("\n\nEnter Input String.. ");
        scanf("%s",string);
        
        while(string[it] != '\0') {
            if((s = check(string[it++], s)) < 0) {
                break;
            }
        }
        
        for(it = 0; it < nfinals; it++) {
            if(finalStates[it] == s) {
                printf("\nvalid string");
                lexemes[currentLexema++] = s;
            } else {
                printf("invalid string");
            }
        }
        
        getchar();
        
        printf("\nDo you want to continue.?  \n(y/n) ");
        s = 0;
    } while(getchar() == 'y');
    
    getchar();
}

int check(char symbol, int currentState) {
    int it;
    for(it = 0; it < ninputs; it++) {
        if(symbol == symbols[it]) {
            return(dfa[currentState][symbol]);
        }
    }
    return -1;
}
