#include <stdio.h>
#include <stdlib.h>

struct ll{
	int a;//alive boolean
	struct ll r;
	struct ll l;
}root;

void createll(int n);

void main(){
	int n,d;
	printf("Enter, how long the list should be?");
	scanf("%d",&n);
	printf("Enter the direction in which the killing should start?")
	scanf("%d",&d);
	
	createll(n);
}

void createll(int n){
	struct ll *l1,*l2,*l3;
	int t1,t2,t3;
	l1=(struct ll*)malloc(sizeof(struct ll));	
	l1->alive=1;
	t1=0;
	while(n>0){
		if(t1>0)
		n--;
	}
}