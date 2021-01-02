/********************************************
	Class: Data Structure and Algorithms
	Project 2: Binary Search Tree

	project2.c

	Name:
	StudentID:
	E-mail:

**********************************************/

#include "BST.h"
treeNode rootNode;

int main(void)
{
	char inputMenu[100];
	char inputData;

	int menu = 0;

	while (1)
	{
		printf("\n-----------------------\n");
		printf("1. Insert a Node\n"); 
		printf("2. Find a Node\n");
		printf("3. Find minimum value\n");
		printf("4. Show the height of tree\n");
		printf("0. Exit\n");
		printf("-----------------------\n");
		printf("->");

		fgets(inputMenu, 100, stdin);
		menu = atoi(inputMenu);

		switch (menu) {

		case 1:
			printf("Type the value to insert\n");
			printf("->");
			fgets(&inputData, 3, stdin);

			insertNode(inputData);

			break;

		case 2:
			printf("Type the node id to find\n");
			printf("->");
			fgets(&inputData, 3, stdin);

			findNode(inputData);

			break;

		case 3:
			findMin(rootNode);

			break;

		case 4:
			findHeight();

			break;

		case 0:
			exit(0);

			break;

		default:
			printf("Input should be 0-4\n");
			break;
		}
	}


	return 0;
}
