#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../source/s21_calc.h"

// PLUS

START_TEST(plus_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "25+15");
  double res = 0.0;
  double true_res = 40.0;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(plus_2) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-25+(-15)");
  double res = 0.0;
  double true_res = -40.0;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(plus_3) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "25.65+(-15.54)");
  double res = 0.0;
  double true_res = 10.11;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(plus_4) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-25.5555553+15.4444441");
  double res = 0.0;
  double true_res = -10.1111112;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

// MINUS

START_TEST(minus_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "25-15");
  double res = 0.0;
  double true_res = 10.0;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(minus_2) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "25-(-15)");
  double res = 0.0;
  double true_res = 40.0;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(minus_3) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-25-(-15)");
  double res = 0.0;
  double true_res = -10.0;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(minus_4) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-25.666-15.334");
  double res = 0.0;
  double true_res = -41.0;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

// MULT

START_TEST(mult_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "20*5");
  double res = 0.0;
  double true_res = 100.0;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(mult_2) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-20.15*(-0.554)");
  double res = 0.0;
  double true_res = 11.1631;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(mult_3) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-20*0.5");
  double res = 0.0;
  double true_res = -10.0;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(mult_4) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-25465.56*155.41");
  double res = 0.0;
  double true_res = -3957602.6796;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

// DIVISION

START_TEST(div_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-25465.56/155.41");
  double res = 0.0;
  double true_res = -163.8604980;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(div_2) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-25465.56/(-155.41)");
  double res = 0.0;
  double true_res = 163.8604980;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(div_3) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-25465.56/0");
  double res_res;
  int res = s21_calc(ex, 1, &res_res);
  int true_res = 3;  // error
  ck_assert_int_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(div_4) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-25465.56/(-0.41)");
  double res = 0.0;
  double true_res = 62111.12195;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-5);
  free(ex);
}
END_TEST

// mod

START_TEST(mod_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "3mod2");
  double res = 0.0;
  double true_res = 1.0;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(mod_2) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "2mod3");
  double res = 0.0;
  double true_res = 2.0;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(mod_3) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "2mod2");
  double res = 0.0;
  double true_res = 0.0;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(mod_4) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "2mod0");
  double res_res;
  int res = s21_calc(ex, 1, &res_res);
  int true_res = 3;  // error
  ck_assert_int_eq(res, true_res);
  free(ex);
}
END_TEST

// degree

START_TEST(deg_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "2^(1.53)");
  double res = 0.0;
  double true_res = 2.8878583;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(deg_2) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-2^(-1.53)");
  double res = 0.0;
  double true_res = -0.3462773;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(deg_3) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "2^(-1.53)");
  double res = 0.0;
  double true_res = 0.3462773;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(deg_4) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "-2^(1.53)");
  double res = 0.0;
  double true_res = -2.8878583;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

// sqrt

START_TEST(sqrt_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "sqrt(16)");
  double res = 0.0;
  double true_res = 4;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(sqrt_2) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "sqrt(23.56)");
  double res = 0.0;
  double true_res = 4.8538644;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(sqrt_3) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "sqrt(-4)");
  double res_res;
  int res = s21_calc(ex, 1, &res_res);
  int true_res = 3;  // error
  ck_assert_int_eq(res, true_res);
  free(ex);
}
END_TEST

// trigon

START_TEST(sin_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "sin(3.56)");
  double res = 0.0;
  double true_res = -0.4063057;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(sin_2) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "sin(x)");
  double res = 0.0;
  double true_res = 0.8414709;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(asin_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "asin(0.95)");
  double res = 0.0;
  double true_res = 1.2532358;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(asin_2) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "asin(1.01)");
  double res_res;
  int res = s21_calc(ex, 1, &res_res);
  int true_res = 3;  // error
  ck_assert_int_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(cos_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "cos(3.56)");
  double res = 0.0;
  double true_res = -0.9137372;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(acos_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "acos(0.95)");
  double res = 0.0;
  double true_res = 0.3175604;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(acos_2) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "acos(1.01)");
  double res_res;
  int res = s21_calc(ex, 1, &res_res);
  int true_res = 3;  // error
  ck_assert_int_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(tan_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "tan(3.56)");
  double res = 0.0;
  double true_res = 0.4446636;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(atan_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "atan(3.56)");
  double res = 0.0;
  double true_res = 1.2969542;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

// log

START_TEST(log_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "log(3.56)");
  double res = 0.0;
  double true_res = 0.5514499;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(log_2) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "log(-0.1)");
  double res_res;
  int res = s21_calc(ex, 1, &res_res);
  int true_res = 3;  // error
  ck_assert_int_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(log_3) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "log(0.0)");
  double res_res;
  int res = s21_calc(ex, 1, &res_res);
  int true_res = 2;  // error
  ck_assert_int_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(ln_1) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "ln(3.56)");
  double res = 0.0;
  double true_res = 1.2697605;
  s21_calc(ex, 1, &res);
  ck_assert_double_eq_tol(res, true_res, 1e-7);
  free(ex);
}
END_TEST

START_TEST(ln_2) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "ln(-0.1)");
  double res_res;
  int res = s21_calc(ex, 1, &res_res);
  int true_res = 3;  // error
  ck_assert_int_eq(res, true_res);
  free(ex);
}
END_TEST

START_TEST(ln_3) {
  char *ex = (char *)malloc(sizeof(char) * 50);
  strcpy(ex, "ln(0.0)");
  double res_res;
  int res = s21_calc(ex, 1, &res_res);
  int true_res = 2;  // error
  ck_assert_int_eq(res, true_res);
  free(ex);
}
END_TEST

// credit

START_TEST(credit_ann_monthly) {
  int time = 24;
  double percent = 10.0;
  double sum = 300000.0;
  double monthly_pay = 0.0;
  double monthly_pay_true = 13843.48;
  double overpay = 0.0;
  double common_pay = 0.0;
  credit_ann(sum, time, percent, &monthly_pay, &overpay, &common_pay);
  ck_assert_double_eq_tol(monthly_pay, monthly_pay_true, 1e-2);
}
END_TEST

//

START_TEST(credit_ann_overpay) {
  int time = 24;
  double percent = 10.0;
  double sum = 300000.0;
  double monthly_pay = 0.0;
  double overpay = 0.0;
  double overpay_true = 32243.52;
  double common_pay = 0.0;
  credit_ann(sum, time, percent, &monthly_pay, &overpay, &common_pay);
  ck_assert_double_eq_tol(overpay, overpay_true, 1e-1);
}
END_TEST

START_TEST(credit_ann_common_pay) {
  int time = 24;
  double percent = 10.0;
  double sum = 300000.0;
  double monthly_pay = 0.0;
  double overpay = 0.0;
  double common_pay = 0.0;
  double common_pay_true = 332243.52;
  credit_ann(sum, time, percent, &monthly_pay, &overpay, &common_pay);
  ck_assert_double_eq_tol(common_pay, common_pay_true, 1e-1);
}
END_TEST

START_TEST(credit_diff_test) {
  int time = 12;
  double percent = 24.0;
  double sum = 300000.0;
  double *monthly_pay = (double *)malloc(sizeof(double) * time);
  double *monthly_pay_true = (double *)malloc(sizeof(double) * time);
  monthly_pay_true[0] = 31000.0;
  for (int j = 1; j < time; j++) {
    monthly_pay_true[j] = monthly_pay_true[j - 1] - 500;
  }
  double overpay = 0.0;
  double overpay_true = 39000.0;
  double common_pay = 0.0;
  double common_pay_true = 339000.0;
  double remainder = sum;
  int cur_m = 0;
  for (int i = 0; i < time; i++) {
    credit_diff(sum, time, percent, remainder, monthly_pay, &overpay, cur_m);
    cur_m++;
    remainder = remainder - (sum / time);
    ck_assert_double_eq_tol(monthly_pay[i], monthly_pay_true[i], 1e-1);
  }
  common_pay = overpay + sum;
  ck_assert_double_eq_tol(overpay, overpay_true, 1e-1);
  ck_assert_double_eq_tol(common_pay, common_pay_true, 1e-1);
  free(monthly_pay);
  free(monthly_pay_true);
}
END_TEST

//////////////////////////////////////////////////////////////////

Suite *plus_suite(void) {
  Suite *s_plus = suite_create("Plus_testcase");
  TCase *tc_plus = tcase_create("Plus");

  suite_add_tcase(s_plus, tc_plus);
  tcase_add_test(tc_plus, plus_1);
  tcase_add_test(tc_plus, plus_2);
  tcase_add_test(tc_plus, plus_3);
  tcase_add_test(tc_plus, plus_4);

  return s_plus;
}

Suite *minus_suite(void) {
  Suite *s_minus = suite_create("Minus_testcase");
  TCase *tc_minus = tcase_create("Minus");

  suite_add_tcase(s_minus, tc_minus);
  tcase_add_test(tc_minus, minus_1);
  tcase_add_test(tc_minus, minus_2);
  tcase_add_test(tc_minus, minus_3);
  tcase_add_test(tc_minus, minus_4);

  return s_minus;
}

Suite *mult_suite(void) {
  Suite *s_mult = suite_create("Mult_testcase");
  TCase *tc_mult = tcase_create("Mult");

  suite_add_tcase(s_mult, tc_mult);
  tcase_add_test(tc_mult, mult_1);
  tcase_add_test(tc_mult, mult_2);
  tcase_add_test(tc_mult, mult_3);
  tcase_add_test(tc_mult, mult_4);

  return s_mult;
}

Suite *div_suite(void) {
  Suite *s_div = suite_create("Div_testcase");
  TCase *tc_div = tcase_create("Div");

  suite_add_tcase(s_div, tc_div);
  tcase_add_test(tc_div, div_1);
  tcase_add_test(tc_div, div_2);
  tcase_add_test(tc_div, div_3);
  tcase_add_test(tc_div, div_4);

  return s_div;
}

Suite *mod_suite(void) {
  Suite *s_mod = suite_create("Mod_testcase");
  TCase *tc_mod = tcase_create("Mod");

  suite_add_tcase(s_mod, tc_mod);
  tcase_add_test(tc_mod, mod_1);
  tcase_add_test(tc_mod, mod_2);
  tcase_add_test(tc_mod, mod_3);
  tcase_add_test(tc_mod, mod_4);

  return s_mod;
}

Suite *deg_suite(void) {
  Suite *s_deg = suite_create("Deg_testcase");
  TCase *tc_deg = tcase_create("Deg");

  suite_add_tcase(s_deg, tc_deg);
  tcase_add_test(tc_deg, deg_1);
  tcase_add_test(tc_deg, deg_2);
  tcase_add_test(tc_deg, deg_3);
  tcase_add_test(tc_deg, deg_4);

  return s_deg;
}

Suite *sqrt_suite(void) {
  Suite *s_sqrt = suite_create("Sqrt_testcase");
  TCase *tc_sqrt = tcase_create("Sqrt");

  suite_add_tcase(s_sqrt, tc_sqrt);
  tcase_add_test(tc_sqrt, sqrt_1);
  tcase_add_test(tc_sqrt, sqrt_2);
  tcase_add_test(tc_sqrt, sqrt_3);

  return s_sqrt;
}

Suite *trig_suite(void) {
  Suite *s_trig = suite_create("Trig_testcase");
  TCase *tc_trig = tcase_create("Trig");

  suite_add_tcase(s_trig, tc_trig);
  tcase_add_test(tc_trig, sin_1);
  tcase_add_test(tc_trig, sin_2);
  tcase_add_test(tc_trig, asin_1);
  tcase_add_test(tc_trig, asin_2);
  tcase_add_test(tc_trig, cos_1);
  tcase_add_test(tc_trig, acos_1);
  tcase_add_test(tc_trig, acos_2);
  tcase_add_test(tc_trig, tan_1);
  tcase_add_test(tc_trig, atan_1);
  return s_trig;
}

Suite *log_suite(void) {
  Suite *s_log = suite_create("Log_testcase");
  TCase *tc_log = tcase_create("Log");

  suite_add_tcase(s_log, tc_log);
  tcase_add_test(tc_log, log_1);
  tcase_add_test(tc_log, log_2);
  tcase_add_test(tc_log, log_3);
  tcase_add_test(tc_log, ln_1);
  tcase_add_test(tc_log, ln_2);
  tcase_add_test(tc_log, ln_3);
  return s_log;
}

Suite *credit_suite(void) {
  Suite *s_credit = suite_create("Credit_testcase");
  TCase *tc_credit = tcase_create("Credit");

  suite_add_tcase(s_credit, tc_credit);
  tcase_add_test(tc_credit, credit_ann_monthly);
  tcase_add_test(tc_credit, credit_ann_overpay);
  tcase_add_test(tc_credit, credit_ann_common_pay);
  tcase_add_test(tc_credit, credit_diff_test);
  return s_credit;
}

//////////////////////////////////////////////////////////

int main() {
  int number_failed;
  Suite *s_plus, *s_minus, *s_mult, *s_div, *s_mod, *s_deg, *s_sqrt, *s_trig,
      *s_log, *s_credit;
  SRunner *sr_plus, *sr_minus, *sr_mult, *sr_div, *sr_mod, *sr_deg, *sr_sqrt,
      *sr_trig, *sr_log, *sr_credit;

  s_plus = plus_suite();
  sr_plus = srunner_create(s_plus);
  srunner_set_fork_status(sr_plus, CK_NOFORK);
  srunner_run_all(sr_plus, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr_plus);
  srunner_free(sr_plus);

  s_minus = minus_suite();
  sr_minus = srunner_create(s_minus);
  srunner_set_fork_status(sr_minus, CK_NOFORK);
  srunner_run_all(sr_minus, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr_minus);
  srunner_free(sr_minus);

  s_mult = mult_suite();
  sr_mult = srunner_create(s_mult);
  srunner_set_fork_status(sr_mult, CK_NOFORK);
  srunner_run_all(sr_mult, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr_mult);
  srunner_free(sr_mult);

  s_div = div_suite();
  sr_div = srunner_create(s_div);
  srunner_set_fork_status(sr_div, CK_NOFORK);
  srunner_run_all(sr_div, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr_div);
  srunner_free(sr_div);

  s_mod = mod_suite();
  sr_mod = srunner_create(s_mod);
  srunner_set_fork_status(sr_mod, CK_NOFORK);
  srunner_run_all(sr_mod, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr_mod);
  srunner_free(sr_mod);

  s_deg = deg_suite();
  sr_deg = srunner_create(s_deg);
  srunner_set_fork_status(sr_deg, CK_NOFORK);
  srunner_run_all(sr_deg, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr_deg);
  srunner_free(sr_deg);

  s_sqrt = sqrt_suite();
  sr_sqrt = srunner_create(s_sqrt);
  srunner_set_fork_status(sr_sqrt, CK_NOFORK);
  srunner_run_all(sr_sqrt, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr_sqrt);
  srunner_free(sr_sqrt);

  s_trig = trig_suite();
  sr_trig = srunner_create(s_trig);
  srunner_set_fork_status(sr_trig, CK_NOFORK);
  srunner_run_all(sr_trig, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr_trig);
  srunner_free(sr_trig);

  s_log = log_suite();
  sr_log = srunner_create(s_log);
  srunner_set_fork_status(sr_log, CK_NOFORK);
  srunner_run_all(sr_log, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr_log);
  srunner_free(sr_log);

  s_credit = credit_suite();
  sr_credit = srunner_create(s_credit);
  srunner_set_fork_status(sr_credit, CK_NOFORK);
  srunner_run_all(sr_credit, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr_credit);
  srunner_free(sr_credit);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}