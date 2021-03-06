#include <stdio.h>
#include <stdlib.h>
#define TYPE int
#define INC 16
#define SIZE 100
typedef struct{
        TYPE *elem;
        int size;
        int length;
}array;
void init(array *arr){
        arr->elem=(TYPE*)malloc(sizeof(TYPE)*SIZE);
        if(!arr->elem)
                printf("ERROR");
        arr->size=SIZE;
        arr->length=0;
}
void input(array *arr){
        int n;
  printf("input the n:");
        scanf("%d\n",&n);
        for(int i=0;i<n;i++){
                scanf("%d",arr->elem+i);
                arr->length++;
        }

}
void inserarray(array *arr,int i,TYPE value){
        if(i>arr->size||i<0)
                printf("ERROR");
        if(arr->length>=arr->size){
                arr->elem=(TYPE*)realloc(arr->elem,sizeof(TYPE)*(arr->size+INC));
                arr->size=SIZE+INC;
        }
        TYPE *p=arr->elem+(i-1);
        TYPE *q=arr->elem+(arr->length-1);
        for(;q>=p;--q)
                *(q+1)=*q;
        *p=value;
        (arr->length)++;
}
void del(array *arr,int i){
         if(i>arr->size||i<0)
                printf("ERROR");
        TYPE *p=&arr->elem[i-1];
        TYPE *q=&arr->elem[arr->length-1];
        for(;q>p;p++)
                *p=*(p+1);
        arr->length--;
         printf("length:%d\n",arr->length);
}
void arrprintf(array *arr){
         for(int i=0;i<arr->length;i++){
                printf("%d  ",arr->elem[i]);
        }
          printf("\n");
          printf("length:%d\n",arr->length);
}

int main(){
        array arr;
        init(&arr);
        input(&arr);
        arrprintf(&arr);
        inserarray(&arr,4,100);
        arrprintf(&arr);
        del(&arr,3);
        arrprintf(&arr);
        return 0;
}

