#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 1000

// Example data structure definitions
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// Utility: Create a new list node
ListNode *create_node(int val) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Utility: Print array
void print_array(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// Utility: Print linked list
void print_list(ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Utility: Free linked list memory
void free_list(ListNode* head) {
    while (head) {
        ListNode *temp = head;
        head = head->next;
        free(temp);
    }
}


int my_func(arg1, arg2) {
    return arg1 + arg2;
}

int main() {
    // test cases 
    int arg1 = 2;
    int arg2 = 3;

    int result = my_func(arg1, arg2);
    return 0;
}

