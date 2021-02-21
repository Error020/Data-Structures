#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;

	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}

};
int main()	{
	struct Node* root = new Node(5);

	root->left = new Node(7);
	root->right = new Node(3);

	root->left->left = new Node(9);
	root->left->right = new Node(6);

	cout << root->left->data << endl;
	return 0; 
}
