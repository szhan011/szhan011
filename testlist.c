#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct Person
{
   int age;
   struct list_head list;

};


int main()
{
   struct Person person_head;
   struct Person new_person1;
   struct Person new_person2;
   
   new_person1.age = 10;
   new_person2.age = 20;
      
   list_init(&person_head.list);
   list_add(&new_person1.list, &person_head.list, &person_head.list);
   person_head.list = *(person_head.list.next);
   list_add(&new_person1.list, &person_head.list, &person_head.list);
   
   struct list_head *pos = (person_head.list).next;
   struct Person *p = list_entry(pos,struct Person,list);
   printf("age : %d\n", p->age);
   pos = pos->prev;
   struct Person *p1 = list_entry(pos,struct Person,list);
   printf("age : %d\n", p1->age);
   
   return 0;

}
