#include <stdio.h>
#include <stdlib.h>

struct ll{
	int s;
	int a;//alive boolean
	struct ll *r;
	struct ll *l;
}*root;

void createll(int n);
void printll();
void kill_ll(int d, int m);
void main(){
	int n,d,m;
	printf("Enter, how long the list should be?\t");
	scanf("%d",&n);
	while(1){
		printf("Enter the direction in which the killing should start, 0 for left, 1 for right:\t");
		scanf("%d",&d);
		if((d==0)||(d==1))
			break;
	}
	while(1){
		printf("Now enter from which person the killing should start?:\t");
		scanf("%d",&m);
		if((m>0)&&(m<=n))
			break;
	}
	
	createll(n);
	printll();
	kill_ll(d,m);
}

void createll(int n){
	struct ll *l1,*l2,*l3;
	int t1,t2,t3;
	t3=n;
	l1=(struct ll*)malloc(sizeof(struct ll));	
	l1->a=1;
	l1->l=NULL;
	l1->r=NULL;
	t1=0;
	n--;
	while(n>0){
		l2=(struct ll*)malloc(sizeof(struct ll));
		l2->a=1;
		l2->r=NULL;
		if(t1==0){
			l1->r=l2;
			l2->l=l1;
			t1++;
		}
		else{
			l3->r=l2;
			l2->l=l3;		
		}
		l3=l2;
		//printf("%d",n);
		n--;
	}
	/*while(n>0){
		l2=(struct ll*)malloc(sizeof(struct ll));
		l2->a=1;
		l2->r=NULL;
		l2->l=NULL;
		if(t1==0){
			l1=l2;
			t1++;
		}
		else{
			l2->l=l3;
			l3->r=l2;
			l3=l2;
		}
		
	}*/
	//root=l1;
	l1->l=l2;
	l2->r=l1;
	//root->s=t3;
	//l1->l=l2;
	//l2->r=l1;
	root=l1;
	root->s=t3;
	printf("\nSize=%d",root->s);
}

void printll(){
	struct ll *l1,*l2,*l3;
	int t1,t2,t3;
	t1=1;
	l1=root;
	printf("\nThe Current list is:\n");
	while(l1->r!=root){
		if(l1->a!=0)
			printf("%d \t",t1);
		else
			printf("*dead* \t");	
		l1=l1->r;
		t1++;
	}
	if(l1->a!=0)
	printf("%d\n",t1);
	else
	printf("*dead* \t");
}
void kill_ll(int d, int m){
	struct ll *l1,*l2,*l3;
	int t1,t2,t3;
	l1=root;
	for(int i=0;i<(m-1);i++){
		l1=l1->r;
	}
	if(d==1)
	l1=l1->r;
	else
	l1=l1->l;
	while(root->s!=1){
		
		l1->a=0;
		(root->s)--;
		//printf("\n%d\n",root->s);
		//printll();
		l2=l1;
		if(d==1){
			while((l2->a==0))
			{	
				//if(l2->r!=l1)
					l2=l2->r;
				//else
				//{	printf("Only one remaining");
				//	break;
				//}
			}
			l2=l2->r;
			while((l2->a==0))
			{	
				l2=l2->r;
			}
		}
		else{
			while((l2->a==0))
			{	
				//if(l2->l!=l1)
					l2=l2->l;
				//else
				//{	printf("Only one remaining");
				//	break;
				//}
			}
			l2=l2->l;
			while((l2->a==0))
			{	
				l2=l2->l;
			}
		
		}
		printll();
		l1=l2;
		
	}
	
	

}