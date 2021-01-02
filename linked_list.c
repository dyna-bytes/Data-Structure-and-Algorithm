/********************************************
	Class: Data Structure and Algorithms, KECE208
		   fall, 2020

	1st Project: List
	linked_list.c

	Name:
	StudentID:
	E-mail:

**********************************************/

#include "linked_list.h"
#include "string.h"
extern int list_exist;

/*	
	@Function name:
	@Parameters:
	@Returns:	
	@Descriptions:	
	@Error cases:
 */

struct linked_list* create_list (int number_of_nodes, int list_type)
{
	int a[number_of_nodes];
	int i, j;
	int bFound;

	if (number_of_nodes < 1)
	{
		printf("Function create_list: the number of nodes is not specified correctly\n");
		return NULL;
	}
	if(list_exist == 1)
	{
		printf("Function create_list: a list already exists\nRestart a Program\n");
		exit(0);	
	}
	if(list_type != 0 && list_type != 1)
	{
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
	if(list_type == 0)
	{
		for ( i = 0; i < number_of_nodes; ++i )
		{
			while ( 1 )
			{
                    
				a[i] = rand() % number_of_nodes + 1;
				bFound = 0;
				for ( j = 0; j < i; ++j )
				{
					if ( a[j] == a[i] )
					{
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
	else if(list_type == 1)
	{
		for ( i = 0; i < number_of_nodes; ++i )
		{
			while ( 1 )
			{
                    
				a[i] = rand() % number_of_nodes + 1;
				bFound = 0;
				for ( j = 0; j < i; ++j )
				{
					if ( a[j] == a[i] )
					{
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

/*	
	@Function name:
	@Parameters:
	@Returns:	
	@Descriptions:	
	@Error cases:
*/
void remove_list(struct linked_list* list)
{
	//your code starts from here
	int deleted_nodes = 0;
	int deleted_node_value;
}

/*	
	@Function name:
	@Parameters:
	@Returns:	
	@Descriptions:	
	@Error cases:
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
	@Function name:
	@Parameters:
	@Returns:	
	@Descriptions:	
	@Error cases:
*/
void insert_node(struct linked_list* list, struct linked_node* node)
{
	node->next = NULL;
	node->prev = NULL;

	if(list->head == NULL)		//if head is NULL, tail is also NULL.
	{
		list->head = node;
		list->tail = node;
		list_exist = 1;
	}
	else if(list->head == list->tail)
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	else if(list->head != list->tail)
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	(list->number_of_nodes)++;
}
	
/*	
	@Function name:
	@Parameters:
	@Returns:	
	@Descriptions:	
	@Error cases:
 */
void remove_node(struct linked_list* list, int rm_node_value)
{
	struct linked_node * del_Node//your code starts from here
}

/*	
	@Function name:
	@Parameters:
	@Returns:	
	@Descriptions:	
	@Error cases:
 */
void push_Stack(struct linked_list* list, struct linked_node* node)
{
	//your code starts from here
	
}

/*	
	@Function name:
	@Parameters:
	@Returns:	
	@Descriptions:	
	@Error cases:
 */
void pop_Stack(struct linked_list* list, int number)
{
	//your code starts from here
}

/*	
	@Function name:
	@Parameters:
	@Returns:	
	@Descriptions:	
	@Error cases:
 */
void search_node(struct linked_list* list, int find_node_value)
{
	struct linked_node * temp_Node =//your code starts from here
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
	for(i=0; i < list->number_of_nodes; i++)
	{
		printf ("%d   ", temp->value);
		temp = temp->next;
	}
	printf("\n");
	printf("****************************************************************************\n\n");
	free(temp);
}

