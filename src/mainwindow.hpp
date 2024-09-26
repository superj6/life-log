#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QGroupBox>

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
  QPushButton *filterButton;
  QListWidget *listOutputs;

  QGroupBox *createInputUI();
  QGroupBox *createDisplayUI();
  void createMainUI(QGroupBox *inputGroupBox, QGroupBox *displayGroupBox);
private slots:
  void onInsertClicked();
  void onFilterClicked();
public:
  MainWindow(QWidget *parent = nullptr);
};

#endif
