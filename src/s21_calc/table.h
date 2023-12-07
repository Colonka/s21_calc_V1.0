#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QTableWidgetItem>

class Table : public QDialog {
  Q_OBJECT

 public:
  explicit Table(QWidget *parent = 0);
  ~Table();

 private:
  QTableWidget *table;
};

#endif  // TABLE_H
