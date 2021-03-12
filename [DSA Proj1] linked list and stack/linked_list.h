/********************************************
	Class: Data Structure and Algorithms, KECE208
		   fall, 2020

	1st Project: List
	linked_list.h

	Name:
	StudentID:
	E-mail:

**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct linked_node{
	int value;
	struct linked_node* next;
	struct linked_node* prev;
};

struct linked_list{
	int type_of_list; // normal = 0, stack = 1
	struct linked_node* head;
	struct linked_node* tail;
	int number_of_nodes;
};

//shows whether the list is exist or not
int list_exist;

//create or remove a list
struct linked_list* create_list (int number_of_nodes, int list_type);
void remove_list(struct linked_list* list);

//create a new node
struct linked_node* create_node (int node_value);

//remove or insert node at proper place
void insert_node(struct linked_list* list, struct linked_node* node);
void remove_node(struct linked_list* list, int rm_node_value);
void push_Stack(struct linked_list* list, struct linked_node* node);
void pop_Stack(struct linked_list* list, int number);

//find a specific node
void search_node(struct linked_list* list, int find_node_value);

//print out the list
void print_list(struct linked_list* list);

//delete whole nodes and list
void remove_list(struct linked_list* list);


