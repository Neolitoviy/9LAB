#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main() {
    system("chcp 1251 & cls");
    int bookstore_number;
    node* root = NULL;
    char fname[FILENAME_MAX];
    printf("������ ���� �� �����:\n");
    scanf("%s", fname);
    FILE* f = fopen(fname, "r");
    if (f == NULL) {
        printf("\n���� �� ������� ������.\n");
        return 0;
    }
    read_from_file(f, &root);
    printf("\n�������� ������:\n");
    print_tree(root);
    printf("\nг����: ");
    for (int i = 1; i <= tree_height(root); ++i)
        printf("%-12d", i);
    printf("\n");
    draw_tree(root, 0);
    printf("\n������ ����� �������:\n");
    scanf("%d", &bookstore_number);
    printf("\n�� �����, ������� �� ������ �������:\n");
    search_books(root, bookstore_number);
    printf("\n������������� ����� ������:\n");
    search_unbalanced_roots(root);
    free_tree(root);
    root = NULL;
    return 0;
}