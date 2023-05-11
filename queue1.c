#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int *p;
	int n;
	int i,j;
	int tmp;
	scanf("%d", &n);
	p = (int *)malloc(n*sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (i = n-1; i >= 0; i--) {
		for (j = 0; j < i; j++) {
			if (p[i] < p[j]) {
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}
}