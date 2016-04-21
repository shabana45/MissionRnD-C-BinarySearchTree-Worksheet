/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdio.h>
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
void print(struct node* root);
struct node * new_node(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node* add_node(struct node *root, int data){
	if (root == NULL) return new_node(data);

	if (data < root->data)
		root->left = add_node(root->left, data);
	else if (data > root->data)
		root->right = add_node(root->right, data);

	return root;
}
struct node* sortedArrayToBST(int *arr, int first, int last)
{
	if (first > last)
		return NULL;
	int mid = (first + last) / 2;
	struct node* root = NULL;
	root = add_node(root, arr[mid]);
	root->left = sortedArrayToBST(arr, first, mid - 1);
	root->right = sortedArrayToBST(arr, mid + 1, last);

	return root;
}
struct node * convert_array_to_bst(int *arr, int len){
	if (arr == NULL || len <= 0)
		return NULL;
	struct node *root = NULL;
	root = sortedArrayToBST(arr, 0, len);
	return root;
}
