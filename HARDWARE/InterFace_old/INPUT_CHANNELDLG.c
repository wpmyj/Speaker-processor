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
#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_BUTTON_0 (GUI_ID_USER + 0x07)
#define ID_BUTTON_1 (GUI_ID_USER + 0x08)
#define ID_BUTTON_2 (GUI_ID_USER + 0x09)
#define ID_BUTTON_3 (GUI_ID_USER + 0x0A)
#define ID_BUTTON_4 (GUI_ID_USER + 0x0B)
#define ID_BUTTON_5 (GUI_ID_USER + 0x0C)


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
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ FRAMEWIN_CreateIndirect, "INPUT_CHANNEL", ID_FRAMEWIN_0, 0, 0, 400, 240, 0, 0x64, 0 },
	{ BUTTON_CreateIndirect, "INPUT_1", ID_BUTTON_0, 16, 17, 103, 71, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "INPUT_2", ID_BUTTON_1, 143, 17, 103, 71, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "INPUT_3", ID_BUTTON_2, 272, 17, 103, 71, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "INPUT_4", ID_BUTTON_3, 16, 105, 103, 71, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "INPUT_5", ID_BUTTON_4, 143, 106, 103, 71, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "INPUT_6", ID_BUTTON_5, 272, 105, 103, 71, 0, 0x0, 0 },
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
//�Զ���Ƥ������
static int _DrawSkin_FRAMEWIN(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo)
{
	switch (pDrawItemInfo->Cmd)
	{
	case WIDGET_ITEM_DRAW_BACKGROUND:  //���Ʊ��ⱳ��
//        GUI_SetBkColor(GUI_BLACK);
//        GUI_Clear();
		GUI_DrawGradientRoundedV(0, 0, 399, 49, 0, 0xC0CEDC, GUI_BLACK);
		GUI_SetPenSize(3);
		GUI_SetColor(GUI_RED);
		GUI_DrawLine(0, 50, 400, 50); //������

		break;
	default:
		return FRAMEWIN_DrawSkinFlex(pDrawItemInfo); //Ĭ�ϻ��ƺ���
	}
	return 0;
}

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog2(WM_MESSAGE * pMsg) {
	WM_HWIN hItem;
	int     NCode;
	int     Id;
	// USER START (Optionally insert additional variables)
	// USER END

	switch (pMsg->MsgId) {
	case WM_INIT_DIALOG:
		//
		// Initialization of 'INPUT_CHANNEL'
		//
		hItem = pMsg->hWin;
		FRAMEWIN_SetTitleHeight(hItem, 50);
		FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		FRAMEWIN_SetFont(hItem, GUI_FONT_32_1);
		FRAMEWIN_SetTextColor(hItem, GUI_MAKE_COLOR(0xffffffff));
//    FRAMEWIN_SetSkin(hItem, _DrawSkin_FRAMEWIN);  //�Զ���Ƥ��
		FRAMEWIN_AddCloseButton(hItem, FRAMEWIN_BUTTON_RIGHT, 0);
//    FRAMEWIN_SetClientColor(hItem,GUI_BLACK);  //���ÿͻ�������ɫ

		//
		// Initialization of 'INPUT_1'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
		BUTTON_SetFont(hItem, GUI_FONT_20_1);
		//
		// Initialization of 'INPUT_2'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
		BUTTON_SetFont(hItem, GUI_FONT_20_1);
		//
		// Initialization of 'INPUT_3'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
		BUTTON_SetFont(hItem, GUI_FONT_20_1);
		//
		// Initialization of 'INPUT_4'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
		BUTTON_SetFont(hItem, GUI_FONT_20_1);
		//
		// Initialization of 'INPUT_5'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
		BUTTON_SetFont(hItem, GUI_FONT_20_1);
		//
		// Initialization of 'INPUT_6'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
		BUTTON_SetFont(hItem, GUI_FONT_20_1);
		// USER START (Optionally insert additional code for further widget initialization)
		// USER END
		break;

	case WM_PAINT:
		break;

//	case WM_DELETE:  //ɾ������ǰ���ܵ���Ϣ
//		CreateMainface();  //��ʾ��ҳ��
//		break;

	//������Ϣ����
	case WM_KEY:
		switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) //��ù��ڰ�����Ϣ��ֵ
		{
		case GUI_KEY_ESCAPE:
			GUI_EndDialog(pMsg->hWin, 0); //�رյ�ǰ����
			CreateMainface();             //��ʾ������
			break;
		}
		break;

	case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (Id) {
		case ID_BUTTON_0: // Notifications sent by 'INPUT_1' //�ؼ���ID
			switch (NCode) {                                 //�ؼ��Ķ���
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_1: // Notifications sent by 'INPUT_2'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_2: // Notifications sent by 'INPUT_3'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_3: // Notifications sent by 'INPUT_4'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_4: // Notifications sent by 'INPUT_5'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_5: // Notifications sent by 'INPUT_6'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
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
*       CreateINPUT_CHANNEL
*/
WM_HWIN CreateINPUT_CHANNEL(void);
WM_HWIN CreateINPUT_CHANNEL(void) {
	WM_HWIN hWin;
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog2, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/