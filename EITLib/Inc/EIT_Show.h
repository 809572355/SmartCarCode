#ifndef _EIT_SHOW_H
#define _EIT_SHOW_H

#include "include.h"
//#include "common.h"

extern int Flag_Car;

extern Site_t Site_DirKp;                      //��ʼ����
extern Site_t Site_DirKpNum;

extern Site_t Site_DirKd;
extern Site_t Site_DirKdNum;

extern Site_t Site_MaxSpeed;
extern Site_t Site_MaxSpeedNum;

extern Site_t Site_MinSpeed ;
extern Site_t Site_MinSpeedNum ;

extern Site_t Site_KpInAngle ;
extern Site_t Site_KpInAngleNum ;

extern Site_t Site_MDSK ;
extern Site_t Site_MDSKNum ;

extern Site_t site  ;                           //��ʾͼ�����Ͻ�λ��
extern Size_t imgsize ;             //ͼ���С
extern Size_t size; 

extern void Lcd_Show(void);

extern void Lcd_ShowImageData(void);

extern void Lcd_ShowImageDataF(void);

#endif //_EIT_SHOW_H