void f1();
void f2();
void f1()
{
   f2();
}
void f2()
{
   f1();
}

int main()
{
   f1();
   return 0;
}