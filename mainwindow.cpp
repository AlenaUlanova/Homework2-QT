#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./parsetext.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

