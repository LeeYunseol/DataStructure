#include <iostream>
#include <string>
using namespace std;

class BST {
	string data;
	BST* left, * right;
public:
	BST() {
		data = "";
		left = right = NULL;
	}
	BST(string data) {
		this->data = data;
		left = right = NULL;
	}
	BST* insert(BST* root, string data) {
		if (!root) return new BST(data);
		if (root->data == data) return root;
		if (root->data.compare(data) > 0) root->left = insert(root->left, data);
		else root->right = insert(root->right, data);
		return root;
	}
	BST* findMin(BST* node) {
		BST* cur = node;
		while (cur && cur->left != NULL)
			cur = cur->left;
		return cur;
	}
	BST* findMax(BST* node) {
		BST* cur = node;
		while (cur && cur->right != NULL)
			cur = cur->right;
		return cur;
	}
	BST* deleteNode(BST* root, string data) {
		if (!root) return root;
		if (root->data.compare(data) > 0) root->left = deleteNode(root->left, data);
		else if (root->data.compare(data) < 0) root->right = deleteNode(root->right, data);
		else {
			if (root->left == NULL && root->right == NULL)
				return NULL;
			else if (root->right != NULL) {
				BST* temp = findMin(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
			else {
				BST* temp = findMax(root->left);
				root->data = temp->data;
				root->left = deleteNode(root->left, temp->data);
			}
		}
		return root;
	}
	void inorder(BST* root) {
		if (!root) return;
		inorder(root->left);
		cout << root->data << ' ';
		inorder(root->right);
	}
	void printDepthK(BST* root, int k) {
		if (root == NULL || k < 0) return;
		if (k == 0) {
			cout << root->data << " ";
			return;
		}
		printDepthK(root->left, k - 1);
		printDepthK(root->right, k - 1);
	}
	void printLeaf(BST* root) {
		if (!root) return;
		if (!root->left && !root->right) {
			cout << root->data << " ";
			return;
		}
		if (root->left) printLeaf(root->left);
		if (root->right) printLeaf(root->right);
	}
};

int main() {

	BST b, * root = NULL;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str1, str2;
		cin >> str1;
		if (str1 == "+") {
			cin >> str2;
			if (!root) root = b.insert(root, str2);
			else b.insert(root, str2);
		}
		else if (str1 == "-") {
			cin >> str2;
			b.deleteNode(root, str2);
		}
		else if (str1 == "depth") {
			if (!root) cout << "NO" << endl;
			else {
				int k;
				cin >> k;
				b.printDepthK(root, k - 1);
				cout << endl;
			}
		}
		else if (str1 == "leaf") {
			b.printLeaf(root);
			cout << endl;
		}
	}
}