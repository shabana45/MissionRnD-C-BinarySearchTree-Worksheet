/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int get_smallest(int* dist, int len);;
int getLeafNodes(struct node* node, int* arr, int* i);
struct node* findCommonAncestor(struct node *root, int n1, int n2);
int Pathlength(struct node *root, int n1);
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	int *arr = (int*)malloc(10 * sizeof(int));
	int *a = (int*)calloc(1, sizeof(int));
	int x = Pathlength(root, temp->data) - 1;
	getLeafNodes(root, arr, a);
	int* dist = (int*)malloc(10 * sizeof(int));
	int* k = (int*)calloc(1, sizeof(int));
	for (int i = 0; i < *a; i++){
		int y = Pathlength(root, arr[i]) - 1;
		int lcaData = findCommonAncestor(root, temp->data, arr[i])->data;
		int lcaDistance = Pathlength(root, lcaData) - 1;
		dist[*k] = (x + y) - 2 * lcaDistance;
		(*k)++;
	}
	return get_smallest(dist, *k);
	return 0;
}
int Pathlength(struct node *root, int n1) {
	if (root != NULL) {
		int x = 0;
		if ((root->data == n1) || (x = Pathlength(root->left, n1)) > 0 || (x = Pathlength(root->right, n1)) > 0)
			return x + 1;
	}
	return 0;
}
struct node* findCommonAncestor(struct node *root, int n1, int n2) {
	if (root != NULL) {
		if (root->data == n1 || root->data == n2) {
			return root;
		}
		struct node* left = findCommonAncestor(root->left, n1, n2);
		struct node* right = findCommonAncestor(root->right, n1, n2);

		if (left != NULL && right != NULL) {
			return root;
		}
		if (left != NULL) {
			return left;
		}
		if (right != NULL) {
			return right;
		}
	}
	return NULL;
}
int getLeafNodes(struct node* node, int* arr, int* i)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL){
		arr[*i] = node->data;
		(*i)++;
		return 1;
	}
	else
		return getLeafNodes(node->left, arr, i) + getLeafNodes(node->right, arr, i);
}
int get_smallest(int *dist, int len)
{
	int small = dist[0];
	for (int i = 1; i < len; i++)
	if (small>dist[i]){
		small = dist[i];
	}
	return small;
}
