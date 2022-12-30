#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./parsetext.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setIconSize(QSize(25, 25));
    ui->listWidget->addItem(new QListWidgetItem(QIcon("C:\\Users\\Alena\\Documents\\task2-1\\img\\c++.png"), "C++", ui->listWidget));
    ui->listWidget->addItem(new QListWidgetItem(QIcon("C:\\Users\\Alena\\Documents\\task2-1\\img\\python.png"), "Python", ui->listWidget));
    ui->listWidget->addItem(new QListWidgetItem(QIcon("C:\\Users\\Alena\\Documents\\task2-1\\img\\java.png"), "Java", ui->listWidget));
    ui->listWidget->addItem(new QListWidgetItem(QIcon("C:\\Users\\Alena\\Documents\\task2-1\\img\\csharp.png"), "C#", ui->listWidget));
    ui->listWidget->addItem(new QListWidgetItem(QIcon("C:\\Users\\Alena\\Documents\\task2-1\\img\\php.png"), "PHP", ui->listWidget));
    ui->listWidget->addItem(new QListWidgetItem(QIcon("C:\\Users\\Alena\\Documents\\task2-1\\img\\js.png"), "JavaScript", ui->listWidget));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ParseText p(ui->plainTextEdit1->toPlainText());
    p.Parse();
    ui->plainTextEdit1->setPlainText(p.GetValue());
}

void MainWindow::on_plainTextEdit1_textChanged()
{
    //Я попыталась поместить код выше здесь, но он крашит..
}


void MainWindow::on_upPushButton_clicked()
{
   int curPos = ui->listWidget->currentRow();
   if(curPos == 0) return;
   QListWidgetItem *currentItem= ui->listWidget->item(curPos);
   ui->listWidget->takeItem(curPos);
   ui->listWidget->insertItem(curPos-1, currentItem);
   ui->listWidget->setCurrentRow(curPos+1);
}


void MainWindow::on_downPushButton_clicked()
{
    int curPos = ui->listWidget->currentRow();
    if(curPos == ui->listWidget->count()) return;
    QListWidgetItem *currentItem= ui->listWidget->item(curPos);
    ui->listWidget->takeItem(curPos);
    ui->listWidget->insertItem(curPos+1, currentItem);
    ui->listWidget->setCurrentRow(curPos+1);
}


void MainWindow::on_addPushButton_clicked()
{
    ui->listWidget->addItem(new QListWidgetItem(QIcon("C:\\Users\\Alena\\Documents\\task2-1\\img\\programming.png"), ui->lineEdit->text(), ui->listWidget));
}


void MainWindow::on_editPushButton_clicked()
{
    ui->listWidget->currentItem()->setText(ui->lineEdit->text());
}


void MainWindow::on_deletePushButton_clicked()
{
    int curPos = ui->listWidget->currentRow();
    if(curPos == -1) return;
    ui->listWidget->takeItem(curPos);
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked()) {
        ui->listWidget->setViewMode(QListWidget::IconMode);
    }
    else {
        ui->listWidget->setViewMode(QListWidget::ListMode);
    }
}

