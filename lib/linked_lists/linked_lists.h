#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// init & utility functions
Node *create_node();

// linked list methods
void print_linked_list(Node *head);
int insert_node(Node *head, int data);

#endif // LINKED_LISTS_H
