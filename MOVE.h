#include"msp430f5529.h"
//ACLK
void wending()
{
    float a;
    //float b;
    //float c;
    int dutycyclex_R,dutycyclex_L;
    //int dutycycley;

    a=Mpu6050AccelAngle(ACCEL_XOUT)-5; //-5为微调
    //b=Mpu6050AccelAngle(ACCEL_YOUT);
    //c=Mpu6050AccelAngle(ACCEL_ZOUT);

    if(a<0)
    {
        dutycyclex_R = 34-abs((int)a*0.5);
        dutycyclex_L = 68-abs((int)a*0.5);
        if (dutycyclex_R < 24)
        {
            dutycyclex_R = 24; // 如果结果小于500(17)，将其修正为500(17)
        } else if (dutycyclex_R > 85)
        {
            dutycyclex_R = 85; // 如果结果大于2500，将其修正为2500
        }
        if (dutycyclex_L < 17)
        {
            dutycyclex_L = 17; // 如果结果小于500(17)，将其修正为500(17)
        } else if (dutycyclex_L > 72)
        {
            dutycyclex_L = 72; // 如果结果大于2500，将其修正为2500
        }
    }
    else if(a>0)
    {
        dutycyclex_R = 34+abs((int)a*0.5);
        dutycyclex_L = 68+abs((int)a*0.5);
        if (dutycyclex_R < 24)
        {
            dutycyclex_R = 24; // 如果结果小于500(17)，将其修正为500(17)
        } else if (dutycyclex_R > 85)
        {
            dutycyclex_R = 85; // 如果结果大于2500，将其修正为2500
        }
        if (dutycyclex_L < 17)
        {
            dutycyclex_L = 17; // 如果结果小于500(17)，将其修正为500(17)
        } else if (dutycyclex_L > 72)
        {
            dutycyclex_L = 72; // 如果结果大于2500，将其修正为2500
        }
    }

//      if(b<0)
//      {
//          dutycycley = 51-abs((int)b*0.375);
//      }
//      else if(b>0)
//      {
//          dutycycley = 51+abs((int)b*0.375);
//      }



//      if (dutycycley < 17)
//      {
//          dutycycley = 17; // 如果结果小于500，将其修正为500
//      } else if (dutycycley > 85)
//      {
//          dutycycley = 85; // 如果结果大于2500，将其修正为2500
//      }
    setPWM_duty_cycle(20,34);setPWM_duty_cycle(12,dutycyclex_R);//前右脚
    setPWM_duty_cycle(21,30);setPWM_duty_cycle(13,dutycyclex_L);//前左脚
    setPWM_duty_cycle(35,30);setPWM_duty_cycle(15,dutycyclex_R);//后右脚
    setPWM_duty_cycle(24,34);setPWM_duty_cycle(14,dutycyclex_L);//后左脚
}

void straight_ACLK()
{
    //三足稳定，一脚前进
    setPWM_duty_cycle(21,20);setPWM_duty_cycle(13,58);//前左脚
    delay_ms(500);
    setPWM_duty_cycle(13,72);
    delay_ms(500);
    setPWM_duty_cycle(21,48);//前左脚
    //delay_ms(500);
    setPWM_duty_cycle(35,48);setPWM_duty_cycle(15,44);//后右脚
    delay_ms(500);
    setPWM_duty_cycle(15,24);
    delay_ms(500);
    setPWM_duty_cycle(35,20);//后右脚
    //delay_ms(500);
    setPWM_duty_cycle(20,48);setPWM_duty_cycle(12,44);//前右脚
    delay_ms(500);
    setPWM_duty_cycle(12,24);
    delay_ms(500);
    setPWM_duty_cycle(20,20);//前右脚
    //delay_ms(500);
    setPWM_duty_cycle(24,20);setPWM_duty_cycle(14,58);//后左脚
    delay_ms(500);
    setPWM_duty_cycle(14,72);
    delay_ms(500);
    setPWM_duty_cycle(24,48);//后左脚
    //delay_ms(500);
}
void zhanli_ACLK()
{
    //set_PWM(655);
    //17-0, 34-45,  51-90,  68-135,  85-180
    //500-0,1000-45,1500-90,2000-135,2500-180
        setPWM_duty_cycle(20,34);setPWM_duty_cycle(12,24);//前右脚
        setPWM_duty_cycle(21,30);setPWM_duty_cycle(13,72);//前左脚
        setPWM_duty_cycle(35,30);setPWM_duty_cycle(15,24);//后右脚
        setPWM_duty_cycle(24,34);setPWM_duty_cycle(14,72);//后左脚
}
void paxia_ACLK()
{
    //趴下，待机动作
        setPWM_duty_cycle(20,34);setPWM_duty_cycle(12,51);//前右脚
        setPWM_duty_cycle(21,30);setPWM_duty_cycle(13,51);//前左脚
        setPWM_duty_cycle(35,30);setPWM_duty_cycle(15,51);//后右脚
        setPWM_duty_cycle(24,34);setPWM_duty_cycle(14,51);//后左脚
}
void nishizhen_ACLK()
{
    //逆时针转圈
    setPWM_duty_cycle(21,48);setPWM_duty_cycle(13,58);//前左脚
    delay_ms(800);
    setPWM_duty_cycle(13,65);
    delay_ms(800);
    setPWM_duty_cycle(21,20);//前左脚
    delay_ms(800);
    setPWM_duty_cycle(24,48);setPWM_duty_cycle(14,58);//后左脚
    delay_ms(800);
    setPWM_duty_cycle(14,65);
    delay_ms(800);
    setPWM_duty_cycle(24,20);//后左脚
    delay_ms(800);
    setPWM_duty_cycle(35,48);setPWM_duty_cycle(15,44);//后右脚
    delay_ms(800);
    setPWM_duty_cycle(15,27);
    delay_ms(800);
    setPWM_duty_cycle(35,20);//后右脚
    delay_ms(800);
    setPWM_duty_cycle(20,48);setPWM_duty_cycle(12,44);//前右脚
    delay_ms(800);
    setPWM_duty_cycle(12,27);
    delay_ms(800);
    setPWM_duty_cycle(20,20);//前右脚
    delay_ms(800);
}
//SMCLK
void straight_SMCLK()
{
    //三足稳定，一脚前进
    setPWM_duty_cycle(21,600);setPWM_duty_cycle(13,1700);//前左脚
    delay_ms(800);
    setPWM_duty_cycle(13,2200);
    delay_ms(800);
    setPWM_duty_cycle(21,1300);//前左脚
    delay_ms(800);
    setPWM_duty_cycle(35,1400);setPWM_duty_cycle(15,1300);//后右脚
    delay_ms(800);
    setPWM_duty_cycle(15,800);
    delay_ms(800);
    setPWM_duty_cycle(35,600);//后右脚
    delay_ms(800);
    setPWM_duty_cycle(20,1400);setPWM_duty_cycle(12,1300);//前右脚
    delay_ms(800);
    setPWM_duty_cycle(12,800);
    delay_ms(800);
    setPWM_duty_cycle(20,600);//前右脚
    delay_ms(800);
    setPWM_duty_cycle(24,600);setPWM_duty_cycle(14,1700);//后左脚
    delay_ms(800);
    setPWM_duty_cycle(14,2200);
    delay_ms(800);
    setPWM_duty_cycle(24,1400);//后左脚
    delay_ms(800);
}
void nishizhen_SMCLK()
{
    //逆时针转圈
    setPWM_duty_cycle(21,1400);setPWM_duty_cycle(13,1700);//前左脚
    delay_ms(800);
    setPWM_duty_cycle(13,2200);
    delay_ms(800);
    setPWM_duty_cycle(21,600);//前左脚
    delay_ms(800);
    setPWM_duty_cycle(24,1400);setPWM_duty_cycle(14,1700);//后左脚
    delay_ms(800);
    setPWM_duty_cycle(14,2200);
    delay_ms(800);
    setPWM_duty_cycle(24,600);//后左脚
    delay_ms(800);
    setPWM_duty_cycle(35,1400);setPWM_duty_cycle(15,1300);//后右脚
    delay_ms(800);
    setPWM_duty_cycle(15,800);
    delay_ms(800);
    setPWM_duty_cycle(35,600);//后右脚
    delay_ms(800);
    setPWM_duty_cycle(20,1400);setPWM_duty_cycle(12,1300);//前右脚
    delay_ms(800);
    setPWM_duty_cycle(12,800);
    delay_ms(800);
    setPWM_duty_cycle(20,600);//前右脚
    delay_ms(800);
}
