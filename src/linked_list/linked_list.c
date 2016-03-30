//
//  linked_list.c
//  
//
//  Created by Krishan Solanki on 25/03/2016.
//
//

#include "linked_list.h"

static struct node *createNode(int data) {
    struct node *pTempNode;
    pTempNode = malloc(sizeof(struct node));
    
        pTempNode->data = data;

    pTempNode->pLink = NULL;
    
    return pTempNode;
}

struct node *createHeadNode() {
    return createNode(0);
}

void addNodeToList(node *head, int data) {
    struct node *pTemp = createNode(data);
    struct node *pCurrent = head;
    
    while(pCurrent->pLink) {
        pCurrent = pCurrent->pLink;
    }
    
    pCurrent->pLink = pTemp;
}

int count(node *temp)
{
    if(temp == NULL)
        return(0);
    return(1 + count(temp->pLink));
}



