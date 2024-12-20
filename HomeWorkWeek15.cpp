#include <iostream>
#include <vector>
using namespace std;

// Khai bao cau truc node
struct Node {
    string title;          // Tieu de cua muc
    int pageCount;         // So trang
    vector<Node*> subSections; // Danh sach cac muc con

    Node(string t, int p) : title(t), pageCount(p) {}
};

// Ham them mot muc vao cay
Node* addSection(Node* parent, string title, int pageCount) {
    Node* newNode = new Node(title, pageCount);
    if (parent != NULL) {
        parent->subSections.push_back(newNode);
    }
    return newNode;
}

// Ham de quy de tinh tong so chuong
int countChapters(Node* root) {
    if (root == NULL) return 0;

    int count = 1; // Dem node hien tai
    for (size_t i = 0; i < root->subSections.size(); ++i) {
        count += countChapters(root->subSections[i]);
    }
    return count;
}

// Ham de quy de tim chuong dai nhat
Node* findLongestChapter(Node* root, Node*& longest) {
    if (root == NULL) return longest;

    if (longest == NULL || root->pageCount > longest->pageCount) {
        longest = root;
    }
    for (size_t i = 0; i < root->subSections.size(); ++i) {
        findLongestChapter(root->subSections[i], longest);
    }
    return longest;
}

// Ham de quy de tim va xoa mot muc
bool deleteSection(Node*& root, string title) {
    if (root == NULL) return false;

    // Kiem tra neu node hien tai co tieu de can xoa
    for (size_t i = 0; i < root->subSections.size(); ++i) {
        if (root->subSections[i]->title == title) {
            delete root->subSections[i];
            root->subSections.erase(root->subSections.begin() + i);
            return true;
        }
    }

    // Duyet tiep trong cac muc con
    for (size_t i = 0; i < root->subSections.size(); ++i) {
        if (deleteSection(root->subSections[i], title)) {
            return true;
        }
    }
    return false;
}

// Ham main de test
int main() {
    Node* book = new Node("Book", 0); // Tao muc goc

    // Them cac muc
    Node* chapter1 = addSection(book, "Chapter 1", 10);
    Node* chapter2 = addSection(book, "Chapter 2", 20);
    addSection(chapter1, "Section 1.1", 5);
    addSection(chapter1, "Section 1.2", 15);
    addSection(chapter2, "Section 2.1", 8);

    // Dem so chuong
    cout << "Tong so chuong: " << countChapters(book) << endl;

    // Tim chuong dai nhat
    Node* longest = NULL;
    findLongestChapter(book, longest);
    if (longest != NULL) {
        cout << "Chuong dai nhat: " << longest->title << " (" << longest->pageCount << " trang)" << endl;
    }

    // Xoa mot muc
    if (deleteSection(book, "Section 1.2")) {
        cout << "Da xoa muc 'Section 1.2' thanh cong." << endl;
    } else {
        cout << "Khong tim thay muc can xoa." << endl;
    }

    // Dem lai so chuong sau khi xoa
    cout << "Tong so chuong sau khi xoa: " << countChapters(book) << endl;

    return 0;
}

