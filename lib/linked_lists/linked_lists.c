#include "linked_lists.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int insert_node(Node *head, int data) {
    if (!head) {
        return -1;
    }
    while (head->next) {
        head = head->next;
    }
    Node *new_node = create_node(data);
    if (!new_node) {
        return -1;
    }
    head->next = new_node;
    new_node->next = NULL;
    return 0;
}

void print_linked_list(Node *node) {
    fprintf(stderr, "----------\nBEGIN LIST:\n----------\n");
    while (node->next) {
        fprintf(stderr, "%d\n", node->data);
        node = node->next;
    }
    fprintf(stderr, "----------\nEND LIST:\n----------\n");
}
