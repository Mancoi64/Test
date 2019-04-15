#include <stdio.h>
#include <stdlib.h>
typedef struct  _node{
        int data;
        struct _node *lch;
        struct _node *rch;
}Bitreenode,*Bitree;
void creat(Bitree *T){
        int data;
        scanf("%d",&data);
        if(0==data){
                *T=NULL;

        }
        else{
                *T=(Bitree)malloc(sizeof(Bitreenode));
                if(!(*T)){
                        printf("����ʧ��");
                }
                else{
                        (*T)->data=data;
                        creat(&(*T)->lch);
                        creat(&(*T)->rch);
                }
        }
}
void preorder(Bitree T){
        if(T){
                printf("%d",T->data);
                preorder(T->lch);
                preorder(T->rch);
        }
}
void midorder(Bitree T){
        if(T){
                midorder(T->lch);
                printf("%d",T->data);
                midorder(T->rch);
        }
}
void postorder(Bitree T){
        if(T){
                postorder(T->lch);
                postorder(T->rch);
                printf("%d",T->data);
        }
}
int main(){
        Bitree T=NULL;
        creat(&T);
        printf("ǰ�������");
        preorder(T);
        printf("\n");
         printf("���������");
        midorder(T);
        printf("\n");
         printf("���������");
        postorder(T);
        return 0;
}

