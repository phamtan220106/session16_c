#include <stdio.h>
#include <stdlib.h>

int length=5;
void add(int *ArrPtr , int value , int index);
int main()
{
    int temp;
    int *ArrPtr=(int *)calloc(length,sizeof(int));
    if(ArrPtr == NULL){
        printf("khong the cap phat bo nho.\n");
        free(ArrPtr);
        return -1;
    }
    for(int i=0; i<=length; i++){
        if(i==length){
            length++;
            ArrPtr = (int *)realloc(ArrPtr, length * sizeof(int));
            if(ArrPtr == NULL){
                printf("khong the cap phat bo nho.\n");
                free(ArrPtr);
                return -1;
            }
        }
        printf("Arr[%d]: ",i);
        scanf("%d",&temp);
        if(temp!=-1){
            *(ArrPtr+i)=temp;
        }else{
            break;
        }
    }
    int index,value;
    printf("nhap vao gia tri moi:");
    scanf("%d",&value);
    printf("nhap vao vi tri them:");
    scanf("%d",&index);
    add(ArrPtr,value,index);
    for(int i=0; i<length; i++){
        printf("%d\t",*(ArrPtr+i));
    }
    free(ArrPtr);
    printf("Hello world!\n");
    return 0;
}

void add(int *ArrPtr , int value , int index){
    for(int i=length; i>=index; i--){
        *(ArrPtr+i)=*(ArrPtr+i-1);
    }
    ArrPtr = (int *)realloc(ArrPtr, (length+1) * sizeof(int));
    *(ArrPtr+index)=value;
}
