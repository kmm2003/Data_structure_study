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

void insertitem(int key) {
	n++;
	h[n] = key;
	upheap(n);
}

int removemax() {
	int key;
	key = h[1];
	h[1] = h[n];
	n--;
	downheap(1);
	return key;
}

void printheap() {
	int i;
	for (i = 1; i <= n; i++) {
		printf(" %d", h[i]);
	}
	printf("\n");
}

int main(void) {
	char c;
	int key;
	while (1) {
		scanf("%c", &c);
		if (c == 'i') {
			scanf("%d", &key);
			insertitem(key);
			printf("0\n");
		}
		if (c == 'd') {
			printf("%d\n",removemax());
		}
		if (c == 'p') {
			printheap();
		}
		if (c == 'q') {
			break;
		}
	}
}