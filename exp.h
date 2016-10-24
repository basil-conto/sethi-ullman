#ifndef EXP_H
# define EXP_H

# include "list.h"

struct exp {
  int height;
  int label;
  char *name;
  struct exp *left;
  struct exp *right;
};

int exp_height(const struct exp *);
struct exp *exp_new(char *, struct exp *, struct exp *);
int exp_label(struct exp *);
void exp_print(const struct exp *);

#endif // EXP_H
