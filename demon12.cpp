// demon12.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include "resource.h"
#include <math.h>


BOOL CALLBACK DialogFun(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	char Text[100];
	double a, b, c, s;

	switch (message)
	{
	case WM_INITDIALOG:

		return TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hwnd, 0);
			return TRUE;
		case IDC_BUTTON1:
		case IDC_CHECK1:
			SendDlgItemMessage(hwnd, IDC_EDIT1, WM_GETTEXT, 100, (LPARAM)Text);
			if (sscanf(Text, "%lf", &a)<1) 
			{
				MessageBox(hwnd, "Неверное значение первого параметра", "Сообщение об ошибке", MB_OK | MB_ICONHAND);
				SendDlgItemMessage(hwnd, IDC_EDIT1, WM_SETTEXT, 0, (LPARAM)""); 
				return TRUE;
			}

			SendDlgItemMessage(hwnd, IDC_EDIT2, WM_GETTEXT, 100, (LPARAM)Text);
			if (sscanf(Text, "%lf", &b)<1) 
			{
				MessageBox(hwnd, "Неверное значение второго параметра", "Сообщение об ошибке", MB_OK | MB_ICONHAND);
				SendDlgItemMessage(hwnd, IDC_EDIT2, WM_SETTEXT, 0, (LPARAM)""); 
				return TRUE;
			}
			SendDlgItemMessage(hwnd, IDC_EDIT3, WM_GETTEXT, 100, (LPARAM)Text);
			if (sscanf(Text, "%lf", &c)<1) 
			{
				MessageBox(hwnd, "Неверное значение третьего параметра", "Сообщение об ошибке", MB_OK | MB_ICONHAND);
				SendDlgItemMessage(hwnd, IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)""); 
				return TRUE;
			}
			s = sqrt(((a + b + c) / 2 *(((a + b + c) / 2 -a)*(((a + b + c) / 2) -b)*(((a + b + c) / 2) -c))));
			sprintf(Text, "%lf", s);
			SendDlgItemMessage(hwnd, IDC_EDIT4, WM_SETTEXT, 0, (LPARAM)Text);

		}


	}

	return FALSE;
}

int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrevIns, LPSTR arg, int WinMode)
{


	DialogBox(hIns, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogFun);
	return 0;


}


  
