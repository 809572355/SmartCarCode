#ifndef _EIT_KEY_H
#define _EIT_KEY_H

#include "include.h"

#define    KeyEnter         PTD5//PTD15                                             //���밴������
#define    KeyAck           PTD6//PTD11                                             //ȷ��
#define    KeyInc           PTD3//PTD12                                            //����
#define    KeyDec           PTD4//PTD13                                            //����
#define    KeyQuit          PTD2//PTD14                                            //�˳�

#define    Model1           PTD7    //����ģʽ��4�����뿪��
#define    Model2           PTD8  
#define    Model3           PTD9  
#define    Model4           PTD10  

typedef enum 
{
  K_En,
  K_Ack,
  K_Inc,
  K_Dec,
  K_Quit,
  K_Null,
}KeyState;

extern int32 Key_En;

extern int32 state;


void Model_Init(void);
void Key_Init(void);
int32 Key_CheckEn(void);
void Key_Debug(void);

#endif //_EIT_KEY_H