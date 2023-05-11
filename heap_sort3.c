#include <stdio.h>
int h[100];
int n=0;
void upheap(int i) {
	int j;
	int tmp;
	for (j = i; j != 1; j = j / 2) {
		if (h[j] > h[j / 2]) {
			tmp = h[j];
			h[j] = h[j / 2];
			h[j / 2] = tmp;
		}
		else {
			break;
		}
	}
}

void insertitem(int key,int i) {
	h[i] = key;
	upheap(i);
}

void downheap(int i, int last){
	int left=2*i;
	int right=2*i+1;
	int greater=0;
	int tmp;
	if(left>last){
		return;
	}
	greater=left;
	if(right<=last){
		if(h[right]>h[greater]){
			greater=right;
		}
	}
	if(h[i]>=h[greater]){
		return;
	}
	tmp=h[i];
	h[i]=h[greater];
	h[greater]=tmp;
	downheap(greater,last);
}

void buildheap(){
	int i;
	int key;
	for(i=1;i<=n;i++){
		scanf("%d",&key);
		insertitem(key,i);
	}
	return;
}

void inplaceheapsort(){
	int i;
	int tmp;
	buildheap();
	for(i=n;i>=2;i--){
		tmp=h[1];
		h[1]=h[i];
		h[i]=tmp;
		downheap(1,i-1);
	}
	return;
}

void printarray() {
	int i;
	for (i = 1; i <= n; i++) {
		printf(" %d", h[i]);
	}
	printf("\n");
}

int main(void){
	scanf("%d",&n);
	inplaceheapsort();
	printarray();
}