#ifndef CREDIT_WINDOW_H
#define CREDIT_WINDOW_H

#include <QDialog>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
class credit_window;
}

class credit_window : public QDialog {
  Q_OBJECT

 public:
  explicit credit_window(QWidget *parent = nullptr);
  ~credit_window();

 private:
  Ui::credit_window *ui;
  QTableWidget *table;
};

#endif  // CREDIT_WINDOW_H
