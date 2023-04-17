#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<modbusengine.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    modbusEngine* mb;
    uint16_t reg[2];// tablica rejestrów modbusa przekazemy jako wskaźnik do obiektu klasy modbus Engine
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void dataRead(); // slot gdy dane będą gotowe do obróbki (tablica rejestrów odświerzona)

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
