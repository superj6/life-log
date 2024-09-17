#include "mainwindow.hpp"

#include <QLayout>
#include <QGroupBox>
#include <QLabel>

#include <QDebug>

void MainWindow::onSubmitClicked(){
  QString input = descriptionInput->toPlainText();

  //qDebug() << input;

  QListWidgetItem *listItem = new QListWidgetItem;
  listItem->setText(input);

  listOutputs->addItem(listItem);
}

QGroupBox *MainWindow::createInputUI(){
  dateInput = new QLineEdit;
  timeInput = new QLineEdit;
  levelInput = new QLineEdit;
  descriptionInput = new QTextEdit;
  insertButton = new QPushButton(tr("Insert Log"));

  connect(insertButton, SIGNAL(clicked(bool)), this, SLOT(onSubmitClicked()));

  QGridLayout *layout = new QGridLayout;
  layout->addWidget(new QLabel(tr("Date")), 0, 0);
  layout->addWidget(new QLabel(tr("Time")), 0, 1);
  layout->addWidget(new QLabel(tr("Level")), 0, 2);

  layout->addWidget(dateInput, 1, 0);
  layout->addWidget(timeInput, 1, 1);
  layout->addWidget(levelInput, 1, 2);

  layout->addWidget(new QLabel(tr("Description")), 2, 0);
  layout->addWidget(descriptionInput, 3, 0, 2, 3);
  layout->addWidget(insertButton, 5, 1);

  QGroupBox *groupBox = new QGroupBox;
  groupBox->setLayout(layout);

  return groupBox;
}

QGroupBox *MainWindow::createDisplayUI(){
  listOutputs = new QListWidget;

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(listOutputs);

  QGroupBox *groupBox = new QGroupBox;
  groupBox->setLayout(layout);

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
