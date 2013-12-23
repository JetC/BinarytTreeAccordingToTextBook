//
//  main.c
//  BinarytTreeAccordingToTextBook
//
//  Created by 孙培峰 on 1312/23/.
//  Copyright (c) 2013 孙培峰. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Datatype;

typedef struct BinaryTreeNode{
    Datatype data;
    struct BinaryTreeNode *leftChild;
    struct BinaryTreeNode *rightChild;
    
}BinaryTreeNode;

void binaryTreeInitiate(BinaryTreeNode **root)
{
    *root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    (*root)->leftChild = NULL;
    (*root)->rightChild = NULL;
}

BinaryTreeNode insertLeftChild(BinaryTreeNode *currentPosition,Datatype x)
{
    BinaryTreeNode *tempForLeftChild = NULL,*tempForSavingAddress = NULL;
    if (currentPosition == NULL)
    {
        exit(233);
    }
    tempForSavingAddress = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tempForSavingAddress = currentPosition->leftChild;
    
    tempForLeftChild = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tempForLeftChild->data = x;
    tempForLeftChild->leftChild = NULL;
    tempForLeftChild->rightChild = NULL;
    
    currentPosition->leftChild = tempForLeftChild;
    return *(currentPosition->leftChild);
}


BinaryTreeNode insertRightChild(BinaryTreeNode *currentPosition,Datatype x)
{
    BinaryTreeNode *tempForRightChild, *tempForSavingAddress;
    if (currentPosition == NULL)
    {
        exit(233);
    }
    tempForSavingAddress = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tempForSavingAddress = currentPosition->leftChild;
    
    tempForRightChild = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tempForRightChild->data = x;
    tempForRightChild->leftChild = NULL;
    tempForRightChild->rightChild = NULL;
    
    currentPosition->rightChild = tempForRightChild;
    return *(currentPosition->rightChild);
}

BinaryTreeNode deleteLeftChild(BinaryTreeNode *currentPosition, Datatype x)
{
    if (currentPosition == NULL || currentPosition->leftChild == NULL)
    {
        exit(234);
    }
    
}

void destroyMyLChildNodes(BinaryTreeNode *currentPosition)
{
    BinaryTreeNode *p, *q;
    p = currentPosition->leftChild;
    while (p->leftChild != NULL)
    {
        q = p->leftChild;
        p->leftChild = NULL;
//TODO:Start Here!
    }
    
}

int main(int argc, const char * argv[])
{
    BinaryTreeNode *rootForBinaryTree;
    rootForBinaryTree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    binaryTreeInitiate(&rootForBinaryTree);
    insertLeftChild(rootForBinaryTree, 5);
    
    return 0;
}




























