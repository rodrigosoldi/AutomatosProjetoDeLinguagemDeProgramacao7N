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

// Functions
int checkTransitionFunction(char, int);
int readWord();
void makeTransitionFunction();
void checkWord();
void createTransitionFunctions();

// Global Variables
int ninputs = 26; // number of input symbols
char symbols[100] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z}; // input symbols

int nfinals = 4; // number of final states
int finalStates[100] = {7, 12, 29, 31}; // final states

int dfa[1000][1000]; // matrix of transition functions
char string[100]; // character flow
int s = 0; // current state

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
        
        s = 0;
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
        if((s = checkTransitionFunction(word[it++], s)) < 0) {
            break;
        }
    }
}

// Verify if the word is valid
void checkWord() {
    int it = 0;
    
    for(it = 0; it < nfinals; it++) {
        if(finalStates[it] == s) {
            printf("%s --> valid string\n", word);
            lexemes[currentLexema++] = s;
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
    dfa[0][B] = 1;
    dfa[1][O] = 2;
    dfa[2][O] = 3;
    dfa[3][L] = 4;
    dfa[4][E] = 5;
    dfa[5][A] = 6;
    dfa[6][N] = 7;
    
    dfa[0][C]  = 8;
    dfa[8][L]  = 9;
    dfa[9][A]  = 10;
    dfa[10][S] = 11;
    dfa[11][S] = 12;
    
    dfa[0][I] = 28;
    dfa[28][F] = 29;
    dfa[28][N] = 30;
    dfa[30][T] = 31;
}
