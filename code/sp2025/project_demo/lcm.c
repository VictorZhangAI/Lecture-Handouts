#include"gcd.h"
#include"lcm.h"

int lcm(int a, int b)
{
   return (a * b) / gcd(a, b);
}
