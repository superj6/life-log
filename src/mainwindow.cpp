#include "mainwindow.hpp"

#include <QVBoxLayout>
#include <QGroupBox>

#include <QDebug>

void MainWindow::onSubmitClicked(){
  QString input = inputField->toPlainText();

  //qDebug() << input;

  QListWidgetItem *listItem = new QListWidgetItem;
  listItem->setText(input);

  listOutputs->addItem(listItem);
}

QGroupBox *MainWindow::createInputUI(){ 
  inputField = new QTextEdit(this);
  submitButton = new QPushButton("Submit", this);

  connect(submitButton, SIGNAL(clicked(bool)), this, SLOT(onSubmitClicked()));

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(inputField);
  layout->addWidget(submitButton);

  QGroupBox *groupBox = new QGroupBox;
  groupBox->setLayout(layout);

  return groupBox;
}

QGroupBox *MainWindow::createDisplayUI(){
  listOutputs = new QListWidget;

  QVBoxLayout *displayVLayout = new QVBoxLayout;
  displayVLayout->addWidget(listOutputs);

  QGroupBox *groupBox = new QGroupBox;
  groupBox->setLayout(displayVLayout);

  return groupBox;
}

void MainWindow::createMainUI(QGroupBox *inputGroupBox, QGroupBox *displayGroupBox){
  QHBoxLayout *layout = new QHBoxLayout;
  layout->addWidget(inputGroupBox);
  layout->addWidget(displayGroupBox);

  QWidget *centralWidget = new QWidget(this);
  centralWidget->setLayout(layout);
  setCentralWidget(centralWidget);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
  QGroupBox *inputGroupBox = createInputUI();
  QGroupBox *displayGroupBox = createDisplayUI();

  createMainUI(inputGroupBox, displayGroupBox);
}
