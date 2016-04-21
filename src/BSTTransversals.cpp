/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

void helper_inorder(struct node* root, int* arr, int* a);
void helper_preorder(struct node* root, int* arr, int a);
void helper_postorder(struct node* root, int* arr, int* a);
void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	int *a = (int*)calloc(1, sizeof(int));
	helper_inorder(root, arr, a);
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
	free(a);
}
void helper_inorder(struct node *root, int *arr, int *a){
	if (root == NULL) return;
	printf("%d", a);
	helper_inorder(root->left, arr, a);
	arr[*a] = root->data;
	(*a)++;
	helper_inorder(root->right, arr, a);
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	int a = 0;
	helper_preorder(root, arr, 0);
}
void helper_preorder(struct node* root, int* arr, int a)
{
	if (root == NULL) return;
	arr[a] = root->data;
	helper_preorder(root->left, arr, ++a);
	helper_preorder(root->right, arr, ++a);
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	int *i = (int*)calloc(1, sizeof(int));
	helper_postorder(root, arr, i);

	free(i);
}
void helper_postorder(struct node* root, int* arr, int* a)
{
	if (root == NULL) return;
	helper_postorder(root->left, arr, a);
	helper_postorder(root->right, arr, a);
	arr[*a] = root->data;
	(*a)++;
}
