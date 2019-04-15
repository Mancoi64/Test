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
                        printf("分配失败");
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
        printf("前序遍历：");
        preorder(T);
        printf("\n");
         printf("中序遍历：");
        midorder(T);
        printf("\n");
         printf("后序遍历：");
        postorder(T);
        return 0;
}

