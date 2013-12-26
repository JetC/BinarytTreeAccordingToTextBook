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

//void destroyMyChildNodes(BinaryTreeNode *currentPosition);
void visitThisBinaryTreeNodeData(BinaryTreeNode a);


void binaryTreeInitiate(BinaryTreeNode **root)
{
    (*root)->leftChild = NULL;
    (*root)->rightChild = NULL;
}

BinaryTreeNode insertLeftChild(BinaryTreeNode *currentPosition,Datatype x)
{
    BinaryTreeNode *tempForLeftChild = NULL;
    if (currentPosition == NULL)
    {
        exit(233);
    }
    tempForLeftChild = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tempForLeftChild->data = x;
    tempForLeftChild->leftChild = NULL;
    tempForLeftChild->rightChild = NULL;
    
    currentPosition->leftChild = tempForLeftChild;
    tempForLeftChild = NULL;
    free(tempForLeftChild);
    return *(currentPosition->leftChild);
}


BinaryTreeNode insertRightChild(BinaryTreeNode *currentPosition,Datatype x)
{
    BinaryTreeNode *tempForRightChild;
    if (currentPosition == NULL)
    {
        exit(233);
    }

    tempForRightChild = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tempForRightChild->data = x;
    tempForRightChild->leftChild = NULL;
    tempForRightChild->rightChild = NULL;
    
    currentPosition->rightChild = tempForRightChild;
    tempForRightChild = NULL;
    free(tempForRightChild);
    return *(currentPosition->rightChild);
}

BinaryTreeNode deleteLeftChild(BinaryTreeNode *currentPosition)
{
    if (currentPosition == NULL || currentPosition->leftChild == NULL)
    {
        exit(234);
    }
    free(currentPosition->leftChild);
    currentPosition->leftChild = NULL;
    return *currentPosition;
}

BinaryTreeNode deleteRightChild(BinaryTreeNode *currentPosition)
{
    if (currentPosition == NULL || currentPosition->rightChild == NULL)
    {
        exit(234);
    }
    free(currentPosition->rightChild);
    currentPosition->rightChild = NULL;
    return *currentPosition;
}

void visitThisBinaryTreeNodeData(BinaryTreeNode a)
{
    printf("    %i\n",a.data);
}

void visitInPreOrder(BinaryTreeNode *t,void visitThisBinaryTreeNodeData(BinaryTreeNode item))
{
    if (t != NULL)
    {
        visitThisBinaryTreeNodeData(*t);
        visitInPreOrder(t->leftChild, visitThisBinaryTreeNodeData);
        visitInPreOrder(t->rightChild, visitThisBinaryTreeNodeData);

    }
    
}

void visitInInnerOrder(BinaryTreeNode *t, void visivisitThisBinaryTreeNodeData(BinaryTreeNode item))
{
    if (t != NULL)
    {
        visitInInnerOrder(t->leftChild, visitThisBinaryTreeNodeData);
        visitThisBinaryTreeNodeData(*t);
        visitInInnerOrder(t->rightChild, visivisitThisBinaryTreeNodeData);
    }
}

void visitInPostOrder(BinaryTreeNode *t, void visivisitThisBinaryTreeNodeData(BinaryTreeNode item))
{
    if (t != NULL)
    {
        visitInPostOrder(t->leftChild,visitThisBinaryTreeNodeData);
        visitInPostOrder(t->rightChild,visitThisBinaryTreeNodeData);
        visitThisBinaryTreeNodeData(*t);
    }

}

BinaryTreeNode * searchInBinaryTree(BinaryTreeNode *bt, Datatype x)
{
    BinaryTreeNode *p;
    if (bt == NULL)
    {
        return NULL;
    }
    if (bt->data == x)
    {
        return  bt;
    }
    if (bt->leftChild != NULL)
    {
        p = searchInBinaryTree(bt->leftChild, x);
        if (p != NULL)
        {
            return p;
        }
    }
    if (bt->rightChild != NULL)
    {
        p = searchInBinaryTree(bt->leftChild, x);
        if (p != NULL)
        {
            return p;
        }
    }
    return NULL;
}



int main(int argc, const char * argv[])
{
    long val;
    BinaryTreeNode *rootForBinaryTree;//建立根节点
    rootForBinaryTree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));//分配内存空间
    binaryTreeInitiate(&rootForBinaryTree);//初始化子节点
    
    insertLeftChild(rootForBinaryTree, 5);//子一级左节点
    insertLeftChild(rootForBinaryTree->leftChild, 8);//子二级左节点
    insertRightChild(rootForBinaryTree, 90);//子一级右节点
//    deleteLeftChild(rootForBinaryTree->leftChild);
//    deleteRightChild(rootForBinaryTree);
//    visitThisBinaryTreeNodeData(*(rootForBinaryTree)->leftChild);
    
    printf("Visit in PRE order starts!\n");
    visitInPreOrder(rootForBinaryTree, visitThisBinaryTreeNodeData );
    printf("Visit in PRE order ends!\n\n");

    printf("Visit in INNER order starts!\n");
    visitInInnerOrder(rootForBinaryTree, visitThisBinaryTreeNodeData);
    printf("Visit in INNER order ends!\n\n");

    printf("Visit in POST order ends!\n");
    visitInPostOrder(rootForBinaryTree,visitThisBinaryTreeNodeData);
    printf("Visit in POST order ends!\n");

    rootForBinaryTree->leftChild = searchInBinaryTree(rootForBinaryTree, 90);
    
    
    free(rootForBinaryTree);
    return 0;
}




























