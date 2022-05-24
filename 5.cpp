// Beginning with an empty binary search tree, construct binary search tree by inserting the values in the given order.
// after constructing a binary tree
// 1. insert a new node
// 2. Find the number of nodes in the longest path

#include <bits/stdc++.h>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* getnewnode(int data) {
    BstNode* newNode = new BstNode();
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data) {
    if (root == NULL) {
        root = getnewnode(data);
    }
    else if (data <= root -> data) {
        root -> left = Insert(root->left , data);
    }
    else {
        root -> right = Insert(root->right , data);
    }
    return root;
}

int FindHeight(BstNode* root) {
    if ( root == NULL) {
        return -1;
    }
    int leftH = FindHeight(root -> left);
    int rightH = FindHeight(root -> right);

    return max(leftH , rightH) + 1;
}

int main() {
  BstNode* root = NULL;
      cout << "1. Insert new node" << "\n";
      cout << "2. Find number of nodes in longest path" << "\n";
      cout << "3. Exit" << "\n";
  while(true) {
      int o;
      cout << "Enter the any option : ";
      cin >> o;

      if (o == 1) {
          int data;
          cout << "Enter the value of data to be insert : ";
          cin >> data;
          root = Insert(root , data);
      }

      if (o == 2) {
          int h = FindHeight(root);
          cout << "Number of nodes in longest path is " << h << "\n";
      }

      if (o == 3) {
          exit(0);
      }
  }
}
