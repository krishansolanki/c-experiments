//
//  linked_list.c
//  
//
//  Created by Krishan Solanki on 25/03/2016.
//
//

#include "linked_list.h"

typedef struct node {
    int data;
    struct node *pLink;
} node;


struct node *createNode( int data) {
    struct node *pTemp;
    pTemp = malloc(sizeof(struct node));
    pTemp->data = data;
    pTemp->pLink = NULL;
    
    return pTemp;
}


int count_list(node *pHead) {
}

