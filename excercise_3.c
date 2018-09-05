#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int value;
    struct node * next;
} node;

typedef struct linkedlist
{
    node * next;
} linkedlist;

void print_list(linkedlist * root)
{
    node * current = root->next;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void  delete_node(linkedlist * root, int value)
{
    node * current = root->next;
    node * previous = root->next;
    while (current->value != value)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
}

void insert_node(linkedlist * root, int value)
{
    node * new = malloc(sizeof(node));
    new->value = value;
    new->next = root->next;
    root->next = new;
}

void initialize(linkedlist * root)
{
    root->next = NULL;
}

int main()
{
    linkedlist * list = malloc(sizeof(linkedlist));
    initialize(list);
    insert_node(list, 1);
    insert_node(list, 2);
    insert_node(list, 3);
    insert_node(list, 4);
    insert_node(list, 5);
    delete_node(list, 3);
    print_list(list);
}