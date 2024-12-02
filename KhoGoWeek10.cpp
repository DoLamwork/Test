#include <iostream>
#include <string>
using namespace std;
#define Max 100

struct KhoGo{
	string typeGo;
	float kichThuoc;
	int ageGo;
};

struct Stack {
    int Top;  //phan tu xac dinh dinh ngan xep
	KhoGo Data[Max];    
};
Stack S;

void Init(Stack& S) {
    S.Top = -1; // Stack kh?i t?o r?ng
}
//Kiem tra ngan xep rong
bool IsEmpty(Stack S) {
    return (S.Top == -1);
}
bool IsFull(Stack S) {
    return (S.Top == Max - 1);
}
void Push(Stack& S, KhoGo x) {
    if (IsFull(S)) {
        cout << "Ngan xep day! Khong the them thanh go moi.\n";
    } else {
        S.Top++;
        S.Data[S.Top] = x; // Luu thanh g? vào stack
    }
}

KhoGo Pop(Stack& S) {
    if (IsEmpty(S)) {
        cout << "Stack rong! Khong the lay thanh go.\n";
        exit(1); // Thoát chuong trình vì không có gì d? l?y
    } else {
        KhoGo x = S.Data[S.Top];
        S.Top--;
        return x;
    }
}

KhoGo nhapKhoGo(){
	KhoGo Go;
	cout << "Nhap loai go: ";
	cin >> Go.typeGo;
	cout << "Nhap kich thuoc: ";
	cin >> Go.kichThuoc;
	cout << "Nhap tuoi go: ";
	cin >> Go.ageGo;
}

void xuatKhoGo(const KhoGo& khoGo) {
    cout << "- Loai go: " << khoGo.typeGo
         << ", Kich thuoc: " << khoGo.kichThuoc << "m"
         << ", Do tuoi: " << khoGo.ageGo << " nam" << endl;
}

void Display(Stack S){
	if (IsEmpty(S)){
		cout << "Kho go rong";
	}
	else {
        cout << "Danh sach cac thanh go trong kho:\n";
        for (int i = S.Top; i >= 0; i--) {
            xuatKhoGo(S.Data[i]);
        }
    }
}

int main() {
    Stack S;
    Init(S); 

    int n;
    cout << "Nhap so luong thanh go muon them vao kho: ";
    cin >> n;

    // Nh?p thông tin các thanh g? và thêm vào stack
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin thanh go thu " << i + 1 << ":\n";
        KhoGo khoGo = nhapKhoGo();
        Push(S, khoGo);
    }

    // Hi?n th? các thanh g? trong stack
    cout << "\nDanh sach cac thanh go trong kho:\n";
    Display(S);

    // L?y m?t thanh g? ra kh?i stack
    if (!IsEmpty(S)) {
        KhoGo removed = Pop(S);
        cout << "\nThanh go vua duoc lay ra:\n";
        xuatKhoGo(removed);
    }

    // Hi?n th? danh sách còn l?i
    cout << "\nDanh sach cac thanh go con lai trong kho:\n";
    Display(S);

    return 0;
}
