#ifndef TREE_H
#define TREE_H

typedef struct {
    int book_code;
    int bookstore_number;
} node_data;

typedef struct node {
    node_data data;
    struct node* left;
    struct node* right;
} node;

void read_from_file(FILE* f, node** root);
node* create_node(node_data* data);
void add_node(node** root, node* new_node);
void search_books(node* root, int bookstore_number);
void search_unbalanced_roots(node* root);
int tree_height(node* root);
void print_tree(node* root);
void draw_tree(node* root, int level);
void free_tree(node* root);

#endif //TREE_H
