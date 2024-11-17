#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cau truc Node cho danh sach lien ket don de luu thong tin file
typedef struct FileNode {
    char address[200];      // Dia chi file
    char name[100];         // Ten file
    time_t modifiedTime;    // Thoi gian chinh sua cuoi cung
    int size;               // Kich thuoc file (don vi: MB)
    struct FileNode* link;  // Con tro toi Node tiep theo
} FileNode;

// Ham sao chep chuoi thu cong
void copyString(char* dest, const char* src, int maxLen) {
    int i;
    for (i = 0; i < maxLen - 1 && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0'; // Ket thuc chuoi
}

// Ham khoi tao mot Node moi
FileNode* createNode(const char* address, const char* name, time_t modifiedTime, int size) {
    FileNode* newNode = (FileNode*)malloc(sizeof(FileNode));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho cho Node moi.\n");
        exit(1);
    }

    // Sao chep thu cong cac chuoi vao cac truong address va name
    copyString(newNode->address, address, 200);
    copyString(newNode->name, name, 100);
    newNode->modifiedTime = modifiedTime;
    newNode->size = size;
    newNode->link = NULL;
    return newNode;
}

// Ham chen mot Node moi vao danh sach theo thu tu thoi gian
void insertFile(FileNode** head, FileNode* newNode) {
    if (*head == NULL || (*head)->modifiedTime >= newNode->modifiedTime) {
        newNode->link = *head;
        *head = newNode;
    } else {
        FileNode* current = *head;
        while (current->link != NULL && current->link->modifiedTime < newNode->modifiedTime) {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}

// Ham them file vao danh sach voi thong tin dia chi, ten, thoi gian, va kich thuoc
void addFile(FileNode** head, const char* address, const char* name, time_t modifiedTime, int size) {
    FileNode* newNode = createNode(address, name, modifiedTime, size);
    insertFile(head, newNode);
}

// Ham tinh tong kich thuoc cua tat ca cac file trong danh sach
int calculateTotalSize(FileNode* head) {
    int totalSize = 0;
    FileNode* current = head;
    while (current != NULL) {
        totalSize += current->size;
        current = current->link;
    }
    return totalSize;
}

// Ham loc cac file de sao luu vao USB co dung luong 32GB
void filterFilesForUSB(FileNode** head, int maxSize) {
    int totalSize = calculateTotalSize(*head);
    while (totalSize > maxSize) {
        // Tim file co kich thuoc nho nhat
        FileNode* current = *head;
        FileNode* prev = NULL;
        FileNode* smallestNode = *head;
        FileNode* smallestPrev = NULL;

        while (current != NULL) {
            if (current->size < smallestNode->size) {
                smallestPrev = prev;
                smallestNode = current;
            }
            prev = current;
            current = current->link;
        }

        // Loai bo node co kich thuoc nho nhat khoi danh sach
        if (smallestPrev == NULL) {
            *head = smallestNode->link;
        } else {
            smallestPrev->link = smallestNode->link;
        }

        // Giai phong bo nho cua node bi loai
        totalSize -= smallestNode->size;
        free(smallestNode);
    }
}

// Ham hien thi danh sach cac file trong danh sach
void displayFiles(FileNode* head) {
    FileNode* current = head;
    printf("Danh sach file:\n");
    while (current != NULL) {
        printf("Dia chi: %s\n", current->address);
        printf("Ten: %s\n", current->name);
        printf("Kich thuoc: %d MB\n", current->size);
        printf("Thoi gian chinh sua: %s", ctime(&current->modifiedTime));
        printf("\n");
        current = current->link;
    }
}

int main() {
    FileNode* fileList = NULL;

    // Them file vao danh sach
    addFile(&fileList, "D:/Document/file1.txt", "file1.txt", time(NULL), 1000);
    addFile(&fileList, "D:/Document/file2.txt", "file2.txt", time(NULL), 2000);
    addFile(&fileList, "D:/Document/file3.txt", "file3.txt", time(NULL), 500);
    addFile(&fileList, "D:/Document/file4.txt", "file4.txt", time(NULL), 700);
    addFile(&fileList, "D:/Document/file5.txt", "file5.txt", time(NULL), 1200);

    // Hien thi danh sach cac file truoc khi loc
    printf("Truoc khi loc:\n");
    displayFiles(fileList);

    // Thuc hien loc cac file de sao luu vao USB 32GB
    filterFilesForUSB(&fileList, 32768);

    // Hien thi danh sach cac file sau khi loc
    printf("Sau khi loc (phu hop voi USB 32GB):\n");
    displayFiles(fileList);

    return 0;
}

