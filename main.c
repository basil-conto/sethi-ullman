#include "exp.h"
#include <stdlib.h>

int main() {
  struct exp *root = exp_new(
    "−",
    exp_new(
      "÷",
      exp_new("a", NULL, NULL),
      exp_new(
        "+",
        exp_new("b", NULL, NULL),
        exp_new("c", NULL, NULL)
      )
    ),
    exp_new(
      "×",
      exp_new("d", NULL, NULL),
      exp_new(
        "+",
        exp_new("e", NULL, NULL),
        exp_new("f", NULL, NULL)
      )
    )
  );
  exp_label(root);
  exp_print(root);

  return EXIT_SUCCESS;
}
