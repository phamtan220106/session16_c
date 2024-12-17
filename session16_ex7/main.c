#include <stdio.h>
#include <stdlib.h>

int length=1,i=0;
void softEnment(int *ArrPtr);
int main()
{
    int temp;
    int *ArrPtr = (int *)calloc(length,sizeof(int));
    if(ArrPtr==NULL){
        printf("khong the cap phat the bo nho.\n");
        free(ArrPtr);
        return 0;
    }
    do{
        if(i==length){
            length++;
            ArrPtr = (int *)realloc(ArrPtr,length*sizeof(int));
            if(ArrPtr==NULL){
                printf("khong the cap phat the bo nho.\n");
                free(ArrPtr);
                return 0;
            }
        }
        printf("Arr[%d]: ",i);
        scanf("%d",&temp);
        if(temp!=-1){
            *(ArrPtr+i)=temp;
            i++;
        }else{
            break;
        }

    }while(temp!=-1);
    softEnment(ArrPtr);
    for(int i=0; i<length-1; i++){
        printf("%d\t",*(ArrPtr+i));
    }
    free(ArrPtr);
    printf("Hello world!\n");
    return 0;
}

void softEnment(int *ArrPtr){
    for(int i=0; i<length-2; i++){
        for(int j=0; j<length-2-i; j++){
            if(*(ArrPtr+j)>*(ArrPtr+j+1)){
                int temp=*(ArrPtr+j);
                *(ArrPtr+j)=*(ArrPtr+j+1);
                *(ArrPtr+j+1)=temp;
            }
        }
    }
}
