#ifndef __LCD_H
#define __LCD_H
#include "sys.h"

#define FSMC_Enable  1   //�Ƿ�ʹ��FSMC
//Ӳ����ص��Ӻ���

#define Bank1_LCD_D    ((u32)0x60020000)    //Disp Data ADDR
#define Bank1_LCD_C    ((u32)0x60000000)	   //Disp Reg ADDR


#define LCD_RST  PDout(12)
#define LCD_WR   PDout(5)
#define LCD_RD   PDout(4)
#define LCD_CS   PDout(7)
#define LCD_RS   PDout(11)  
#define LCD_BL   PDout(13)  //LCD����
#define DB0      PDout(14)
#define DB1      PDout(15)
#define DB2      PDout(0)
#define DB3      PDout(1)
#define DB4      PEout(7)
#define DB5      PEout(8)
#define DB6      PEout(9)
#define DB7      PEout(10)
#define DB8      PEout(11)
#define DB9      PEout(12)
#define DB10     PEout(13)
#define DB11     PEout(14)
#define DB12     PEout(15)
#define DB13     PDout(10)
#define DB14     PDout(9)
#define DB15     PDout(8)

#define White          0xFFFF
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

void Lcd_Initialize(void);
void Lcd_Clear(u16 Color);
void BlockWrite(unsigned int Xstart,unsigned int Xend,unsigned int Ystart,unsigned int Yend);
void DrawPixel(u16 x, u16 y, int Color);
u16 GetPoint(u16 x, u16 y);
void Lcd_SetCursor(u16 x,u16 y);
void WriteComm(u16 CMD);
 void WriteData(u16 tem_data);
#endif