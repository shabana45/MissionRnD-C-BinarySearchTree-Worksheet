/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void helper_preorder1(struct node* root, int* arr, int a);
void preorder1(struct node *root, int *arr);
//struct node * new_node(int data);
void helper_preorder1(struct node* root, int* arr, int a)
{
	if (root == NULL) return;
	printf("%d ", a);
	arr[a] = root->data;
	helper_preorder1(root->left, arr, ++a);
	helper_preorder1(root->right, arr, ++a);
}
void preorder1(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	helper_preorder1(root, arr, 0);
	for (int i = 0; i < 3; i++)
    	printf("%d ", arr[i]);
	printf("\n");
}
void fix_bst(struct node *root){
	if (root = NULL) return; 
	int *arr = (int*)calloc(10 , sizeof(int));
	preorder1(root, arr);
	//for (int i = 0; i < 3; i++)
		//printf("%d ", results[i]);
	//for (int i = 0; i < 10;i++)
		//root = add_node(root, results[i]);

}
