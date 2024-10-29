#include <iostream>
using namespace std;

struct DT{
	double *a;
	int n;
};

void nhapDT(DT &dathuc) {
    cout << "Nhap bac cua da thuc: ";
    cin >> dathuc.n; //nhap bac
    dathuc.a = new double[dathuc.n + 1]; //cap bo nho

    for (int i = dathuc.n; i >= 0; i--) {
        cout << "Nhap he so bac " << i << ": ";
        cin >> dathuc.a[i]; //nhap he so
    }
}

void inDT(const DT &dathuc) {
    cout << "Da thuc: ";
    for (int i = dathuc.n; i >= 0; i--) {
        cout << dathuc.a[i]; //in ra he so da thuc
        if (i > 0) {
            cout << "x^" << i << " + "; //in ra bac da thuc
        }
    }
    cout << endl;
}

int main() {
    DT dathuc;
    nhapDT(dathuc);  
    inDT(dathuc);     

    delete[] dathuc.a;
    return 0;
}
