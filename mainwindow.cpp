#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mb=new modbusEngine(reg,sizeof(reg),0,"127.0.0.1",this);
    connect(mb,SIGNAL(dataRaded()),this,SLOT(dataRead()));
    mb->modbusStart();
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    mb->writeBit(1,1);
}

void MainWindow::dataRead()
{
    ui->lineEdit->setText(QString::number(reg[0]));
    ui->lineEdit_2->setText(QString::number(reg[1]));
}

