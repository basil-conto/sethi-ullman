#include "list.h"
#include <stdlib.h>

// TODO: * free memory!
//       * abstract/parameterise push and pop functions
//         mirror image?
//       * clean unnecessary statics and includes

struct list *list_new() {
  struct list *list = malloc(sizeof(struct list));
  list->head = list->tail = NULL;
  return list;
}

void list_pushl(struct list *list, void *data) {
  struct list_node *node = malloc(sizeof(struct list_node));

  if (list->head) {
    list->head->prev = node;
  } else {
    list->tail = node;
  }

  node->prev = NULL;
  node->next = list->head;
  node->data = data;
  list->head = node;
}

void list_pushr(struct list *list, void *data) {
  struct list_node *node = malloc(sizeof(struct list_node));

  if (list->tail) {
    list->tail->next = node;
  } else {
    list->head = node;
  }

  node->prev = list->tail;
  node->next = NULL;
  node->data = data;
  list->tail = node;
}

void list_popl(struct list *list) {
  struct list_node *node;
  if ((node = list->head)) {
    list->head = node->next;
    if (node == list->tail) {
      list->tail = node->prev;
    } else {
      node->next->prev = node->prev;
    }
  }
}

void list_popr(struct list *list) {
  struct list_node *node;
  if ((node = list->tail)) {
    list->tail = node->prev;
    if (node == list->head) {
      list->head = node->next;
    } else {
      node->prev->next = node->next;
    }
  }
}

static inline void list_for(void (*f)(void *), struct list_node *node,
                            struct list_node *(*next)(struct list_node *)) {
  for ( ; node; node = next(node)) {
    f(node->data);
  }
}

static inline struct list_node *list_node_next(struct list_node *node) {
  return node->next;
}

static inline struct list_node *list_node_prev(struct list_node *node) {
  return node->prev;
}

inline void list_forl(struct list *list, void (*f)(void *)) {
  list_for(f, list->head, list_node_next);
}

inline void list_forr(struct list *list, void (*f)(void *)) {
  list_for(f, list->tail, list_node_prev);
}
