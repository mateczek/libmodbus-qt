#include "modbusengine.h"
#include <string>
bool modbusEngine::modbusStop()
{
    timer->stop();
    if(mb!=nullptr){
        modbus_close(mb);
        modbus_free(mb);
        mb=nullptr;
    }
    emit modbusError();
}

modbusEngine::modbusEngine(uint16_t *_modbusReg,int _regSize,int _baseAdr, QString _ip, QObject *parent)
    : QObject{parent}
{
    modbusReg=_modbusReg;
    regSize=_regSize;
    baseAdr =_baseAdr;
    ip = _ip;
    mb=nullptr;
    timer=new QTimer(this);// timer do cyklicznych zapytań 
    connect(timer,SIGNAL(timeout()),this,SLOT(loopReadData()));//loopReadData wywoływana przez timer funkcja pytająca o rejestry
}

modbusEngine::~modbusEngine()
{
   modbusStop();
}

bool modbusEngine::writeBit(int adress, int value)
{
   int ret= modbus_write_bit(mb,adress,value);
   if (ret==-1) modbusStop();
}

bool modbusEngine::modbusStart()
{
    mb = modbus_new_tcp(ip.toStdString().c_str() ,502);
    int ret =modbus_connect(mb);
    if (ret==-1){
        modbusStop();
    }else timer->start(1000);
}

void modbusEngine::loopReadData()
{
    int ret=modbus_read_registers(mb,baseAdr,regSize,modbusReg);
    //odczyt rejestów zaczynających się od baseAdr i w liczbie regSize. odczytane rejestry do tablicy modbusReg
    if (ret==-1) emit modbusStop();//gdy się nie powiedzie odczyt zatrzymaj aplikację.
    else emit dataRaded();
}
