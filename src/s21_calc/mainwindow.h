#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDateTime>
#include <QDialog>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <Qvector>

extern "C" {
#include "../source/s21_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  bool isClickedX = false;
  QString input_real;
  double h, X;
  int Xbegin, Xend, Ybegin, Yend;
  QVector<double> x, y;
  QTableWidget *table;
  QString date_credit;
  std::string date_credit_str;
  QDate cd;

 private slots:
  /**
   * @brief Функция обработки нажатия кнопок цифр и простых операторов
   */
  void digit_buttons();
  /**
   * @brief Функция обработки нажатия кнопок тригонометрических функция
   */
  void trigon_func();
  /**
   * @brief Функция обработки нажатия кнопки посимвольного удаления
   */
  void button_delete();
  /**
   * @brief Функция обработки нажатия кнопки удаления всей строки
   */
  void button_AC();
  /**
   * @brief Функция обработки нажатия кнопки печати символа "х"
   */
  void button_X();
  /**
   * @brief Функция обработки нажатия кнопки символа "="
   */
  void button_equal();
  /**
   * @brief Функция обработки нажатия кнопки построения графика
   */
  void button_build_graph();
  /**
   * @brief Функция обработки нажатия кнопки расчета кредита
   */
  void on_pushButton_credit_count_clicked();
  /**
   * @brief Вспомогательная функция для заполнения столбца "Месяц"
   * @param month - номер месяца
   * @param month - номер года
   * @param res - указатель на переменную храняющую данные месяца и года в
   * строковом формате
   */
  void set_credit_date(int month, int year, QString *res);
  /**
   * @brief Функция для расчета количества месяцев прошедших с начала кредита до
   * текущего месяца
   * @param st_m - номер месяца начала кредита
   * @param st_y - номер года начала кредита
   * @param cr_m - номер месяца начала кредита
   * @param cr_y - номер года начала кредита
   * @return  количество месяцев прошедших с даты начала кредита по текущцю дату
   */
  int time_from_start(int st_m, int st_y, int cr_m, int cr_y);
};
#endif  // MAINWINDOW_H
