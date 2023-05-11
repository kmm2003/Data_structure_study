#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	int num;
	struct node *left;
	struct node *right;
}node;

typedef struct tree {
	node *root;
}tree;

void inittree(tree *p) {
	p->root = NULL;
}

node *cheaktree(node *p,int f) {
	node *op;
	node *po;
	if (p->num == f) {
		return p;
	}
	else if (p->num == 0) {
		return NULL;
	}
	else {
		op = cheaktree(p->left, f);
		if (op != NULL) {
			return op;
		}
		po = cheaktree(p->right, f);
		if (po != NULL) {
			return po;
		}
		return NULL;
	}
}

int insertnode(tree *p,int f,int l,int r) {
	node *rootnode = (struct node*)malloc(sizeof(struct node));
	node *leftnode = (struct node*)malloc(sizeof(struct node));
	node *rightnode = (struct node*)malloc(sizeof(struct node));
	node *trash;
	rootnode->num = f;
	rootnode->left = NULL;
	rootnode->right = NULL;
	leftnode->num = l;
	leftnode->left = NULL;
	leftnode->right = NULL;
	rightnode->num = r;
	rightnode->left = NULL;
	rightnode->right = NULL;
	if (p->root == NULL) {
		rootnode->left = leftnode;
		rootnode->right = rightnode;
		p->root = rootnode;
		return;
	}
	trash = cheaktree(p->root, f);
	trash->left = leftnode;
	trash->right = rightnode;
	return;
}

int main(void) {
	int n, s;
	int i, j;
	int f, l, r;
	char x[101];
	tree *p = (struct tree*)malloc(sizeof(struct tree));
	node *trash;
	inittree(p);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &f, &l, &r);
		insertnode(p, f, l, r);
	}
	scanf("%d", &s);
	trash = p->root;
	for (i = 0; i < s; i++) {
		scanf("%s", x);
		printf(" %d", trash->num);
		for (j = 0; j < strlen(x); j++) {
			if (x[j] == 'L') {
				trash = trash->left;
				printf(" %d", trash->num);
			}
			else {
				trash = trash->right;
				printf(" %d", trash->num);
			}
		}
		printf("\n");
		trash = p->root;
	}
}