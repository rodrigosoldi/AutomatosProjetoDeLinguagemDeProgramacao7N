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

static Production * createPROG() {
    char * lhs = "PROG";    
    char *rhs[] = {"MAIN"};
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
