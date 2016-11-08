//
//  Sintatic.c
//  TestAutomato
//
//  Created by Kaique Damato on 11/6/16.
//  Copyright © 2016 Kaique Damato. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//void MAIN();
//void PROG();
//void var_x();
//int var_y();
//int tipo();
//int tipo1();
//int consume(char *token);
//void consumeAux(char *token);
//
//ListNode *aux;
//
//void PROG() {
//    aux = LIST->head;
//    MAIN();
//}
//
//void MAIN() {
//    consumeAux("class");
//    consumeAux("ID");
//    consumeAux("{");
//    consumeAux("public");
//    consumeAux("static");
//    consumeAux("void");
//    consumeAux("main");
//    consumeAux("(");
//    consumeAux("String");
//    consumeAux("[");
//    consumeAux("]");
//    consumeAux("ID");
//    consumeAux(")");
//    consumeAux("{");
//    var_x();
//    consumeAux("}");
//    consumeAux("}");
//}
//
//void var_x() {
//    while (var_y()) {}
//}
//
//int var_y() {
//    if (tipo()) {
//        consumeAux("ID");
//        consumeAux(";");
//        return 1;
//    }
//    
//    return 0;
//}
//
//int tipo() {
//    if (consume("boolean")) {
//        return 1;
//    } else if (consume("ID")) {
//        return 1;
//    } else if (consume("int")) {
//        return tipo1();
//    }
//    return 0;
//}
//
//int tipo1() {
//    if (consume("[")) {
//        if (!consume("]")) {
//            printf("Deu ruim no tipo1");
//            exit(1);
//        }
//    }
//    return 1;
//}
//
//int consume(char *token) {
//    if ((strcmp(aux->lexeme, token) == 0) || (strcmp(aux->class, token) == 0)) {
//        aux = aux->next;
//        return 1;
//    }
//    
//    return 0;
//}
//
//void consumeAux(char *token) {
//    if ((strcmp(aux->lexeme, token) == 0) || (strcmp(aux->class, token) == 0)) {
//        aux = aux->next;
//    } else {
//        printf("Deu ruim no consumeAux, achou: %s, tentou consumir: %s\n", aux->lexeme, token);
//        exit(1);
//    }
//}
