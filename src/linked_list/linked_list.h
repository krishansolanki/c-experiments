//
//  linked_list.h
//  
//
//  Created by Krishan Solanki on 25/03/2016.
//
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


typedef struct Node {
    int data;
    struct Node *pNext;
} Node;

struct Node *
linked_list_create();

void
linked_list_add(Node *head, int data);

void
linked_list_delete(Node *pHead, int position);

int
linked_list_count(Node *linkedNode);

#endif