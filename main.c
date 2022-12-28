#include <stdio.h>
#include <stdlib.h>

struct db
{
   int ID;
   char* NAME;
   char* DEPARTMENT;
   double SALARY;
   struct db* NEXT;
};

struct db* TABLE = NULL;

void insert(int ID, char* NAME, char* DEPARTMENT, double SALARY)
{
   struct db* RECORD = (struct db*)malloc(sizeof(struct db));
   RECORD->ID = ID;
   RECORD->NAME = NAME;
   RECORD->DEPARTMENT = DEPARTMENT;
   RECORD->SALARY = SALARY;
   RECORD->NEXT = NULL;
   if(TABLE == NULL)
   {
      TABLE = RECORD;
      return;
   }
   struct db* CURRENT_RECORD = TABLE;
   while(CURRENT_RECORD->NEXT != NULL)
   {
      CURRENT_RECORD = CURRENT_RECORD->NEXT;
   }
   CURRENT_RECORD->NEXT = RECORD;
}

void select_all()
{
   struct db* CURRENT_RECORD = TABLE;
   while(CURRENT_RECORD != NULL)
   {
      printf("RECORD -> %d %s %s %lf\n", CURRENT_RECORD->ID, CURRENT_RECORD->NAME, CURRENT_RECORD->DEPARTMENT, CURRENT_RECORD->SALARY);
      CURRENT_RECORD = CURRENT_RECORD->NEXT;
   }
}

int main(void)
{
   struct db* c = TABLE;
   insert(1, "Jedsada Aimjit", "Data Engineer", 100000);
   insert(2, "Somchai Prayuth", "Police", 12000);
   select_all();

   return 0;
}
