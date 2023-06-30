#include "driverlib.h"
#include "mpu6050/Mpu-6050.h"
#include "clk.h"
#include"PWM_ACLK.h"
#include"MOVE.h"
#define LED BIT0 // LED连接到P1.0
#define RXD BIT3 // RXD连接到P3.4
#define TXD BIT4 // TXD连接到P3.5
int bn;
void UART_init(void)
{
    P3SEL |= RXD + TXD; // 配置P4.4和P4.5为UART模式

    UCA0CTL1 |= UCSSEL_2; // 使用SMCLK作为UART时钟
    UCA0BR0 = 52; // 设置波特率为9600（SMCLK=1MHz时）
    UCA0BR1 = 0;
    UCA0MCTL = UCBRS_1 + UCBRF_0 + UCOS16; // UCBRSx值为0x00

    UCA0CTL1 &= ~UCSWRST; // 初始化UART
    UCA0IE |= UCRXIE; // 启用UART接收中断
}

//#define duty_points 1000
int main(void)
{

  WDT_A_hold(WDT_A_BASE);
  InitMPU6050();
  clk_Init ();

  set_PWM(655);//20ms

  UART_init(); // 初始化UART

  __bis_SR_register(GIE); // 进入低功耗模式，启用全局中断

  while(1)
  {
      while(bn==1){
        straight_ACLK();
      }
      while(bn==2){
        nishizhen_ACLK();
      }
      while(bn==0){
        paxia_ACLK();
      }
      while(bn==3){
        zhanli_ACLK();
      }while(bn==4){
          wending();
      }
  }
}
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
{
    switch(__even_in_range(UCA0IV, USCI_A0_VECTOR))
    {
        case USCI_NONE: break;
        case USCI_UCRXIFG: // UART接收中断
            if (UCA0RXBUF == '1') // 如果收到'1'
            {
                bn=1;
            }
            else if (UCA0RXBUF == '0') // 如果收到'0'
            {
                bn=0;
            }
            else if (UCA0RXBUF == '2') // 如果收到'2'
            {
                bn=2;
            }
            else if (UCA0RXBUF == '3') // 如果收到'3'
            {
                bn=3;
            }
            else if (UCA0RXBUF == '4') // 如果收到'4'
            {
                bn=4;
            }
            break;
        default: break;
    }
}
