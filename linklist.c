#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
	int data;
	struct _node *next;
}node,*Lnode;
void init(Lnode *h){
	*h=(node *)malloc(sizeof(node));
	(*h)->next=NULL;
} 
void creat(Lnode l,int n){
	int i;
	Lnode p;
	for(i=0;i<n;i++){
		int data;
		scanf("%d",&data);
		p=(Lnode)malloc(sizeof(node));
		p->data=data;
		p->next=l->next;
		l->next=p;
	}
}
void inser(Lnode l,int i,int value){
	int j=1;
	Lnode p,s;
	p=l;
	while(p&&j<i){
        p=p->next;
        j++;
	}
	s=(Lnode)malloc(sizeof(node));
	s->data=value;
	s->next=p->next;
	p->next=s;
}
void linkprintf(Lnode l){
	Lnode p;
	p=l->next;
	while(p){
		printf("data is :%d\n",p->data);
		p=p->next;
	}
}
void reverse(Lnode head){
  Lnode p,q,pr;
  p = head->next;
  q = NULL;
  head->next = NULL;
  while(p){
    pr = p->next;
    p->next = q;
    q = p;
    p = pr;
  }
  head->next = q;
}
void del(Lnode l,int i,int value){
	int j=1;
	Lnode p,s;
	p=l;
	while(p&&j<i){
        p=p->next;
        j++;
	}
	s=p->next;
	p->next=s->next;
	value=s->data;
	free(s);
	printf("É¾³ýÔªËØÎª£º%d\n",value);
	
}

int main(){
	int value=0;
	Lnode l=NULL;
	init(&l);
	creat(l,5);
	printf("--------------------------------\n");
	reverse(l);
	linkprintf(l);
	printf("--------------------------------\n");
	inser(l,3,98);
	linkprintf(l);
	printf("--------------------------------\n");
	del(l,4,value);
	linkprintf(l);
	return 0;
}
