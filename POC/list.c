#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int number;
    struct node * next;
}
node;

int main(void)
{
    node *list = NULL;
    node *n = malloc(sizeof(node));
    n->number = 1;
    n->next = NULL; //clear garbage value
    printf("%p", n);

    node *list = malloc(sizeof(node));
    list->number = 2;
    list->next = NULL;
    n->next = list;
    list = n;
}