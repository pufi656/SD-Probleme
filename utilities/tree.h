#include <stdlib.h>

typedef struct tree {
    int n;
    struct tree *left, *right;
} tree_t;

tree_t *init_tree(int root) {
    tree_t *tree = (tree_t *) malloc(sizeof(tree_t));
    tree->n = root;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void add_to_tree(tree_t *tree, int n, int where) {
    // where = 0 => right
    // where = 1 => left
    tree_t *new_tree = (tree_t *) malloc(sizeof(tree_t));
    new_tree->n = n;
    if (where) {
        if (tree->left != NULL) return;
        tree->left = new_tree;
    } else {
        if (tree->right != NULL) return;
        tree->right = new_tree;
    }
}