//
//  linked_list.c
//  
//
//  Created by Krishan Solanki on 25/03/2016.
//
//

#include "linked_list.h"

struct node *createNode( int data) {
    struct node *pTempNode;
    pTempNode = malloc(sizeof(struct node));
    pTempNode->data = data;
    pTempNode->pLink = NULL;
    
    return pTempNode;
}

