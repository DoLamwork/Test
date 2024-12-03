#include <bits/stdc++.h>
using namespace std;

struct node{
	string data;
	node *left;
	node *right;
};

bool isEmpty(node* root) {
    return root == NULL;
}
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
    if (isEmpty(root)) {
        cout << "Cay rong, khong co gi de duyet!" << endl;
        return;
    }

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

void insertNode(node* root) {
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        if (current->left == NULL) {
            string data;
            cout << "Nhap phan tu moi cho trai cua " << current->data << ": ";
            cin >> data;
            current->left = createNode(data);
            return;
        } else {
            q.push(current->left);
        }

        if (current->right == NULL) {
            string data;
            cout << "Nhap phan tu moi cho phai cua " << current->data << ": ";
            cin >> data;
            current->right = createNode(data);
            return;
        } else {
            q.push(current->right);
        }
    }
}

int main() {
	node* root = createNode("+");
	root->left = createNode("-");
	root->right = createNode("*");
	root->left->left = createNode("*");
	root->left->right = createNode("*");
	root->left->left->left = createNode("a");
	root->left->left->right = createNode("5");
	root->left->right->left = createNode("b");
	root->left->right->right = createNode("/");
	root->left->right->right->left = createNode("^");
	root->left->right->right->right = createNode("d");
	root->left->right->right->left->left = createNode("c");
	root->left->right->right->left->right = createNode("6");
	root->right->left = createNode("-");
	root->right->right = createNode("^");
	root->right->left->left = createNode("h");
	root->right->left->right = createNode("f");	
	root->right->right->left = createNode("e");
	root->right->right->right = createNode("/");
	root->right->right->right->left = createNode("1");
	root->right->right->right->right = createNode("2");

 	char choice;
    do {
        insertNode(root);
        cout << "Ban co muon them phan tu nua khong? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
        
	chooseTraversal(root);
    
    return 0;
}
