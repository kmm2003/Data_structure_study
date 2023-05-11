#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int **x;
   int i,j,num;
   int a, b, w;
   char cmp=0;
   x = (int **)malloc(6*sizeof(int *));
   for (i = 0; i < 6; i++)
   {
      x[i] = (int *)malloc(6*sizeof(int));
   }
   for (i = 0; i < 6; i++)
   {
      x[i][i] = -1;
   }
   x[4][4] = 4;
   x[0][1] = 1;
   x[0][2] = 1;
   x[0][3] = 1;
   x[0][4] = -1;
   x[0][5] = 2;
   x[1][2] = 1;
   x[1][3] = -1;
   x[1][4] = -1;
   x[1][5] = -1;
   x[2][3] = -1;
   x[2][4] = 4;
   x[2][5] = -1;
   x[3][4] = -1;
   x[3][5] = -1;
   x[4][5] = 3;
   for (i = 0; i < 6; i++)
   {
      for (j = 0; j < 6; j++)
      {
         x[j][i] = x[i][j];
      }
   }

   while (1)
   {
      scanf("%c", &cmp);
      switch (cmp)
      {
      case 'a':
         scanf("%d", &num);
         if (num <= 6 && num >= 1) {
            for (i = 0; i < 6; i++)
            {
               if (x[num - 1][i] != -1 && x[num - 1][i] != 0)
               {
                  printf(" %d %d", i + 1, x[num - 1][i]);
               }
            }
         }
         else {
            printf("-1");
         }
         printf("\n");
         break;
      case 'm':
         scanf("%d %d %d", &a, &b, &w);
         if ((a >= 1 && a <= 6) && (b >= 1 && b <= 6))
         {
            if (w == 0) {
               x[a - 1][b - 1] = -1;
               x[b - 1][a - 1] = -1;
            }
            else if (w > 0) {
               x[a - 1][b - 1] = w;
               x[b - 1][a - 1] = w;
            }
            else
               break;
         }
         else {
            printf("-1\n");
         }
         break;
      case 'q':
         return 0;
         break;
      }
   }
}