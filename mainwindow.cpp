#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mb=new modbusEngine(reg,sizeof(reg),0,"127.0.0.1",this);
        // stworzenie obiektu klasy modbusEngine i przekazanie takich parametrów jak
        //wskaźnik na tablice rejestrów
        //rozmiar rejestrów do odczytania
        //bazowy rejestr  tutaj 0
        //adres ip serwera modbus
        
    connect(mb,SIGNAL(dataRaded()),this,SLOT(dataRead()));
        //gdy nowe dane przybędą wywołaj slot dataRead()
    mb->modbusStart(); //połącz
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    mb->writeBit(1,1); //przykładowa funkcja zapisz bit - ustawia jedynkę
}

void MainWindow::dataRead()  //aktualizacja cyklicznych danych na formatce
{
    ui->lineEdit->setText(QString::number(reg[0]));
    ui->lineEdit_2->setText(QString::number(reg[1]));
}

