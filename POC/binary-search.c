#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;


int main(void){
    node *tree = malloc(sizeof(node));
    printf("%i\n", sizeof(node));
    // search(tree, 6);
}

// bool search(node *tree, int number){
//     if(tree == NULL) 
//         return false;
//     if(number < tree->number){
//         search(tree->left, number);
//     }
//     else if(number > tree->number){
//         search(tree->right, number);
//     } else{
//         printf("pointer is %n", tree->number);
//         return true;
//     }

//     return false;
// }