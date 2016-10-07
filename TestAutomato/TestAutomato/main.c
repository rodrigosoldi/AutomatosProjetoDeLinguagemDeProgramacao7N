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
#include <unistd.h>
#include "constants.c"
#include "ReadFile.c"

// Functions
int checkTransitionFunction(char, int);
int readWord();
void makeTransitionFunction();
void checkWord();
void createTransitionFunctions();
char *tokenForState(int);
void generateTokens(int[],int);

// Global Variables
int ninputs = 81; // number of input symbols
char symbols[100] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, opPar, clPar, opBrac, clBrac, opChav, clChav, vir, pt, ptVir, eCom, larger, smaller, excQuote, equal, minus, plus, times, slash, backslash, zero, one, two, three, four, five, six, seven, eight, nine}; // input symbols

int nfinals = 49; // number of final states
int finalStates[100] = {7, 12, 16, 22, 27, 29, 31, 37, 41, 44, 47, 53, 59, 65, 71, 88, 92, 95, 99, 104, 106, 107, 108, 109, 110, 111, 113, 114, 115, 116, 117, 118, 119, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 200}; // final states

int dfa[130][130]; // matrix of transition functions
char string[100]; // character flow
int cs = 0; // current state

int lexemes[100]; // The state where the lexema was recognized
int currentLexema = 0; // The current index position of the lexemes array

char word[1024]; // Current word on reading

FILE *file;

int main() {
    createTransitionFunctions();
    
    char cwd[1024];
    char cwd2[1024];
    
    if (getcwd(cwd, sizeof(cwd)) != NULL && getcwd(cwd2, sizeof(cwd2)) != NULL) {
        strcat(cwd, "/Files/yourfile.txt");
        strcat(cwd2, "/words.txt");
    } else {
        perror("getcwd() error");
    }
    
    readFile(cwd);
    file = fopen(cwd2, "r");
    
    while (readWord()) {
        
        makeTransitionFunction();
        checkWord();
        
        cs = 0;
    }
    generateTokens(lexemes, currentLexema);
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
    printf("unaccepted state: %d\n", cs);
}

// Read the next word in txt
int readWord() {
    if (fscanf(file, "%1023s", word) != -1) {
        return 1;
    }
    return 0;
}

////////////////////////////////////////////////

void generateTokens(int lexems[], int length) {
    char *tokens[length];
    char *tokensString = malloc(1000);
//    tokensString[0] = '\;
    int it;
    for (it = 0; it < length; it++) {
        tokens[it] = tokenForState(lexems[it]);
        printf("-> %s\n", tokens[it]);
        strcat(tokensString, tokens[it]);
        strcat(tokensString, "\n");
        printf("->>>> %s\n", tokensString);
    }
    char buffer[200];
    char *path = getcwd(buffer, sizeof(buffer));
    FILE *file = fopen(strcat(path, "/tokens"), "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    printf("**--** %s **--**\n", tokensString);
    fprintf(file, "%s", tokensString);
    fclose(file);
    printf("::: %s :::", tokensString);
    
    
}

char *tokenForState(int state) {
    switch (state) {
        case 7:
            return "<boolean>";
            break;
        case 12:
            return "<class>";
            break;
        case 16:
            return "<else>";
            break;
        case 22:
            return "<extends>";
            break;
        case 27:
            return "<false>";
            break;
        case 29:
            return "<if>";
            break;
        case 31:
            return "<int>";
            break;
        case 37:
            return "<length>";
            break;
        case 41:
            return "<main>";
            break;
        case 44:
            return "<new>";
            break;
        case 47:
            return "<null>";
            break;
        case 53:
            return "<public>";
            break;
        case 59:
            return "<return>";
            break;
        case 65:
            return "<static>";
            break;
        case 71:
            return "<String>";
            break;
        case 88:
            return "<System.out.println>";
            break;
        case 92:
            return "<this>";
            break;
        case 95:
            return "<true>";
            break;
        case 99:
            return "<void>";
            break;
        case 104:
            return "<while>";
            break;
        case 114:
            return "<OP,MA>";
            break;
        case 115:
            return "<OP,ME>";
            break;
        case 116:
            return "<OP,AT>";
            break;
        case 118:
            return "<OP,CP>";
            break;
        case 117:
            return "<OP,MN";
            break;
        case 121:
            return "<OP,AN>";
            break;
        case 122:
            return "<PT,PA>";
            break;
        case 123:
            return "<PT,PF>";
            break;
        case 124:
            return "<PT,CA>";
            break;
        case 125:
            return "<PT,CF>";
            break;
        case 126:
            return "<PT,XA>";
            break;
        case 127:
            return "<PT,XF>";
            break;
        case 128:
            return "<PT,PV>";
            break;
        case 129:
            return "<PT,VR>";
            break;
        case 130:
            return "<PT,PT>";
            break;
        case 200:
            return "<OP,MR>";
            break;
        case 131:
            return "<int>";
            break;
        case 132:
        case 133:
        case 134:
        case 135:
            return "<id,X>";
            break;
            
        default:
            return "ERROR";
            break;
    }
}

////////////////////////////////////////////////

// Create the transition functions
void createTransitionFunctions() {
    
    // path from reserved words to variables
    int myState;
    char myIn;
    for (myState = 1; myState <= 104; myState++) {
        for (myIn = 'a'; myIn <= 'z'; myIn++) {
            dfa[myState][myIn] = 132;
        }
        for (myIn = 'A'; myIn <= 'Z'; myIn++) {
            dfa[myState][myIn] = 132;
        }
        for (myIn = '0'; myIn <= '9'; myIn++) {
            dfa[myState][myIn] = 132;
        }
        dfa[myState]['_'] = 132;
    }
    
    // letras maiúsculas
    char myChar;
    for (myChar = 'A'; myChar <= 'Z'; myChar++) {
        dfa[0][myChar] = 133;
    }
    for (myChar = 'a'; myChar <= 'z'; myChar++) {
        dfa[0][myChar] = 133;
    }
    int myCurrentState;
    for (myCurrentState = 131; myCurrentState <= 135; myCurrentState++) {
        for (myChar = 'A'; myChar <= 'Z'; myChar++) {
            dfa[myCurrentState][myChar] = 133;
        }
        for (myChar = 'a'; myChar <= 'z'; myChar++) {
            dfa[myCurrentState][myChar] = 133;
        }
    }
    
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
    
    //transition functions for false
    dfa[0][f] = 23;
    dfa[23][a] = 24;
    dfa[24][l] = 25;
    dfa[25][s] = 26;
    dfa[26][e] = 27;
    
    //transition functions for if or int
    dfa[0][i] = 28;
    dfa[28][f] = 29;
    dfa[28][n] = 30;
    dfa[30][t] = 31;
    
    //transition functions for length
    dfa[0][l] = 32;
    dfa[32][e] = 33;
    dfa[33][n] = 34;
    dfa[34][g] = 35;
    dfa[35][t] = 36;
    dfa[36][h] = 37;
    
    //transition functions for main
    dfa[0][m] = 38;
    dfa[38][a] = 39;
    dfa[39][i] = 40;
    dfa[40][n] = 41;
    
    //transition functions for new
    dfa[0][n] = 42;
    dfa[42][e] = 43;
    dfa[43][w] = 44;
    
    //transition functions for null
    dfa[42][u] = 45;
    dfa[45][l] = 46;
    dfa[46][l] = 47;
    
    //transition functions for public
    dfa[0][p] = 48;
    dfa[48][u] = 49;
    dfa[49][b] = 50;
    dfa[50][l] = 51;
    dfa[51][i] = 52;
    dfa[52][c] = 53;
    
    //transition functions for return
    dfa[0][r] = 54;
    dfa[54][e] = 55;
    dfa[55][t] = 56;
    dfa[56][u] = 57;
    dfa[57][r] = 58;
    dfa[58][n] = 59;
    
    //transition functions for static
    dfa[0][s] = 60;
    dfa[60][t] = 61;
    dfa[61][a] = 62;
    dfa[62][t] = 63;
    dfa[63][i] = 64;
    dfa[64][c] = 65;
    
    //transition functions for String
    dfa[0][S] = 66;
    dfa[66][t] = 67;
    dfa[67][r] = 68;
    dfa[68][i] = 69;
    dfa[69][n] = 70;
    dfa[70][g] = 71;
    
    //transition functions fot System.out.println
    dfa[66][y] = 72;
    dfa[72][s] = 73;
    dfa[73][t] = 74;
    dfa[74][e] = 75;
    dfa[75][m] = 76;
    dfa[76][pt] = 77;
    dfa[77][o] = 78;
    dfa[78][u] = 79;
    dfa[79][t] = 80;
    dfa[80][pt] = 81;
    dfa[81][p] = 82;
    dfa[82][r] = 83;
    dfa[83][i] = 84;
    dfa[84][n] = 85;
    dfa[85][t] = 86;
    dfa[86][l] = 87;
    dfa[87][n] = 88;
    
    //transition functions for this
    dfa[0][t] = 89;
    dfa[89][h] = 90;
    dfa[90][i] = 91;
    dfa[91][s] = 92;
    
    //transition functions for true
    dfa[89][r] = 93;
    dfa[93][u] = 94;
    dfa[94][e] = 95;
    
    //transition functions for void
    dfa[0][v] = 96;
    dfa[96][o] = 97;
    dfa[97][i] = 98;
    dfa[98][d] = 99;
    
    //transitions functions for while
    dfa[0][w] = 100;
    dfa[100][h] = 101;
    dfa[101][i] = 102;
    dfa[102][l] = 103;
    dfa[103][e] = 104;
    
    //transition functions for pontuation
    dfa[0][backslash] = 105;
    dfa[105][n] = 106;
    dfa[105][t] = 107;
    dfa[105][r] = 108;
    dfa[105][f] = 109;
    dfa[0][plus] = 114;
    dfa[0][minus] = 115;
    dfa[0][equal] = 116;
    dfa[116][equal] = 118;
    dfa[0][excQuote] = 119;
    dfa[119][equal] = 118;
    dfa[0][smaller] = 117;
    dfa[0][eCom] = 120;
    dfa[120][eCom] = 121;
    dfa[0][opPar] = 122;
    dfa[0][clPar] = 123;
    dfa[0][opBrac] = 124;
    dfa[0][clBrac] = 125;
    dfa[0][opChav] = 126;
    dfa[0][clChav] = 127;
    dfa[0][ptVir] = 128;
    dfa[0][vir] = 129;
    dfa[0][pt] = 130;
    dfa[0][larger] = 200;
    dfa[0][zero] = 131;
    dfa[131][zero] = 131;
    dfa[0][one] = 131;
    dfa[131][one] = 131;
    dfa[0][two] = 131;
    dfa[131][two] = 131;
    dfa[0][three] = 131;
    dfa[131][three] = 131;
    dfa[0][four] = 131;
    dfa[131][four] = 131;
    dfa[0][five] = 131;
    dfa[131][five] = 131;
    dfa[0][six] = 131;
    dfa[131][six] = 131;
    dfa[0][seven] = 131;
    dfa[131][seven] = 131;
    dfa[0][eight] = 131;
    dfa[131][eight] = 131;
    dfa[0][nine] = 131;
    dfa[131][nine] = 131;
    /***/
   
    
}
