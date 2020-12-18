#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) { 
		val = x;
		left = nullptr;
		right = nullptr;
	}
};

TreeNode* buildTree(vector<int> preorder, vector<int> inorder);
TreeNode* helper(unsigned int preStart, int inStart, int inEnd, vector<int> preorder, vector<int> inorder);

int main(int argc, char** argv) {
	
	vector <int> preorder;
	vector <int> inorder;

	ifstream fin;
	int temp; //streaming in integers for pre/inorder traversals
	char encodedtemp = 0; //streaming in number by number for Huffman navigation
	
//Streaming in inorder
	
	fin.open(argv[1]);

	while (!fin.eof())
	{
		fin >> temp;
		inorder.push_back(temp);
	}

	fin.close();

//Streaming in preorder
	
	fin.open(argv[2]);

	while (!fin.eof())
	{
		fin >> temp;
		preorder.push_back(temp);
	}

	fin.close();

//Building Tree from Traversal

	TreeNode* root = buildTree(preorder, inorder);
	
	
//Navigating Tree w/ Encoded Message

	fin.open(argv[3]);

	TreeNode* current = root; //initializes tree for navigation

	while (!fin.eof()) {
		
		/*
		while (current->val >= 128) {
			fin >> encodedtemp;
			if (encodedtemp == '1') {
				current = current->right;
			}
			else if (encodedtemp == '0') {
				current = current->left;
			}
			
		}*/

		fin >> encodedtemp;
		if (encodedtemp == '1') {
			current = current->right;
		}
		else if (encodedtemp == '0') {
			current = current->left;
		}
		if ((current->val < 128) && (!fin.eof())) {
			cout << static_cast<char>(current->val);
			current = root; //resetting navigation
		}
	}
}


//Tree Building Functions
TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
	return helper(0, 0, inorder.size() - 1, preorder, inorder);
}

TreeNode* helper(unsigned int preStart, int inStart, int inEnd, vector<int> preorder, vector<int> inorder) {
	if (preStart > preorder.size() - 1 || inStart > inEnd) return nullptr;

	TreeNode* root = new TreeNode(preorder[preStart]);

	int inIndex = 0;
	for (int i = inStart; i <= inEnd; i++) {
		if (root->val == inorder[i]) {
			inIndex = i;
		}
	}

	root->left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder);
	root->right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);

	return root;
}

