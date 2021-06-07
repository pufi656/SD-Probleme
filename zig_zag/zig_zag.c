#include <stdio.h>
#include "../utilities/stack.h"
#include "../utilities/tree.h"
#include <math.h>

void zigzag(tree_t *tree) {
    if (tree == NULL) {
        return;
    }
    stack_t *stack_right = init_stack();
    stack_t *stack_left = init_stack();
    int depth = 0;
    int stop = 0;
    int counter = 1;
    push_stack(stack_right, tree);
    while (!stop) {
        if (depth % 2 == 0) tree = (tree_t *) pop_stack(stack_right);
        else tree = (tree_t *) pop_stack(stack_left);
        if (depth % 2 == 0) {
            if (tree->left) push_stack(stack_left, tree->left);
            if (tree->right) push_stack(stack_left, tree->right);
        } else {
            if (tree->right) push_stack(stack_right, tree->right);
            if (tree->left) push_stack(stack_right, tree->left);
        }
        printf("%d ", tree->n);
        free(tree);
        if (stack_right->size == 0 && stack_left->size == 0) stop = 1;
        counter++;
        depth = (int) (floor(log(counter)/log(2)));
    }
    free(stack_left);
    free(stack_right);
}

int main() {
    tree_t *tree = init_tree(4);
    add_to_tree(tree, 1, 1);
    add_to_tree(tree, 6, 0);
    add_to_tree(tree->left, 0, 1);
    add_to_tree(tree->left, 3, 0);
    add_to_tree(tree->right, 5, 1);
    add_to_tree(tree->right, 8, 0);
    zigzag(tree);
    printf("\n");
    return 0;
}