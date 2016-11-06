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

static Production * createMAIN() {
    char * lhs = "MAIN";
    char *rhs[] = {"class", "id", "{", "public", "static", "void", "main", "(", "String", "[", "]", "id", ")", "{", "CMD", "}", "}"};
    return createProduction(lhs, rhs);
}

static Production * createCLASSE1() {
    char * lhs = "CLASSE";
    char *rhs[] = {"class", "id", "{", "}"};
    return createProduction(lhs, rhs);
}

static Production * createCLASSE2() {
    char * lhs = "CLASSE";
    char *rhs[] = {"class", "id", "{", "METODO_X", "}"};
    return createProduction(lhs, rhs);
}

static Production * createMETODO_X1() {
    char * lhs = "METODO_X";
    char *rhs[] = {"METODO", "METODO_X"};
    return createProduction(lhs, rhs);
}

static Production * createMETODO_X2() {
    char * lhs = "METODO_X";
    char *rhs[] = {"METODO"};
    return createProduction(lhs, rhs);
}

static Production * createCLASSE3() {
    char * lhs = "CLASSE";
    char *rhs[] = {"class", "id", "{", "VAR_X", "}"};
    return createProduction(lhs, rhs);
}

static Production * createVAR_X1() {
    char * lhs = "VAR_X";
    char *rhs[] = {"VAR", "VAR_X"};
    return createProduction(lhs, rhs);
}

static Production * createVAR_X2() {
    char * lhs = "VAR_X";
    char *rhs[] = {"VAR"};
    return createProduction(lhs, rhs);
}

static Production * createCLASSE4() {
    char * lhs = "CLASSE";
    char *rhs[] = {"class", "id", "{", "VAR_METODO_X", "}"};
    return createProduction(lhs, rhs);
}

static Production * createVAR_METODO_X1() {
    char * lhs = "VAR_METODO_X";
    char *rhs[] = {"VAR_X", "METODO_X"};
    return createProduction(lhs, rhs);
}

static Production * createVAR_METODO_X2() {
    char * lhs = "VAR_METODO_X";
    char *rhs[] = {"METODO_X", "VAR_X"};
    return createProduction(lhs, rhs);
}

static Production * createVAR1() {
    char * lhs = "VAR";
    char *rhs[] = {"TIPO", "id"};
    return createProduction(lhs, rhs);
}

static Production * createMETODO1() {
    char * lhs = "METODO";
    char *rhs[] = {"public", "TIPO", "id", "(", ")", "{", "return", "EXP", ";", "}"};
    return createProduction(lhs, rhs);
}

static Production * createMETODO2() {
    char * lhs = "METODO";
    char *rhs[] = {"public", "TIPO", "id", "(", ")", "{", "VAR_CMD_X", "return", "EXP", "}"};
    return createProduction(lhs, rhs);
}

static Production * createVAR_CMD_X1() {
    char * lhs = "VAR_CMD_X";
    char *rhs[] = {"VAR_X"};
    return createProduction(lhs, rhs);
}

static Production * createCMD_X1() {
    char * lhs = "CMD_X";
    char *rhs[] = {"CMD", "CMD_X"};
    return createProduction(lhs, rhs);
}

static Production * createCMD_X2() {
    char * lhs = "CMD_X";
    char *rhs[] = {"CMD"};
    return createProduction(lhs, rhs);
}

static Production * createVAR_CMD_X2() {
    char * lhs = "VAR_CMD_X";
    char *rhs[] = {"CMD_X"};
    return createProduction(lhs, rhs);
}

static Production * createVAR_CMD_X3() {
    char * lhs = "VAR_CMD_X";
    char *rhs[] = {"VAR_X", "CMD_X"};
    return createProduction(lhs, rhs);
}

static Production * createVAR_CMD_X4() {
    char * lhs = "VAR_CMD_X";
    char *rhs[] = {"CMD_X", "VAR_X"};
    return createProduction(lhs, rhs);
}

static Production * createMETODO3() {
    char * lhs = "METODO";
    char *rhs[] = {"public", "TIPO", "id", "(", "PARAMS", ")", "{", "return", "EXP", ";", "}"};
    return createProduction(lhs, rhs);
}

static Production * createMETODO4() {
    char * lhs = "METODO";
    char *rhs[] = {"public", "TIPO", "id", "(", "PARAMS", ")", "{", "VAR_CMD_X", "return", "EXP", ";", "}"};
    return createProduction(lhs, rhs);
}

static Production * createPARAMS1() {
    char * lhs = "PARAMS";
    char *rhs[] = {"TIPO", "id"};
    return createProduction(lhs, rhs);
}

static Production * createPARAMS2() {
    char * lhs = "PARAMS";
    char *rhs[] = {"TIPO", "id", "TIPOS_X"};
    return createProduction(lhs, rhs);
}

static Production * createTIPOS_X1() {
    char * lhs = "TIPOS_X";
    char *rhs[] = {",", "TIPO", "id", "TIPOS_X"};
    return createProduction(lhs, rhs);
}

static Production * createTIPOS_X2() {
    char * lhs = "TIPOS_X";
    char *rhs[] = {",", "TIPO", "id"};
    return createProduction(lhs, rhs);
}

static Production * createTIPO1() {
    char * lhs = "TIPO";
    char *rhs[] = {"int", "[", "]"};
    return createProduction(lhs, rhs);
}

static Production * createTIPO2() {
    char * lhs = "TIPO";
    char *rhs[] = {"boolean"};
    return createProduction(lhs, rhs);
}

static Production * createTIPO3() {
    char * lhs = "TIPO";
    char *rhs[] = {"int"};
    return createProduction(lhs, rhs);
}

static Production * createTIPO4() {
    char * lhs = "TIPO";
    char *rhs[] = {"id"};
    return createProduction(lhs, rhs);
}


static Production * createCMD1() {
    char * lhs = "CMD";
    char *rhs[] = {"{", "}"};
    return createProduction(lhs, rhs);
}

static Production * createCMD2() {
    char * lhs = "CMD";
    char *rhs[] = {"{", "CMD_X", "}"};
    return createProduction(lhs, rhs);
}

static Production * createCMD3() {
    char * lhs = "CMD";
    char *rhs[] = {"id", "=", "EXP", ";"};
    return createProduction(lhs, rhs);
}

static Production * createCMD4() {
    char * lhs = "CMD";
    char *rhs[] = {"if", "(", "EXP", ")", "CMD"};
    return createProduction(lhs, rhs);
}

static Production * createCMD5() {
    char * lhs = "CMD";
    char *rhs[] = {"if", "(", "EXP", ")", "CMD", "else", "CMD"};
    return createProduction(lhs, rhs);
}

static Production * createCMD6() {
    char * lhs = "CMD";
    char *rhs[] = {"System.out.println", "(", "EXP", ")", ";"};
    return createProduction(lhs, rhs);
}

static Production * createEXP1() {
    char * lhs = "EXP";
    char *rhs[] = {"EXP", "&&", "REXP"};
    return createProduction(lhs, rhs);
}

static Production * createEXP2() {
    char * lhs = "EXP";
    char *rhs[] = {"REXP"};
    return createProduction(lhs, rhs);
}

static Production * createREXP1() {
    char * lhs = "REXP";
    char *rhs[] = {"REXP", "<", "AEXP"};
    return createProduction(lhs, rhs);
}

static Production * createREXP2() {
    char * lhs = "REXP";
    char *rhs[] = {"REXP", "=", "=", "AEXP"};
    return createProduction(lhs, rhs);
}

static Production * createREXP3() {
    char * lhs = "REXP";
    char *rhs[] = {"REXP", "!", "=", "AEXP"};
    return createProduction(lhs, rhs);
}

static Production * createREXP4() {
    char * lhs = "REXP";
    char *rhs[] = {"AEXP"};
    return createProduction(lhs, rhs);
}

static Production * createAEXP1() {
    char * lhs = "AEXP";
    char *rhs[] = {"AEXP", "+", "MEXP"};
    return createProduction(lhs, rhs);
}

static Production * createAEXP2() {
    char * lhs = "AEXP";
    char *rhs[] = {"AEXP", "-", "MEXP"};
    return createProduction(lhs, rhs);
}

static Production * createAEXP3() {
    char * lhs = "AEXP";
    char *rhs[] = {"MEXP"};
    return createProduction(lhs, rhs);
}

static Production * createMEXP1() {
    char * lhs = "MEXP";
    char *rhs[] = {"MEXP", "*", "SEXP"};
    return createProduction(lhs, rhs);
}

static Production * createMEXP2() {
    char * lhs = "MEXP";
    char *rhs[] = {"SEXP"};
    return createProduction(lhs, rhs);
}

static Production * createSEXP1() {
    char * lhs = "SEXP";
    char *rhs[] = {"!", "SEXP"};
    return createProduction(lhs, rhs);
}

static Production * createSEXP2() {
    char * lhs = "SEXP";
    char *rhs[] = {"-", "SEXP"};
    return createProduction(lhs, rhs);
}

static Production * createSEXP3() {
    char * lhs = "SEXP";
    char *rhs[] = {"true"};
    return createProduction(lhs, rhs);
}

static Production * createSEXP4() {
    char * lhs = "SEXP";
    char *rhs[] = {"false"};
    return createProduction(lhs, rhs);
}

static Production * createSEXP5() {
    char * lhs = "SEXP";
    char *rhs[] = {"num"};
    return createProduction(lhs, rhs);
}

static Production * createSEXP6() {
    char * lhs = "SEXP";
    char *rhs[] = {"null"};
    return createProduction(lhs, rhs);
}

static Production * createSEXP7() {
    char * lhs = "SEXP";
    char *rhs[] = {"PEXP", ".", "length"};
    return createProduction(lhs, rhs);
}

static Production * createSEXP8() {
    char * lhs = "SEXP";
    char *rhs[] = {"PEXP"};
    return createProduction(lhs, rhs);
}

static Production * createPEXP1() {
    char * lhs = "PEXP";
    char *rhs[] = {"id"};
    return createProduction(lhs, rhs);
}

static Production * createPEXP2() {
    char * lhs = "PEXP";
    char *rhs[] = {"this"};
    return createProduction(lhs, rhs);
}

static Production * createPEXP3() {
    char * lhs = "PEXP";
    char *rhs[] = {"new", "id", "(", ")"};
    return createProduction(lhs, rhs);
}

static Production * createPEXP4() {
    char * lhs = "PEXP";
    char *rhs[] = {"(", "EXP", ")"};
    return createProduction(lhs, rhs);
}

static Production * createPEXP5() {
    char * lhs = "PEXP";
    char *rhs[] = {"PEXP", ".", "id"};
    return createProduction(lhs, rhs);
}

static Production * createPEXP6() {
    char * lhs = "PEXP";
    char *rhs[] = {"PEXP", ".", "id", "(", ")"};
    return createProduction(lhs, rhs);
}

static Production * createPEXP7() {
    char * lhs = "PEXP";
    char *rhs[] = {"PEXP", ".", "id", "(", "EXPS", ")"};
    return createProduction(lhs, rhs);
}

static Production * createEXPS1() {
    char * lhs = "EXPS";
    char *rhs[] = {"EXP"};
    return createProduction(lhs, rhs);
}

static Production * createEXPS2() {
    char * lhs = "EXPS";
    char *rhs[] = {"EXP", "EXP_X"};
    return createProduction(lhs, rhs);
}

static Production * createEXP_X1() {
    char * lhs = "EXP_X";
    char *rhs[] = {",", "EXP"};
    return createProduction(lhs, rhs);
}

static Production * createEXP_X2() {
    char * lhs = "EXP_X";
    char *rhs[] = {",", "EXP", "EXP_X"};
    return createProduction(lhs, rhs);
}



// NEVER NEVER NEVER

static Production * createProduction(char *lhs, char **rhs) {
    Production *prod = (Production *)malloc(sizeof(Production));
    prod->lhs = lhs;
    prod->rhs = rhs;
    
    return prod;
}
