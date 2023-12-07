#include "s21_calc.h"

int calculation(char* input, double x, double* result) {
  stack* calcul = NULL;
  int error = 1;
  for (int i = 0; input[i] != '\0'; i++) {
    if (isNumber(input[i])) {  // If number
      double number = 0;
      i += string_to_num(&input[i], &number);
      union vtype num = {.v = number};
      push(num, &calcul);
    } else if (input[i] == 'x') {
      union vtype NUM = {.v = x};
      push(NUM, &calcul);
    } else if (isOper(input[i])) {  // Function for operator
      oper(input[i], &calcul, &error);
    } else if (isFunc(input[i])) {  // Function for function
      func(input[i], &calcul, &error);
    }
  }
  if (calcul) *result = calcul->val.v;  // Writing value
  destroy(calcul);
  return error;
}

void oper(char ch, stack** top, int* error) {
  union vtype a, b, c;
  a = pop(top);
  b = pop(top);
  if (ch == '+') {
    c.v = a.v + b.v;
    push(c, top);
  } else if (ch == '-') {
    c.v = b.v - a.v;
    push(c, top);
  } else if (ch == '*') {
    c.v = a.v * b.v;
    push(c, top);
  } else if (ch == '/') {
    if (a.v == 0) {
      *error = 0;
    } else {
      c.v = b.v / a.v;
      push(c, top);
    }
  } else if (ch == '^') {
    c.v = pow(b.v, a.v);
    push(c, top);
  } else if (ch == '%') {
    if (a.v == 0) {
      *error = 0;
    } else {
      c.v = (int)b.v % (int)a.v;
      push(c, top);
    }
  }
}

int string_to_num(char* str, double* x) {
  int counter = 0;
  int found_point = 0;
  int point_counter = 0;
  while (1) {  // Parse micro string
    if (isNumber(str[counter]) == 1 && found_point == 0) {
      point_counter++;
      counter++;
    } else if (isNumber(str[counter]) == 2 && found_point == 0) {
      point_counter = counter;
      counter++;
      found_point = 1;
    } else if (isNumber(str[counter]) == 1 && found_point == 1) {
      counter++;
    } else {
      break;
    }
  }
  for (int i = 0; i < point_counter; i++) {
    *x += ((int)str[i] + 2) % 10 * pow(10, point_counter - i - 1);
  }  // Before dot
  for (int i = point_counter + 1; i < counter; i++) {
    *x += ((int)str[i] + 2) % 10 * (1. / pow(10, i - point_counter));
  }  // After dot
  return counter;
}

void func(char ch, stack** top, int* error) {
  union vtype a, b;
  a = pop(top);
  if (ch == '?') {
    b.v = a.v * (-1);
    push(b, top);
  } else if (ch == 'i') {
    b.v = sin(a.v);
    push(b, top);
  } else if (ch == 'o') {
    b.v = cos(a.v);
    push(b, top);
  } else if (ch == 't') {
    if (cos(a.v) == 0) {
      *error = 0;
    } else {
      b.v = sin(a.v) / cos(a.v);
      push(b, top);
    }
  } else if (ch == 'q') {
    if (a.v < 0) {
      *error = 0;
    } else {
      b.v = sqrt(a.v);
      push(b, top);
    }
  } else if (ch == 'n') {
    if (a.v == 0.0) {
      *error = 2;
    } else if (a.v < 0) {
      *error = 0;
    } else {
      b.v = log(a.v);
      push(b, top);
    }
  } else if (ch == 'g') {
    if (a.v == 0.0) {
      *error = 2;
    } else if (a.v < 0) {
      *error = 0;
    } else {
      b.v = log10(a.v);
      push(b, top);
    }
  } else if (ch == 'd') {
    if (a.v > 1.0 || a.v < -1.0) {
      *error = 0;
    } else {
      b.v = asin(a.v);
      push(b, top);
    }
  } else if (ch == 'v') {
    if (a.v > 1 || a.v < -1) {
      *error = 0;
    } else {
      b.v = acos(a.v);
      push(b, top);
    }
  } else if (ch == 'y') {
    b.v = atan(a.v);
    push(b, top);
  }
}