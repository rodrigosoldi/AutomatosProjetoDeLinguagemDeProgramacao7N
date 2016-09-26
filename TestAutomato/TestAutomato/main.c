//
//  main.c
//  TestAutomato
//
//  Created by Kaique Damato on 9/19/16.
//  Copyright © 2016 Kaique Damato. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.c"
#include "readFile.c"

// Functions
int checkTransitionFunction(char, int);
int readWord();
void makeTransitionFunction();
void checkWord();
void createTransitionFunctions();

// Global Variables
int ninputs = 52; // number of input symbols
char symbols[100] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z}; // input symbols

int nfinals = 20; // number of final states
int finalStates[100] = {7, 12, 16, 22, 27, 29, 31, 37, 41, 44, 47, 53, 59, 65, 71, 88, 92, 95, 99, 104}; // final states

int dfa[1000][1000]; // matrix of transition functions
char string[100]; // character flow
int cs = 0; // current state

int lexemes[100]; // The state where the lexema was recognized
int currentLexema = 0; // The current index position of the lexemes array

char word[1024]; // Current word on reading

FILE *file;

int main() {
    
    createTransitionFunctions();
    
    file = fopen("/Users/KaiqueDamato/Documents/AutomatosProjetoDeLinguagemDeProgramacao7N/words.txt", "r");
    
    while (readWord()) {
        
        makeTransitionFunction();
        checkWord();
        
        cs = 0;
    }
}

// Get the current state and the current carecter and return the new state
int checkTransitionFunction(char symbol, int currentState) {
    int it;
    for(it = 0; it < ninputs; it++) {
        if(symbol == symbols[it]) {
            return(dfa[currentState][symbol]);
        }
    }
    return -1;
}

// Iterate over word and calls checkTransitionFunction
void makeTransitionFunction() {
    int it = 0;
    
    while(word[it] != '\0') {
        if((cs = checkTransitionFunction(word[it++], cs)) < 0) {
            break;
        }
    }
}

// Verify if the word is valid
void checkWord() {
    int it = 0;
    
    for(it = 0; it < nfinals; it++) {
        if(finalStates[it] == cs) {
            printf("%s --> valid string\n", word);
            lexemes[currentLexema++] = cs;
            return;
        }
    }
    printf("%s --> invalid string\n", word);
}

// Read the next word in txt
int readWord() {
    if (fscanf(file, "%1023s", word) != -1) {
        return 1;
    }
    return 0;
}

// Create the transition functions
void createTransitionFunctions() {
    //transition functions for boolean
    dfa[0][b] = 1;
    dfa[1][o] = 2;
    dfa[2][o] = 3;
    dfa[3][l] = 4;
    dfa[4][e] = 5;
    dfa[5][a] = 6;
    dfa[6][n] = 7;
    
    //transition functions for class
    dfa[0][c]  = 8;
    dfa[8][l]  = 9;
    dfa[9][a]  = 10;
    dfa[10][s] = 11;
    dfa[11][s] = 12;
    
    //transition functions for if or int
    dfa[0][i] = 28;
    dfa[28][f] = 29;
    dfa[28][n] = 30;
    dfa[30][t] = 31;
    
    //transition functions for else
    dfa[0][e] = 13;
    dfa[13][l] = 14;
    dfa[14][s] = 15;
    dfa[15][e] = 16;
    
    //transition functions for extends
    dfa[13][x] = 17;
    dfa[17][t] = 18;
    dfa[18][e] = 19;
    dfa[19][n] = 20;
    dfa[20][d] = 21;
    dfa[21][s] = 22;
}
