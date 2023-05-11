#include <stdio.h>
int h[100];
int n=0;
void downheap(int i) {
	int j;
	int tmp;
	j = i;
	while (1) {
		if (j*2 == n) {
			h[j * 2 + 1] = 0;
		}
		if (j*2 > n) {
			h[j * 2 + 1] = 0;
			h[j * 2] = 0;
		}
		if (h[j] > h[j * 2] && h[j] > h[j * 2 + 1]) {
			break;
		}
		if (h[j * 2] > h[j * 2 + 1]) {
			if (h[j] < h[j * 2]) {
				tmp = h[j];
				h[j] = h[j * 2];
				h[j * 2] = tmp;
				j = j * 2;
			}
		}
		if (h[j * 2] < h[j * 2 + 1]) {
			if (h[j] < h[j * 2 + 1]) {
				tmp = h[j];
				h[j] = h[j * 2 + 1];
				h[j * 2 + 1] = tmp;
				j = j * 2 + 1;
			}
		}
	}
}

void rbuildheap(int i) {
	if (i > n) {
		return;
	}
	rbuildheap(2 * i);
	rbuildheap(2 * i + 1);
	downheap(i);
	return;
}

void printheap() {
	int i;
	for (i = 1; i <= n; i++) {
		printf(" %d", h[i]);
	}
	printf("\n");
}

int main(void) {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	rbuildheap(1);
	printheap();
}