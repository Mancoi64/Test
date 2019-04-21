#include <stdio.h>
#include <stdlib.h>
typedef struct Bitnode{
	int data;
	struct Bitnode *lch,*rch;
}Bitnode,*PBitnode;
void insert(PBitnode *T,int e){
	if(!(*T)){
		*T=(Bitnode *)malloc(sizeof(Bitnode));
		(*T)->data=e;
		(*T)->lch=NULL;
		(*T)->rch=NULL;
	}
	else{
		if(e < (*T)->data){
	        	insert(&(*T)->lch,e);
        }
        if(e > (*T)->data){
        	insert(&(*T)->rch,e);
		}	
	}
}
void creat(PBitnode *T,int a[],int n){
	int i;
	for(i=0;i<n;i++){
		insert(&(*T),a[i]);
	}
}
void del(PBitnode *T){
	if(!(*T)->rch){
		PBitnode p=*T;
		*T=(*T)->lch;
		free(p);
	}
	else if(!(*T)->lch){
		PBitnode p=*T;
		*T=(*T)->rch;
		free(p);
	}
	else{
		PBitnode p,s;
		p=*T;
		s=(*T)->lch;
		while(s->rch){
			p=s;
			s=s->rch;
		}
		(*T)->data=s->data;
		if(p!=(*T)){
			p->rch=s->lch;
		}
		else{
			s->lch=p->rch;
		}
		free(s);
	}
}
void delBST(PBitnode *T,int e){
	if(!*(T)){
		printf("二叉树为空");
	}
	else{
		if(e==(*T)->data)
		del(&(*T));
		else if(e<(*T)->data){ 
			del(&(*T)->lch);
		}
		else{
			del(&(*T)->rch);
		}
	} 
}

void preorder(PBitnode T){
        if(T){
        	    preorder(T->lch);
                printf("%d  ",T->data);
                preorder(T->rch);
        }
}
int main(){
	int a[6]={10,58,3,40,5,6};
	PBitnode T=NULL;
	creat(&T,a,6);
	printf("中序遍历：");
    preorder(T);
    delBST(&T,3);
    printf("中序遍历：");
    preorder(T);
	return 0;
} 
