#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void inputArray(int A[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Nh?p s? th? " << i+1 << ": ";
        cin >> A[i];
    }
}
void printArray(int A[], int n) {
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int A[], int n){
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
            }
        }
        // In ra sau m?i vòng l?p
        cout << "Bu?c " << i << ": ";
        printArray(A, n);
    }
}

void insertionSort(int A[], int n){
    int last, j;
    for(int i = 1; i < n; i++) {
        last = A[i];
        j = i;
        while((j > 0) && (A[j-1] > last)) {
            A[j] = A[j-1];
            j = j-1;
        }
        A[j] = last;
        // In ra sau m?i l?n chèn
        cout << "Bu?c " << i << ": ";
        printArray(A, n);
    }
}

void selectionSort(int A[], int n){
    int min;
    for(int i = 0; i < n-1; i++) {
        min = i;
        for(int j = i+1; j < n; j++) {
            if(A[j] < A[min]) {
                min = j;
            }
        }
        swap(A[i], A[min]);
        // In ra sau m?i vòng l?p
        cout << "Bu?c " << i+1 << ": ";
        printArray(A, n);
    }
}

int partition(int a[], int start, int end)
{
    // Pick the rightmost element as a pivot from the array
    int pivot = a[end];
 
    // elements less than the pivot will be pushed to the left of `pIndex`
    // elements more than the pivot will be pushed to the right of `pIndex`
    // equal elements can go either way
    int pIndex = start;
 
    // each time we find an element less than or equal to the pivot, `pIndex`
    // is incremented, and that element would be placed before the pivot.
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
 
    // swap `pIndex` with pivot
    swap (a[pIndex], a[end]);
 
    // return `pIndex` (index of the pivot element)
    return pIndex;
}
 
// Quicksort routine
void quicksort(int a[], int start, int end)
{
    // base condition
    if (start >= end) {
        return;
    }
 
    // rearrange elements across pivot
    int pivot = partition(a, start, end);
 
    // recur on subarray containing elements that are less than the pivot
    quicksort(a, start, pivot - 1);
 
    // recur on subarray containing elements that are more than the pivot
    quicksort(a, pivot + 1, end);
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Kích thu?c m?ng trái
    int n2 = right - mid;    // Kích thu?c m?ng ph?i

    int *L = new int[n1];    // M?ng trái
    int *R = new int[n2];    // M?ng ph?i

    // Sao chép d? li?u vào m?ng t?m th?i L[] và R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // H?p nh?t các m?ng t?m th?i l?i vào arr[left..right]
    int i = 0; // Ch? s? ban d?u c?a m?ng con trái
    int j = 0; // Ch? s? ban d?u c?a m?ng con ph?i
    int k = left; // Ch? s? ban d?u c?a m?ng h?p nh?t

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các ph?n t? còn l?i c?a L[], n?u có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các ph?n t? còn l?i c?a R[], n?u có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // In m?ng sau khi h?p nh?t
    cout << "Sau khi hop nhat: ";
    printArray(arr, right - left + 1);
}

// Hàm s?p x?p h?p nh?t
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Tính ch? s? gi?a

        // S?p x?p t?ng n?a
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // H?p nh?t hai n?a dã s?p x?p
        merge(arr, left, mid, right);
    }
}

int main() {
    int n, choice;
    
    cout << "Nh?p s? trong dãy ";
    cin >> n;
    int A[n];
    
    inputArray(A, n);
    
    cout << "Ch?n cách s?p x?p: \n";
    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Selection Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Merge Sort\n";
    cin >> choice;
    
    switch(choice) {
        case 1:
            bubbleSort(A, n);
            cout << "dãy sau s?p x?p Bubble Sort: \n";
            break;
        case 2:
            insertionSort(A, n);
            cout << "dãy sau s?p x?p Insertion Sort: \n";
            break;
        case 3:
            selectionSort(A, n);
            cout << "dayx sau s?p x?p Selection Sort: \n";
            break;
        case 4:
        	quicksort(A, 0, n-1);
        	cout << "day sau sap xep Quick Sort: \n";
        	break;
        case 5: 
        	mergeSort(A, 0, n-1);
        	cout << "day sau sap xep Merge Sort: \n";
        	break;
        default:
            cout << "Invalid!";
            return 1;
    }
    
    printArray(A, n);
    
    return 0;
}

