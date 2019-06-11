#include <iostream>
#include <string>
using namespace std;

class BST {
private:
	struct node {
		string info;
		node *left;
		node *right;
	};
	node *root;
public:
	void ClearTree() { root = NULL; }
	void insertBST(node *&p, string val) {
		if (p == NULL) { p = new(node); p->info = val; p->left = p->right = NULL; }
		else {
			if (val < p->info) { insertBST(p->left, val); }
			if (val > p->info) { insertBST(p->right, val); }
		}
	}
	void InOrder(node *p) {
		if (p != NULL) {
			//(L)(P)(R)

			InOrder(p->left);		// L
			cout << p->info << " "; // P
			InOrder(p->right);		// R
		}
	}
	void PreOrder(node *p) {
		if (p != NULL) {
			//(P)(L)(R)

			cout << p->info << " "; // P
			PreOrder(p->left);		// L
			PreOrder(p->right);		// R
		}
	}
	void PostOrder(node *p) {
		if (p != NULL) {

			PostOrder(p->left);		// L
			PostOrder(p->right);	// R
			cout << p->info << " "; // P
		}
	}

	void insert(string val) { insertBST(root, val); }
	void displayIn() { InOrder(root); }
	void displayPre() { PreOrder(root); }
	void displayPost() { PostOrder(root); }
};

int main() {

	string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	//string months[12] = { "Apr", "Aug", "Dec", "Feb", "Jan", "Jul", "Jun", "Mar", "May", "Nov", "Oct", "Sep" };
	BST m; m.ClearTree();
	for (int i = 0; i < 12; ++i) {
		m.insert(months[i]);
	}

	cout << "Inorder: ";
	m.displayIn();
	cout << "\nPreorder: ";
	m.displayPre();
	cout << "\nPostorder: ";
	m.displayPost();
	cout << endl;
	system("pause");
	return 0;
}

/*

Inorder: Apr Aug Dec Feb Jan Jul Jun Mar May Nov Oct Sep
Preorder: Jan Feb Apr Aug Dec Mar Jun Jul May Sep Oct Nov
Postorder: Dec Aug Apr Feb Jul Jun Nov Oct Sep May Mar Jan
Press any key to continue . . .

*/