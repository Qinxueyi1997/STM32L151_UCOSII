/************************************************************************
* Copyright (C) 2020 Nercita
*
* 文件名称： delay.h
* 文件标识：
* 内容摘要： delay相关函数声明
* 其它说明：
* 当前版本：
* 作    者： woody
* 完成日期： 2020.09.07
*
* 修改记录1：
*    修改日期：
*    版 本 号：
*    修 改 人：
*    修改内容：
* 修改记录2：…
************************************************************************/
#ifndef __DELAY_H
#define __DELAY_H
#include "stm32l1xx.h"





void delay_init(void);		//初始化延时函数
void delay_ms(uint16_t nms);	//ucos 毫秒延时函数
void delay_us(uint32_t nus);	//微秒延时函数
void delay_Hms(uint32_t nms);   //硬毫秒延时函数
#endif  /* __DELAY_H */





























