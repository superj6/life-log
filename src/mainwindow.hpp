#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include <QGroupBox>

class MainWindow : public QMainWindow{
  Q_OBJECT
private:
  QTextEdit *inputField;
  QPushButton *submitButton;
  QListWidget *listOutputs;

  QGroupBox *createInputUI();
  QGroupBox *createDisplayUI();
  void createMainUI(QGroupBox *inputGroupBox, QGroupBox *displayGroupBox);
private slots:
  void onSubmitClicked();
public:
  MainWindow(QWidget *parent = nullptr);
};

#endif
