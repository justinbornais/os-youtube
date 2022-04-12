#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    char str[10];
    struct node* left;
    struct node* right;
} node;

node* new_node(int id, char str[], struct node* left, struct node* right);
node* new_node(int id, char str[], struct node* left, struct node* right) {
    
    node* newnode = (node*) malloc(sizeof(node));
    if(newnode == NULL) {
        printf("Error: out of memory.\n");
        return NULL;
    }
    
    newnode->id = id;
    strcpy(newnode->str, str);
    newnode->left = left;
    newnode->right = right;
    
    return newnode;
}

void free_tree(node* root);
void free_tree(node* root) {
    
    if(root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int height(node* root);
int height(node* root) {
    
    if(root == NULL) return 0;
    int hleft = height(root->left);
    int hright = height(root->right);
    
    if(hleft >= hright) return hleft + 1;
    return hright + 1;
}

void print_inorder(node* root);
void print_inorder(node* root) {
    
    if(root == NULL) return;
    print_inorder(root->left);
    printf("Tree node with id %d: \"%s\"\n", root->id, root->str);
    print_inorder(root->right);
}
void print_preorder(node* root);
void print_preorder(node* root) {
    
    if(root == NULL) return;
    printf("Tree node with id %d: \"%s\"\n", root->id, root->str);
    print_preorder(root->left);
    print_preorder(root->right);
}
void print_postorder(node* root);
void print_postorder(node* root) {
    
    if(root == NULL) return;
    print_postorder(root->left);
    print_postorder(root->right);
    printf("Tree node with id %d: \"%s\"\n", root->id, root->str);
}
void print_breadthfirst(node* root, int level);
void print_breadthfirst(node* root, int level) {
    
    if(root == NULL) return;
    if(level == 1) {
        printf("Tree node with id %d: \"%s\"\n", root->id, root->str);
    }
    else {
        print_breadthfirst(root->left, level - 1);
        print_breadthfirst(root->right, level - 1);
    }
}

int main(void) {
    
    node* one = new_node(100, "one", NULL, NULL);
    node* two = new_node(120, "two", NULL, NULL);
    node* three = new_node(130, "three", NULL, NULL);
    node* four = new_node(150, "four", one, two);
    node* five = new_node(200, "five", four, three);
    
    printf("Height of tree: %d\n\n", height(five));
    
    printf("INORDER:\n");
    print_inorder(five);
    printf("\n\nPREORDER:\n");;
    print_preorder(five);
    printf("\n\nPOSTORDER:\n");
    print_postorder(five);
    printf("\n\nBREADTH-FIRST:\n");
    for(int i = 1;i <= height(five);i++)
        print_breadthfirst(five, i);
    
    free_tree(five);
}