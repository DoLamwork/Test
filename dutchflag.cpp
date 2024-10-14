#include <iostream>
using namespace std;

void swap(int A[], int i, int j){ //hàm đổi chỗ
    int temp = A[i];
    A[i] = A[j];
    A[j] =  temp;
}

string MauSac(int num){ //hàm đổi số quy ước về lại màu sắc
    if(num == 0) return "đỏ";
    else if(num == 1) return "trắng";
    else return "xanh";
}

void SapXep(int A[], int end){ //quy ước đỏ trắng xanh là 0 1 2
    int start = 0, mid = 0; //lấy ra 3 con trỏ start mid end
    int pivot = 1;  //pivot chính là 1 màu trắng ở giữa

    while(mid<=end){
        if(A[mid] < pivot){ // nếu mid nhỏ hơn 1 => là màu đỏ nên phải đổi chỗ cho start
            swap(A, start, mid);
            ++start;
            ++mid;  //tăng 1 cho start và mid để màu đỏ nằm ở đầu
        }
        else if(A[mid] > pivot){
            swap(A, mid, end);
            --end; // giảm 1 cho end để màu xanh ở cuối
        }
        else{
            ++mid; // tăng 1 cho mid để con trỏ chỉ vào số tiếp theo
        }
    }
}

int main(){
    int A[] = {2, 0, 2, 0, 0, 1, 0, 2, 1};
    int n = sizeof(A)/sizeof(A[0]);
    
    SapXep(A, n-1);

    cout << "Mang da sap xep: ";
    for(int i = 0; i<n; i++){
        cout << MauSac(A[i]) << " ";
    }
    cout << endl;

    return 0;
}