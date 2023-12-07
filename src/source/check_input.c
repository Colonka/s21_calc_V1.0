#include "s21_calc.h"

int check_input(char* in_equation, char* out_equation) {
  int scob = 0, flag = 1;
  char c[2];
  c[1] = '\0';
  if (in_equation[0] != ')' && in_equation[0] != '*' && in_equation[0] != '/' &&
      in_equation[0] != '+' && in_equation[0] != '%') {
    for (int i = 0; in_equation[i] != '\0'; i++) {
      if (in_equation[i] == '(' || in_equation[i] == ')') {
        check_bracket(&in_equation[i], &scob, out_equation);
      } else if (isNumber(in_equation[i])) {
        int count = 0;
        number_check(&in_equation[i], &count, out_equation);
        i += count - 1;
        count = 0;
      } else if (in_equation[i] == 's' || in_equation[i] == 'c' ||
                 in_equation[i] == 't' || in_equation[i] == 'a' ||
                 in_equation[i] == 'l' || in_equation[i] == 'm') {
        i += check_trigon(&in_equation[i], out_equation);
      } else if (in_equation[i] == '*' || in_equation[i] == '/' ||
                 in_equation[i] == '+' || in_equation[i] == '^') {
        c[0] = in_equation[i];
        strcat(out_equation, c);
      } else if (in_equation[i] == 'x') {
        c[0] = in_equation[i];
        strcat(out_equation, c);
      } else if (in_equation[i] == '-') {
        if (i == 0) {
          c[0] = '?';
          strcat(out_equation, c);
        } else {
          check_minus(&in_equation[i], out_equation);
        }
      }
    }
  } else {
    flag = 0;
  }
  if (scob != 0) flag = 0;
  return flag;
}

void number_check(char* form, int* count, char* out_equation) {
  int g = 0, len = 0, len_after_dot = 0;
  char chis[256];
  while (form[g] != '\0' && !isOper(form[g]) && form[g] != ')' &&
         form[g] != 'x') {
    if (isNumber(form[g])) {
      chis[g] = form[g];
      len++;
      g++;
    } else if (isNumber(form[g]) == 2) {  // "."
      chis[g] = form[g];
      g++;
      while (form[g] != '\0' && !isOper(form[g]) && form[g] != ')' &&
             form[g] != 'x') {
        if (isNumber(form[g])) {
          chis[g] = form[g];
          len_after_dot++;
          g++;
        } else {
          break;
        }
      }
      len_after_dot++;
    } else {
      break;
    }
  }
  char c[2];
  c[1] = '\0';
  for (int i = 0; i < g; i++) {
    c[0] = chis[i];
    strcat(out_equation, c);
  }
  *count = len + len_after_dot;
}

int check_trigon(const char* form, char* result) {
  int i = 0, res = 2;
  char c[2];
  c[1] = '\0';
  if (form[i] == 's' && form[i + 1] == 'i' && form[i + 2] == 'n') {
    c[0] = 'i';
    strcat(result, c);
  }
  if (form[i] == 's' && form[i + 1] == 'q' && form[i + 2] == 'r' &&
      form[i + 3] == 't') {
    c[0] = 'q';
    strcat(result, c);
    res++;
  }
  if (form[i] == 'c' && form[i + 1] == 'o' && form[i + 2] == 's') {
    c[0] = 'o';
    strcat(result, c);
  }
  if (form[i] == 't' && form[i + 1] == 'a' && form[i + 2] == 'n') {
    c[0] = 't';
    strcat(result, c);
  }
  if (form[i] == 'l') {
    if (form[i + 1] == 'n') {
      c[0] = 'n';
      strcat(result, c);
      res--;
    }
    if (form[i + 1] == 'o' && form[i + 2] == 'g') {
      c[0] = 'g';
      strcat(result, c);
    }
  }
  if (form[i] == 'a') {
    if (form[i + 1] == 's') {
      c[0] = 'd';  // asin
      strcat(result, c);
      res++;
    }
    if (form[i + 1] == 'c') {
      c[0] = 'v';  // acos
      strcat(result, c);
      res++;
    }
    if (form[i + 1] == 't') {
      c[0] = 'y';  // atan
      strcat(result, c);
      res++;
    }
  }
  if (form[i] == 'm') {
    c[0] = '%';
    strcat(result, c);
  }
  return res;
}

void check_minus(char* form, char* out_equation) {
  int i = 0;
  char c[2];
  c[1] = '\0';
  if (afterminus(&form[i]) &&
      (!isNumber(form[i - 1]) && !isFunc(form[i - 1]) &&
       !isOper(form[i - 1])) &&
      form[i - 1] != ')') {
    c[0] = '?';
    strcat(out_equation, c);
  } else {
    c[0] = '-';
    strcat(out_equation, c);
  }
}

int afterminus(char* form) {
  int res = 0;
  if (isNumber(form[1])) res = 1;
  if (form[1] == 's') res = 1;
  if (form[1] == 'c') res = 1;
  if (form[1] == 't') res = 1;
  if (form[1] == 'a') res = 1;
  if (form[1] == 'l') res = 1;
  if (form[1] == 'x') res = 1;
  if (form[-1] == '(') res = 1;
  if (form[1] == '(') res = 1;
  return res;
}

void check_bracket(const char* form, int* scob, char* out_equation) {
  int i = 0;
  char c[2];
  c[1] = '\0';
  if (form[i] == '(') {
    c[0] = form[i];
    strcat(out_equation, c);
    *scob = *scob + 1;
  } else {
    c[0] = form[i];
    strcat(out_equation, c);
    *scob = *scob - 1;
  }
}
