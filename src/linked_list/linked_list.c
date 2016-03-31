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
    pTempNode->pNext = NULL;
    
    return pTempNode;
}

struct node *createHeadNode() {
    return createNode(0);
}

void addNodeToList(node *head, int data) {
    struct node *pTemp = createNode(data);
    struct node *pCurrent = head;
    
    while(pCurrent->pNext) {
        pCurrent = pCurrent->pNext;
    }
    
    pCurrent->pNext = pTemp;
}

void deleteNode(node *pHead, int position) {
    struct node *pTemp = pHead;
    struct node *pPrev;
    int nodeCount = count(pTemp);
    
    if(position > 0 && position <= nodeCount) {
        for (int i = 0; i < position; i++) {
            if (i == (position-1)) {
                pPrev = pTemp;
                pTemp = pTemp->pNext;
                pPrev->pNext = pTemp->pNext;
                free(pTemp);
            }else {
                pTemp = pTemp->pNext;
            }
        }
    }
}



