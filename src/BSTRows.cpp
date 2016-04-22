/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void helper_BSTRighttoLeftRows(struct node* root, int *arr, int* a, int row);
int height(struct node *root);
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int* arr = (int*)malloc(10 * sizeof(int));
	int ht = height(root);
	int* a = (int*)calloc(1, sizeof(int));
	for (int i = 1; i <= ht; i++)
		helper_BSTRighttoLeftRows(root, arr, a, i);
	for (int i = 0; i <*a; i++)
		printf("%d ", arr[i]);
	return arr;
}
void helper_BSTRighttoLeftRows(struct node* root, int *arr, int* a, int row)
{
	if (root == NULL)
		return;
	if (row == 1){
		arr[*a] = root->data;
		(*a)++;
	}
		helper_BSTRighttoLeftRows(root->right, arr, a, row-1);
		helper_BSTRighttoLeftRows(root->left, arr, a, row-1);
}
int height(struct node *root){
	if (root == NULL)
		return 0;
	else{
		int left_height = height(root->left);
		int right_height = height(root->right);
		if (left_height > right_height)
			return (left_height + 1);
		return (right_height + 1);
	}
}


