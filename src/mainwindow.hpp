#ifndef WINDOW_H
#define WINDOW_H

#include "rapidcsv.h"

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QGroupBox>

#include <vector>

class MainWindow : public QMainWindow{
  Q_OBJECT
private:
  QLineEdit *dateInput;
  QLineEdit *timeInput;
  QLineEdit *levelInput;
  QTextEdit *descriptionInput;
  QPushButton *insertButton;
  
  QLineEdit *startDateFilter;
  QLineEdit *endDateFilter;
  QLineEdit *levelFilter;
  QListWidget *listOutputs;
  QPushButton *removeButton;

  rapidcsv::Document logDataDoc;

  void loadLogData();
  std::vector<std::vector<QString>> getFilteredLogData();
  void displayLogData();

  QGroupBox *createInputUI();
  QGroupBox *createDisplayUI();
  void createMainUI(QGroupBox *inputGroupBox, QGroupBox *displayGroupBox);
private slots:
  void onInsertClicked();
  void onFilterChanged();
public:
  MainWindow(QWidget *parent = nullptr);
};

#endif
