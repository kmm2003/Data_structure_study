#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int key;
	struct node *lchild;
	struct node *rchild;
}node;

typedef struct tree {
	node *root;
}tree;

void inittree(tree *p) {
	p->root = NULL;
}

int insertitem(tree *p, int k) {
	node *t = p->root;
	node *newnode = (struct node*)malloc(sizeof(struct node));
	int q;
	if (t == NULL) {
		newnode->key = k;
		newnode->lchild = NULL;
		newnode->rchild = NULL;
		p->root = newnode;
		return;
	}
	while (1) {
		if (t->key > k) {
			if (t->lchild == NULL) {
				q = 0;
				break;
			}
			t = t->lchild;
		}
		else if (t->key < k) {
			if (t->rchild == NULL) {
				q = 1;
				break;
			}
			t = t->rchild;
		}
	}
	if (q == 0) {
		newnode->key = k;
		newnode->lchild = NULL;
		newnode->rchild = NULL;
		t->lchild = newnode;
	}
	else if (q == 1) {
		newnode->key = k;
		newnode->lchild = NULL;
		newnode->rchild = NULL;
		t->rchild = newnode;
	}
	return;
}

int findelement(tree *p, int k) {
	node *t = p->root;
	while (t != NULL) {
		if (t->key < k) {
			t = t->rchild;
		}
		else if (t->key > k) {
			t = t->lchild;
		}
		else {
			return k;
		}
	}
	return -1;
}

int removeelement(tree *p, int k) {
	node *t = p->root;
	node *r;
	int fl = 0;
	if (t == NULL) {
		return -1;
	}
	if (t->key == k) {
		fl = 1;
		if (t->lchild == NULL&&t->rchild == NULL) {
			p->root = NULL;
			return k;
		}
	}
	else {
		while (t != NULL) {
			r = t;
			if (t->lchild != NULL&&t->lchild->key == k) {
				t = t->lchild;
				fl = 1;
				break;
			}
			else if (t->rchild != NULL&&t->rchild->key == k) {
				t = t->rchild;
				fl = 1;
				break;
			}
			else if (t->key < k) {
				t = t->rchild;
			}
			else if (t->key > k) {
				t = t->lchild;
			}
		}
	}
	if (fl == 0) {
		return -1;
	}
	else {
		if (t->lchild == NULL&&t->rchild == NULL) {
			if (r->lchild != NULL&&t->key == r->lchild->key) {
				r->lchild = NULL;
			}
			else if (r->rchild != NULL&&t->key == r->rchild->key) {
				r->rchild = NULL;
			}
		}
		else if (t->lchild != NULL&&t->rchild != NULL) {
			node *t2 = t;
			node *r2 = t;
			int i = 0;
			t2 = t2->rchild;
			while (t2->lchild != NULL) {
				t2 = t2->lchild;
				if (i == 0) {
					r2 = r2->rchild;
					i++;
					continue;
				}
				r2 = r2->lchild;
			}
			if (t2->rchild == NULL) {
				if (i == 0) {
					t->key = t2->key;
					r2->rchild = NULL;
				}
				else {
					t->key = t2->key;
					r2->lchild = NULL;
				}
			}
			else {
				t->key = t2->key;
				t2->key = t2->rchild->key;
				t2->lchild = t2->rchild->lchild;
				t2->rchild = t2->rchild->rchild;
			}
		}
		else {
			if (t->rchild == NULL) {
				t->key = t->lchild->key;
				t->rchild = t->lchild->rchild;
				t->lchild = t->lchild->lchild;
			}
			else if (t->lchild == NULL) {
				t->key = t->rchild->key;
				t->lchild = t->rchild->lchild;
				t->rchild = t->rchild->rchild;
			}
		}
		return k;
	}
}

int print(node *p) {
	if (p == NULL) {
		return;
	}
	printf(" %d", p->key);
	print(p->lchild);
	print(p->rchild);
	return;
}

int main(void) {
	char c;
	int k;
	int re;
	tree *p = (struct tree*)malloc(sizeof(struct tree));
	inittree(p);
	while (1) {
		scanf("%c", &c);
		if (c == 'i') {
			scanf(" %d", &k);
			insertitem(p, k);
		}
		else if (c == 'd') {
			scanf(" %d", &k);
			re = removeelement(p, k);
			if (re == -1) {
				printf("X\n");
			}
			else {
				printf("%d\n", re);
			}
		}
		else if (c == 's') {
			scanf(" %d", &k);
			re = findelement(p, k);
			if (re == -1) {
				printf("X\n");
			}
			else {
				printf("%d\n", re);
			}
		}
		else if (c == 'p') {
			print(p->root);
			printf("\n");
		}
		else if (c == 'q') {
			break;
		}
	}
}