#include "exp.h"
#include "list.h"

#include <stdlib.h> // malloc
#include <stdio.h>  // fputs, printf, puts
#include <math.h>   // fmax

static void exp_print_node(const struct exp *, const char *, char *,
                           struct list *);

inline int exp_height(const struct exp *root) {
  return root ? root->height : -1;
}

struct exp *exp_new(char *name, struct exp *left, struct exp *right) {
  struct exp *exp = malloc(sizeof(struct exp));
  exp->height = (int)fmax(exp_height(left), exp_height(right)) + 1;
  exp->name   = name;
  exp->left   = left;
  exp->right  = right;
  exp->label  = -1;
  return exp;
}

static int exp_label_node(struct exp *root, int bias) {
  if (root->left && root->right) {
    int l = exp_label_node(root->left,  1);
    int r = exp_label_node(root->right, 0);
    bias = l > r ? l : r + (l >= r);
  }
  return root->label = bias;
}

int exp_label(struct exp *root) {
  return exp_label_node(root, -1);
}

static inline void list_print_node(void *name) {
  fputs((char *)name, stdout);
}

static inline void list_print(struct list *list) {
  list_forl(list, list_print_node);
}

static inline void exp_format_node(const struct exp *root) {
  fputs(root->name, stdout);
  if (root->label >= 0) printf(" (%d)", root->label);
  puts("");
}

static inline void exp_printl(const struct exp *root, struct list *list) {
  exp_print_node(root, "├", "│ ", list);
}

static inline void exp_printr(const struct exp *root, struct list *list) {
  exp_print_node(root, "└", "  ", list);
}

static void exp_print_node(const struct exp *root, const char *prefix,
                           char *step, struct list *list) {
  if (!root) return;
  list_print(list);
  list_pushr(list, step);
  printf("%s─", prefix);
  exp_format_node(root);
  exp_printl(root->left,  list);
  exp_printr(root->right, list);
  list_popr(list);
}

void exp_print(const struct exp *root) {
  if (root) {
    struct list *list = list_new();
    exp_format_node(root);
    exp_printl(root->left,  list);
    exp_printr(root->right, list);
  } else {
    puts("*");
  }
}
