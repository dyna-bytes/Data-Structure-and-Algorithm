/********************************************
	Class: Data Structure and Algorithms
	Project 2: Binary Search Tree

	BST.h

	Name:
	StudentID:
	E-mail:

**********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct bstNode* treeNode;

struct bstNode {
	char data;
	treeNode parentNode;
	treeNode leftNode;
	treeNode rightNode;
};

extern treeNode rootNode;

treeNode createNode(char inputData);

int insertNode(char inputData);
int isNodeExist(char inputData);
treeNode findPosition(char inputData, treeNode node);
int findDepth(char inputData);
treeNode findMin(treeNode node);
int findNode(char inputData);
int findHeight(void);