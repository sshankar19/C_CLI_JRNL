//
//  avltree.h
//  
//
//  Created by Shashank Shankar on 10/14/14.
//
//

#ifndef ____avltree__
#define ____avltree__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

typedef struct Entry {
    char* dataEntry;
    struct tm * timeStamp;
    char* (*getTimeAsString) (struct Entry*);
    char* (*getMessage) (struct Entry*);
}Entry;

typedef struct AVLNode {
    struct AVLNode* left;
    struct AVLNode* right;
    struct AVLNode* parent; // Do I really need this?
    struct Entry* jrnlEntry;
    int leftHeight;
    int rightHeight;
    int (*balanceFactor) (struct AVLNode*);
}Node;

typedef struct AVLTree {
    Node* root;
    void(*insert) (struct AVLTree*, Node*);
    void(*delete) (struct AVLTree*, Node*);
    void (*find) (struct AVLTree*, Node*);
    int size;
}AVL;



void createEntry (Entry* entry, char* message); //Set function pointers and set the time and stuff

void createNode( Node* node, char* message);

void createAVL (AVL* tree);

char* getTimeAsString(Entry*, struct tm*);

char* getMessage(Entry*);

int balanceFactor(Node*);

void insert (AVL*, Node*);

void find (AVL*, Node*);


#endif /* defined(____avltree__) */
