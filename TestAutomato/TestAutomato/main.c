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
#include "Productions.c"

void MAIN();
void PROG();
void var_x();
int var_y();
int tipo();
int tipo1();
int param();
int param_y();
int cmd_x();
int cmds();
int cmd();
int exp1();
int rexp();
int exp_x();
int aexp();
int aexp_x();
int rexp_x();
int mexp();
int mexp_x();
int sexp();
int sexp_x();
int pexp();
int pexp_x();
int exps();
int else_x();
int ponto_x();
void metodo_x();
int param_x();
int inside_metodo();
int metodo();
int consume(char *token);
void consumeAux(char *token);

/*******************************************************/

// Functions
int checkTransitionFunction(char, int);
int makeTransitionFunction(char *lexeme);
void createTransitionFunctions();
void tokenForState(int, ListNode *);
void generateTokens();
char * checkExistVariable(char *var);
char * createNewVariable(char *var);

// Global Variables
int ninputs = 82; // number of input symbols
char symbols[82] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, opPar, clPar, opBrac, clBrac, opChav, clChav, vir, pt, ptVir, eCom, larger, smaller, excQuote, equal, minus, plus, times, slash, backslash, zero, one, two, three, four, five, six, seven, eight, nine, underscore}; // input symbols

int nfinals = 49; // number of final states
int finalStates[49] = {7, 12, 16, 22, 27, 29, 31, 37, 41, 44, 47, 53, 59, 65, 71, 88, 92, 95, 99, 104, 106, 107, 108, 109, 110, 111, 113, 114, 115, 116, 117, 118, 119, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 200}; // final states

int dfa[136][136]; // matrix of transition functions

int sizeVariables = 0;
char *variables[100];

FILE *file;

int main() {
    
    createProductions();
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
    
    ListNode *aux = LIST->head;
    while (aux->next != NULL) {
        int finalState = makeTransitionFunction(aux->lexeme);
        tokenForState(finalState, aux);
        
        aux = aux->next;
    }
    
    printList(LIST);
    generateTokens();
    PROG();
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
int makeTransitionFunction(char * lexeme) {
    int it = 0;
    
    int finalState = 0;
    while(lexeme[it] != '\0') {
        if((finalState = checkTransitionFunction(lexeme[it++], finalState)) < 0) {
            break;
        }
    }
    return finalState;
}

////////////////////////////////////////////////

void generateTokens() {
    
    char *tokensString = malloc(1000);
    char *tokens[LIST->count];
    
    ListNode *aux = LIST->head;
    while (aux->next != NULL) {
        
        char *minor = "<";
        char *major = ">";
        char *virg = ",";
        
        char *token = malloc(1024 * sizeof(char));
        if (aux->class != NULL) {
            
            strcat(token, minor);
            strcat(token, aux->class);
            
            if (aux->parameter != NULL) {
                strcat(token, virg);
                strcat(token, aux->parameter);
            }
            
            strcat(token, major);
            
            strcat(tokensString, token);
            strcat(tokensString, "\n");
        }
        aux = aux->next;
    }
    
    char buffer[200];
    char *path = getcwd(buffer, sizeof(buffer));
    FILE *file = fopen(strcat(path, "/tokens.txt"), "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    fprintf(file, "%s", tokensString);
    fclose(file);
}

void tokenForState(int state, ListNode *listNode) {
    switch (state) {
        case 7:
            listNode->class = "boolean";
            break;
        case 12:
            listNode->class = "class";
            break;
        case 16:
            listNode->class = "else";
            break;
        case 22:
            listNode->class = "extends";
            break;
        case 27:
            listNode->class = "false";
            break;
        case 29:
            listNode->class = "if";
            break;
        case 31:
            listNode->class = "int";
            break;
        case 37:
            listNode->class = "length";
            break;
        case 41:
            listNode->class = "main";
            break;
        case 44:
            listNode->class = "new";
            break;
        case 47:
            listNode->class = "null";
            break;
        case 53:
            listNode->class = "public";
            break;
        case 59:
            listNode->class = "return";
            break;
        case 65:
            listNode->class = "static";
            break;
        case 71:
            listNode->class = "String";
            break;
        case 88:
            listNode->class = "System.out.println";
            break;
        case 92:
            listNode->class = "this";
            break;
        case 95:
            listNode->class = "true";
            break;
        case 99:
            listNode->class = "void";
            break;
        case 104:
            listNode->class = "while";
            break;
        case 111:
            listNode->class = "OP";
            listNode->parameter = "MT";
            break;
        case 114:
            listNode->class = "OP";
            listNode->parameter = "MA";
            break;
        case 115:
            listNode->class = "OP";
            listNode->parameter = "ME";
            break;
        case 116:
            listNode->class = "OP";
            listNode->parameter = "AT";
            break;
        case 118:
            listNode->class = "OP";
            listNode->parameter = "CP";
            break;
        case 117:
            listNode->class = "OP";
            listNode->parameter = "MN";
            break;
        case 121:
            listNode->class = "OP";
            listNode->parameter = "AN";
            break;
        case 122:
            listNode->class = "PT";
            listNode->parameter = "PA";
            break;
        case 123:
            listNode->class = "PT";
            listNode->parameter = "PF";
            break;
        case 124:
            listNode->class = "PT";
            listNode->parameter = "CA";
            break;
        case 125:
            listNode->class = "PT";
            listNode->parameter = "CF";
            break;
        case 126:
            listNode->class = "PT";
            listNode->parameter = "XA";
            break;
        case 127:
            listNode->class = "PT";
            listNode->parameter = "XF";
            break;
        case 128:
            listNode->class = "PT";
            listNode->parameter = "PV";
            break;
        case 129:
            listNode->class = "PT";
            listNode->parameter = "VR";
            break;
        case 130:
            listNode->class = "PT";
            listNode->parameter = "PTF";
            break;
        case 200:
            listNode->class = "OP";
            listNode->parameter = "MR";
            break;
        case 131:{
            listNode->class = "number";
            listNode->parameter = listNode->lexeme;
            
            break;
        }
        case 132:
        case 133:
        case 134:
        case 135: {
            
            char *number = checkExistVariable(listNode->lexeme);
            listNode->class = "ID";
            listNode->parameter = number;
            
            break;
        }
        default:
            printf("ERRO NA LEITURA\n\n");
            generateTokens();
            exit(1);
            break;
    }
}

////////////////////////////////////////////////

int strcmpa(char *s1, char *s2) {
    int it;
    for (it = 0; s1[it] == s2[it]; it++)
        if (s1[it] == '\0')
            return 0;
    return s1[it] - s2[it];
}

char * checkExistVariable(char *var) {
    
    if (sizeVariables == 0) {
        return  createNewVariable(var);
    }
    
    int it;
    for (it = 0; it < sizeVariables; it++) {
        
        if (strcmpa(variables[it], var) == 0) {
            char *number = malloc(sizeof(char));
            sprintf(number, "%d", it);
            return number;
        }
    }
    
    return createNewVariable(var);
}

char * createNewVariable(char *var) {
    char *number = malloc(sizeof(char));
    variables[sizeVariables] = var;
    sprintf(number, "%d", sizeVariables);
    sizeVariables++;
    return number;
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
        dfa[myCurrentState]['_'] = 132;
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
    dfa[0][times] = 111;
}

/************************************************************************************************************************************************/

ListNode *aux;

void PROG() {
    aux = LIST->head;
    MAIN();
}


void MAIN() {
    consumeAux("class");
    consumeAux("ID");
    consumeAux("{");
    consumeAux("public");
    consumeAux("static");
    consumeAux("void");
    consumeAux("main");
    consumeAux("(");
    consumeAux("String");
    consumeAux("[");
    consumeAux("]");
    consumeAux("ID");
    consumeAux(")");
    consumeAux("{");
    var_x();
    inside_metodo();
    consumeAux("}");
//    metodo_x();
    consumeAux("}");
}

void var_x() {
    while (var_y()) {}
}

int var_y() {
    if (tipo()) {
        consumeAux("ID");
        consumeAux(";");
        return 1;
    }
    
    return 0;
}

void metodo_x() {
    while (metodo()) {}
}


int metodo() {
    if (consume("public")) {
        if (tipo()) {
            consumeAux("ID");
            consumeAux("(");
            param_x();
            consumeAux(")");
            consumeAux("{");
            inside_metodo();
            consumeAux("}");
            return 1;
        }
    }
    
    return 0;
}


int param_x() {
    if (param()) {
        return param_y();
    }
    return 0;
}

int param() {
    if (tipo()) {
        return consume("ID");
    }
    
    return 0;
}

int param_y() {
    if (!consume(",")) {
        return 1;
    }
    
    consumeAux(",");
    return param_x();
}

int inside_metodo() {
    var_x();
    return cmd_x();
}

int cmd_x() {
    if (cmds()) {
        return return_x();
    }
    
    return 1;
}

int return_x() {
    if (consume("return")) {
        if (exp1()) {
            return consume(";");
        }
        
        return 0;
    }
    
    return 1;
}

int cmds() {
    while (cmd()) ;
    
    return 1;
}

int cmd() {
    
    if (consume("{")) {
        cmds();
        return consume("}");
    } else if (consume("ID")) {
        consumeAux("=");
        exp1();
        return consume(";");
    } else if (consume("if")) {
        consumeAux("(");
        if (exp1()) {
            consumeAux(")");
            
            if (cmd()) {
                return else_x();
            }
        }
        return 0;
    } else if (consume("System.out.println")) {
        consumeAux("(");
        if (exp1()) {
            consumeAux(")");
            return consume(";");
        }
    }
    
    return 0;
}

int else_x() {
    if (consume("else")) {
        return cmd();
    }
    
    return 1;
}

int exp1() {
    if (rexp()) {
        return exp_x();
    } else if (consume("ID")) {
        consumeAux("(");
        return consume(")");
    }
    
    return 0;
}

int exp_x() {
    if (consume("&&")) {
        return exp1();
    }
    
    return 1;
}

int rexp() {
    if (aexp()) {
        return rexp_x();
    }
    
    return 0;
}

int rexp_x() {
    if (consume("<")) {
        return rexp();
    } else if (consume("==")) {
        return rexp();
    } else if (consume("!=")) {
        return rexp();
    }
    return 1;
}

int aexp() {
    
    if (mexp()) {
        return aexp_x();
    }
    
    return 0;
}

int aexp_x() {
    if (consume("+") || consume("-")) {
        return aexp();
    }
    
    return 1;
}

int mexp() {
    
    if (sexp()) {
        return mexp_x();
    }
    
    return 0;
}

int mexp_x() {
    if (consume("*")) {
        return mexp();
    }
    
    return 1;
}

int sexp() {
    
    if (consume("!") || consume("-")) {
        return sexp();
    } else if ( consume("true") || consume("false") || consume("number") || consume("null") ) {
        return 1;
    } else if (pexp()) {
        return pexp_x();
    }
    
    return 0;
    
    //return consume("ID") || consume("number");
}

int ponto_x() {
    return consume("length");
}

int pexp() {
    if (consume("this")) {
        return 1;
    } else if (consume("new")) {
        consumeAux("ID");
        consumeAux("(");
        consumeAux(")");
        return 1;
    } else if (consume("(")) {
        if (exp1()) {
            if (consume(")")) {
                return pexp_x();
            }
        }
    } else if (consume("ID")) {
        return pexp_x();
    }
    
    return 0;
}

int pexp_x() {
    
    if (consume(".")) {
        if (ponto_x()) {
            return 1;
        }
        
        return pexp();
    } else if (consume("(")) {
        exp1();
        return consume(")");
    }
    
    return 1;
}

int tipo() {
    if (consume("boolean")) {
        return 1;
    } else if (consume("ID")) {
        return 1;
    } else if (consume("int")) {
        return tipo1();
    }
    return 0;
}

int tipo1() {
    if (consume("[")) {
        if (!consume("]")) {
            printf("Deu ruim no tipo1");
            exit(1);
        }
    }
    return 1;
}

int consume(char *token) {
    if ((strcmp(aux->lexeme, token) == 0) || (strcmp(aux->class, token) == 0)) {
        aux = aux->next;
        return 1;
    }
    
    return 0;
}

void consumeAux(char *token) {
    if ((strcmp(aux->lexeme, token) == 0) || (strcmp(aux->class, token) == 0)) {
        aux = aux->next;
    } else {
        printf("Deu ruim no consumeAux, achou: %s, tentou consumir: %s\n", aux->lexeme, token);
        exit(1);
    }
}

