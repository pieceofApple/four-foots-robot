#include "driverlib.h"
#include "msp430f5529.h"
#include "IIC.h"
#define    SCL_HIGH    P8OUT|=BIT1
#define    SCL_LOW     P8OUT&=~BIT1
#define    SDA_HIGH    P8OUT|=BIT2
#define    SDA_LOW     P8OUT&=~BIT2
#define    SDA_OUT     P8DIR|=BIT2
#define    SDA_IN      P8DIR&=~BIT2
#define    SCL_OUT     P8DIR|=BIT1
#define    SDA         P8IN&BIT2


void IIC_start();//
void IIC_stop();//
void SendACK(unsigned char ack);
void IIC_writebyte(unsigned char IIC_byte);///
unsigned char IIC_testACK();///
unsigned char IIC_readebyte();///



///开启信号
void IIC_start()
{
    SDA_OUT;
    SCL_OUT;
    SCL_HIGH;
    SDA_HIGH;
    __delay_cycles(5);
    SDA_LOW;
    __delay_cycles(5);
    SCL_LOW;
}
///停止信号
void IIC_stop()
{
    SDA_OUT;
    SCL_OUT;
    SDA_LOW;
    SCL_HIGH;
    __delay_cycles(5);
    SDA_HIGH;
    __delay_cycles(5);
}


//发送应答信号(MCU=>||)
void SendACK(unsigned char ack)
{
    SDA_OUT;
    SCL_OUT;
if(ack==1)
{
    SDA_HIGH;
}
else if(ack==0)
{
    SDA_LOW;
}
else
    return;
SCL_HIGH;
__delay_cycles(5);
SCL_LOW;
__delay_cycles(5);
}
////接收应答信号（||=>MCU）
unsigned char IIC_testACK()
{
    unsigned char a;
    SCL_OUT;
    SDA_IN;
//GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P8, GPIO_PIN2);
    SCL_HIGH;
    __delay_cycles(5);
    if(GPIO_getInputPinValue (GPIO_PORT_P8, GPIO_PIN2)==1)
    {
        a=1;
    }
    else
    {
        a=0;
    }

    SCL_LOW;
    __delay_cycles(5);
    SDA_OUT;
    return a;
}

///向IIC总线发送数据（MCU=>||）
void IIC_writebyte(unsigned char IIC_byte)
{
    unsigned char i;
    SDA_OUT;
    SCL_OUT;
//    SCL_LOW;
        for (i=0; i<8; i++)         //8位计数器
            {
                if((IIC_byte<<i)&0x80)
                {
                    SDA_HIGH;
                }
                else
                {
                    SDA_LOW;
                }

        __delay_cycles(5);
        SCL_HIGH;
        __delay_cycles(5);
        SCL_LOW;
//        __delay_cycles(10);
//        IIC_byte<<=1;
    }

    IIC_testACK();
}


////IIC接收一个字节(||——>MCU)
unsigned char IIC_readebyte()
{
    unsigned char i,k=0;
    SDA_IN;
    GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P8, GPIO_PIN2);
    SCL_OUT;
    SCL_LOW;
    __delay_cycles(50);
    for(i=0;i<8;i++)
    {
        SCL_HIGH;
        k=k<<1;
        if(SDA)
            k|=1;
        SCL_LOW;
        __delay_cycles(50);
    }
    SDA_OUT;
    __delay_cycles(50);
    return k;
}




