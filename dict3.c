#include <stdio.h>
int main(void) {
	int a, b, q;
	int i;
	int m;
	int k;
	char an;
	scanf("%d %d %d ", &a, &b, &q);
	m = (a + b) / 2;
	for (i = 0; i < q; i++) {
		scanf("%c", &an);
		if (an == 'Y') {
			a = m + 1;
		}
		else {
			b = m;
		}
		if (i == q - 1) {
			k = a;
		}
		m = (a + b) / 2;
	}
	printf("%d", k);
}