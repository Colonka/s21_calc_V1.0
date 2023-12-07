#include "s21_calc.h"

void credit_ann(double sum, int time, double percent, double* month_pay,
                double* overpay, double* common_pay) {
  double month_perc = percent / (12 * 100);
  double k_down = 1 - pow(1 + month_perc, -time);
  *month_pay = sum * month_perc / k_down;
  *common_pay = *month_pay * (double)time;
  *overpay = *common_pay - sum;
}

void credit_diff(double sum, int time, double percent, double remainder,
                 double* month_pay, double* overpay, int cur_m) {
  double body = sum / time;
  double profit = remainder * (percent / 12 / 100);
  month_pay[cur_m] = body + profit;
  *overpay = *overpay + profit;
}