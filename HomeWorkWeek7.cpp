#include <iostream>
using namespace std;

struct YearPopulation {
    int nam;       
    int danSo; 
};

void nhapDuLieu(YearPopulation data[], int size) {
    int nam[] = {1920, 1921, 1922, 1923, 1924, 1925, 1926, 1927, 1928, 1929, 1930, 1931, 1932, 1933, 1934, 1935, 1936, 1937, 1938, 1939,
                 1940, 1941, 1942, 1943, 1944, 1945, 1946, 1947, 1948, 1949, 1950, 1951, 1952, 1953, 1954, 1955, 1956, 1957, 1958, 1959,
                 1960, 1961, 1962, 1963, 1964, 1965, 1966, 1967, 1968, 1969, 1970};
    int danSo[] = {19, 77, 40, 90, 2, 25, 54, 17, 79, 6, 44, 24, 14, 4, 95, 47, 66, 48, 23, 98, 15, 86, 25, 50, 9, 29, 64, 3, 67, 4, 
                   90, 81, 74, 34, 98, 13, 87, 96, 56, 90, 49, 85, 94, 66, 19, 95, 47, 42, 65, 87, 11};
    
    for (int i = 0; i < size; i++) {
        data[i].nam = nam[i];
        data[i].danSo = danSo[i];
    }
}

void xuatDuLieu(YearPopulation data[], int size) {
    cout << "Nam\tSo luong nguoi sinh ra" << endl;
    for (int i = 0; i < size; i++) {
        cout << data[i].nam << "\t" << data[i].danSo << endl;
    }
}

void timDanSoLonNhatVaNhoNhat(YearPopulation data[], int size) {
    int danSoLonNhat = data[0].danSo;
    int danSoNhoNhat = data[0].danSo;
    int namLonNhat = data[0].nam;
    int namNhoNhat = data[0].nam;

    for (int i = 1; i < size; i++) {
        if (data[i].danSo > danSoLonNhat) {
            danSoLonNhat = data[i].danSo;
            namLonNhat = data[i].nam;
        }
        if (data[i].danSo < danSoNhoNhat) {
            danSoNhoNhat = data[i].danSo;
            namNhoNhat = data[i].nam;
        }
    }

    cout << "Nam co so luong nguoi sinh ra nhieu nhat: " << namLonNhat << " voi " << danSoLonNhat << " nguoi." << endl;
    cout << "Nam co so luong nguoi sinh ra it nhat: " << namNhoNhat << " voi " << danSoNhoNhat << " nguoi." << endl;
}

void timNamCungDanSo(YearPopulation data[], int size) {
    bool timThay = false;
    cout << "Cac nam co cung so luong nguoi sinh ra:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (data[i].danSo == data[j].danSo) {
                cout << data[i].nam << " va " << data[j].nam << " co cung dan so: " << data[i].danSo << endl;
                timThay = true;
            }
        }
    }
    if (!timThay) {
        cout << "Khong co nam nao co cung so luong nguoi sinh ra." << endl;
    }
}

int main() {
    const int SIZE = 51;
    YearPopulation data[SIZE];

    nhapDuLieu(data, SIZE);

    xuatDuLieu(data, SIZE);

    timNamCungDanSo(data, SIZE);

    timDanSoLonNhatVaNhoNhat(data, SIZE);

    return 0;
}

