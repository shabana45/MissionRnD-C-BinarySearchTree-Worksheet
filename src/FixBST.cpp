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
void helper_fixBST(struct node* root, struct node** start, struct node** last, struct node** prevnode);
void fix_bst(struct node *root){
	if (root == NULL)
		return;
	struct node *start=0, *end=0, *prevnode=0;
	helper_fixBST(root, &start, &end, &prevnode);
	if (start != 0 && end != 0){
		int temp = start->data;
	    start->data = end->data;
    	end->data = temp;
      }

}
void helper_fixBST(struct node* root, struct node** start, struct node** last, struct node** prevnode)
{
	if (root == NULL) return;
	helper_fixBST(root->right, start, last, prevnode);
	printf("s");
	if (*prevnode && root->data > (*prevnode)->data)
		{
			if (*start==NULL)
			{
				*start = *prevnode;
				*last = root;
			}
			else
				*last = root;
		}
		*prevnode = root;
		printf("x");
		helper_fixBST(root->left, start, last, prevnode);
}