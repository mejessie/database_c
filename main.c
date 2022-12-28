#include <stdio.h>

struct db
{
   int ID;
   char* NAME;
   char* DEPARTMENT;
   char* SALARY;
   struct db* NEXT;
}

int main(void)
{
   printf("Hello World !!!");

   return 0;
}
