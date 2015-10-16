#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node *left,*right;
} TreeNode;

TreeNode *create(int *i, int argc, char *argv[])
{
    TreeNode *root=NULL;
    if(*i<argc) {
        int input = atoi(argv[*i]);
        if(input) {
            root = (TreeNode *)malloc(sizeof(TreeNode));
            root->data = input;
            *i=*i+1;
            root->left = create(i,argc,argv);
            *i=*i+1;
            root->right = create(i,argc,argv);
        }
    }
    return root;
}

void print(TreeNode *root)
{
    if(root==NULL) {
        printf("0 ");
        return;
    }
    printf("%d ",root->data);
    print(root->left);
    print(root->right);
}

void flatten(TreeNode *root, TreeNode *stack)
{
    if(root==NULL && stack==NULL) {
        return;
    }
    if(root->right!=NULL) {
        TreeNode *new=malloc(sizeof(TreeNode));
        new->right=stack;
        new->left=root->right;
        stack=new;
    }
    if(root->left!=NULL) {
        root->right=root->left;
        root->left=NULL;
    } else {
        if(stack!=NULL) {
            TreeNode *pop=stack;
            stack=stack->right;
            pop->right=NULL;
            root->right=pop->left;
            free(pop);
        }
    }
    return flatten(root->right,stack);
}

int main(int argc, char *argv[])
{
    // Check Input
    assert((argc>1) && "No input data!");
    // Create binary tree
    int i=1;
    TreeNode *root=create(&i,argc,argv);
    print(root);
    printf("\n");
    // Flatten
    flatten(root,NULL);
    print(root);
    printf("\n");
    return 0;
}
