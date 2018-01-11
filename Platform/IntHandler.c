/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : IntHandler.c
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


#include  "IntHandler.h"              

#define CAM_VSYNC 29

void PORTA_handler(void)
{
    uint32 flag = PORTA_ISFR;
    PORTA_ISFR  = ~0; 
   if(flag & (1 << CAM_VSYNC))                                 //PTA29�����ж�
   {
       ImageOver=0;
       camera_vsync();
       gVar.time++;
   }
}

//DMA�ж�
void DMA0_IRQHandler()
{
    camera_dma();
    ImageOver=1;
}
//��ʱ�ж�
void PIT0_IRQHandler(void)
{
   ControlSpeedTask();
   PIT_Flag_Clear(PIT0);
}

//ͨ���ж�
void PORTE_IRQHandler()
{
    uint8  n;    //���ź�
    uint32 flag;

    flag = PORTE_ISFR;
    PORTE_ISFR  = ~0;                                   //���жϱ�־λ

    n = 27;
    if(flag & (1 << n))                                 //PTE27�����ж�
    {
        nrf_handler();
    }
}
