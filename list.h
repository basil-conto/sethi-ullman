#ifndef LIST_H
# define LIST_H

// TODO: * add new function declarations
//       * add replace()

struct list_node {
  struct list_node *prev;
  struct list_node *next;
  void *data;
};

struct list {
  struct list_node *head;
  struct list_node *tail;
};

struct list *list_new();

void list_pushl(struct list *, void *);
void list_pushr(struct list *, void *);

void list_popl(struct list *);
void list_popr(struct list *);

void list_forl(struct list *, void (*)(void *));
void list_forr(struct list *, void (*)(void *));

#endif // DLL_H
