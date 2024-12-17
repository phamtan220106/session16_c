#include <stdio.h>
#include <stdlib.h>

int search(int *arrPtr, int length, int value);

int main() {
    int length = 5, i = 0, temp, value;
    int *arrPtr = (int *)malloc(length * sizeof(int));
    if (arrPtr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }
    do {
        if (i == length) {
            length++;
            int *tempPtr = (int *)realloc(arrPtr, length * sizeof(int));
            if (tempPtr == NULL) {
                printf("Khong the cap phat bo nho.\n");
                free(arrPtr);
                return 1;
            }
            arrPtr = tempPtr;
        }
        printf("arr[%d]: ", i);
        scanf("%d", &temp);
        if (temp != -1) {
            arrPtr[i] = temp;
            i++;
        }
    } while (temp != -1);
    printf("Nhap gia tri muon tim vi tri: ");
    scanf("%d", &value);
    int index = search(arrPtr, i, value);
    printf("\nVi tri cua gia tri %d: %d\n", value, index);
    free(arrPtr);
    return 0;
}

int search(int *arrPtr, int length, int value) {
    for (int i = 0; i < length; i++) {
        if (arrPtr[i] == value) {
            return i;
        }
    }
    return -1;
}
