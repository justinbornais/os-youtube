#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the singly linked list.
typedef struct node {
    int id;
    struct node* next; // Points to the next node in the list (or NULL if we reached the end of the list).
} node;

// Simple method to create a new node of a singly linked list.
node* new_node(int id, node* next);
node* new_node(int id, node* next) {
    
    node* newnode = (node*) malloc(sizeof(node)); // Allocate memory for the node itself.
    if(newnode == NULL) { // or if(!newnode)
        printf("Error: out of memory.\n"); // malloc failed, so we're out of memory!
        return NULL;
    }
    
    // Copy properties into the node and return it.
    newnode->id = id;
    newnode->next = next;
    return newnode;
}

int add_ids(node* head);
int add_ids(node* head) {
    
    int sum = 0;
    
    while(head != NULL) {
        sum += head->id;
        head = head->next; // Move to the next node.
    }
    
    return sum;
}

int main(void) {
    
    // Create our nodes. The linked list will be in the following order:
    // head -> node1 -> node2 -> node3 -> tail
    node* tail = new_node(100, NULL);
    node* node3 = new_node(90, tail);
    node* node2 = new_node(70, node3);
    node* node1 = new_node(50, node2);
    node* head = new_node(10, node1);
    
    printf("Sum of IDs: %d\n", add_ids(head)); // Get the sum of all IDs in the linked list.
    
    // Free all the nodes.
    free(tail);
    free(node3);
    free(node2);
    free(node1);
    free(head);
}