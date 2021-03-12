/********************************************
	Class: Data Structure and Algorithms, KECE208
		   fall, 2020

	1st Project: List
	linked_list.c

	Name:Park Jihyuk
	StudentID:2016160145
	E-mail:wlgur1023@naver.com

**********************************************/

#include "linked_list.h"
#include "string.h"
int list_exist;

/*	
	@Function name: create_list
	@Parameters:    number_of_nodes, list_type
	@Returns:       new_list
	@Descriptions: This function gets the parameter by number of nodes and list type, and creates list. 
		If list type is 0, the function creates linked list, and if list type is 1, then the function creates stack.
		The type of return is struct linked_list*, which means this function returns the address of the first node of the list.
	@Error cases:
		1. If the input is less than 1, it prints error message ¡°Function create_list: the number of nodes is not specified correctly
		and exit the function.
		2. If a list already exists, then it prints the error message ¡°Function create_list: a list already exists¡± and exit the function.
		3. If  the input value for the type is not 0 or 1, it should print the error message ¡°Function create_list: the list type is wrong¡±. 
 */

struct linked_list* create_list (int number_of_nodes, int list_type)
{
	int a[number_of_nodes];
	int i, j;
	int bFound;

	if (number_of_nodes < 1){
		printf("Function create_list: the number of nodes is not specified correctly\n");
		return NULL;
	}
	if(list_exist == 1){
		printf("Function create_list: a list already exists\nRestart a Program\n");
		exit(0);	
	}
	if(list_type != 0 && list_type != 1){
		printf("Function create_list: the list type is wrong\n");
		exit(0);	
	}
	struct linked_list * new_list = (struct linked_list*)malloc(sizeof(struct linked_list));
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->number_of_nodes = 0;
	new_list->type_of_list = list_type;

	//now put nodes into the list with random numbers.
	srand((unsigned int)time(NULL));
	if(list_type == 0){
		for ( i = 0; i < number_of_nodes; ++i )	{
			while ( 1 ){
                    
				a[i] = rand() % number_of_nodes + 1;
				bFound = 0;
				for ( j = 0; j < i; ++j ){
					if ( a[j] == a[i] ){
						bFound = 1;
						break;
					}
				}
				if ( !bFound )
					break;
			}
			struct linked_node* new_node = create_node(a[i]);
			insert_node(new_list, new_node);
		}
	}
	else if(list_type == 1)	{
		for ( i = 0; i < number_of_nodes; ++i )	{
			while ( 1 ){
                    
				a[i] = rand() % number_of_nodes + 1;
				bFound = 0;
				for ( j = 0; j < i; ++j ){
					if ( a[j] == a[i] ){
						bFound = 1;
						break;
					}
				}
				if ( !bFound )
					break;
			}
			struct linked_node* new_node = create_node(a[i]);
			push_Stack(new_list, new_node);
		}
	}
	list_exist = 1;
	printf("List is created!\n");
	return new_list;
}

void RemoveFront(struct linked_list* list){				/*deletes the first node and moves head to the second node*/	
	if(list->head != NULL){
		if(list->head == list->tail){						//if the list has only one node,
			struct linked_node *ptr = list->head;
			
			free(ptr);										//free the node
			list->head = list->tail = NULL;					//and make list to initial form.
		}
		else{												//else
			struct linked_node *ptr = list->head, *nxt = (list->head)->next;			
			
			nxt->prev = NULL;
			free(ptr);										//free the first node
			list->head = nxt; 								//assign the next node to new head node.
		}
		(list->number_of_nodes)--;
	}
}

void RemoveRear(struct linked_list* list){				/*deletes the last node and moves tail to the previous node*/
	if(list->head != NULL){
		if(list->number_of_nodes == 1) RemoveFront(list);	//if the list has only one node, it's same with RemoveFront;
		else{
			struct linked_node* ptr = list->tail, *pre = (list->tail)->prev;
			pre->next = NULL;
			free(ptr);										//free the last node
			list->tail = pre; 								//assign the previous node to new tail node.
			(list->number_of_nodes)--;
		}	
	}
}


/*	
	@Function name: remove_list
	@Parameters:    list
	@Returns:	    None
	@Descriptions:    This function removes the list with freeing every nodes separately.
		For every deletion of a node, this function prints message ¡°The node with value n (corresponding value) is deleted!¡±
		and  if the whole list is deleted, it prints message ¡°The list is completely deleted: n nodes are deleted¡±
	@Error cases:    None
*/
void remove_list(struct linked_list* list)
{
	//your code starts from here
	int deleted_nodes = 0;
	int deleted_node_value;

	//if(list_exist == 0){ printf("No list exist to remove/n"); return;}  //error case for list extistance
	
	if(list_exist == 1){
		if(list->type_of_list == 0)			//if data is the linked list,
			while(list->number_of_nodes != 0){
				printf("The node with value %d is deleted!\n", deleted_node_value = list->head->value);
				RemoveFront(list);			//remove the node from the front.
				deleted_nodes++;
			}
		else if(list->type_of_list == 1)	//if data is the stack,
			while(list->number_of_nodes != 0){
				printf("The node with value %d is deleted!\n", deleted_node_value = list->tail->value);
				RemoveRear(list);			//remove the node from the rear.
				deleted_nodes++;
			}
	
		free(list->head), free(list->tail), free(list);		//free the list pointers for sure
		printf("The list is completely deleted: %d nodes are deleted\n", deleted_nodes);
		list_exist = 0;
	}	
}

/*	
	@Function name: create_node
	@Parameters:    node_value
	@Returns:	    node
	@Descriptions:    By using structure of linked_node, this function allocates the memory space of sturcture for a pointer.
		And assign values for the components or the pointer.
		As *node.next & *node.prev are the self-referencing structure, we have to assign NULL pointer for initialization of address value.
	@Error cases:	none
 */
struct linked_node* create_node (int node_value)
{
	struct linked_node* node = (struct linked_node*)malloc(sizeof(struct linked_node));
	node->value = node_value;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

/*	
	@Function name: insert_node
	@Parameters:    list, node
	@Returns:	    none
	@Descriptions:	This function inserts node in the front of the list, and has three cases for node insertion.
		1. If the list is empty
		2. If the list has only one node
		3. If the list has more than two nodes
	@Error cases:    none
*/
void insert_node(struct linked_list* list, struct linked_node* node)		//insert node in the front of list
{
	node->next = NULL;
	node->prev = NULL;

	if(list->head == NULL)				//if head is NULL, tail is also NULL.
	{
		list->head = node;
		list->tail = node;
		list_exist = 1;
	}
	else if(list->head == list->tail)	//if the list has only one node
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	else if(list->head != list->tail)	//if the list has more than two nodes
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	(list->number_of_nodes)++;
}
	
/*	
	@Function name: remove_node
	@Parameters:    list, node
	@Returns:	    none
	@Descriptions:	searches rm_node_value in the list, and deletes the searched node from list.
	@Error cases:
	    1. if the list type is stack, print "Function remove_node: The list type is not normal. Removal is not allowed" and  exit the function
	    2. if the rm_node_value is not seached,print "Function remove_node:There is no such node to remove and  exit the function
 */
void remove_node(struct linked_list* list, int rm_node_value)
{
	if (list->type_of_list == 1){
		printf("Function remove_node: The list type is not normal. Removal is not allowed\n");
		return;
	}

	struct linked_node* del_Node = (struct linked_node*)malloc(sizeof(struct linked_node)); 
	struct linked_node* ptr = (struct linked_node*)malloc(sizeof(struct linked_node));
	
	for(del_Node = list->head; del_Node != NULL; del_Node = del_Node->next)			//search rm_node_value in list
		if(del_Node->value == rm_node_value) break;

	if(del_Node == NULL){
		printf("Function remove_node:There is no such node to remove\n");
		return;
	}
	
	if(list->head != NULL){
		if(del_Node == list->head)		//if rm_node is the first node,
			RemoveFront(list);			//deletes the first node from list.
		else if(del_Node == list->tail) //if rm_node is the last node,
			RemoveRear(list);			//deletes the last node from list.
		else{
			ptr = del_Node->prev;
			ptr->next = del_Node->next;
			free(del_Node);
			(list->number_of_nodes)--;
		}
	}
	
	if(list->number_of_nodes == 0){
		free(list->head), free(list->tail), free(list);
		list_exist = 0;
	}
}

/*	
	@Function name:push_Stack
	@Parameters:   list, node
	@Return:       none
	@Descriptions: insert new nodeto stack. it's actually the reverse version of insert_node
	@Error cases:
	    if the data type is not stack, print "Function push_Stack: The list type is not a stack" and exit the function
 */
void push_Stack(struct linked_list* list, struct linked_node* node)  //reverse version of insert_node
{
	//your code starts from here
	if(list->type_of_list == 0) {
		printf("Function push_Stack: The list type is not a stack");
		return;
	}

	node->next = NULL;
	node->prev = NULL;

	if(list->head == NULL)				//if head is NULL, tail is also NULL.
	{
		list->head = node;
		list->tail = node;
		list_exist = 1;
	}
	else if(list->head == list->tail)	//if only one node existed
	{
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	else if(list->head != list->tail)	//if more than two node existed
	{
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	(list->number_of_nodes)++;
	
}

/*	
	@Function name: pop_Stack
	@Parameters:    list, number
	@Returns:       none
	@Descriptions:  Deletes nodes from the stack. This function removes the tail of the list repeatedly for the "number" times.
	@Error cases:
	    1. if the data type is not stack, print "Function push_Stack: The list type is not a stack" and exit the function
	    2. if the input number is small than 1, print "Function popStack: The number of nodes which will be removed is more than 1"  and exit function
	    3. if the input number is larger than the number_of_nodes, print "Function popStack: The number of nodes which will be removed is more than that in the stack"
        and exit function
*/
void pop_Stack(struct linked_list* list, int number)
{
	//your code starts from here
	if(list->type_of_list == 0){
		printf("Function push_Stack: The list type is not a stack");
		return;
	}
	if(number < 1){
		printf("Function popStack: The number of nodes which will be removed is more than 1");
		return;
	}
	if(number > list->number_of_nodes){
		printf("Function popStack: The number of nodes which will be removed is more than that in the stack");
		return;
	}
	
	else if(list_exist == 1){
		for(; number; number--) RemoveRear(list);
		
		if(list->number_of_nodes == 0){
			free(list->head), free(list->tail), free(list);
			list_exist = 0;
		}
	}
	
}

/*	
	@Function name: search_node
	@Parameters:    list, find_node_value
	@Returns:	    none
	@Descriptions:	searches node from the list which has same value with find_node_list. 
	    If the node is found, the function prints "The order of (node_value) is (order)."
	@Error cases:
	    If the node is not found, the function prints "Function search_node : There is no such node to search." and exit function.
 */
void search_node(struct linked_list* list, int find_node_value)
{
	//struct linked_node * temp_Node =//your code starts from here
	struct linked_node* ptr = (struct linked_node*)malloc(sizeof(struct linked_node));
	int order = 1;		//order starts from 1
	
	for(ptr = list->head; ptr != NULL; ptr = ptr->next, order++)	//search find_node_value in list
		if(ptr->value == find_node_value){
			printf("The order of %d is %d.\n", find_node_value, order);
			break;
		}
		
	if(ptr == NULL){
		printf("Function search_node : There is no such node to search.\n");
		return;
	}
}


/*	
	@Function name: print_list
	@Parameters:	list
	@Returns:		none
	@Descriptions:	This function prints the list in proper looking way
	@Error cases:	none. Even if the list is empty, it still prints the list
 */
void print_list(struct linked_list* list)
{
	if(list_exist == 0)
	{
		printf("There is no list to print\n");
		return;
	}
	struct linked_node * temp = list->head;
	printf("****************************************************************************\n\n");
	printf("	Number of nodes: %d\n", list->number_of_nodes);
	printf("\n");
	int i=0;
	for(i=0; i < list->number_of_nodes; i++)  //
	{
		printf ("%d   ", temp->value);
		temp = temp->next;
		
	}
	printf("\n");
	printf("****************************************************************************\n\n");
	free(temp);
}

