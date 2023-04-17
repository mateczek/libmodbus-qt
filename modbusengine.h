#ifndef MODBUSENGINE_H
#define MODBUSENGINE_H

#include <QObject>
#include<QTimer>
#include<modbus/modbus-tcp.h>
class modbusEngine : public QObject
{
    Q_OBJECT
    uint16_t *modbusReg;
    int regSize;
    int baseAdr;
    QString ip;

    modbus_t *mb;
    QTimer *timer;

    bool modbusStop();
public:
    explicit modbusEngine(uint16_t *_modbusReg,int _regSize,int _baseAdr, QString _ip, QObject *parent = nullptr);
    ~modbusEngine();
    bool writeBit(int adress, int value);
    bool modbusStart();



signals:
    void dataRaded();
    void modbusError();

private slots:
    void loopReadData();
};

#endif // MODBUSENGINE_H
