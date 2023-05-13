#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main() {
    system("chcp 1251 & cls");
    int bookstore_number;
    node* root = NULL;
    char fname[FILENAME_MAX];
    printf("Введіть шлях до файлу:\n");
    scanf("%s", fname);
    FILE* f = fopen(fname, "r");
    if (f == NULL) {
        printf("\nФайл не вдалося знайти.\n");
        return 0;
    }
    read_from_file(f, &root);
    printf("\nЕлементи дерева:\n");
    print_tree(root);
    printf("\nРівень: ");
    for (int i = 1; i <= tree_height(root); ++i)
        printf("%-12d", i);
    printf("\n");
    draw_tree(root, 0);
    printf("\nВведіть номер книгарні:\n");
    scanf("%d", &bookstore_number);
    printf("\nУсі книги, завезені до заданої книгарні:\n");
    search_books(root, bookstore_number);
    printf("\nНезбалансовані корені дерева:\n");
    search_unbalanced_roots(root);
    free_tree(root);
    root = NULL;
    return 0;
}