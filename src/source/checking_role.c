#include "s21_calc.h"

int isFunc(char x) {
  int res = 0;
  if (x == '?' || x == 'i' || x == 'o' || x == 't' || x == 'q' || x == 'g' ||
      x == 'n' || x == 'd' || x == 'v' || x == 'y')
    res = 1;
  return res;
}
int isOper(char x) {
  int res = 0;
  if (x == '+' || x == '-' || x == '/' || x == '*' || x == '^' || x == '%')
    res = 1;
  return res;
}
int isNumber(char x) {
  int res = 0;
  if (x > 47 && x < 58) res = 1;
  if (x == '.') res = 2;
  return res;
}