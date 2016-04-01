//
//  linked_list.c
//  
//
//  Created by Krishan Solanki on 25/03/2016.
//
//

#include "linked_list.h"

static struct node *
create(int data);

struct node *
linked_list_create() {
    return create(0);
}

void
linked_list_add(node *head, int data) {
    struct node *pTemp = create(data);
    struct node *pCurrent = head;
    
    while(pCurrent->pNext) {
        pCurrent = pCurrent->pNext;
    }
    
    pCurrent->pNext = pTemp;
}

void
linked_list_delete(Node *pHead, int position) {
    struct Node *pTemp = pHead;
    struct Node *pPrev;
    int nodeCount = linked_list_count(pTemp);
    
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

int
linked_list_count(Node *linkedNode)
{
    if(linkedNode == NULL) {
        return(0);
    }
    
    return(1 + linked_list_count(linkedNode->pNext));
}

static struct Node *
create(int data) {
    struct Node *pTempNode;
    pTempNode = malloc(sizeof(struct Node));
    
    pTempNode->data = data;
    
    pTempNode->pNext = NULL;
    
    return pTempNode;
}



