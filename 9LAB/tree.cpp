#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#define ABS(x) ((x) >= 0 ? (x) : -(x))

void read_from_file(FILE* f, node** root) {
    node_data temp;
    while (fscanf(f, "%d", &temp.book_code) == 1 && fscanf(f, "%d", &temp.bookstore_number) == 1)
        add_node(root, create_node(&temp));
    fclose(f);
}

node* create_node(node_data* data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Помилка при виділенні пам'яті для нового вузла.\n");
        return NULL;
    }
    new_node->data = *data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void add_node(node** root, node* new_node) {
    if (*root == NULL) {
        *root = new_node;
        return;
    }
    if (new_node->data.book_code == (*root)->data.book_code) {
        free(new_node);
        return;
    }
    if (new_node->data.book_code < (*root)->data.book_code)
        add_node(&(*root)->left, new_node);
    else
        add_node(&(*root)->right, new_node);
}

void search_books(node* root, int bookstore_number) {
    stack* head = NULL;
    node* node;
    push(&head, root);
    while ((node = pop(&head)) != NULL) {
        if (node->data.bookstore_number == bookstore_number)
            printf_s("%d\n", node->data.book_code);
        if (node->left != NULL)
            push(&head, node->left);
        if (node->right != NULL)
            push(&head, node->right);
    }
}

int tree_height(node* root) {
    if (root == NULL) return 0;
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    return left_height > right_height ? left_height + 1 : right_height + 1;
}

void search_unbalanced_roots(node* root) {
    if (root == NULL) return;
    if (ABS(tree_height(root->left) - tree_height(root->right)) > 1)
        printf_s("%d (%d)\n", root->data.book_code, root->data.bookstore_number);
    search_unbalanced_roots(root->left);
    search_unbalanced_roots(root->right);
}

void print_tree(node* root) {
    if (root == NULL) return;
    printf_s("Код книги - %d, номер книгарні - %d\n", root->data.book_code,
        root->data.bookstore_number);
    print_tree(root->right);
    print_tree(root->left);
}

void draw_tree(node* root, int level) {
    if (root == NULL) return;
    draw_tree(root->right, level + 1);
    printf_s("%*c%d (%d)\n", level * 12 + 8, ' ', root->data.book_code,
        root->data.bookstore_number);
    draw_tree(root->left, level + 1);
}

void free_tree(node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}