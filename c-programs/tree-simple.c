#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of a node in a tree data structure.
typedef struct node {
    int id;
    char str[10];
    struct node* left; // Points to the left node.
    struct node* right; // Points to the right node.
} node;

// Creates a new node of a tree with dynamic memory allocation.
// left and right can either be a node or simply NULL for no left/right node.
node* new_node(int id, char str[], struct node* left, struct node* right);
node* new_node(int id, char str[], struct node* left, struct node* right) {
    
    node* newnode = (node*) malloc(sizeof(node)); // Allocate enough memory for the node.
    
    // Check if malloc failed.
    if(newnode == NULL) {
        printf("Error: out of memory.\n");
        return NULL;
    }
    
    // Copy properties and return.
    newnode->id = id;
    strcpy(newnode->str, str);
    newnode->left = left;
    newnode->right = right;
    return newnode;
}

// Free all memory associated with the tree.
void free_tree(node* root);
void free_tree(node* root) {
    
    if(root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root); // This is last to avoid memory leaks.
}

// Calculate the height of a given root node of a tree.
// The height of a tree is defined as the maximum distance from a root node to a leaf node. The root and leaf nodes count in the numerical value of the height.
int height(node* root);
int height(node* root) {
    
    if(root == NULL) return 0;
    int hleft = height(root->left); // Get the height of the left subtree.
    int hright = height(root->right); // Get the height of the right subtree.
    
    if(hleft >= hright) return hleft + 1; // Return hleft if greater than the right.
    return hright + 1; // Otherwise right height is greater.
}

// Print all tree nodes in an inorder fashion.
// Inorder goes left -> root -> right.
void print_inorder(node* root);
void print_inorder(node* root) {
    
    if(root == NULL) return;
    print_inorder(root->left); // Left first.
    printf("Tree node with id %d: \"%s\"\n", root->id, root->str); // Then root.
    print_inorder(root->right); // Then right.
}

// Print all tree nodes in a preorder fashion.
// Preorder goes root -> left -> right.
void print_preorder(node* root);
void print_preorder(node* root) {
    
    if(root == NULL) return;
    printf("Tree node with id %d: \"%s\"\n", root->id, root->str); // Root first.
    print_preorder(root->left); // Then left.
    print_preorder(root->right); // Then right.
}

// Print all tree nodes in a postorder fashion.
// Postorder goes left -> right -> root.
void print_postorder(node* root);
void print_postorder(node* root) {
    
    if(root == NULL) return;
    print_postorder(root->left); // Left first.
    print_postorder(root->right); // Then right.
    printf("Tree node with id %d: \"%s\"\n", root->id, root->str); // Then root.
}

// Print all tree nodes using a breadth-first algorithm.
// Breadth-first prints level by level.
// Requires: root can be a node or NULL, and level >= 1.
void print_breadthfirst(node* root, int level);
void print_breadthfirst(node* root, int level) {
    
    if(root == NULL) return;
    if(level == 1) {
        printf("Tree node with id %d: \"%s\"\n", root->id, root->str); // Only print when the level is 1.
    }
    else {
        print_breadthfirst(root->left, level - 1);
        print_breadthfirst(root->right, level - 1);
    }
}

int main(void) {
    
    // Create nodes.
    node* one = new_node(100, "one", NULL, NULL);
    node* two = new_node(120, "two", NULL, NULL);
    node* three = new_node(130, "three", NULL, NULL);
    node* four = new_node(150, "four", one, two);
    node* five = new_node(200, "five", four, three);
    
    printf("Height of tree: %d\n\n", height(five)); // Output the height.
    
    // Output the inorder traversal.
    printf("INORDER:\n");
    print_inorder(five);
    
    // Output the preorder traversal.
    printf("\n\nPREORDER:\n");;
    print_preorder(five);
    
    // Output the postorder traversal.
    printf("\n\nPOSTORDER:\n");
    print_postorder(five);
    
    // Output the breadth-first traversal.
    printf("\n\nBREADTH-FIRST:\n");
    for(int i = 1;i <= height(five);i++)
        print_breadthfirst(five, i); // Allows each level to be printed at a time, starting with the root level.
    
    free_tree(five); // Free all nodes in the tree.
}