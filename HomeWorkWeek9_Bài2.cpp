#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Cau truc Node cho danh sach lien ket de luu tu
typedef struct WordNode {
    char word[100];           // Tu vung
    int count;                // So lan xuat hien
    struct WordNode* link;    // Con tro toi Node tiep theo
} WordNode;

// Ham sao chep chuoi thu cong
void copyString(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Ham tao mot Node moi
WordNode* createNode(const char* word) {
    WordNode* newNode = (WordNode*)malloc(sizeof(WordNode));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho cho Node moi.\n");
        exit(1);
    }
    copyString(newNode->word, word);
    newNode->count = 1;
    newNode->link = NULL;
    return newNode;
}

// Ham them tu vao danh sach (neu tu da ton tai thi tang so lan xuat hien)
void addWord(WordNode** head, const char* word) {
    WordNode* current = *head;
    WordNode* prev = NULL;

    // Kiem tra tu da ton tai trong danh sach chua
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        prev = current;
        current = current->link;
    }

    // Neu tu chua ton tai, them Node moi vao cuoi danh sach
    WordNode* newNode = createNode(word);
    if (prev == NULL) {
        *head = newNode; // Danh sach dang rong
    } else {
        prev->link = newNode;
    }
}

// Ham xac dinh tu xuat hien nhieu nhat
WordNode* findMostFrequentWord(WordNode* head) {
    WordNode* mostFrequent = head;
    WordNode* current = head;

    while (current != NULL) {
        if (current->count > mostFrequent->count) {
            mostFrequent = current;
        }
        current = current->link;
    }
    return mostFrequent;
}

// Ham dem so tu trong danh sach
int countWords(WordNode* head) {
    int count = 0;
    WordNode* current = head;

    while (current != NULL) {
        count++;
        current = current->link;
    }
    return count;
}

// Ham hien thi danh sach tu
void displayWords(WordNode* head) {
    WordNode* current = head;

    printf("Danh sach tu:\n");
    while (current != NULL) {
        printf("%s: %d lan\n", current->word, current->count);
        current = current->link;
    }
}

// Ham xoa tu lay (vi du: xanh xanh)
void removeDuplicateWords(WordNode** head) {
    WordNode* current = *head;
    WordNode* prev = NULL;

    while (current != NULL) {
        char* word = current->word;
        int len = strlen(word);

        // Neu tu la tu lap (xanh xanh)
        if (len % 2 == 0) {
            int half = len / 2;
            bool isDuplicate = true;

            for (int i = 0; i < half; i++) {
                if (word[i] != word[half + i]) {
                    isDuplicate = false;
                    break;
                }
            }

            // Xoa tu lap neu dung
            if (isDuplicate) {
                WordNode* toDelete = current;
                if (prev == NULL) {
                    *head = current->link;
                } else {
                    prev->link = current->link;
                }
                current = current->link;
                free(toDelete);
                continue;
            }
        }
        prev = current;
        current = current->link;
    }
}

// Ham tach tu thu cong tu mot cau
void splitWords(const char* sentence, WordNode** head) {
    char word[100] = {0};
    int index = 0;

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t') {
            if (index > 0) {
                word[index] = '\0'; // Ket thuc tu
                addWord(head, word); // Them tu vao danh sach
                index = 0;           // Reset index
            }
        } else {
            word[index++] = sentence[i];
        }
    }

    // Xu ly tu cuoi cung (neu co)
    if (index > 0) {
        word[index] = '\0';
        addWord(head, word);
    }
}

// Ham chinh
int main() {
    WordNode* wordList = NULL;

    // Cau dau vao
    const char sentence[] = "xanh xanh do vang xanh do vang xanh xanh";

    // Tach tu tu cau va them vao danh sach lien ket
    splitWords(sentence, &wordList);

    // Hien thi danh sach tu
    printf("Truoc khi xu ly:\n");
    displayWords(wordList);

    // Xac dinh tu xuat hien nhieu nhat
    WordNode* mostFrequent = findMostFrequentWord(wordList);
    printf("\nTu xuat hien nhieu nhat: %s (%d lan)\n", mostFrequent->word, mostFrequent->count);

    // Loai bo tu lay neu co
    removeDuplicateWords(&wordList);

    // Hien thi danh sach tu sau khi loai bo tu lay
    printf("\nSau khi loai bo tu lay:\n");
    displayWords(wordList);

    // Dem tong so tu
    int totalWords = countWords(wordList);
    printf("\nTong so tu trong danh sach: %d\n", totalWords);

    return 0;
}

