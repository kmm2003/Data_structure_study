#include <stdio.h>
#include <stdlib.h>
int wotnl(int x[], int k, int l, int r) {
	int mid = (l + r) / 2;
	if (x[mid] > k&&l == mid) {
		return mid - 1;
	}
	if (x[mid] < k&&r == mid) {
		return mid;
	}
	if (x[mid] == k) {
		return mid;
	}
	else if (x[mid] > k) {
		return wotnl(x, k, l, mid - 1);
	}
	else if (x[mid] < k) {
		return wotnl(x, k, mid + 1, r);
	}
}

int main(void) {
	int n, i;
	int *x;
	int k;
	scanf("%d %d", &n, &k);
	x = (int *)malloc(n * sizeof(int));
	for (i = 0;i < n;i++) {
		scanf("%d", &x[i]);
	}
	printf("%d", wotnl(x, k, 0, n - 1));
}