#include<stdio.h>
int main()
{
   int sum;
   for(int i = 1; i <= 100; i++)
      sum += i;
   printf("sum = %d\n", sum);
   return 0;
}