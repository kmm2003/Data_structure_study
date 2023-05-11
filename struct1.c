#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
   char elem;
   struct ListNode *prev;
   struct ListNode *next;
}Node;

typedef struct HT{
   int len;
   Node * head;
   Node * tail;
}List;

Node* NewNode( char data )
{
    Node* n = ( Node * )malloc( sizeof( Node ) );
    n->elem = data;
    n->prev = n->next = NULL;
    return n;
}

Node* getNode( List *list, int pos )
{
    Node *t;
    int i;
   if ( pos >= list->len )
        return NULL;
    t = list->head;
    for ( i = 0; i <= pos; i++ )
        t = t->next;
    return t;
}

void initList(List *list)
{
   list -> head=NewNode( NULL );
   list -> tail=NewNode( NULL );
   list->head->next=list->tail;
   list->tail->prev=list->head;
   list->len=0;
}

void traverseList(List *list)
{
   int i;
   Node *p=getNode(list,0);
   if ( p == NULL )
    {
        printf("invalid position\n");
        return;
    }

    for ( i = 0; i < list->len; i++ )
    {
        printf("%c",p->elem);
        p = p->next;
    }
   printf("\n");
}

Node *insertAfter(List *list,Node *p,char e)
{
   Node *q=NewNode(e);
   if ( p == NULL )
    {
      printf("invalid position\n");
      free(q);
        return;
    }
   q->next=p->next;
   q->prev=p;   
   (p->next)->prev=q;
   p->next=q;
   list->len++;
}

char remo(Node *p)
{
   char e=p->elem;
   (p->prev)->next=p->next;
   (p->next)->prev=p->prev;
   return e;
}

void add(List *list,int position, char item)
{
   Node *p=getNode(list,position-1);
   insertAfter(list,p,item);
}

char del(List *list,int position)
{
   Node *p=getNode(list,position);
   if ( p == NULL )
    {
        printf("invalid position\n");
        return;
    }
   remo(p);
   list->len--;
   free(p);
}

char get_entry(List *list,int position)
{
   Node *p=getNode(list,position);
   if(p==NULL)
   {
      printf("invalid position\n");
      return;
   }
   printf("%c\n", p->elem);
    return;
}

void prin(List *list)
{
   traverseList(list);
}
int main(void)
{
   List *list=(List*)malloc(sizeof(List));
   int i,n,pos;
   char k,item;
   scanf("%d",&n);
   initList(list);
   for(i=0;i<n;i++)
   {
      scanf(" %c",&k);
      if(k=='A')
      {
         scanf("%d %c",&pos,&item);
         add(list,pos-1,item);
      }
      else if(k=='D')
      {
         scanf("%d",&pos);
         del(list,pos-1);
      }
      else if(k=='G')
      {
         scanf("%d",&pos);
         get_entry(list,pos-1);
      }
      else if(k=='P')
         prin(list);
   }
}