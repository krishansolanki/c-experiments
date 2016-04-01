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


typedef struct {
    int data;
    struct Node *pNext;
} Node;

static struct Node *
create(int data);

static struct Node *
linked_list_create(int data);

int
linked_list_count(Node *linkedNode);