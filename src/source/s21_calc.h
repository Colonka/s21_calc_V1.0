#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SRC_S21_CALC_H_s
#define SRC_S21_CALC_H_

// Functions

// ? - unary minus
// i - sin
// o - cos
// t - tan
// q - sqrt
// n - ln
// g - log
// d - asin
// v - acos
// y - atan

// Priority

// () - 1
// +- - 2
// */ - 3
// ^ or functions - 4

/// @brief union that content equation's item
union vtype {
  char op;   ///< Operator
  double v;  ///< Value
};

/// @brief struct that content node of the list
typedef struct st_ack {
  union vtype val;      ///< Value
  struct st_ack* next;  ///< pointer to the next node
} stack;

// MAIN

/**
 * @brief Calculator function (full cycle)
 * @param input_string pointer to the input equation string
 * @param x - x value
 * @param resultic - equation result
 * @return error code 0 - invalid input, 1 - ok, 2 - infinity, 3 - error
 */
int s21_calc(char* input_string, double x, double* resultic);

// CALCULATION

/**
 * @brief The function of calling the calculation of the credit (annuity)
 * @param sum - credit sum
 * @param time - credit term
 * @param percent - annual interest rate
 * @param month_pay - monthly pay
 * @param overpay - overpay sum
 * @param common_pay - summury pay
 */
void credit_ann(double sum, int time, double percent, double* month_pay,
                double* overpay, double* common_pay);

/**
 * @brief The function of calling the calculation of the credit (differentional)
 * @param sum - credit sum
 * @param time - credit term
 * @param percent - annual interest rate
 * @param remainder - credit sum remainder
 * @param month_pay - monthly pay
 * @param overpay - overpay sum
 * @param cur_m - current month
 */
void credit_diff(double sum, int time, double percent, double remainder,
                 double* month_pay, double* overpay, int cur_m);

/**
 * @brief Only calculation function
 * @param input pointer to the input equation string
 * @param x - value х
 * @param result - calculation result
 * @return code error 1 - ok, 0 - error, 2 - inf
 */
int calculation(char* input, double x, double* result);

// SUPPORT FUNCTION

/**
 * @brief Support function for calculation when encounter operator
 * @param ср opearator id
 * @param top - pointer to stack
 * @param error - error variable
 */
void oper(char ch, stack** top, int* error);

/**
 * @brief Support function for calculation when encounter function
 * @param сh func id
 * @param top - pointer to stack
 * @param error - error variable
 */
void func(char ch, stack** top, int* error);

/**
 * @brief Function that transform number from string format to double
 * @param str pointer to string number
 * @param x - pointer to double number
 * @return counter - the number of characters read
 */
int string_to_num(char* str, double* x);

// REVERSE to POLISH NOTATION

/**
 * @brief Transform infix string to revers polish string
 * @param in_equation pointer to infix string
 * @param out_equation pointer to reverse polish string
 */
void rpn(char* input, char* output);

/**
 * @brief Priority determinant
 * @param x checking item
 * @return priority 1||2||3||4
 */
int prec(char x);

// STACK

/**
 * @brief Stack initialization
 * @param value value
 * @return pointer to created stack
 */
stack* init(union vtype value);

/**
 * @brief Add node to stack
 * @param value value
 * @param указатель pointer to stack
 */
void push(union vtype value, stack** top);

/**
 * @brief Recieving value of node from stack
 * @param указатель pointer to stack
 * @return value of node's
 */
union vtype pop(stack** top);

/**
 * @brief Stack removing
 * @param указатель pointer to removing stack
 */
void destroy(stack* top);

// CHECKING AND READING

/**
 * @brief Main parcing input eqaution string function
 * @param in_equation pointer to input eqaution string
 * @param out_equation pointer to parced eqaution string
 * @return error code 1 - ok, 0 - invalid input
 */
int check_input(char* in_equation, char* out_equation);

// SUPPORT PARCING FUNCTIONS

/**
 * @brief Checking when encounter number in equation string
 * @param form pointer to parcing string
 * @param count variable that content amount of checking items
 * @param out_equation pointer to parced string
 */
void number_check(char* form, int* count, char* out_equation);

/**
 * @brief Checking when encounter function in equation string
 * @param form pointer to parcing string
 * @param result pointer to parced string
 * @return amount of checking items
 */
int check_trigon(const char* form, char* result);

/**
 * @brief Checking when encounter "-" in equation string
 * @param form pointer to parcing string
 * @param out_equation pointer to parced string
 */
void check_minus(char* form, char* out_equation);

/**
 * @brief Checking "-" sign is unary or operator?
 * @param form pointer to parcing string
 * @return 0 - operator, 1 - unary minus
 */
int afterminus(char* form);

/**
 * @brief Checking when encounter "(" or ")" in equation string
 * @param form pointer to parcing string
 * @param scob variable that show bracket is closed or no(even - closed, odd -
 * opened)
 * @param out_equation pointer to parced string
 */
void check_bracket(const char* form, int* scob, char* out_equation);

// CHECKING ROLE

/**
 * @brief Checking item is number or no
 * @param x checking item
 * @return 0 - not a number, 1 - int number, 2 - float number
 */
int isNumber(char x);

/**
 * @brief Checking item is function or no
 * @param x checking item
 * @return 0 - not a function, 1 - function
 */
int isFunc(char x);

/**
 * @brief Checking item is operator or no
 * @param x checking item
 * @return 0 - not a operator, 1 - operator
 */
int isOper(char x);

#endif  // SRC_S21_CALC_H_