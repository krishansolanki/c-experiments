//
//  linked_list.h
//  
//
//  Created by Krishan Solanki on 25/03/2016.
//
//

#ifndef ____linked_list__
#define ____linked_list__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#endif /* defined(____linked_list__) */

typedef struct node {
    int data;
    struct node *pNext;
} node;

int count(node *linkedNode)
{
    if(linkedNode == NULL)
        return(0);
    return(1 + count(linkedNode->pNext));
}