#ifndef LIST_H
#define LIST_H

struct list_head
{
   struct list_head *prev,*next;
};

void list_init(struct list_head *head)
{
   head->next = head;
   head->prev = head;
}

void list_add(struct list_head *new, struct list_head *prev, struct list_head *next)
{
   prev->next = new;
   next->prev = new;
   new->prev = prev;
   new->next = next;
}

void list_del(struct list_head *prev, struct list_head *next)
{
   prev->next = next;
   next->prev = prev;
}





#endif
