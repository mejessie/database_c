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

void select_all()
{
   printf("\n");
   struct db* CURRENT_RECORD = TABLE;
   int i = 1;
   while(CURRENT_RECORD != NULL)
   {
      printf("RECORD[%d] ->   %d - %s - %s - %lf\n", i, CURRENT_RECORD->ID, CURRENT_RECORD->NAME, CURRENT_RECORD->DEPARTMENT, CURRENT_RECORD->SALARY);
      CURRENT_RECORD = CURRENT_RECORD->NEXT;
      ++i;
   }
}

void insert(int ID, char* NAME, char* DEPARTMENT, double SALARY)
{
   printf("\n");
   struct db* RECORD = (struct db*)malloc(sizeof(struct db));
   RECORD->ID = ID;
   RECORD->NAME = NAME;
   RECORD->DEPARTMENT = DEPARTMENT;
   RECORD->SALARY = SALARY;
   RECORD->NEXT = NULL;
   if(TABLE == NULL)
   {
      TABLE = RECORD;
      printf("You just inserted (%d, %s, %s, %lf) .\n", RECORD->ID, RECORD->NAME, RECORD->DEPARTMENT, RECORD->SALARY);
      return;
   }
   if(TABLE->ID == ID)
   {
      printf("Duplicate ID !!!\n");
      return;
   }
   struct db* CURRENT_RECORD = TABLE;
   while(CURRENT_RECORD->NEXT != NULL && CURRENT_RECORD->ID != ID)
   {
      CURRENT_RECORD = CURRENT_RECORD->NEXT;
   }
   if(CURRENT_RECORD->ID == ID)
   {
      printf("Duplicate ID !!!\n");
      return;
   }
   CURRENT_RECORD->NEXT = RECORD;
   printf("You just inserted (%d, %s, %s, %lf) .\n", RECORD->ID, RECORD->NAME, RECORD->DEPARTMENT, RECORD->SALARY);
}

void update_id(int ID, char* NAME, char* DEPARTMENT, double SALARY)
{
   struct db* CURRENT_RECORD = TABLE;
   while(CURRENT_RECORD->ID != ID)
   {
      CURRENT_RECORD = CURRENT_RECORD->NEXT;
   }
   if(NAME != NULL)
   {
      CURRENT_RECORD->NAME = NAME;
   }
   if(DEPARTMENT != NULL)
   {
      CURRENT_RECORD->DEPARTMENT = DEPARTMENT;
   }
   if(SALARY >= 0)
   {
      CURRENT_RECORD->SALARY = SALARY;
   }
}

void delete(int ID)
{
   struct db* CURRENT_RECORD = TABLE;
   if(CURRENT_RECORD->ID == ID)
   {
      TABLE = TABLE->NEXT;
      free(CURRENT_RECORD);
      return;
   }
   struct db* PREVIOUS_RECORD;
   PREVIOUS_RECORD = CURRENT_RECORD;
   CURRENT_RECORD = CURRENT_RECORD->NEXT;
   while(CURRENT_RECORD->ID != ID)
   {
      PREVIOUS_RECORD = CURRENT_RECORD;
      CURRENT_RECORD = CURRENT_RECORD->NEXT;
   }
   PREVIOUS_RECORD->NEXT = CURRENT_RECORD->NEXT;
   free(CURRENT_RECORD);
}

int main(void)
{
   insert(1, "test1", "test1", 1000);
   insert(2, "test2", "test2", 2000);
   insert(3, "test3", "test3", 3000);
   insert(3, "test4", "test4", 4000);
   insert(3, "test5", "test5", 5000);
   select_all();

   return 0;
}
