#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>

class MainWindow : public QMainWindow{
  Q_OBJECT
private:
  QTextEdit *inputField;
  QPushButton *submitButton;
  QListWidget *listOutputs;
private slots:
  void onSubmitClicked();
public:
  MainWindow(QWidget *parent = nullptr);
};

#endif
