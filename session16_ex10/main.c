#include <stdio.h>
#include <stdlib.h>

int length=5;
void deleteItem(int *arrPtr,int index);
int main()
{
    int temp,i=0;
    printf("nhap vao tung phan tu trong mang, nhập -1 để kết thúc:\n");
    int *arrPtr=(int *)calloc(length,sizeof(int));
    if(arrPtr==NULL){
        printf("khong the cap phat bo nho.\n");
        free(arrPtr);
        return 0;
    }
    do{
        if(i==length){
            length++;
            arrPtr=realloc(arrPtr,length*sizeof(int));
            if(arrPtr==NULL){
            printf("khong the cap phat bo nho.\n");
            free(arrPtr);
            return 0;
            }
        }
        printf("Arr[%d]: ",i+1);
        scanf("%d",&temp);
        if(temp!=-1){
            *(arrPtr+i)=temp;
            i++;
        }
    }while(temp!=-1);
    int index;
    printf("nhap vi tri muon xoa: ");
    scanf("%d",&index);
    deleteItem(arrPtr,index);
    for(int i=0; i<length-1; i++){
        printf("%d  ",*(arrPtr+i));
    }
    free(arrPtr);
    printf("\nHello world!\n");
    return 0;
}

void deleteItem(int *arrPtr, int index){
    if(index <0 || index >=length){
        printf("vi tri khong hop le.\n");
        return 0;
    }
    for(int i=index;i<length-2;i++){
        *(arrPtr+i)=*(arrPtr+i+1);
    }
    length--;
    arrPtr=realloc(arrPtr,length*sizeof(int));
}
