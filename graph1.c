#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   int dest;
   int weight;
   struct Node *next;
}Node;

Node **a;
int N;

Node * make_new_Node(int dest, int weight) {
   Node *newNode;

   newNode = (Node *)malloc(sizeof(Node));
   
   newNode->dest = dest;
   newNode->weight = weight;
   newNode->next = NULL;
   
   return newNode;
}

void insertitem(int start, int dest, int weight) {
   Node *n, *tmp;
   
   tmp = a[start];
   n = make_new_Node(dest, weight);


   if(tmp->dest == 0) {
      a[start] = n;
      return;
   }
   else if(tmp->dest > n->dest) {
      n->next = a[start];
      a[start] = n;
      return;
   }
   else {
      while(tmp->next != NULL) {
         if(tmp->next->dest > n->dest) {
            n->next = tmp->next;
            tmp->next = n;
            return;
         }
         tmp = tmp->next;
      }
      tmp->next = n;
      //printsetNode(start);
   }

}

void printsetNode(int start) {
   Node *tmp;
   
   tmp = a[start];
   if(tmp->dest == 0) {
      printf("-1\n");
      return;
   }
   
   while(tmp != NULL) {
      printf(" %d %d",tmp->dest, tmp->weight);
      tmp = tmp->next;
   }
   printf("\n");
}

Node * find(int start, int dest) {
   Node *tmp, *n;
   n = (Node *)calloc(1,sizeof(Node));
   
   tmp = a[start];
   
   while(tmp != NULL) {
      if(tmp->dest == dest) {
         n = tmp;
         return n;
      }
      tmp = tmp->next;
   }
   return n;
}

void remove_item(int start, int dest) {
   Node *n, *tmp;
   
   tmp = make_new_Node(0,0);
   
   n = a[start];
   while(n->dest != 0) {
      if(n->dest == dest) {
         if(tmp->dest == 0) a[start] = n->next;
         else tmp->next = n->next;
         //free(n);
         return;
      }
      tmp = n;
      n = n->next;
   }
   return;
}

void change(int start, int dest, int weight) {
   Node *tmp, *temp;
   
   if(start<1 || start > 6 || dest < 1 || dest >6) {
      printf("-1\n");
      return;   
   }
   
   tmp = find(start, dest);
   
   if(weight == 0) {
      if(tmp->dest == 0) {
         return;   
      }
      if(start == dest ) remove_item(start, dest);
      else {
      remove_item(start, dest);
      remove_item(dest, start);
      }
      return;
   }
   
   tmp = find(start, dest);
   
   if(tmp->dest == 0) {
      temp = a[start];
      if(temp == NULL) a[start] = (Node *)malloc(sizeof(Node)); 
      if(start == dest) {
         insertitem(start,dest, weight);
         return;
      }
      temp = a[dest];
      if(temp == NULL) a[dest] = (Node *)malloc(sizeof(Node));
      insertitem(start, dest, weight);
      insertitem(dest, start,weight);
   }
   else {
      if(start == dest) {
         tmp->weight = weight;
         return;
      }
      tmp->weight = weight;
      tmp = find(dest, start);
      tmp->weight = weight;
   }

}

int main() {
   int i, flag = 1, start;
   int j, k, s;
   Node *tmp;
   char menu;
   
   N = 7;
   a = (Node **)calloc(N, sizeof(Node *));
   
   for(i=0;i<7;i++) {
      a[i] = make_new_Node(0,0);
   }
   
   insertitem(1,2,1);
   insertitem(1,3,1);
   insertitem(1,4,1);
   insertitem(1,6,2);
   insertitem(2,1,1);
   insertitem(2,3,1);
   insertitem(3,1,1);
   insertitem(3,2,1);
   insertitem(3,5,4);
   insertitem(4,1,1);
   insertitem(5,3,4);
   insertitem(5,5,4);
   insertitem(5,6,3);
   insertitem(6,1,2);
   insertitem(6,5,3);
   
   while(flag) {
      scanf("%c",&menu);
      switch(menu) {
         case 'a' :
            scanf(" %d",&start);
            tmp = a[start];
            
            if(start > 6 || start < 1) printf("-1\n");
            else if(tmp == NULL) printf("-1\n");
            else printsetNode(start);
            break;
         case 'm' :
            scanf(" %d %d %d",&j,&k,&s);
            change(j,k,s);
            break;
         case 'q' :
            flag = 0;
            break;
      }
   }
   
   return 0;
}