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
#define Coax_Esc  5 //�˳�
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x09)
#define ID_LISTBOX_0 (GUI_ID_USER + 0x0A)

// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/


// USER START (Optionally insert additional static data)
struct COAX_face
{
    char Window_Switch ; //����һ���������б�ǰ������۽����ĸ����ڣ�0�������б���
    WM_HWIN hChild;
    int Sel;
};

struct COAX_face Coax_data = {0, 0, 0};
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
		Coax_data.Sel = 0;
        //
        // Initialization of 'Listbox'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0);
        LISTBOX_AddString(hItem, "SET_1");
        LISTBOX_AddString(hItem, "SET_2");
        LISTBOX_AddString(hItem, "SET_3");
        LISTBOX_AddString(hItem, "SET_4");
        LISTBOX_AddString(hItem, "SET_5");
        LISTBOX_AddString(hItem, "Coax_Esc");
        LISTBOX_SetFont(hItem, GUI_FONT_20_1);  //��������

        //�Ӵ���
        Coax_data.hChild = CreateSecond_Child(); //����Input����Ľ���
        WM_AttachWindowAt(Coax_data.hChild, pMsg->hWin, 115, 0);  //�Ѵ��ڼӵ��ø�������
        WM_SetFocus(hItem);
        break;
    

    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc); //�õ�����֪ͨ��Ϣ���ڵľ��
        NCode = pMsg->Data.v; //�õ������������Ϣ
        switch(Id)
        {
        case ID_LISTBOX_0: // Notifications sent by 'Listbox'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED: //��������¼�
                // USER START (Optionally insert code for reacting on notification message)
//                if(COA_DATA.Sel == 5)
//                {
//                    GUI_EndDialog(pMsg->hWin,0);
//                    CreateMainface();
//                }
                // USER END
                break;
            case WM_NOTIFICATION_RELEASED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
            case WM_NOTIFICATION_SEL_CHANGED: //ѡ����ı�
                // USER START (Optionally insert code for reacting on notification message)
                Coax_data.Sel = LISTBOX_GetSel(pMsg->hWinSrc); //���ѡ���
                if(Coax_data.Sel == 0)
                {
                    GUI_EndDialog(Coax_data.hChild, 0); //���´���һ���Ӵ���
                    Coax_data.hChild = CreateSecond_Child();
                    WM_AttachWindowAt(Coax_data.hChild, pMsg->hWin, 115, 0);
                    WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)); //�۽����б���
                }
                else if(Coax_data.Sel == 1)
                {
                    GUI_EndDialog(Coax_data.hChild, 0); //���´���һ���Ӵ���
                    Coax_data.hChild = CreateCOAX_face_3();
                    WM_AttachWindowAt(Coax_data.hChild, pMsg->hWin, 115, 0);
                    WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)); //�۽����б���
                }
                else if(Coax_data.Sel == 2)
                {
					if (WM_IsWindow(Coax_data.hChild)) //������Ƿ���Ч
                    {
                        GUI_EndDialog(Coax_data.hChild, 1); //ɾ����һ������
                    }
                    Coax_data.hChild = CreateThird_Child(); //Input����������
                    WM_AttachWindowAt(Coax_data.hChild, pMsg->hWin, 115, 0); //�Ѵ��ڼӵ��ø�������
                    WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0));//�۽����б���

                }
                else if(Coax_data.Sel == 3)
                {
					if (WM_IsWindow(Coax_data.hChild)) //������Ƿ���Ч
                    {
                        GUI_EndDialog(Coax_data.hChild, 1); //ɾ����һ������
                    }
                    Coax_data.hChild = CreateFour_Child(); //Input����������
                    WM_AttachWindowAt(Coax_data.hChild, pMsg->hWin, 115, 0); //�Ѵ��ڼӵ��ø�������
                    WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0));//�۽����б���
                }
                else if(Coax_data.Sel == 4)
                {
					if (WM_IsWindow(Coax_data.hChild)) //������Ƿ���Ч
                    {
                        GUI_EndDialog(Coax_data.hChild, 1); //ɾ����һ������
                    }
                    Coax_data.hChild = CreateFive_Child(); //Input����������
                    WM_AttachWindowAt(Coax_data.hChild, pMsg->hWin, 115, 0); //�Ѵ��ڼӵ��ø�������
                    WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0));//�۽����б���

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

    /*******************************�Զ�����Ϣ����*****************************************/
    //��ť
    //CONTROL��ת
    case MSG_KNOB_CONTROL_LEFT:
        if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin,
                                        ID_LISTBOX_0))) //�жϾ۽��Ƿ����б���
        {
            GUI_SendKeyMsg(GUI_KEY_DOWN, 1); //listѡ�������ƶ�
        }
        else
        {
            GUI_SendKeyMsg(GUI_KEY_TAB, 1);     //��һ���۽���
        }
        break;
    //CONTROL��ת
    case MSG_KNOB_CONTROL_RIGHT:
        if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin,
                                        ID_LISTBOX_0))) //�жϾ۽��Ƿ����б���
        {
            GUI_SendKeyMsg(GUI_KEY_UP, 1);  //listѡ�������ƶ�
        }
        else
        {
            GUI_SendKeyMsg(GUI_KEY_BACKTAB, 1); //��һ���۽�
        }
        break;
	//��ת
	case MSG_KNOB_OUT_LEFT:
		if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) //���۽��Ƿ���ѡ���
		{
			//����۽����б���������Ը���Ϣ
		}
		else if(Coax_data.Sel != list_0)
		{
			GUI_SendKeyMsg(GUI_KEY_RIGHT,1); //��������
		}
		else
		{
			GUI_SendKeyMsg(GUI_KEY_UP,1);   //SPINBOX��ֵ����,
		}
		break;
	
		
	//��ת
	case MSG_KNOB_OUT_RIGHT:
		if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) //���۽��Ƿ���ѡ���
		{
			//����۽����б���������Ը���Ϣ
		}
		else if(Coax_data.Sel != list_0)
		{
			GUI_SendKeyMsg(GUI_KEY_LEFT,1); //��������
		}
		else
		{
			GUI_SendKeyMsg(GUI_KEY_DOWN,1);   //SPINBOX��ֵ����,
		}
		break;
		
		
	//����
	//CONTROL����
	case MSG_KEY_CONTROL:
		if(!WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) 
		{
			if(Coax_data.Sel == list_1) //��ť�ɽ��ܸ���Ϣ���Ҳ����Լ��ͷ�
			{
				GUI_SendKeyMsg(GUI_KEY_SPACE, 1);   //�л� CHECKBOX �ؼ���ѡ��״̬��
			}
		}
		else
		{
			GUI_SendKeyMsg(GUI_KEY_ENTER, 1);   //ȷ����Ϣ
		}
		break;
		
    //�˳���
    case MSG_KEY_ESC:
        GUI_SendKeyMsg(GUI_KEY_ESCAPE, 1);  //ESC
        break;
	
	//INPUT
	case MSG_KEY_INPUT:
		INPUT_channel = 0;  //����ͨ���۽�λ�ñ�־
        GUI_EndDialog(pMsg->hWin, 0); //����������
        hWin_now = CreateINPUT_CHANNEL(); //��ʾINPUT�ӽ���
		break;
	
	//OUT
	case MSG_KEY_OUTPUT:
		OUTPUT_channel = 0;
        GUI_EndDialog(pMsg->hWin,0);     //������ǰҳ��
        hWin_now = CreateOut_face();     //���OUT�ӽ���
		break;
	
	//SYS
	case MSG_KEY_SYSTEM:
		GUI_EndDialog(pMsg->hWin,0);
		hWin_now = CreateSystem();
		break;
/***************************END********************************************/
	//������Ϣ����
    case WM_KEY:
        switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) //��ù��ڰ�����Ϣ��ֵ
        {
        case GUI_KEY_ESCAPE:
            if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin,
                                            ID_LISTBOX_0)))//������ڵľ۽��Ƿ���listbox��
            {
                GUI_EndDialog(pMsg->hWin, 0); //�رյ�ǰ����
                hWin_now = CreateMainface();  //Main����
            }
            else
            {
                WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)); //�۽����б���
                LISTBOX_SetSel(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0),
                               Coax_data.Sel); //�����б�����ѡ��Ŀ
            }
            break;

        case GUI_KEY_ENTER:
				if(Coax_data.Sel != Coax_Esc && WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)))
				{
					WM_SetFocus(WM_GetFirstChild(Coax_data.hChild));
				}
				else if (Coax_data.Sel == Coax_Esc)
				{
					Coax_data.Sel = 0;
					GUI_EndDialog(pMsg->hWin,0);  //����������
					hWin_now = CreateMainface();  //������
				}
				break;
        }
        break;
	
	//Ĭ����Ϣ����
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

WM_HWIN Create_COAX_face(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate),
                               _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/