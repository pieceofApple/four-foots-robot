/*
 * IIC.h
 *
 *  Created on: 2021��9��4��
 *      Author: dwb
 */

#ifndef IIC_H_
#define IIC_H_

void IIC_start();//��ʼ
void IIC_stop();//ֹͣ
void SendACK(unsigned char ack);//��iic���ͱ�־
void IIC_writebyte(unsigned char IIC_byte);///����iic��־
unsigned char IIC_testACK();///��������
unsigned char IIC_readebyte();///��������
#endif /* IIC_H_ */
