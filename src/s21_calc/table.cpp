#include "table.h"
// #include "ui_table.h"

Table::Table(QWidget *parent) : QDialog(parent) {
  // doing this creates the table, then you set the row count
  table = new QTableWidget;
  table->setRowCount(5);
  table->setColumnCount(5);

  // QTableWidgetItem puts data into each cell. Just an example
  //    for (int i = 0; i < 30000; i++){
  //        for (int j = 0; j < 1; j++) {
  //            QTableWidgetItem *item = new
  //                QTableWidgetItem(tr("%1").arg(pow(i, j+1)));
  //            table->setItem(i, j, item);
  //        }
  //    }

  QHBoxLayout *layout = new QHBoxLayout;
  layout->addWidget(table);

  setLayout(layout);
}

// Table::~Table() {
//     delete table;
// }
