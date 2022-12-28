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

void select_all()
{
   printf("\n");
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
   insert(3, "Pom Pom", "Programmer", 30000);
   insert(4, "Koon Kong", "Security Guard", 12000);
   insert(5, "LOL LMAO", "Human Resource", 30000);
   select_all();
   delete(3);
   select_all();
   update_id(2, NULL, NULL, 20000);
   select_all();

   return 0;
}
