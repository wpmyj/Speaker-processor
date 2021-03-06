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
#define Esc 2
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_LISTBOX_0 (GUI_ID_USER + 0x01)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Gen_Sweep", ID_WINDOW_0, 0, 0, 400, 240, 0, 0x0, 0 },
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
        //
        // Initialization of 'Listbox'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0);
        LISTBOX_AddString(hItem, "SET_1");
        LISTBOX_AddString(hItem, "SET_2");
		LISTBOX_AddString(hItem, "Sweep_Esc");
        LISTBOX_SetFont(hItem, GUI_FONT_20_1);
	
		Gen_data.hChild = CreateSweep_child_1();
        WM_AttachWindowAt(Gen_data.hChild, pMsg->hWin, 115, 0); //把窗口加到该父窗口中
        WM_SetFocus(hItem); //设置聚焦为列表框
        // USER START (Optionally insert additional code for further widget initialization)
        // USER END
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_LISTBOX_0: // Notifications sent by 'Listbox'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
            case WM_NOTIFICATION_RELEASED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
            case WM_NOTIFICATION_SEL_CHANGED:
                // USER START (Optionally insert code for reacting on notification message)
				Gen_data.Sel = LISTBOX_GetSel(pMsg->hWinSrc); //获得选项号
				if(Gen_data.Sel == 0)
				{
					if (WM_IsWindow(Gen_data.hChild)) //检测句柄是否有效
                    {
                        GUI_EndDialog(Gen_data.hChild, 1); //删除上一个窗口
                    }
                    Gen_data.hChild = CreateSweep_child_1(); //创建窗口，第一个界面
                    WM_AttachWindowAt(Gen_data.hChild, pMsg->hWin, 115, 0); //把窗口加到该父窗口中
                    WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)); //聚焦到列表框
				}
				else if(Gen_data.Sel == 1)
				{
					if (WM_IsWindow(Gen_data.hChild)) //检测句柄是否有效
                    {
                        GUI_EndDialog(Gen_data.hChild, 1); //删除上一个窗口
                    }
                    Gen_data.hChild = CreateSweep_Two(); //创建窗口，第一个界面
                    WM_AttachWindowAt(Gen_data.hChild, pMsg->hWin, 115, 0); //把窗口加到该父窗口中
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
    default:
        WM_DefaultProc(pMsg);
        break;

    /*********************************自定义信息*********************************************/
    //退出键
    case MSG_KEY_ESC:
        GUI_SendKeyMsg(GUI_KEY_ESCAPE, 1);  //ESC
        break;

    //CONTROL左转
    case MSG_KNOB_CONTROL_LEFT:
        if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin,
                                        ID_LISTBOX_0))) //判断聚焦是否在列表框
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
        if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin,
                                        ID_LISTBOX_0))) //判断聚焦是否在列表框
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
        if(!WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) //不在列表框
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
		if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) //检测聚焦是否在选项框
		{
			//如果聚焦在列表框上则忽略该信息
		}
		else if(Gen_data.Sel == list_1)
		{
			GUI_SendKeyMsg(GUI_KEY_RIGHT,1); //滑块左移
		}
        break;


    //右转
    case MSG_KNOB_OUT_RIGHT:
        if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) //检测聚焦是否在选项框
		{
			//如果聚焦在列表框上则忽略该信息
		}
		else if(Gen_data.Sel == list_1) //当选中列表1时
		{
			GUI_SendKeyMsg(GUI_KEY_LEFT,1); //滑块左移
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
        OUTPUT_channel = 0;
        GUI_EndDialog(pMsg->hWin, 0);    //结束当前页面
        hWin_now = CreateOut_face();     //输出OUT子界面
        break;
	
	//SYS
	case MSG_KEY_SYSTEM:
		GUI_EndDialog(pMsg->hWin,0);
		hWin_now = CreateSystem();
		break;
    /************************************END******************************************/

    //信息处理
    case WM_KEY:
        switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) //获得关于按键信息的值
        {
        case GUI_KEY_ESCAPE:
            if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin,
                                            ID_LISTBOX_0)))//检测现在的聚焦是否在listbox上
            {
                GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
                hWin_now = CreateGen_Out();  //Gen_Out界面
            }
            else
            {
                WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)); //聚焦到列表框
                LISTBOX_SetSel(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0),
                               Gen_data.Sel); //返回列表框所选项目
            }
            break;

        case GUI_KEY_ENTER:
            if(Gen_data.Sel != Esc && WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)))
            {
                WM_SetFocus(WM_GetFirstChild(Gen_data.hChild)); //跳到子界面的第一个控件上
            }
            else if (Gen_data.Sel == Esc) //退出
            {
                Gen_data.Sel = 0;
                GUI_EndDialog(pMsg->hWin, 0);
                hWin_now = CreateGen_Out();  //上一层界面
            }
            break;
        }
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
*       CreateGen_Sweep
*/

WM_HWIN CreateGen_Sweep(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate),
                               _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
