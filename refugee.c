#include "refugee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void init_refugee(char* userid, char* name, char* profession, int age, Refugee **new_refugee) 
{
    Refugee* usersR = (Refugee*) malloc(sizeof(Refugee));

    strcpy(usersR->userid, userid);
	strcpy(usersR->name, name);
	strcpy(usersR->profession, profession);
	usersR->age = age;

    *new_refugee = usersR;
}

void print_refugee(const Refugee *refugee) 
{
    printf("%s | %s | %s | %d\n", refugee->userid, refugee->name, refugee->profession, refugee->age);
}

void display_users(NodeType **list)
{
    NodeType *cur = *list;
    while(cur != NULL)
    {
        print_refugee(cur->data);
        cur = cur->next;
    }	
}

Refugee* search_user(NodeType **list, char *userid) 
{
    NodeType *cur = *list;
    while(cur != NULL)
    {
        if (strcmp(cur->data->userid, userid) == 0)
		{
			printf("The user found is: ");
			print_refugee(cur->data);
			return cur->data;
		}

        cur = cur->next;
    }	

    return NULL;
}

Refugee* youngest_user(NodeType **list)
{
    Refugee* youngest = NULL;
	int min_age = 200;

    NodeType *cur = *list;

    while(cur != NULL)
    {
        if (cur->data->age < min_age)
		{
			youngest = cur->data;
			min_age = cur->data->age;
		}

        cur = cur->next;
    }	

    return youngest;
}

void add_user(NodeType  **list, Refugee *refugee, int pos) 
{
    NodeType *cur = NULL;

    NodeType* node = (NodeType*) malloc(sizeof(NodeType));
    node->data = refugee;
    node->next = NULL;

    int index = -1;
    do
    {        
        if( index >= pos - 1 )
            break;
        if( index < 0 )
            cur = *list;
        else
            cur = cur->next;
        index++;
    } while(cur != NULL);

    if( cur == NULL )
    {
        node->next = *list;
        *list = node;        
        // printf("Add On Header1 %s\n", (*list)->data->userid);
        // if( (*list)->next != NULL )
        //     printf("Add On Header2 %s\n", (*list)->next->data->userid);
        return;
    }

    node->next = cur->next;
    cur->next = node;
}

int remove_user(NodeType **list, char *userid)
{
    NodeType *cur = *list;
    NodeType *prev = NULL;
    int index = -1;
    while(cur != NULL)
    {
        index++;
        if (strcmp(cur->data->userid, userid) == 0)
        {
            if( prev == NULL )  // head
                *list = cur->next;                
            else
                prev->next = cur->next;
            
            free(cur->data);
            free(cur);

            break;
        }

        prev = cur;
        cur = cur->next;
    }	

    return index;
}

void cleanup(NodeType *head)
{
    NodeType *cur = head;
    while(cur != NULL)
    {
        NodeType *next = cur->next;
        free(cur->data);
        free(cur);
        cur = next;
    }	
}

void sort_data(NodeType **list)
{
    NodeType* temp = *list;
 
    // Traverse the List
    while (temp) {
        NodeType* min = temp;
        NodeType* r = temp->next;
 
        // Traverse the unsorted sublist
        while (r) {
            if (min->data->age > r->data->age)
                min = r;
 
            r = r->next;
        }
 
        // Swap Data
        Refugee *x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->next;
    }
}

