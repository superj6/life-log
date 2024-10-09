#include "mainwindow.hpp"

#include <QLayout>
#include <QGroupBox>
#include <QLabel>

#include <QDebug>

namespace rapidcsv{
  template<>
  void Converter<QString>::ToVal(const std::string& pStr, QString& pVal) const{
    pVal = QString::fromStdString(pStr);
  }


  template<>
  void Converter<QString>::ToStr(const QString& pVal, std::string& pStr) const{
    pStr = pVal.toStdString();
  }
}

void MainWindow::loadLogData(){
  logDataDoc = rapidcsv::Document("resources/log.csv");
}

std::vector<std::vector<QString>> MainWindow::getFilteredLogData(){
  std::vector<std::vector<QString>> logData;
  for(unsigned int i = 0; i < logDataDoc.GetRowCount(); i++){
    std::vector<QString> row = logDataDoc.GetRow<QString>(i);
    if(!startDateFilter->text().isEmpty() && row[0] < startDateFilter->text()){
      continue;
    }
    if(!endDateFilter->text().isEmpty() && row[0] > endDateFilter->text()){
      continue;
    }
    if(!levelFilter->text().isEmpty() && row[2] < levelFilter->text()){
      continue;
    }
    logData.push_back(std::move(row));
  }
  return logData;
}

void MainWindow::displayLogData(){
  std::vector<std::vector<QString>> logData = getFilteredLogData();
  
  sort(logData.begin(), logData.end());

  listOutputs->clear();
  for(auto row : logData){
    QListWidgetItem *listItem = new QListWidgetItem;
    QString listItemText = QString("%1 %2 %3 - %4").arg(row[0], row[1], row[2], row[3]); 
    listItem->setText(listItemText);
    listOutputs->addItem(listItem);
  }
}

void MainWindow::onInsertClicked(){
  QString input = descriptionInput->toPlainText();

  std::vector<QString> row = {dateInput->text(), timeInput->text(), levelInput->text(), input};
  logDataDoc.InsertRow(logDataDoc.GetRowCount(), row);
  logDataDoc.Save();

  displayLogData();
}

void MainWindow::onFilterChanged(){
  displayLogData();
}

QGroupBox *MainWindow::createInputUI(){
  dateInput = new QLineEdit;
  timeInput = new QLineEdit;
  levelInput = new QLineEdit;
  descriptionInput = new QTextEdit;
  insertButton = new QPushButton(tr("Insert"));

  connect(insertButton, SIGNAL(clicked(bool)), this, SLOT(onInsertClicked()));

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

  layout->setRowStretch(6, 1);

  QGroupBox *groupBox = new QGroupBox;
  groupBox->setLayout(layout);

  return groupBox;
}

QGroupBox *MainWindow::createDisplayUI(){
  startDateFilter = new QLineEdit;
  endDateFilter = new QLineEdit;
  levelFilter = new QLineEdit;
  listOutputs = new QListWidget;
  removeButton = new QPushButton(tr("Remove"));

  listOutputs->setWordWrap(true);

  connect(startDateFilter, SIGNAL(textChanged(const QString &)), this, SLOT(onFilterChanged()));
  connect(endDateFilter, SIGNAL(textChanged(const QString &)), this, SLOT(onFilterChanged()));
  connect(levelFilter, SIGNAL(textChanged(const QString &)), this, SLOT(onFilterChanged()));

  QGridLayout *layout = new QGridLayout;
  layout->addWidget(new QLabel(tr("Start Date")), 0, 0);
  layout->addWidget(new QLabel(tr("End Date")), 0, 1);
  layout->addWidget(new QLabel(tr("Level Cutoff")), 0, 2);

  layout->addWidget(startDateFilter, 1, 0);
  layout->addWidget(endDateFilter, 1, 1);
  layout->addWidget(levelFilter, 1, 2);
 
  layout->addWidget(new QLabel(tr("Logs")), 2, 0);
  layout->addWidget(listOutputs, 3, 0, 2, 3);
  layout->addWidget(removeButton, 5, 1);

  layout->setRowStretch(4, 1);

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

  loadLogData();
  displayLogData();
}
