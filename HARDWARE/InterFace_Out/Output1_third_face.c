/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x09)
#define ID_LISTBOX_0 (GUI_ID_USER + 0x0A)
#define ESC 3

// USER START (Optionally insert additional defines)
// USER END
struct Out1_third  //存放该窗口要用到的数据
{
	char Window_Switch ; //设置一个变量来判别当前的输入聚焦在哪个窗口，0代表在列表框
    WM_HWIN hChild; //子窗口句柄
    int Sel;            //索引号
} ;
struct Out1_third Out1_third_data= {0,0,0};
/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
static const char out_Esc[][12]=
{
	"Output1_Esc",
	"Output2_Esc",
	"Output3_Esc",
	"Output4_Esc",
	"Output5_Esc",
	"Output6_Esc",
	"Output7_Esc",
	"Output8_Esc",
};
// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Output1_third_face", ID_WINDOW_0, 0, 0, 400, 240, 0, 0x0, 0 },
    { LISTBOX_CreateIndirect, "Listbox", ID_LISTBOX_0, 0, 0, 114, 240, 0, 0x0, 0 },
    // USER START (Optionally insert additional widgets)
    // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    // USER START (Optionally insert additional variables)
    // USER END

    switch (pMsg->MsgId)
    {
    case WM_INIT_DIALOG:
		Out1_third_data.Sel = 0;
        //
        // Initialization of 'Listbox'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0);
        LISTBOX_AddString(hItem, "SET_1");
        LISTBOX_AddString(hItem, "SET_2");
        LISTBOX_AddString(hItem, "SET_3");
        LISTBOX_AddString(hItem, out_Esc[OUTPUT_channel]); //显示Esc
        LISTBOX_SetFont(hItem, GUI_FONT_20_1);  //设置字体

        //子窗口
        Out1_third_data.hChild = CreateOut_First();
        WM_AttachWindowAt(Out1_third_data.hChild, pMsg->hWin, 115, 0); //把窗口加到该父窗口中
        WM_SetFocus(hItem); //设置聚焦为列表框
        break;

    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc); //得到传输通知信息窗口的句柄
        NCode = pMsg->Data.v; //得到传输过来的信息
        switch(Id)
        {
        case ID_LISTBOX_0: // Notifications sent by 'Listbox'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED: //发生点击事件
                // USER START (Optionally insert code for reacting on notification message)
                if(Out1_third_data.Sel == ESC)
                {
                    Out1_third_data.Sel = 0;
                    GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
                    CreateOut_face();  //显示第二页面
                }
                // USER END
                break;
            case WM_NOTIFICATION_RELEASED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
            case WM_NOTIFICATION_SEL_CHANGED: //选项发生改变
                // USER START (Optionally insert code for reacting on notification message)
                Out1_third_data.Sel = LISTBOX_GetSel(pMsg->hWinSrc); //获得选项号
                if(Out1_third_data.Sel == 0) //第一项
                {
                    GUI_EndDialog(Out1_third_data.hChild,0); //重新创建一个子窗口
                    Out1_third_data.hChild = CreateOut_First();
                    WM_AttachWindowAt(Out1_third_data.hChild,pMsg->hWin,115,0);
                    WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)); //聚焦到列表框
                }
                else if(Out1_third_data.Sel == 1)
                {
                    GUI_EndDialog(Out1_third_data.hChild,0); //重新创建一个子窗口
                    Out1_third_data.hChild = CreateOut_twoface();
                    WM_AttachWindowAt(Out1_third_data.hChild,pMsg->hWin,115,0);
                    WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)); //聚焦到列表框
                }
                else if (Out1_third_data.Sel == 2)
                {
                    GUI_EndDialog(Out1_third_data.hChild,0); //重新创建一个子窗口
                    Out1_third_data.hChild = CreateOut_threeface();
                    WM_AttachWindowAt(Out1_third_data.hChild,pMsg->hWin,115,0);
                    WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)); //聚焦到列表框
                }

                // USER END
                break;
                // USER START (Optionally insert additional code for further notification handling)
                // USER END
            }
            break;
            // USER START (Optionally insert additional code for further Ids)
            // USER END
        }
        break;
    // USER START (Optionally insert additional message handling)
    // USER END
		
	case WM_KEY:
		switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) //获得关于按键信息的值
		{
			case GUI_KEY_ESCAPE:
			if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)))//检测现在的聚焦是否在listbox上
            {
                GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
                hWin_now = CreateOut_face();  //OUT_CHANNEL页面
            }
            else
            {
                WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)); //聚焦到列表框
                LISTBOX_SetSel(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0),Out1_third_data.Sel); //返回列表框所选项目
            }
				break;
			
			case GUI_KEY_ENTER:
				if(Out1_third_data.Sel != ESC && WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)))
				{
					WM_SetFocus(WM_GetFirstChild(Out1_third_data.hChild));
				}
				else if (Out1_third_data.Sel == ESC)
				{
					Out1_third_data.Sel = 0;
					GUI_EndDialog(pMsg->hWin,0);
					hWin_now = CreateOut_face();  //OUT_CHANNEL页面
				}
				break;
		}
		break;	
/*********************************自定义信息*********************************************/
	//退出键
	case MSG_KEY_ESC:  
		GUI_SendKeyMsg(GUI_KEY_ESCAPE, 1);  //ESC
		break;
	
	//CONTROL左转
	case MSG_KNOB_CONTROL_LEFT:
		if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) //判断聚焦是否在列表框
		{
			GUI_SendKeyMsg(GUI_KEY_DOWN, 1); //list选项向下移动
		}
		else 
		{
			GUI_SendKeyMsg(GUI_KEY_TAB, 1);     //下一个聚焦点
		}
		break;
		
	//CONTROL右转
	case MSG_KNOB_CONTROL_RIGHT:
		if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) //判断聚焦是否在列表框
		{
			GUI_SendKeyMsg(GUI_KEY_UP, 1);  //list选项向上移动
		}
		else 
		{
			GUI_SendKeyMsg(GUI_KEY_BACKTAB, 1); //上一个聚焦
		}
		break;
	
	//CONTROL按下
	case MSG_KEY_CONTROL:
		if(!WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) 
		{
			GUI_SendKeyMsg(GUI_KEY_SPACE, 1);   //切换 CHECKBOX 控件的选中状态。
		}
		else
		{
			GUI_SendKeyMsg(GUI_KEY_ENTER, 1);   //确定消息
		}
		break;
	
	//左转
	case MSG_KNOB_OUT_LEFT:
		if(WM_HasFocus(WM_GetDialogItem(Out1_third_data.hChild,(GUI_ID_USER + 0x01)))) //滑块
		{
			if(Out1_third_data.Sel != 2)
			{
				GUI_SendKeyMsg(GUI_KEY_RIGHT, 1); //滑块左移
			}
			else
			{
				GUI_SendKeyMsg(GUI_KEY_UP,1);   //数值增加
			}
		}
		else if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) //检测是否在选项框
		{
			
		}
		else 
		{
			GUI_SendKeyMsg(GUI_KEY_UP,1);   //数值增加
		}
		break;
	
		
	//右转
	case MSG_KNOB_OUT_RIGHT:
		if(WM_HasFocus(WM_GetDialogItem(Out1_third_data.hChild,(GUI_ID_USER + 0x01)))) //滑块
		{
			if(Out1_third_data.Sel != 2)
			{
				GUI_SendKeyMsg(GUI_KEY_LEFT, 1); //滑块左移
			}
			else
			{
				GUI_SendKeyMsg(GUI_KEY_DOWN,1);   //数值减少
			}
		}
		else if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) //检测是否在选项框
		{
			
		}
		else
		{
			GUI_SendKeyMsg(GUI_KEY_DOWN,1);   //数值减少
		}
		break;
		
	//INPUT
	case MSG_KEY_INPUT:
		INPUT_channel = 0;  //输入通道聚焦位置标志
        GUI_EndDialog(pMsg->hWin, 0); //结束本界面
        hWin_now = CreateINPUT_CHANNEL(); //显示INPUT子界面
		break;
	
	//OUT
	case MSG_KEY_OUTPUT:
		WM_SendMessageNoPara(hWin_now, MSG_KEY_CONTROL);
		break;
	
	//SYS
	case MSG_KEY_SYSTEM:
		GUI_EndDialog(pMsg->hWin,0);
		hWin_now = CreateSystem();
		break;
/************************************END******************************************/	
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateOutput1_third_face
*/

WM_HWIN CreateOutput1_third_face(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
