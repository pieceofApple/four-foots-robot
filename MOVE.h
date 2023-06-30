#include"msp430f5529.h"
//ACLK
void wending()
{
    float a;
    //float b;
    //float c;
    int dutycyclex_R,dutycyclex_L;
    //int dutycycley;

    a=Mpu6050AccelAngle(ACCEL_XOUT)-5; //-5Ϊ΢��
    //b=Mpu6050AccelAngle(ACCEL_YOUT);
    //c=Mpu6050AccelAngle(ACCEL_ZOUT);

    if(a<0)
    {
        dutycyclex_R = 34-abs((int)a*0.5);
        dutycyclex_L = 68-abs((int)a*0.5);
        if (dutycyclex_R < 24)
        {
            dutycyclex_R = 24; // ������С��500(17)����������Ϊ500(17)
        } else if (dutycyclex_R > 85)
        {
            dutycyclex_R = 85; // ����������2500����������Ϊ2500
        }
        if (dutycyclex_L < 17)
        {
            dutycyclex_L = 17; // ������С��500(17)����������Ϊ500(17)
        } else if (dutycyclex_L > 72)
        {
            dutycyclex_L = 72; // ����������2500����������Ϊ2500
        }
    }
    else if(a>0)
    {
        dutycyclex_R = 34+abs((int)a*0.5);
        dutycyclex_L = 68+abs((int)a*0.5);
        if (dutycyclex_R < 24)
        {
            dutycyclex_R = 24; // ������С��500(17)����������Ϊ500(17)
        } else if (dutycyclex_R > 85)
        {
            dutycyclex_R = 85; // ����������2500����������Ϊ2500
        }
        if (dutycyclex_L < 17)
        {
            dutycyclex_L = 17; // ������С��500(17)����������Ϊ500(17)
        } else if (dutycyclex_L > 72)
        {
            dutycyclex_L = 72; // ����������2500����������Ϊ2500
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
//          dutycycley = 17; // ������С��500����������Ϊ500
//      } else if (dutycycley > 85)
//      {
//          dutycycley = 85; // ����������2500����������Ϊ2500
//      }
    setPWM_duty_cycle(20,34);setPWM_duty_cycle(12,dutycyclex_R);//ǰ�ҽ�
    setPWM_duty_cycle(21,30);setPWM_duty_cycle(13,dutycyclex_L);//ǰ���
    setPWM_duty_cycle(35,30);setPWM_duty_cycle(15,dutycyclex_R);//���ҽ�
    setPWM_duty_cycle(24,34);setPWM_duty_cycle(14,dutycyclex_L);//�����
}

void straight_ACLK()
{
    //�����ȶ���һ��ǰ��
    setPWM_duty_cycle(21,20);setPWM_duty_cycle(13,58);//ǰ���
    delay_ms(500);
    setPWM_duty_cycle(13,72);
    delay_ms(500);
    setPWM_duty_cycle(21,48);//ǰ���
    //delay_ms(500);
    setPWM_duty_cycle(35,48);setPWM_duty_cycle(15,44);//���ҽ�
    delay_ms(500);
    setPWM_duty_cycle(15,24);
    delay_ms(500);
    setPWM_duty_cycle(35,20);//���ҽ�
    //delay_ms(500);
    setPWM_duty_cycle(20,48);setPWM_duty_cycle(12,44);//ǰ�ҽ�
    delay_ms(500);
    setPWM_duty_cycle(12,24);
    delay_ms(500);
    setPWM_duty_cycle(20,20);//ǰ�ҽ�
    //delay_ms(500);
    setPWM_duty_cycle(24,20);setPWM_duty_cycle(14,58);//�����
    delay_ms(500);
    setPWM_duty_cycle(14,72);
    delay_ms(500);
    setPWM_duty_cycle(24,48);//�����
    //delay_ms(500);
}
void zhanli_ACLK()
{
    //set_PWM(655);
    //17-0, 34-45,  51-90,  68-135,  85-180
    //500-0,1000-45,1500-90,2000-135,2500-180
        setPWM_duty_cycle(20,34);setPWM_duty_cycle(12,24);//ǰ�ҽ�
        setPWM_duty_cycle(21,30);setPWM_duty_cycle(13,72);//ǰ���
        setPWM_duty_cycle(35,30);setPWM_duty_cycle(15,24);//���ҽ�
        setPWM_duty_cycle(24,34);setPWM_duty_cycle(14,72);//�����
}
void paxia_ACLK()
{
    //ſ�£���������
        setPWM_duty_cycle(20,34);setPWM_duty_cycle(12,51);//ǰ�ҽ�
        setPWM_duty_cycle(21,30);setPWM_duty_cycle(13,51);//ǰ���
        setPWM_duty_cycle(35,30);setPWM_duty_cycle(15,51);//���ҽ�
        setPWM_duty_cycle(24,34);setPWM_duty_cycle(14,51);//�����
}
void nishizhen_ACLK()
{
    //��ʱ��תȦ
    setPWM_duty_cycle(21,48);setPWM_duty_cycle(13,58);//ǰ���
    delay_ms(800);
    setPWM_duty_cycle(13,65);
    delay_ms(800);
    setPWM_duty_cycle(21,20);//ǰ���
    delay_ms(800);
    setPWM_duty_cycle(24,48);setPWM_duty_cycle(14,58);//�����
    delay_ms(800);
    setPWM_duty_cycle(14,65);
    delay_ms(800);
    setPWM_duty_cycle(24,20);//�����
    delay_ms(800);
    setPWM_duty_cycle(35,48);setPWM_duty_cycle(15,44);//���ҽ�
    delay_ms(800);
    setPWM_duty_cycle(15,27);
    delay_ms(800);
    setPWM_duty_cycle(35,20);//���ҽ�
    delay_ms(800);
    setPWM_duty_cycle(20,48);setPWM_duty_cycle(12,44);//ǰ�ҽ�
    delay_ms(800);
    setPWM_duty_cycle(12,27);
    delay_ms(800);
    setPWM_duty_cycle(20,20);//ǰ�ҽ�
    delay_ms(800);
}
//SMCLK
void straight_SMCLK()
{
    //�����ȶ���һ��ǰ��
    setPWM_duty_cycle(21,600);setPWM_duty_cycle(13,1700);//ǰ���
    delay_ms(800);
    setPWM_duty_cycle(13,2200);
    delay_ms(800);
    setPWM_duty_cycle(21,1300);//ǰ���
    delay_ms(800);
    setPWM_duty_cycle(35,1400);setPWM_duty_cycle(15,1300);//���ҽ�
    delay_ms(800);
    setPWM_duty_cycle(15,800);
    delay_ms(800);
    setPWM_duty_cycle(35,600);//���ҽ�
    delay_ms(800);
    setPWM_duty_cycle(20,1400);setPWM_duty_cycle(12,1300);//ǰ�ҽ�
    delay_ms(800);
    setPWM_duty_cycle(12,800);
    delay_ms(800);
    setPWM_duty_cycle(20,600);//ǰ�ҽ�
    delay_ms(800);
    setPWM_duty_cycle(24,600);setPWM_duty_cycle(14,1700);//�����
    delay_ms(800);
    setPWM_duty_cycle(14,2200);
    delay_ms(800);
    setPWM_duty_cycle(24,1400);//�����
    delay_ms(800);
}
void nishizhen_SMCLK()
{
    //��ʱ��תȦ
    setPWM_duty_cycle(21,1400);setPWM_duty_cycle(13,1700);//ǰ���
    delay_ms(800);
    setPWM_duty_cycle(13,2200);
    delay_ms(800);
    setPWM_duty_cycle(21,600);//ǰ���
    delay_ms(800);
    setPWM_duty_cycle(24,1400);setPWM_duty_cycle(14,1700);//�����
    delay_ms(800);
    setPWM_duty_cycle(14,2200);
    delay_ms(800);
    setPWM_duty_cycle(24,600);//�����
    delay_ms(800);
    setPWM_duty_cycle(35,1400);setPWM_duty_cycle(15,1300);//���ҽ�
    delay_ms(800);
    setPWM_duty_cycle(15,800);
    delay_ms(800);
    setPWM_duty_cycle(35,600);//���ҽ�
    delay_ms(800);
    setPWM_duty_cycle(20,1400);setPWM_duty_cycle(12,1300);//ǰ�ҽ�
    delay_ms(800);
    setPWM_duty_cycle(12,800);
    delay_ms(800);
    setPWM_duty_cycle(20,600);//ǰ�ҽ�
    delay_ms(800);
}
