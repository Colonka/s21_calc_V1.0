#include "s21_calc.h"

void rpn(char *input, char *output) {
  union vtype temp;
  stack *st = NULL;
  int count = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == ')' && st != NULL) {  // check closing bracket
      while (st->val.op != '(') {         // pop untill open bracket
        output[count++] = pop(&st).op;
        output[count++] = ' ';
      }
      pop(&st);                    // destroy opened bracket
    } else if (input[i] == '(') {  // push opening bracket
      temp.op = '(';
      push(temp, &st);
    } else if (isNumber(input[i])) {  // output number
      int j = 0;
      while (isNumber(input[i + j])) {
        output[count++] = input[i + (j++)];
      }
      i += j - 1;
      output[count++] = ' ';
    } else if (input[i] == 'x') {  // output x
      output[count++] = input[i];
      output[count++] = ' ';
    } else if (isOper(input[i]) ||
               isFunc(input[i])) {  // output operator and func
      while (st &&
             (prec(st->val.op) > prec(input[i])  // pop depending on precedence
              || (prec(st->val.op) == prec(input[i]) && input[i] != '^'))) {
        output[count++] = pop(&st).op;
        output[count++] = ' ';
      }
      temp.op = input[i];
      push(temp, &st);  // push last
    }
  }
  do {
    output[count++] = pop(&st).op;
    output[count++] = ' ';
  } while (st);
  destroy(st);           // clear
  output[count] = '\0';  // add \0
}

int prec(char x) {
  int res = 0;
  if (x == '(' || x == ')') res = 1;
  if (x == '+' || x == '-') res = 2;
  if (x == '*' || x == '/' || x == '%') res = 3;
  if (x == '^' || isFunc(x)) res = 4;
  return res;
}