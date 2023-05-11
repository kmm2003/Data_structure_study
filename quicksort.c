#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct part {
	int *LT, *EQ, *GT;
	int n1, n2, n3;
};
int find_pivot(int l,int r) {
	int ar[3];
	int i, j,tmp;
	srand(time(NULL));

	ar[0] = (rand() % (r - l)) + l;
	ar[1] = (rand() % (r - l) )+ l;
	ar[2] = (rand() % (r - l)) + l;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2 - i; j++) {
			if (ar[j] < ar[j + 1]) {
				tmp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tmp;
			}
		}
	}

	return ar[1];
}


struct part partition(int *L,int k) {
	if (k > 1) {
		struct part re;
		int *LT, *EQ, *GT;
		int i, n1, n2, n3, pivot;

		pivot = L[find_pivot(0, k)];
		n1 = n2 = n3 = 0;
		for (i = 0; i < k; i++) {
			if (pivot > L[i]) n1 = n1 + 1;

			else if (pivot == L[i]) n2 = n2 + 1;

			else n3 = n3 + 1;
		}

		LT = (int*)malloc(n1 * sizeof(int));
		EQ = (int*)malloc(n2 * sizeof(int));
		GT = (int*)malloc(n3 * sizeof(int));

		n1 = n2 = n3 = 0;
		for (i = 0; i < k; i++) {
			if (pivot > L[i]) {
				LT[n1] = L[i];
				n1 = n1 + 1;
			}
			else if (pivot == L[i]) {
				EQ[n2] = L[i];
				n2 = n2 + 1;
			}
			else {
				GT[n3] = L[i];
				n3 = n3 + 1;
			}
		}
		
		re.LT = LT;
		re.EQ = EQ;
		re.GT = GT;
		re.n1 = n1;
		re.n2 = n2;
		re.n3 = n3;

		return re;
	}
	
}

int *merge(int *L, int n, struct part p) {
	int *re,i,j;
	re = (int*)malloc(n * sizeof(int));
	for (i = 0; i < p.n1; i++) {
		re[i] = p.LT[i];
	}
	for (i,j=0; j < p.n2; i++,j++) {
		re[i] = p.EQ[j];
	}
	for (i, j = 0; j < p.n3; j++,i++) {
		re[i] = p.GT[j];
	}

	return re;

}

int *quickSort(int *L,int n) {

	if (n > 1) {
		struct part p;
		p = partition(L, n);
		p.LT = quickSort(p.LT, p.n1);
		p.GT = quickSort(p.GT, p.n3);
		L = merge(L, n, p);
	}
	return L;
}

int main() {
	int N,i;
	int *ar;
	
	scanf("%d", &N);
	ar = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) {
		scanf("%d", ar + i);
	}
	ar=quickSort(ar, N);

	
	for (i = 0; i < N; i++) {
		printf(" %d", ar[i]);
	}
	return 0;
}