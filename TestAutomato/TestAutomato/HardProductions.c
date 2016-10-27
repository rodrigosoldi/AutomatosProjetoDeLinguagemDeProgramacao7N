//
//  HardProductions.c
//  TestAutomato
//
//  Created by Rodrigo Soldi Lopes on 26/10/16.
//  Copyright © 2016 Kaique Damato. All rights reserved.
//

#include <stdio.h>

// Structures ================

typedef struct production {
    
    char *lhs;
    char **rhs;
    int rhsLength;
    
} Production;

// Prototypes ============
static Production * createProduction(char *, char **);


// Implementations ================

static Production * createPROG1() {
    char * lhs = "PROG";    
    char *rhs[] = {"MAIN"};
    return createProduction(lhs, rhs);
}

static Production * createPROG2() {
    char * lhs = "PROG";
    char *rhs[] = {"MAIN", "CLASSE_X"};
    return createProduction(lhs, rhs);
}

static Production * createCLASSE_X1() {
    char * lhs = "CLASSE_X";
    char *rhs[] = {"CLASSE", "CLASSE_X"};
    return createProduction(lhs, rhs);
}

static Production * createCLASSE_X2() {
    char * lhs = "CLASSE_X";
    char *rhs[] = {"CLASSE"};
    return createProduction(lhs, rhs);
}


// NEVER NEVER NEVER

static Production * createProduction(char *lhs, char **rhs) {
    Production *prod = (Production *)malloc(sizeof(Production));
    prod->lhs = lhs;
    prod->rhs = rhs;
    prod->rhsLength = 1;
    
    return prod;
}
