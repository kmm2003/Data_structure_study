#include <stdio.h>
#include <stdlib.h>
int qlwotnl(int x[], int k, int l, int r) {
	while (1) {
		int mid = (l + r) / 2;
		if (x[mid] > k&&l == mid) {
			return mid;
		}
		if (x[mid] < k&&r == mid) {
			return mid+1;
		}
		if (x[mid] == k) {
			return mid;
		}
		else if (x[mid] > k) {
			r = mid - 1;
			continue;
		}
		else if (x[mid] < k) {
			l=mid+1;
			continue;
		}
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
	printf("%d", qlwotnl(x, k, 0, n - 1));
}