#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int *cause;
	int *result;
	int n;
	int i,j;
	int tmp;
	scanf("%d", &n);
	cause = (int*)malloc(n * sizeof(int));
	result = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &cause[i]);
		result[i] = cause[i];
	}
	for (i = 1; i < n; i++) {
		tmp = i;
		for (j = 0; j < i; j++) {
			if (cause[j] > cause[i]) {
				tmp = j;
				break;
			}
		}
		for (j = 0; j < tmp; j++) {
			result[j] = cause[j];
		}
		result[tmp] = cause[i];
		for (j = tmp + 1; j <= i; j++) {
			result[j] = cause[j - 1];
		}
		for (j = 0; j < n; j++) {
			cause[j] = result[j];
		}
	}
	for (i = 0; i < n; i++) {
		printf(" %d", result[i]);
	}
}
