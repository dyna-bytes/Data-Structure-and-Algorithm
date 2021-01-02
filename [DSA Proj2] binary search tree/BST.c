/********************************************
 Class: Data Structure and Algorithms
 Project 2: Binary Search Tree

 BST.c

 Name:		Park Ji Hyuk
 StudentID:	2016160145
 E-mail:	wlgur1023@naver.com

 **********************************************/
#include "BST.h"
/*
@Function name:	createNode
@Parameters:	inputData
@Descriptions:	creates new node with input data and returns the pointer of created bstNode structure
@Error cases:	
	If the input data is not ACSII small letter, the function prints error message.
	If the the function failed with allocation of memory, it prints error message and returns NULL.
*/
treeNode createNode(char inputData)
{
	if (inputData < 97 || inputData > 122) {
		printf("Type of inputData is wrong\n");
		return NULL;
	}
	treeNode newNode;

	if ((newNode = (treeNode)malloc(sizeof(struct bstNode))) == NULL) {
		printf("Node creation is failed\n");
		return NULL;
	}
	newNode->data = inputData;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	newNode->parentNode = NULL;

	return newNode;
}

/*
@Function name:	insertNode
@Parameters:	inputData
@Descriptions:	This function inserts a new node to BST. If there is no root node, it should put the node as a root node.
@Error cases:	
	If duplication of data is happened or node creation failed, it prints error message and return 0.
*/
int insertNode(char inputData) 
{
	treeNode existNode, bufNode;
	treeNode newNode;
	printf("%c is put\n", inputData);
	if((newNode = createNode(inputData)) == NULL){
		printf("creating a node is failed\n");
		return 0;
	}

	if(rootNode == NULL){     //if there is no root node
		rootNode = newNode;  //put the new node as root node
		printf("%c is inserted successfully\n", newNode->data);
		return 0;
	}
	
	int foundLeft = 0;
	for(existNode = rootNode; existNode != NULL; ){
		bufNode = existNode;
		if(inputData == existNode->data){
			printf("data is duplicated\n");
			return 0;
		}
		else if(inputData < existNode->data){
			existNode = existNode->leftNode;
			foundLeft = 1;
		}
		else if(inputData > existNode->data){
			existNode = existNode->rightNode;
			foundLeft = 0;
		}
	}
	newNode->parentNode = bufNode;
	if(foundLeft) bufNode->leftNode = newNode;
	else bufNode->rightNode = newNode;
	printf("%c is inserted successfully\n", newNode->data);
	return 0;	
}

/*
@Function name:	isNodeExist
@Parameters:	inputData
@Descriptions:	This function checks the tree with input data. If there is a node which data is inputData, it returns 1.
@Error cases:	If node is empty or node is not in the tree, it prints error message and returns 0.
*/
int isNodeExist(char inputData)
{
	treeNode existNode;
	if(rootNode == NULL){
		printf("Tree is empty\n");
		return 0;
	}
	for(existNode = rootNode; existNode != NULL; ){
		if(inputData == existNode->data)
			return 1;
		else if(inputData < existNode->data)
			existNode = existNode->leftNode;
		else if(inputData > existNode->data)
			existNode = existNode->rightNode;
	}
	printf("%c is not in the tree\n", inputData);
	return 0;	
}

/*
@Function name:	findPosition
@Parameters:	inputData, node
@Descriptions:	This function finds and returns the node that is the nearest node with the given data or the exactly matched node.
@Error cases:	none.
*/
treeNode findPosition(char inputData, treeNode node)
{
	if(inputData == node->data) return node;
	else if(node->leftNode == NULL && node->rightNode == NULL) return node; //if the node reached to a leaf node, return the leaf node
	
	if(inputData < node->data){
		treeNode leftSubtree = findPosition(inputData, node->leftNode);
		int minDistReturnedFromSubtree = inputData - leftSubtree->data > 0 ? inputData - leftSubtree->data : -(inputData - leftSubtree->data);//abs value
		int distToCurrentNode = inputData - node->data > 0 ? inputData - node->data : -(inputData - node->data);//abs value
		
		if(minDistReturnedFromSubtree > distToCurrentNode) return node; //if distance from inputData to current node is closer than minimum distance, return current node
		else return leftSubtree;
	}
	else{ //if(inputData > node->data)
		treeNode rightSubtree = findPosition(inputData, node->rightNode);
		int minDistReturnedFromSubtree = inputData - rightSubtree->data > 0 ? inputData - rightSubtree->data : -(inputData - rightSubtree->data);//abs value
		int distToCurrentNode = inputData - node->data > 0 ? inputData - node->data : -(inputData - node->data);//abs value
		
		if(minDistReturnedFromSubtree > distToCurrentNode) return node;
		else return rightSubtree;
	}
}

/*
@Function name:	findDepth
@Parameters:	inputData
@Descriptions:	This function finds a node that has inputData, and then calculates depth of the node.
@Error cases:	It should return 0 when there is no matched node with inputData.
*/
int findDepth(char inputData)
{
	if(!isNodeExist(inputData))	return 0;
	
	int depth = -1;
	treeNode existNode;
	for(existNode = rootNode; existNode != NULL; ){
		depth++;
		if(inputData == existNode->data)
			break;
		else if(inputData < existNode->data)
			existNode = existNode->leftNode;
		else if(inputData > existNode->data)
			existNode = existNode->rightNode;
	}
	return depth;
}

/*
@Function name:	findMin
@Parameters:	node
@Descriptions:	This function finds a node that has the minimum value as data in the subtree.
				It returns the pointer of the node that has minimum value in the subtree.
@Error cases:	none.
*/
treeNode findMin(treeNode node)
{
	if(node == NULL){
		printf("Tree is empty\n");
		return NULL;
	}
	
	treeNode existNode;
	for(existNode = node; existNode->leftNode != NULL; existNode = existNode->leftNode)
	;
	printf("minimum value : %c\n", existNode->data);
	return existNode;
}

/*
@Function name:	findNode
@Parameters:	inputData
@Descriptions:	
	This function finds a node that has inputData.
	It prints the data of parent node, left child node, right child node, and the depth of the node.
@Error cases:	If the tree is empty or the node is not in thetree, it prints error message 
*/
int findNode(char inputData) 
{
	if(!isNodeExist(inputData))	return 0;
	
	treeNode position = findPosition(inputData, rootNode);
	
	if(position->parentNode != NULL)
	    printf("Parent node is %c\n", position->parentNode->data);
	else
		printf("Parent node is NULL\n");
	if(position->leftNode != NULL)
	    printf("Left child node is %c\n", position->leftNode->data);
	else
	    printf("Left child node is NULL\n");
	if(position->rightNode != NULL)
	    printf("Right child node is %c\n", position->rightNode->data);
	else
	    printf("Right child node is NULL\n");
	    
	printf("Depth of %c is %d\n", inputData, findDepth(inputData));
	
	return 1;
}

/*
@Function name:	findHeight
@Parameters:	none
@Descriptions:	This function finds the height of tree.
@Error cases:	It returns -1 when there is no tree.
*/
int findHeight(void) 
{
	if(rootNode == NULL){
		printf("Tree is empty\n");
		return -1;
	}
	
	char input;
	int height = -1;
	treeNode existNode;
	
	for(input = 'a'; input <= 'z'; input++){
		for(existNode = rootNode; existNode != NULL; ){
			if(input == existNode->data){
				if(height < findDepth(input))
					height = findDepth(input);
				break;
			}
			else if(input < existNode->data)
				existNode = existNode->leftNode;
			else if(input > existNode->data)
				existNode = existNode->rightNode;
		}
	}
	
	printf("The height of tree is %d\n", height);
	return height;
}
