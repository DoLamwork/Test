#include <bits/stdc++.h>
using namespace std;

struct node{
	string data;
	node *left;
	node *right;
};

//cap phat node moi
node *createNode(string x){
	node *newNode = new node;
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//preorder
void preorder(node *root){
	if(root != NULL){
		cout << root->data << ' ';
		preorder(root -> left);
		preorder(root->right);
	}
}

//postorder
void postorder(node *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << root->data << ' ';
	}
}

//inorder
void inorder(node *root){
	if(root != NULL){
		inorder(root->left);
		cout << root->data << ' ';
		inorder(root->right);
	}
}

void chooseTraversal(node* root) {
    int choice;
    cout << "\nChon phuong phap duyet cay:" << endl;
    cout << "1. Preorder" << endl;
    cout << "2. Inorder" << endl;
    cout << "3. Postorder" << endl;
    cout << "Nhap lua chon cua ban (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Duyet cay theo Preorder: ";
            preorder(root);
            break;
        case 2:
            cout << "Duyet cay theo Inorder: ";
            inorder(root);
            break;
        case 3:
            cout << "Duyet cay theo Postorder: ";
            postorder(root);
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
    }
    cout << endl;
}

int main() {
	node* root = createNode("+");
    root->left = createNode("-");
    root->right = createNode("^");
    root->left->left = createNode("x");
    root->left->right = createNode("*");
    root->right->left = createNode("/");
    root->right->right = createNode("3");
    root->left->right->left = createNode("2");
    root->left->right->right = createNode("y");
    root->right->left->left = createNode("y");
    root->right->left->right = createNode("z");
    
	chooseTraversal(root);

    return 0;
}
