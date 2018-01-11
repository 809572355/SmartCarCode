/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : CarSystem.c
 * This file is part of EIT Car Project
 * Embedded Innovation Team(EIT) - 
 * Website:http://www.mizhiquan.com
 * ----------------------------------------------------------------------------
 * LICENSING TERMS:
 * 
 *     The Code is provided in source form for FREE evaluation and  educational 
 * use.
 * 
 * ----------------------------------------------------------------------------
 * Change Logs:
 * Date           Author       Notes
 * 2016-02-08     Xian.Chen    the first version
 * 2016-07-08     Xian.Chen    update
 *
 *******************************************************************************
 */
 
#include "include.h"
 
void Embedded_Init(void);
void Control_Init(void);
void CarSystem_Init(void)
{
    Control_Init(); 
    Embedded_Init();
}
void Embedded_Init(void)
{
     
    LCD_init();
    //Camera
    camera_init(imgbuff0); 
    Steer_Init(gParam.SteerMid);
    //MotorL_Init();
    MotorR_Init(); 
    led_init (LED_MAX);
    
    DataLog_Init();
    
    Model_Init();
    Key_Init();
    
    set_vector_handler(PORTA_VECTORn,PORTA_handler);
    enable_irq(PORTA_IRQn);
    
    pit_init_ms(PIT0,10);
    set_vector_handler(PIT0_VECTORn,PIT0_IRQHandler);
    enable_irq(PIT0_IRQn);
    
    set_vector_handler(DMA0_VECTORn ,DMA0_IRQHandler);      //����LPTMR���жϸ�λ����Ϊ PORTA_IRQHandler
    enable_irq(DMA0_IRQn);
    
    
    //��������ͨ���ж�����
    set_vector_handler(PORTE_VECTORn ,PORTE_IRQHandler);                //���� PORTE ���жϸ�λ����Ϊ PORTE_VECTORn
    enable_irq(PORTE_IRQn);

    gpio_init (PTA15, GPO,0);//���������ʱ��
}
void Control_Init(void)
{
    ControlVar_Init();
    ControlParam_Init();
    MotorLPID_Init();
    MotorRPID_Init();
}


