/* Converting a binary tree to a threaded binary tree*/

#include<bits/stdc++.h>
using namespace std;

struct Btnode {
	int data;
	Btnode* left;
	Btnode* right;
	bool isThreaded; // true or false
};

Btnode* newNode(int data) {
	Btnode* temp = new Btnode;
	temp -> left = temp -> right = NULL;
	temp -> data = data;
	return temp;
}

Btnode* createThread(Btnode* root) {
	if(root == NULL) {
		return NULL;
	}
	if (root -> left == NULL && root -> right == NULL) {
		return root;
	}

	if (root -> left != NULL) {
		Btnode* l = createThread(root -> left);
		l->right = root;
		l->isThreaded = true;
	}
	if (root -> right == NULL) {
		return root;
	}

	return createThread(root -> right);
}

Btnode *leftMost(Btnode *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

void inorder(Btnode *root)
{
    if (root == NULL) return;

    Btnode *cur = leftMost(root);

    while (cur != NULL)
    {
        cout << cur->data << " ";
        if (cur->isThreaded) {
            cur = cur->right;
		}

        else {
            cur = leftMost(cur->right);
		}
    }
}


int main() {
	Btnode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
	createThread(root);

    cout << "Inorder traversal of created threaded tree is..\n";
    inorder(root);
	return 0;
}
