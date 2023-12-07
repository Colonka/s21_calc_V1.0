#include "s21_calc.h"

stack *init(union vtype value) {
  stack *temp = (stack *)malloc(sizeof(stack));
  temp->next = NULL;
  temp->val = value;
  return temp;
}

void push(union vtype value, stack **top) {
  if ((*top) != NULL) {
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->next = *top;
    temp->val = value;
    *top = temp;
  } else {
    (*top) = init(value);
  }
}

union vtype pop(stack **top) {
  union vtype ret = {0};
  if ((*top) != NULL) {
    ret = (*top)->val;
    stack *temp = (*top);
    (*top) = (*top)->next;
    free(temp);
  }
  return ret;
}

void destroy(stack *top) {
  while (top) {
    stack *temp = top;
    top = top->next;
    free(temp);
  }
}