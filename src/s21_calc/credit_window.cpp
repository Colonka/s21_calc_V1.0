#include "credit_window.h"

#include "ui_credit_window.h"

credit_window::credit_window(QWidget *parent)
    : QDialog(parent), ui(new Ui::credit_window) {
  table = new QTableWidget;
  table->setRowCount(5);
  table->setColumnCount(5);
  table->show();
  // ui->setupUi(this);
}

credit_window::~credit_window() { delete ui; }
