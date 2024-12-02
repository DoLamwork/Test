#include <iostream>
#include <string>
using namespace std;

// Khai bao cau truc node
struct Node {
    string name;
    int sanphamA;
    double tongtien;
    Node* next;
};

// Ham them khach hang vao hang doi
void enqueue(Node*& front, Node*& rear, string name, int sanphamA, double tongtien) {
    Node* newNode = new Node{name, sanphamA, tongtien, NULL};  
    if (rear == NULL) {  
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Ham xoa khach hang dau tien khoi hang doi
void dequeue(Node*& front, Node*& rear) {
    if (front == NULL) {  
        cout << "Hang doi rong, khong the xoa!" << endl;
        return;
    }
    Node* temp = front;  
    front = front->next; 

    if (front == NULL) { 
        rear = NULL;  
    }

    delete temp; 
}

// Kiem tra hang doi co rong hay khong
bool isEmpty(Node* front) {
    return front == NULL; 
}

// Giai phong toan bo hang doi
void clearQueue(Node*& front, Node*& rear) {
    while (!isEmpty(front)) {
        dequeue(front, rear);
    }
}

// Ham hien thi toan bo hang doi
void outputQueue(Node* front) {
    if (isEmpty(front)) {
        cout << "Hang doi rong." << endl;
        return;
    }
    cout << "\nDanh sach khach hang trong hang doi: " << endl;
    Node* temp = front;
    while (temp != NULL) {  
        cout << "Khach hang: " << temp->name
             << ", San pham A: " << temp->sanphamA
             << ", Tong tien: " << temp->tongtien << endl;
        temp = temp->next;
    }
}

// Ham xu ly toan bo hang doi
void processQueue(Node*& front, Node*& rear) {
    int totalProductA = 0;     
    double totalRevenue = 0.0; 

    cout << "\nThanh toan tung khach hang..." << endl;

    while (!isEmpty(front)) {
        Node* khachHang = front;

        cout << "Khach hang: " << khachHang->name
             << ", San pham A: " << khachHang->sanphamA
             << ", Tong tien: " << khachHang->tongtien << endl;

        totalProductA += khachHang->sanphamA;
        totalRevenue += khachHang->tongtien;

        dequeue(front, rear);
    }

    cout << "\nTong so san pham A da ban: " << totalProductA << endl;
    cout << "Tong doanh thu: " << totalRevenue << endl;
}

// Ham nhap thong tin khach hang vao hang doi
void inputQueue(Node*& front, Node*& rear) {
    int n;
    cout << "Nhap so luong khach hang: ";
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        string name;
        int sanphamA;
        double tongtien;

        cout << "\nNhap thong tin cho khach hang thu " << i + 1 << ":" << endl;
        cout << "Ten khach hang: ";
        getline(cin, name);
        cout << "So luong san pham A: ";
        cin >> sanphamA;
        cout << "Tong tien: ";
        cin >> tongtien;
        cin.ignore(); 

        enqueue(front, rear, name, sanphamA, tongtien);
    }
}

int main() {
    Node* front = NULL;  
    Node* rear = NULL;     

    // Nhap thong tin khach hang
    inputQueue(front, rear);

    // Hien thi danh sach trong hang doi
    outputQueue(front);

    // Xu ly thanh toan hang doi
    processQueue(front, rear);

    // Giai phong hang doi
    clearQueue(front, rear);

    return 0;
}

