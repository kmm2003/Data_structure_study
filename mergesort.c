#include<stdio.h>

#include<stdlib.h>



typedef struct Node

{

	int data;

	struct Node* next;

}Node;



typedef struct MyStruct

{

	Node* L1;

	Node* L2;

}SubNode;




Node* merge(Node* L1, Node* L2)

{

	Node* result = NULL;





	if (L1 == NULL)

		return(L2);

	else if (L2 == NULL)

		return(L1);



	
	if (L1->data <= L2->data)

	{

		result = L1;

		result->next = merge(L1->next, L2);

	}

	else

	{

		result = L2;

		result->next = merge(L1, L2->next);

	}

	return(result);

}





void mg_partition(Node* source,

	Node** frontRef, Node** backRef) {

	Node* fast;

	Node* slow;

	slow = source;

	fast = source->next;





	while (fast != NULL)

	{

		fast = fast->next;

		if (fast != NULL)

		{

			slow = slow->next;

			fast = fast->next;

		}

	}

	*frontRef = source;

	*backRef = slow->next;

	slow->next = NULL;

}







void mergeSort(Node **L) {

	Node* head = *L;

	Node* L1;

	Node* L2;




	if ((head == NULL) || (head->next == NULL))

	{

		return;

	}





	mg_partition(head, &L1, &L2);






	mergeSort(&L1);

	mergeSort(&L2);




	*L = merge(L1, L2);

}





void push(Node** L, int data)

{

	Node* new_node = (Node*)malloc(sizeof(Node));





	new_node->data = data;

	new_node->next = (*L);



	(*L) = new_node;

}



int main()

{

	int N;

	scanf("%d", &N);



	Node* L = (Node*)malloc(N * sizeof(Node));

	L->data = 0;

	L->next = NULL;



	Node *tmp = L;

	for (int i = 0; i < N; i++)

	{

		int num;

		scanf("%d", &num);

		getchar();

		push(&L, num);

	}



	mergeSort(&L);



	tmp = L->next;

	for (int i = 0; i < N; i++)

	{

		printf(" %d", tmp->data);

		tmp = tmp->next;

	}



	free(L);

}