#include "driverlib.h"
#include"UART.h"
void UARTInit()
{
    GPIO_setAsPeripheralModuleFunctionInputPin(
        GPIO_PORT_P3,
        GPIO_PIN3+GPIO_PIN4
        );

    USCI_A_UART_initParam param1 = {0};
    param1.selectClockSource = USCI_A_UART_CLOCKSOURCE_SMCLK;
    param1.clockPrescalar = 52;
    param1.firstModReg = 1;
    param1.secondModReg = 0;
    param1.parity = USCI_A_UART_NO_PARITY;
    param1.msborLsbFirst = USCI_A_UART_LSB_FIRST;
    param1.numberofStopBits = USCI_A_UART_ONE_STOP_BIT;
    param1.uartMode = USCI_A_UART_MODE;
    param1.overSampling = USCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION;

    if (STATUS_FAIL == USCI_A_UART_init(USCI_A0_BASE, &param1)){
        return;
    }
    USCI_A_UART_enable(USCI_A0_BASE);
}

void FS(unsigned char*write)                          //向串口写一个字符串
{
        while(*write!='\0')
        {
            USCI_A_UART_transmitData (USCI_A0_BASE,*write);
            __delay_cycles(5);
                write++;
        }
        USCI_A_UART_transmitData (USCI_A0_BASE,0x0d);
        USCI_A_UART_transmitData (USCI_A0_BASE,0x0a);
}
void FSNO(unsigned char*write)                          //向串口写一个字符串
{
        while(*write!='\0')
        {
            USCI_A_UART_transmitData (USCI_A0_BASE,*write);
            __delay_cycles(5);
                write++;
        }
}

void YS(int b)
{
    unsigned char a0[2]="0";
    unsigned char a1[2]="1";
    unsigned char a2[2]="2";
    unsigned char a3[2]="3";
    unsigned char a4[2]="4";
    unsigned char a5[2]="5";
    unsigned char a6[2]="6";
    unsigned char a7[2]="7";
    unsigned char a8[2]="8";
    unsigned char a9[2]="9";
    if(b==0)
    {
    FSNO(a0);
    }
    else if(b==1)
    {
    FSNO(a1);
    }
    else if(b==2)
    {
    FSNO(a2);
    }
    else if(b==3)
    {
    FSNO(a3);
    }
    else if(b==4)
    {
    FSNO(a4);
    }
    else if(b==5)
    {
    FSNO(a5);
    }
    else if(b==6)
    {
    FSNO(a6);
    }
    else if(b==7)
    {
    FSNO(a7);
    }
    else if(b==8)
    {
    FSNO(a8);
    }
    else if(b==9)
    {
    FSNO(a9);
    }

}




void HS(int a)
{

int b;
int c;
int e;
int f;
unsigned char sign[2]="-";
if(a>=0)
{
b= a%10;               //个位数
c= a/ 10 % 10;           //十位数
e= a/ 100 % 10;          //百位数
f= a/ 1000;              //千位数
if(f==0&&e==0&&c==0&&b!=0)
{
YS(b);
}
else if(f==0&&e==0&&c!=0)
{
YS(c);
YS(b);
}
else if(f==0&&e!=0)
{
 YS(e);
 YS(c);
 YS(b);
}
else if(f!=0)
{
    YS(f);
    YS(e);
    YS(c);
    YS(b);
}
}
else if(a<0)
{
a=-a;
b= a%10;               //个位数
c= a/ 10 % 10;           //十位数
e= a/ 100 % 10;          //百位数
f= a/ 1000;              //千位数
if(a<10)
{
FSNO(sign);
YS(b);
}
else if(f==0&&e==0&&c==0&&b!=0)
{
FSNO(sign);
YS(c);
YS(b);
}
else if(f==0&&e==0&&c!=0)
{
FSNO(sign);
 YS(e);
 YS(c);
 YS(b);
}
else if(f!=0)
{
    FSNO(sign);
    YS(f);
    YS(e);
    YS(c);
    YS(b);
}
















}

}


