#include "s21_calc.h"

int s21_calc(char *input_string, double x, double *resultic) {
  int res = 1;
  char *initial_string = (char *)malloc(sizeof(char) * 4097);
  char *rpn_string = (char *)malloc(sizeof(char) * 4097);
  int error = check_input(input_string, initial_string);
  if (error) {
    rpn(initial_string, rpn_string);
    int code_calc = calculation(rpn_string, x, resultic);
    if (code_calc == 0) {
      res = 3;
    }
    if (code_calc == 2) {
      res = 2;
    }
  } else {
    res = 0;
  }
  free(initial_string);
  free(rpn_string);
  return res;
}