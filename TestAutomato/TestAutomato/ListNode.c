//
//  ListNode.c
//  TestAutomato
//
//  Created by Rodrigo Soldi Lopes on 25/10/16.
//  Copyright © 2016 Kaique Damato. All rights reserved.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <stdio.h>

// Data Structures -------

typedef struct listNode {
    char *lexeme;
    char *class;
    char *parameter;
    int finalState;
    struct listNode *next;
} ListNode;

typedef struct list {
    int count;
    ListNode *head;
} List;



// Prototypes -----

static void printListNode(ListNode *listNode);



// Functions ----

static List * createList() {
    
    List *list = (List *)malloc(sizeof(List));
    list->count = 0;
    list->head = NULL;
    
    return list;
}

static void printList(List *list) {
    printf("\n\n\n*****************\n");
    ListNode *aux = list->head;
    while (aux->next != NULL) {
        printListNode(aux);
        aux = aux->next;
    }
    
    printf("*****************\n\n\n");
}

static ListNode * createNode(char *lex) {
    
    ListNode *listNode = (ListNode *)malloc(sizeof(ListNode));
    listNode->lexeme = lex;
    listNode->class = NULL;
    listNode->parameter = NULL;
    listNode->next = NULL;
    listNode->finalState = -1;
    
    return listNode;
}

static void printListNode(ListNode *listNode) {
    
    
    printf("-----\n");
    
    if (listNode->lexeme != NULL) {
        printf("Lexeme: %s\n", listNode->lexeme);
    }
    
    if (listNode->class != NULL) {
        printf("Class: %s\n", listNode->class);
    }
    
    if (listNode->parameter != NULL) {
        printf("Parameter: %s\n", listNode->parameter);
    }
    
    printf("-----\n");
    
}

static void addListNode(List *list, ListNode *listNode) {
    
    if (list->count == 0) {
        list->head = listNode;
    } else {
        ListNode *aux = list->head;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = listNode;
    }
    list->count++;
}

//ListNode *ln = (ListNode *) malloc (sizeof(ListNode));
