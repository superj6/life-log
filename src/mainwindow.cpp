#include "mainwindow.hpp"

#include <QVBoxLayout>
#include <QGroupBox>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
  inputField = new QTextEdit(this);
  submitButton = new QPushButton("Submit", this);

  connect(submitButton, SIGNAL(clicked(bool)), this, SLOT(onSubmitClicked()));

  QVBoxLayout *inputVLayout = new QVBoxLayout;
  inputVLayout->addWidget(inputField);
  inputVLayout->addWidget(submitButton);

  QGroupBox *inputGroupBox = new QGroupBox;
  inputGroupBox->setLayout(inputVLayout);

  listOutputs = new QListWidget;

  QVBoxLayout *displayVLayout = new QVBoxLayout;
  displayVLayout->addWidget(listOutputs);

  QGroupBox *displayGroupBox = new QGroupBox;
  displayGroupBox->setLayout(displayVLayout);

  QHBoxLayout *centralHLayout = new QHBoxLayout;
  centralHLayout->addWidget(inputGroupBox);
  centralHLayout->addWidget(displayGroupBox);

  QWidget *centralWidget = new QWidget(this);
  centralWidget->setLayout(centralHLayout);
  setCentralWidget(centralWidget);
}

void MainWindow::onSubmitClicked(){
  QString input = inputField->toPlainText();

  //qDebug() << input;

  QListWidgetItem *listItem = new QListWidgetItem;
  listItem->setText(input);

  listOutputs->addItem(listItem);
}
