/*
 * IIC.h
 *
 *  Created on: 2021年9月4日
 *      Author: dwb
 */

#ifndef IIC_H_
#define IIC_H_

void IIC_start();//开始
void IIC_stop();//停止
void SendACK(unsigned char ack);//向iic发送标志
void IIC_writebyte(unsigned char IIC_byte);///接收iic标志
unsigned char IIC_testACK();///发送数据
unsigned char IIC_readebyte();///接收数据
#endif /* IIC_H_ */
