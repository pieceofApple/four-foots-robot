#include"msp430f5529.h"

void delay_ms(int t)
{
  int i;
  for(i=0;i<t;i++)
  __delay_cycles(1000);
}
void setPWM_duty_cycle(int P_IO,int duty_cycle)
{
    switch (P_IO)
    {
    case 12:TA0CCR1 = duty_cycle;break;
    case 13:TA0CCR2 = duty_cycle;break;
    case 14:TA0CCR3 = duty_cycle;break;
    case 15:TA0CCR4 = duty_cycle;break;
    case 20:TA1CCR1 = duty_cycle;break;
    case 21:TA1CCR2 = duty_cycle;break;
    case 24:TA2CCR1 = duty_cycle;break;
    //case 25:TA2CCR2 = duty_cycle;break;//P25
    case 35:TB0CCR5 = duty_cycle;break;
    case 36:TB0CCR6 = duty_cycle;break;
    case 57:TB0CCR1 = duty_cycle;break;
    case 74:TB0CCR2 = duty_cycle;break;
    case 75:TB0CCR3 = duty_cycle;break;
    case 76:TB0CCR4 = duty_cycle;break;
    default:
        break;
    }
}

void set_PWM(int Cycle)
{
/**************/
//TA0~TA2
//Timer_A,TA0
    P1DIR |= BIT2 + BIT3+BIT4+BIT5;  // P1.2,3,4,5
    P1SEL |= BIT2 + BIT3+BIT4+BIT5;  // P1.2,3,4,5
    TA0CCR0 = Cycle;    //  PWM
    TA0CCTL1 =OUTMOD_7;  //TA0//  P1.2ΪOUTMOD_7ģʽ
    TA0CCR1 = 800; //  PWM   P1.2
    TA0CCTL2 = OUTMOD_7;//  P1.3ΪOUTMOD_7ģʽ
    TA0CCR2 =2200;   //  PWM   P1.3
    TA0CCTL3 = OUTMOD_7;//  P1.3ΪOUTMOD_7ģʽ
    TA0CCR3 =2200;   //  PWM   P1.4
    TA0CCTL4 = OUTMOD_7;//  P1.3ΪOUTMOD_7ģʽ
    TA0CCR4 =800;   //  PWM   P1.5
    TA0CTL = TASSEL_2 + MC_1 +TACLR +ID_3;
//Timer_A,TA1
    P2DIR |= BIT0 + BIT1+BIT3+BIT4;  // P2.0,1,3,4
    P2SEL |= BIT0 + BIT1+BIT3+BIT4;  // P2.0,1,3,4
    TA1CCR0 = Cycle;    //  PWM
    TA1CCTL1 =OUTMOD_7;
    TA1CCR1 = 1000; //  PWM   P2.0
    TA1CCTL2 = OUTMOD_7;//  P2.1ΪOUTMOD_7ģʽ
    TA1CCR2 =800;   //  PWM   P2.1
    TA1CTL = TASSEL_2 + MC_1 +TACLR+ID_3;
//TA2
    TA2CCR0 = Cycle;//PWM
    TA2CCTL1 = OUTMOD_7;//  P2.4ΪOUTMOD_7ģʽ
    TA2CCR1 = 800;
    //TA2CCTL2 = OUTMOD_7;//  P2.5ΪOUTMOD_7ģʽ
    //TA2CCR2 =500; //  PWM   P2.5
    /*P2.5  ʱ   */
    TA2CTL = TASSEL_2 + MC_1 +TACLR+ID_3;
//Timer_B,TA0
    P3DIR |= BIT5 + BIT6; // P3.5,6
    P3SEL |= BIT5 + BIT6; // P3.5,6
    P5DIR |= BIT7;
    P5SEL |= BIT7;
    P7DIR |= BIT4+BIT5+BIT6+BIT7;
    P7SEL |= BIT4+BIT5+BIT6+BIT7;
    TB0CCR0 = Cycle;      //  PWM
    TB0CCTL5 =OUTMOD_7;   //TB0 //  P3.5ΪOUTMOD_7ģʽ
    TB0CCR5 = 1000;       //  PWM   P3.5
    TB0CCTL6 = OUTMOD_7;  //  P3.6ΪOUTMOD_7ģʽ
    TB0CCR6 = 500;        //  PWM   P3.6
    TB0CCTL1 =OUTMOD_7;   //TB0 //  P5.7ΪOUTMOD_7ģʽ
    TB0CCR1 = 500;       //  PWM   P5.7
    TB0CCTL2 = OUTMOD_7;  //  P7.4ΪOUTMOD_7ģʽ
    TB0CCR2 = 500;        //  PWM   P7.4
    TB0CCTL3 =OUTMOD_7;   //TB0 //  P7.5ΪOUTMOD_7ģʽ
    TB0CCR3 = 500;       //  PWM   P7.5
    TB0CCTL4 = OUTMOD_7;  //  P7.6ΪOUTMOD_7ģʽ
    TB0CCR4 = 500;        //  PWM   P7.6

    TB0CTL = TASSEL_2 + MC_1 +TACLR+ID_3;
//Timer_B,TB0
/**************/
}
