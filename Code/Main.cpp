#include <Windows.h>
#include <fstream>
#include <string>
#include "resource.h"
#include "Definitions.h"

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);
int ReadSaveFile();
void SaveSaveFile();

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
	ReadSaveFile();
	hPic1 = (HBITMAP)LoadImage(hInst, pic1, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hPic2 = (HBITMAP)LoadImage(hInst, pic2, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hPic3 = (HBITMAP)LoadImage(hInst, pic3, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hPic4 = (HBITMAP)LoadImage(hInst, pic4, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hPic5 = (HBITMAP)LoadImage(hInst, pic5, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hPic6 = (HBITMAP)LoadImage(hInst, pic6, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMath3Page1 = (HBITMAP)LoadImage(hInst, math3Page1, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMath3Page2 = (HBITMAP)LoadImage(hInst, math3Page2, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMath3Page3 = (HBITMAP)LoadImage(hInst, math3Page3, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMath3Page4 = (HBITMAP)LoadImage(hInst, math3Page4, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMath4Page1 = (HBITMAP)LoadImage(hInst, math4Page1, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMath4Page2 = (HBITMAP)LoadImage(hInst, math4Page2, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMath4Page3 = (HBITMAP)LoadImage(hInst, math4Page3, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	switch (intSelectedPic)
	{
	case 0:
		hBitmap = (HBITMAP)LoadImage(hInst, pic1, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		break;
	case 1:
		hBitmap = (HBITMAP)LoadImage(hInst, pic2, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		break;
	case 2:
		hBitmap = (HBITMAP)LoadImage(hInst, pic3, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		break;
	case 3:
		hBitmap = (HBITMAP)LoadImage(hInst, pic4, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		break;
	case 4:
		hBitmap = (HBITMAP)LoadImage(hInst, pic5, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		break;
	case 5:
		hBitmap = (HBITMAP)LoadImage(hInst, pic6, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		break;
	default:
		break;
	}

	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, selectedCursor, hInst, LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)), L"MainWindowClass", SoftwareMainProcedure);
	if (!RegisterClassW(&SoftwareMainClass)) {
		return -1;
	}

	MSG SoftwareMainMessage = { 0 };
	CreateWindow(L"MainWindowClass", L"Помощь родителям", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 1280, 720, NULL, NULL, NULL, NULL);
	
	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}
	return 0;
}

int ReadSaveFile() {
	std::ifstream file("Saves\\Save.txt");
	std::string str;
	if (!file.is_open()) { // если файла нет
		std::ofstream f("Saves\\Save.txt");
		f << "100000\n100000\n100000\n0\n0\n0\n0\n";
		for (int i = 1; i < math3classSize + 1; i++) {
			f << "0!";
		}
		f << "\n";
		for (int i = 1; i < math4classSize + 1; i++) {
			f << "0!";
		}
		file.close();
	}
	else {
		// Fonts cost
		file >> str;
		if (std::stoi(str) % 100000 / 10000 == 1) {
			DECORATIVEFontRectangleCost = 0;
		}
		if (std::stoi(str) % 10000 / 1000 == 1) {
			DONTCAREFontRectangleCost = 0;
		}
		if (std::stoi(str) % 1000 / 100 == 1) {
			MODERNFontRectangleCost = 0;
		}
		if (std::stoi(str) % 100 / 10 == 1) {
			SCRIPTFontRectangleCost = 0;
		}
		if (std::stoi(str) % 10 / 1 == 1) {
			SWISSFontRectangleCost = 0;
		}
		// Cursor cost
		file >> str;
		if (std::stoi(str) % 100000 / 10000 == 1) {
			CROSSCursorCost = 0;
		}
		if (std::stoi(str) % 10000 / 1000 == 1) {
			HELPCursorCost = 0;
		}
		if (std::stoi(str) % 1000 / 100 == 1) {
			NOCursorCost = 0;
		}
		if (std::stoi(str) % 100 / 10 == 1) {
			SIZEALLCursorCost = 0;
		}
		if (std::stoi(str) % 10 / 1 == 1) {
			UPARROWCursorCost = 0;
		}
		// Pic cost
		file >> str;
		if (std::stoi(str) % 100000 / 10000 == 1) {
			pic2Cost = 0;
		}
		if (std::stoi(str) % 10000 / 1000 == 1) {
			pic3Cost = 0;
		}
		if (std::stoi(str) % 1000 / 100 == 1) {
			pic4Cost = 0;
		}
		if (std::stoi(str) % 100 / 10 == 1) {
			pic5Cost = 0;
		}
		if (std::stoi(str) % 10 / 1 == 1) {
			pic6Cost = 0;
		}
		// Using Font
		file >> str;
		switch (std::stoi(str))
		{
		case 0:
			selectedFont = DEFAULTFontRectangle;
			bigSelectedFont = BigDEFAULTFontRectangle;
			break;
		case 1:
			selectedFont = DECORATIVEFontRectangle;
			bigSelectedFont = BigDECORATIVEFontRectangle;
			break;
		case 2:
			selectedFont = DONTCAREFontRectangle;
			bigSelectedFont = BigDONTCAREFontRectangle;
			break;
		case 3:
			selectedFont = MODERNFontRectangle;
			bigSelectedFont = BigMODERNFontRectangle;
			break;
		case 4:
			selectedFont = SCRIPTFontRectangle;
			bigSelectedFont = BigSCRIPTFontRectangle;
			break;
		case 5:
			selectedFont = SWISSFontRectangle;
			bigSelectedFont = BigSWISSFontRectangle;
			break;
		default:
			break;
		}
		// Using cursor
		file >> str;
		switch (std::stoi(str))
		{
		case 0:
			selectedCursor = ARROWCursor;
			break;
		case 1:
			selectedCursor = CROSSCursor;
			break;
		case 2:
			selectedCursor = HELPCursor;
			break;
		case 3:
			selectedCursor = NOCursor;
			break;
		case 4:
			selectedCursor = SIZEALLCursor;
			break;
		case 5:
			selectedCursor = UPARROWCursor;
			break;
		default:
			break;
		}
		// Using pic
		file >> str;
		switch (std::stoi(str))
		{
		case 0:
			intSelectedPic = 0;
			break;
		case 1:
			intSelectedPic = 1;
			break;
		case 2:
			intSelectedPic = 2;
			break;
		case 3:
			intSelectedPic = 3;
			break;
		case 4:
			intSelectedPic = 4;
			break;
		case 5:
			intSelectedPic = 5;
			break;
		default:
			break;
		}
		// Money
		file >> str;
		money = std::stoi(str);
		// Math 3
		int temp = 0;
		int masNum = 0;
		file >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != '!') {
				temp = temp * 10 + (str[i] - 48);
			}
			else if (str[i] == '!') {
				math3class[masNum] = temp;
				masNum++;
				temp = 0;
			}
		}
		// Math 4
		temp = 0;
		masNum = 0;
		file >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != '!') {
				temp = temp * 10 + (str[i] - 48);
			}
			else if (str[i] == '!') {
				math4class[masNum] = temp;
				masNum++;
				temp = 0;
			}
		}
		file.close();
	}
}

void SaveSaveFile() {
	std::ofstream f("Saves\\Save.txt", std::ios_base::trunc);

	if (DECORATIVEFontRectangleCost == 0) {
		boughtFonts = boughtFonts + 10000;
	}
	if (DONTCAREFontRectangleCost == 0) {
		boughtFonts = boughtFonts + 1000;
	}
	if (MODERNFontRectangleCost == 0) {
		boughtFonts = boughtFonts + 100;
	}
	if (SCRIPTFontRectangleCost == 0) {
		boughtFonts = boughtFonts + 10;
	}
	if (SWISSFontRectangleCost == 0) {
		boughtFonts = boughtFonts + 1;
	}
	if (CROSSCursorCost == 0) {
		boughtCursors = boughtCursors + 10000;
	}
	if (HELPCursorCost == 0) {
		boughtCursors = boughtCursors + 1000;
	}
	if (NOCursorCost == 0) {
		boughtCursors = boughtCursors + 100;
	}
	if (SIZEALLCursorCost == 0) {
		boughtCursors = boughtCursors + 10;
	}
	if (UPARROWCursorCost == 0) {
		boughtCursors = boughtCursors + 1;
	}
	if (pic2Cost == 0) {
		boughtPics = boughtPics + 10000;
	}
	if (pic3Cost == 0) {
		boughtPics = boughtPics + 1000;
	}
	if (pic4Cost == 0) {
		boughtPics = boughtPics + 100;
	}
	if (pic5Cost == 0) {
		boughtPics = boughtPics + 10;
	}
	if (pic6Cost == 0) {
		boughtPics = boughtPics + 1;
	}

	f << boughtFonts << "\n" << boughtCursors  << "\n" << boughtPics << "\n" << intSelectedFont << "\n" << intSelectedCursor << "\n" << intSelectedPic << "\n" << money << "\n";
	for (int i = 0; i < math3classSize; i++) {
		f << math3class[i] << "!";
	}
	f << "\n";
	for (int i = 0; i < math4classSize; i++) {
		f << math4class[i] << "!";
	}
	f.close();
}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
	WNDCLASS NWC = { 0 };
	NWC.hIcon = Icon;
	NWC.hCursor = Cursor;
	NWC.hInstance = hInst;
	NWC.lpszClassName = Name;
	NWC.hbrBackground = BGColor;
	NWC.lpfnWndProc = Procedure;

	return NWC;
}

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	HDC hdcStatic = NULL; // For transparent text
	int wmId, wmEvent;
	switch (msg){
	case WM_COMMAND:
		switch (LOWORD(wp)){
		case OnMath3ButtonClicked:
			currentMaxPoints = maxMath3Page1Points;
			WorkSpaceMath3(hWnd);
			currentPage = 1000;
			PagePic = hMath3Page1;
			whatToDraw = 1;
			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
			Math3Page1(hWnd);
			break;
		case OnMath4ButtonClicked:
			currentMaxPoints = maxMath4Page1Points;
			WorkSpaceMath4(hWnd);
			currentPage = 2000;
			PagePic = hMath4Page1;
			whatToDraw = 1;
			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
			Math4Page1(hWnd);
			break;
		case PageListMath3: 
			if (HIWORD(wp) == LBN_DBLCLK){ // Double click
				int j = SendDlgItemMessage(hWnd, PageListMath3, LB_GETCURSEL, 0, 0L);
				DestroyAllResponseFields(hWnd);
				switch (j)
				{
				case 0:
					points = math3class[0];
					currentMaxPoints = maxMath3Page1Points;
					PagePic = hMath3Page1;
					currentPage = 1000;
					Math3Page1(hWnd);
					break;
				case 1:
					points = math3class[1];
					currentMaxPoints = maxMath3Page2Points;
					PagePic = hMath3Page2;
					currentPage = 1001;
					Math3Page2(hWnd);
					break;
				case 2:
					points = math3class[2];
					currentMaxPoints = maxMath3Page3Points;
					PagePic = hMath3Page3;
					currentPage = 1002;
					Math3Page3(hWnd);
					break;
				case 3:
					points = math3class[3];
					currentMaxPoints = maxMath3Page4Points;
					PagePic = hMath3Page4;
					currentPage = 1003;
					Math3Page4(hWnd);
					break;
				default:
					break;
				}
				whatToDraw = 1;
				InvalidateRect(hWnd, NULL, TRUE);
				UpdateWindow(hWnd);
			}
			break;
		case PageListMath4: 
			if (HIWORD(wp) == LBN_DBLCLK){ // Double click
				int j = SendDlgItemMessage(hWnd, PageListMath4, LB_GETCURSEL, 0, 0L);
				DestroyAllResponseFields(hWnd);
				switch (j)
				{
				case 0:
					points = math4class[0];
					currentMaxPoints = maxMath4Page1Points;
					PagePic = hMath4Page1;
					currentPage = 2000;
					Math4Page1(hWnd);
					break;
				case 1:
					points = math4class[1];
					currentMaxPoints = maxMath4Page2Points;
					PagePic = hMath4Page2;
					currentPage = 2001;
					Math4Page2(hWnd);
					break;
				case 2:
					points = math4class[2];
					currentMaxPoints = maxMath4Page3Points;
					PagePic = hMath4Page3;
					currentPage = 2002;
					Math4Page3(hWnd);
					break;
				default:
					break;
				}
				whatToDraw = 1;
				InvalidateRect(hWnd, NULL, TRUE);
				UpdateWindow(hWnd);
			}
			break;
		case OnShopButtonClicked:
			ShopWndAddWidgets(hWnd);
			break;
		case ToMainMenuButtonClicked:
			DestroyAllResponseFields(hWnd);
			whatToDraw = 0;
			switch (intSelectedPic)
			{
			case 0:
				hBitmap = hPic1;
				break;
			case 1:
				hBitmap = hPic2;
				break;
			case 2:
				hBitmap = hPic3;
				break;
			case 3:
				hBitmap = hPic4;
				break;
			case 4:
				hBitmap = hPic5;
				break;
			case 5:
				hBitmap = hPic6;
				break;
			default:
				break;
			}
			MainWndAddWidgets(hWnd);
			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
			break;
		case OnCheckResponseClicked:
			switch (currentPage)
			{
			case 1000:
				CheckResponseInMath3Page1(hWnd);
				break;
			case 1001:
				CheckResponseInMath3Page2(hWnd);
				break;
			case 1002:
				CheckResponseInMath3Page3(hWnd);
				break;
			case 1003:
				CheckResponseInMath3Page4(hWnd);
				break;
			case 2000:
				CheckResponseInMath4Page1(hWnd);
				break;
			case 2001:
				CheckResponseInMath4Page2(hWnd);
				break;
			case 2002:
				CheckResponseInMath4Page3(hWnd);
				break;
			default:
				break;
			}
			break;
		case OnPic1ButtonClicked:
			hBitmap = hPic1;
			ChangePic(hWnd);
			intSelectedPic = 0;
			break;
		case OnPic2ButtonClicked:
			if (money >= pic2Cost) {
				hBitmap = hPic2;
				money = money - pic2Cost;
				pic2Cost = 0;
				ChangePic(hWnd);
				intSelectedPic = 1;
			}
			break;
		case OnPic3ButtonClicked:
			if (money >= pic3Cost) {
				hBitmap = hPic3;
				money = money - pic3Cost;
				pic3Cost = 0;
				ChangePic(hWnd);
				intSelectedPic = 2;
			}
			break;
		case OnPic4ButtonClicked:
			if (money >= pic4Cost) {
				hBitmap = hPic4;
				money = money - pic4Cost;
				pic4Cost = 0;
				ChangePic(hWnd);
				intSelectedPic = 3;
			}
			break;
		case OnPic5ButtonClicked:
			if (money >= pic5Cost) {
				hBitmap = hPic5;
				money = money - pic5Cost;
				pic5Cost = 0;
				ChangePic(hWnd);
				intSelectedPic = 4;
			}
			break;
		case OnPic6ButtonClicked:
			if (money >= pic6Cost) {
				hBitmap = hPic6;
				money = money - pic6Cost;
				pic6Cost = 0;
				ChangePic(hWnd);
				intSelectedPic = 5;
			}
			break;
		case OnCursor1ButtonClicked:
			selectedCursor = ARROWCursor;
			ChangeCursor(hWnd);
			intSelectedCursor = 0;
			break;
		case OnCursor2ButtonClicked:
			if (money >= CROSSCursorCost) {
				money = money - CROSSCursorCost;
				CROSSCursorCost = 0;
				selectedCursor = CROSSCursor;
				ChangeCursor(hWnd);
				intSelectedCursor = 1;
			}
			break;
		case OnCursor3ButtonClicked:
			if (money >= HELPCursorCost) {
				money = money - HELPCursorCost;
				HELPCursorCost = 0;
				selectedCursor = HELPCursor;
				ChangeCursor(hWnd);
				intSelectedCursor = 2;
			}
			break;
		case OnCursor4ButtonClicked:
			if (money >= NOCursorCost) {
				money = money - NOCursorCost;
				NOCursorCost = 0;
				selectedCursor = NOCursor;
				ChangeCursor(hWnd);
				intSelectedCursor = 3;
			}
			break;
		case OnCursor5ButtonClicked:
			if (money >= SIZEALLCursorCost) {
				money = money - SIZEALLCursorCost;
				SIZEALLCursorCost = 0;
				selectedCursor = SIZEALLCursor;
				ChangeCursor(hWnd);
				intSelectedCursor = 4;
			}
			break;
		case OnCursor6ButtonClicked:
			if (money >= UPARROWCursorCost) {
				money = money - UPARROWCursorCost;
				UPARROWCursorCost = 0;
				selectedCursor = UPARROWCursor;
				ChangeCursor(hWnd);
				intSelectedCursor = 5;
			}
			break;
		case OnFont1ButtonClicked:
			selectedFont = DEFAULTFontRectangle;
			bigSelectedFont = BigDEFAULTFontRectangle;
			ChangeFont(hWnd);
			intSelectedFont = 0;
			break;
		case OnFont2ButtonClicked:
			if (money >= DECORATIVEFontRectangleCost) {
				money = money - DECORATIVEFontRectangleCost;
				DECORATIVEFontRectangleCost = 0;
				selectedFont = DECORATIVEFontRectangle;
				bigSelectedFont = BigDECORATIVEFontRectangle;
				ChangeFont(hWnd);
				intSelectedFont = 1;
			}
			break;
		case OnFont3ButtonClicked:
			if (money >= DONTCAREFontRectangleCost) {
				money = money - DONTCAREFontRectangleCost;
				DONTCAREFontRectangleCost = 0;
				selectedFont = DONTCAREFontRectangle;
				bigSelectedFont = BigDONTCAREFontRectangle;
				ChangeFont(hWnd);
				intSelectedFont = 2;
			}
			break;
		case OnFont4ButtonClicked:
			if (money >= MODERNFontRectangleCost) {
				money = money - MODERNFontRectangleCost;
				MODERNFontRectangleCost = 0;
				selectedFont = MODERNFontRectangle;
				bigSelectedFont = BigMODERNFontRectangle;
				ChangeFont(hWnd);
				intSelectedFont = 3;
			}
			break;
		case OnFont5ButtonClicked:
			if (money >= SCRIPTFontRectangleCost) {
				money = money - SCRIPTFontRectangleCost;
				SCRIPTFontRectangleCost = 0;
				selectedFont = SCRIPTFontRectangle;
				bigSelectedFont = BigSCRIPTFontRectangle;
				ChangeFont(hWnd);
				intSelectedFont = 4;
			}
			break;
		case OnFont6ButtonClicked:
			if (money >= SWISSFontRectangleCost) {
				money = money - SWISSFontRectangleCost;
				SWISSFontRectangleCost = 0;
				selectedFont = SWISSFontRectangle;
				bigSelectedFont = BigSWISSFontRectangle;
				ChangeFont(hWnd);
				intSelectedFont = 5;
			}
			break;
		default:
			break;
		}
	case WM_PAINT:
		PAINTSTRUCT     ps;
		HDC             hdc;
		BITMAP          bitmap;
		HDC             hdcMem1, hdcMem2;
		HGDIOBJ         oldBitmap1, oldBitmap2;
		if (whatToDraw == 0) {
			hdc = BeginPaint(hWnd, &ps);
			SetBkMode(ps.hdc, TRANSPARENT);
			hdcMem1 = CreateCompatibleDC(hdc);
			oldBitmap1 = SelectObject(hdcMem1, hBitmap);
			GetObject(hBitmap, sizeof(bitmap), &bitmap);
			BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem1, 0, 0, SRCCOPY);
			DeleteDC(hdcMem1);
			EndPaint(hWnd, &ps);
		}
		else if (whatToDraw == 1) {
			hdc = BeginPaint(hWnd, &ps);
			SetBkMode(ps.hdc, TRANSPARENT);
			hdcMem1 = CreateCompatibleDC(hdc);
			hdcMem2 = CreateCompatibleDC(hdc);
			oldBitmap1 = SelectObject(hdcMem1, hBitmap);
			oldBitmap2 = SelectObject(hdcMem2, PagePic);
			GetObject(hBitmap, sizeof(bitmap), &bitmap);
			BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem1, 0, 0, SRCCOPY);
			BitBlt(hdc, 350, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem2, 0, 0, SRCCOPY);
			DeleteDC(hdcMem1);
			DeleteDC(hdcMem2);
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_CTLCOLORSTATIC: // For transparent text
		hdcStatic = (HDC)wp;
		SetTextColor(hdcStatic, RGB(0, 0, 0));
		SetBkMode(hdcStatic, TRANSPARENT);

		return (LRESULT)GetStockObject(NULL_BRUSH);
		break;
	case WM_SETCURSOR:
		SetCursor(selectedCursor);
		break;
	case WM_CREATE:
		CreateWidgets(hWnd);
		MainWndAddWidgets(hWnd);
		break;
	case WM_DESTROY:
		SaveSaveFile();
		DeleteObject(hBitmap);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
}

void CreateWidgets(HWND hWnd) {
	// Money
	MoneyMessage = CreateWindowA("static", ("Монеты: " + std::to_string(money)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 1035, 650, 200, 30, hWnd, NULL, NULL, NULL);
	SendMessageA(MoneyMessage, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	// Main menu
	welcomeMessage1 = CreateWindowA("static", "Добро пожаловать в программу \n\"ПОМОЩЬ РОДИТЕЛЯМ\"", WS_VISIBLE | WS_CHILD | ES_CENTER, 550, 230, 600, 250, hWnd, NULL, NULL, NULL);
	welcomeMessage2 = CreateWindowA("static", "Выберите учебник, с которым хотите работать:", WS_VISIBLE | WS_CHILD | ES_CENTER, 100, 180, 300, 50, hWnd, NULL, NULL, NULL);
	welcomeButton1 = CreateWindowA("button", "Математика 3 класс", WS_VISIBLE | WS_CHILD | ES_CENTER, 100, 250, 300, 50, hWnd, (HMENU)OnMath3ButtonClicked, NULL, NULL);
	welcomeButton2 = CreateWindowA("button", "Математика 4 класс", WS_VISIBLE | WS_CHILD | ES_CENTER, 100, 310, 300, 50, hWnd, (HMENU)OnMath4ButtonClicked, NULL, NULL);
	welcomeButton3 = CreateWindowA("button", "Магазин", WS_VISIBLE | WS_CHILD | ES_CENTER, 1035, 590, 200, 50, hWnd, (HMENU)OnShopButtonClicked, NULL, NULL);

	// Shop
	shopMessage1 = CreateWindowA("static", "Магазин", WS_VISIBLE | WS_CHILD | ES_CENTER, 568, 80, 200, 150, hWnd, NULL, NULL, NULL);
	shopMessage2 = CreateWindowA("static", "Фоны:", WS_VISIBLE | WS_CHILD | ES_CENTER, 250, 150, 150, 100, hWnd, NULL, NULL, NULL);
	shopMessage3 = CreateWindowA("static", "Курсоры:", WS_VISIBLE | WS_CHILD | ES_CENTER, 600, 150, 150, 100, hWnd, NULL, NULL, NULL);
	shopMessage4 = CreateWindowA("static", "Шрифты:", WS_VISIBLE | WS_CHILD | ES_CENTER, 950, 150, 150, 100, hWnd, NULL, NULL, NULL);
	shopPicButton1 = CreateWindowA("button", ("Стандарт.  Цена " + std::to_string(pic1Cost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 210, 180, 240, 50, hWnd, (HMENU)OnPic1ButtonClicked, NULL, NULL);
	shopPicButton2 = CreateWindowA("button", ("Зелень.  Цена " + std::to_string(pic2Cost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 210, 240, 240, 50, hWnd, (HMENU)OnPic2ButtonClicked, NULL, NULL);
	shopPicButton3 = CreateWindowA("button", ("Радуга.  Цена " + std::to_string(pic3Cost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 210, 300, 240, 50, hWnd, (HMENU)OnPic3ButtonClicked, NULL, NULL);
	shopPicButton4 = CreateWindowA("button", ("Модерн.  Цена " + std::to_string(pic4Cost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 210, 360, 240, 50, hWnd, (HMENU)OnPic4ButtonClicked, NULL, NULL);
	shopPicButton5 = CreateWindowA("button", ("РГБ.  Цена " + std::to_string(pic5Cost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 210, 420, 240, 50, hWnd, (HMENU)OnPic5ButtonClicked, NULL, NULL);
	shopPicButton6 = CreateWindowA("button", ("Изящество.  Цена " + std::to_string(pic6Cost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 210, 480, 240, 50, hWnd, (HMENU)OnPic6ButtonClicked, NULL, NULL);
	shopCursorButton1 = CreateWindowA("button", ("Стрелка.  Цена " + std::to_string(ARROWCursorCost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 560, 180, 240, 50, hWnd, (HMENU)OnCursor1ButtonClicked, NULL, NULL);
	shopCursorButton2 = CreateWindowA("button", ("Плюсик.  Цена " + std::to_string(CROSSCursorCost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 560, 240, 240, 50, hWnd, (HMENU)OnCursor2ButtonClicked, NULL, NULL);
	shopCursorButton3 = CreateWindowA("button", ("Вопрос?.  Цена " + std::to_string(HELPCursorCost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 560, 300, 240, 50, hWnd, (HMENU)OnCursor3ButtonClicked, NULL, NULL);
	shopCursorButton4 = CreateWindowA("button", ("Запрещаю.  Цена " + std::to_string(NOCursorCost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 560, 360, 240, 50, hWnd, (HMENU)OnCursor4ButtonClicked, NULL, NULL);
	shopCursorButton5 = CreateWindowA("button", ("Компас.  Цена " + std::to_string(SIZEALLCursorCost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 560, 420, 240, 50, hWnd, (HMENU)OnCursor5ButtonClicked, NULL, NULL);
	shopCursorButton6 = CreateWindowA("button", ("Вверх.  Цена " + std::to_string(UPARROWCursorCost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 560, 480, 240, 50, hWnd, (HMENU)OnCursor6ButtonClicked, NULL, NULL);
	shopFontButton1 = CreateWindowA("button", ("Стандарт.  Цена " + std::to_string(DEFAULTFontRectangleCost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 910, 180, 240, 50, hWnd, (HMENU)OnFont1ButtonClicked, NULL, NULL);
	shopFontButton2 = CreateWindowA("button", ("Декор.  Цена " + std::to_string(DECORATIVEFontRectangleCost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 910, 240, 240, 50, hWnd, (HMENU)OnFont2ButtonClicked, NULL, NULL);
	shopFontButton3 = CreateWindowA("button", ("Всё равно.  Цена " + std::to_string(DONTCAREFontRectangleCost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 910, 300, 240, 50, hWnd, (HMENU)OnFont3ButtonClicked, NULL, NULL);
	shopFontButton4 = CreateWindowA("button", ("Модерн.  Цена " + std::to_string(MODERNFontRectangleCost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 910, 360, 240, 50, hWnd, (HMENU)OnFont4ButtonClicked, NULL, NULL);
	shopFontButton5 = CreateWindowA("button", ("Скрипт.  Цена " + std::to_string(SCRIPTFontRectangleCost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 910, 420, 240, 50, hWnd, (HMENU)OnFont5ButtonClicked, NULL, NULL);
	shopFontButton6 = CreateWindowA("button", ("Швейцар.  Цена " + std::to_string(SWISSFontRectangleCost)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 910, 480, 240, 50, hWnd, (HMENU)OnFont6ButtonClicked, NULL, NULL);
	shopToMainMenu = CreateWindowA("button", "В главное меню", WS_VISIBLE | WS_CHILD | ES_CENTER, 583, 590, 200, 50, hWnd, (HMENU)ToMainMenuButtonClicked, NULL, NULL);

	// work space
	scrollMessage = CreateWindowA("static", "Страницы:", WS_VISIBLE | WS_CHILD | ES_CENTER, 0, 10, 200, 50, hWnd, NULL, NULL, NULL);
	pageScrollerMath3 = CreateWindowA("Listbox", NULL, WS_VISIBLE | WS_CHILD | WS_VSCROLL | WS_TABSTOP | WS_BORDER | LBS_NOTIFY, 0, 50, 200, 690, hWnd, (HMENU)PageListMath3, NULL, NULL);
	for (int i = 3; i < math3PageNum + 3; i++) {
		SendDlgItemMessage(hWnd, PageListMath3, LB_ADDSTRING, 0, (LPARAM)std::to_string(i).c_str());
	}
	pageScrollerMath4 = CreateWindowA("Listbox", NULL, WS_VISIBLE | WS_CHILD | WS_VSCROLL | WS_TABSTOP | WS_BORDER | LBS_NOTIFY, 0, 50, 200, 690, hWnd, (HMENU)PageListMath4, NULL, NULL);
	for (int i = 3; i < math4PageNum + 3; i++) {
		SendDlgItemMessage(hWnd, PageListMath4, LB_ADDSTRING, 0, (LPARAM)std::to_string(i).c_str());
	}
	numberOfPoints = CreateWindowA("static", ("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str(), WS_VISIBLE | WS_CHILD | ES_CENTER, 1035, 471, 200, 50, hWnd, NULL, NULL, NULL);
	checkAnswersButton = CreateWindowA("button", "Проверить ответы", WS_VISIBLE | WS_CHILD | ES_CENTER, 1035, 531, 200, 50, hWnd, (HMENU)OnCheckResponseClicked, NULL, NULL);
	workSpaceToMainMenu = CreateWindowA("button", "В главное меню", WS_VISIBLE | WS_CHILD | ES_CENTER, 1035, 591, 200, 50, hWnd, (HMENU)ToMainMenuButtonClicked, NULL, NULL);
}

void MainWndAddWidgets(HWND hWnd) {
	// turn on the necessary
	SendMessageA(welcomeMessage1, WM_SETFONT, (WPARAM)bigSelectedFont, TRUE);
	ShowWindow(welcomeMessage1, SW_SHOW);
	SendMessageA(welcomeMessage2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(welcomeMessage2, SW_SHOW);
	SendMessageA(welcomeButton1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(welcomeButton1, SW_SHOW);
	SendMessageA(welcomeButton2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(welcomeButton2, SW_SHOW);
	SendMessageA(welcomeButton3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(welcomeButton3, SW_SHOW);

	SetClassLongPtr(welcomeButton1, GCLP_HCURSOR, (LONG_PTR)selectedCursor); // change to selected cursor for buttons

	// turn off the rest
	ShowWindow(shopMessage1, SW_HIDE);
	ShowWindow(shopMessage2, SW_HIDE);
	ShowWindow(shopMessage3, SW_HIDE);
	ShowWindow(shopMessage4, SW_HIDE);
	ShowWindow(shopFontButton1, SW_HIDE);
	ShowWindow(shopFontButton2, SW_HIDE);
	ShowWindow(shopFontButton3, SW_HIDE);
	ShowWindow(shopFontButton4, SW_HIDE);
	ShowWindow(shopFontButton5, SW_HIDE);
	ShowWindow(shopFontButton6, SW_HIDE);
	ShowWindow(shopCursorButton1, SW_HIDE);
	ShowWindow(shopCursorButton2, SW_HIDE);
	ShowWindow(shopCursorButton3, SW_HIDE);
	ShowWindow(shopCursorButton4, SW_HIDE);
	ShowWindow(shopCursorButton5, SW_HIDE);
	ShowWindow(shopCursorButton6, SW_HIDE);
	ShowWindow(shopPicButton1, SW_HIDE);
	ShowWindow(shopPicButton2, SW_HIDE);
	ShowWindow(shopPicButton3, SW_HIDE);
	ShowWindow(shopPicButton4, SW_HIDE);
	ShowWindow(shopPicButton5, SW_HIDE);
	ShowWindow(shopPicButton6, SW_HIDE);
	ShowWindow(shopToMainMenu, SW_HIDE);
	ShowWindow(scrollMessage, SW_HIDE);
	ShowWindow(pageScrollerMath3, SW_HIDE);
	ShowWindow(pageScrollerMath4, SW_HIDE);
	ShowWindow(numberOfPoints, SW_HIDE);
	ShowWindow(checkAnswersButton, SW_HIDE);
	ShowWindow(workSpaceToMainMenu, SW_HIDE);
}

void ShopWndAddWidgets(HWND hWnd) {
	// turn on the necessary
	SendMessageA(shopMessage1, WM_SETFONT, (WPARAM)bigSelectedFont, TRUE);
	ShowWindow(shopMessage1, SW_SHOW);
	SendMessageA(shopMessage2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopMessage2, SW_SHOW);
	SendMessageA(shopMessage3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopMessage3, SW_SHOW);
	SendMessageA(shopMessage4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopMessage4, SW_SHOW);
	SendMessageA(shopFontButton1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopFontButton1, SW_SHOW);
	SendMessageA(shopFontButton2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopFontButton2, SW_SHOW);
	SendMessageA(shopFontButton3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopFontButton3, SW_SHOW);
	SendMessageA(shopFontButton4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopFontButton4, SW_SHOW);
	SendMessageA(shopFontButton5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopFontButton5, SW_SHOW);
	SendMessageA(shopFontButton6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopFontButton6, SW_SHOW);
	SendMessageA(shopCursorButton1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopCursorButton1, SW_SHOW);
	SendMessageA(shopCursorButton2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopCursorButton2, SW_SHOW);
	SendMessageA(shopCursorButton3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopCursorButton3, SW_SHOW);
	SendMessageA(shopCursorButton4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopCursorButton4, SW_SHOW);
	SendMessageA(shopCursorButton5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopCursorButton5, SW_SHOW);
	SendMessageA(shopCursorButton6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopCursorButton6, SW_SHOW);
	SendMessageA(shopPicButton1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopPicButton1, SW_SHOW);
	SendMessageA(shopPicButton2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopPicButton2, SW_SHOW);
	SendMessageA(shopPicButton3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopPicButton3, SW_SHOW);
	SendMessageA(shopPicButton4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopPicButton4, SW_SHOW);
	SendMessageA(shopPicButton5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopPicButton5, SW_SHOW);
	SendMessageA(shopPicButton6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopPicButton6, SW_SHOW);
	SendMessageA(shopToMainMenu, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopToMainMenu, SW_SHOW);

	SetClassLongPtr(welcomeButton1, GCLP_HCURSOR, (LONG_PTR)selectedCursor); // change to selected cursor for buttons

	// turn off the rest
	ShowWindow(welcomeMessage1, SW_HIDE);
	ShowWindow(welcomeMessage2, SW_HIDE);
	ShowWindow(welcomeButton1, SW_HIDE);
	ShowWindow(welcomeButton2, SW_HIDE);
	ShowWindow(welcomeButton3, SW_HIDE);
	ShowWindow(scrollMessage, SW_HIDE);
	ShowWindow(pageScrollerMath3, SW_HIDE);
	ShowWindow(pageScrollerMath4, SW_HIDE);
	ShowWindow(numberOfPoints, SW_HIDE);
	ShowWindow(checkAnswersButton, SW_HIDE);
	ShowWindow(workSpaceToMainMenu, SW_HIDE);
}

void ChangeFont(HWND hWnd) {
	ShowWindow(MoneyMessage, SW_HIDE);
	
	SendMessageA(MoneyMessage, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(MoneyMessage, WM_SETTEXT, NULL, (LPARAM)("Монеты: " + std::to_string(money)).c_str());
	ShowWindow(MoneyMessage, SW_SHOW);
	ShowWindow(shopMessage1, SW_HIDE);
	SendMessageA(shopMessage1, WM_SETFONT, (WPARAM)bigSelectedFont, TRUE);
	ShowWindow(shopMessage1, SW_SHOW);
	ShowWindow(shopMessage2, SW_HIDE);
	SendMessageA(shopMessage2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopMessage2, SW_SHOW);
	ShowWindow(shopMessage3, SW_HIDE);
	SendMessageA(shopMessage3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopMessage3, SW_SHOW);
	ShowWindow(shopMessage4, SW_HIDE);
	SendMessageA(shopMessage4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopMessage4, SW_SHOW);
	ShowWindow(shopFontButton1, SW_HIDE);
	SendMessageA(shopFontButton1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopFontButton1, WM_SETTEXT, NULL, (LPARAM)("Стандарт.  Цена " + std::to_string(DEFAULTFontRectangleCost)).c_str());
	ShowWindow(shopFontButton1, SW_SHOW);
	ShowWindow(shopFontButton2, SW_HIDE);
	SendMessageA(shopFontButton2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopFontButton2, WM_SETTEXT, NULL, (LPARAM)("Декор.  Цена " + std::to_string(DECORATIVEFontRectangleCost)).c_str());
	ShowWindow(shopFontButton2, SW_SHOW);
	ShowWindow(shopFontButton3, SW_HIDE);
	SendMessageA(shopFontButton3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopFontButton3, WM_SETTEXT, NULL, (LPARAM)("Всё равно.  Цена " + std::to_string(DONTCAREFontRectangleCost)).c_str());
	ShowWindow(shopFontButton3, SW_SHOW);
	ShowWindow(shopFontButton4, SW_HIDE);
	SendMessageA(shopFontButton4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopFontButton4, WM_SETTEXT, NULL, (LPARAM)("Модерн.  Цена " + std::to_string(MODERNFontRectangleCost)).c_str());
	ShowWindow(shopFontButton4, SW_SHOW);
	ShowWindow(shopFontButton5, SW_HIDE);
	SendMessageA(shopFontButton5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopFontButton5, WM_SETTEXT, NULL, (LPARAM)("Скрипт.  Цена " + std::to_string(SCRIPTFontRectangleCost)).c_str());
	ShowWindow(shopFontButton5, SW_SHOW);
	ShowWindow(shopFontButton6, SW_HIDE);
	SendMessageA(shopFontButton6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopFontButton6, WM_SETTEXT, NULL, (LPARAM)("Швейцар.  Цена " + std::to_string(SWISSFontRectangleCost)).c_str());
	ShowWindow(shopFontButton6, SW_SHOW);
	ShowWindow(shopCursorButton1, SW_HIDE);
	SendMessageA(shopCursorButton1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopCursorButton1, SW_SHOW);
	ShowWindow(shopCursorButton2, SW_HIDE);
	SendMessageA(shopCursorButton2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopCursorButton2, SW_SHOW);
	ShowWindow(shopCursorButton3, SW_HIDE);
	SendMessageA(shopCursorButton3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopCursorButton3, SW_SHOW);
	ShowWindow(shopCursorButton4, SW_HIDE);
	SendMessageA(shopCursorButton4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopCursorButton4, SW_SHOW);
	ShowWindow(shopCursorButton5, SW_HIDE);
	SendMessageA(shopCursorButton5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopCursorButton5, SW_SHOW);
	ShowWindow(shopCursorButton6, SW_HIDE);
	SendMessageA(shopCursorButton6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopCursorButton6, SW_SHOW);
	ShowWindow(shopPicButton1, SW_HIDE);
	SendMessageA(shopPicButton1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopPicButton1, SW_SHOW);
	ShowWindow(shopPicButton2, SW_HIDE);
	SendMessageA(shopPicButton2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopPicButton2, SW_SHOW);
	ShowWindow(shopPicButton3, SW_HIDE);
	SendMessageA(shopPicButton3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopPicButton3, SW_SHOW);
	ShowWindow(shopPicButton4, SW_HIDE);
	SendMessageA(shopPicButton4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopPicButton4, SW_SHOW);
	ShowWindow(shopPicButton5, SW_HIDE);
	SendMessageA(shopPicButton5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopPicButton5, SW_SHOW);
	ShowWindow(shopPicButton6, SW_HIDE);
	SendMessageA(shopPicButton6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopPicButton6, SW_SHOW);
	ShowWindow(shopToMainMenu, SW_HIDE);
	SendMessageA(shopToMainMenu, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(shopToMainMenu, SW_SHOW);
}

void ChangeCursor(HWND hWnd) {
	ShowWindow(MoneyMessage, SW_HIDE);
	SendMessageA(MoneyMessage, WM_SETTEXT, NULL, (LPARAM)("Монеты: " + std::to_string(money)).c_str());
	ShowWindow(MoneyMessage, SW_SHOW);

	ShowWindow(shopCursorButton1, SW_HIDE);
	SendMessageA(shopCursorButton1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopCursorButton1, WM_SETTEXT, NULL, (LPARAM)("Стрелка.  Цена " + std::to_string(ARROWCursorCost)).c_str());
	ShowWindow(shopCursorButton1, SW_SHOW);
	ShowWindow(shopCursorButton2, SW_HIDE);
	SendMessageA(shopCursorButton2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopCursorButton2, WM_SETTEXT, NULL, (LPARAM)("Плюсик.  Цена " + std::to_string(CROSSCursorCost)).c_str());
	ShowWindow(shopCursorButton2, SW_SHOW);
	ShowWindow(shopCursorButton3, SW_HIDE);
	SendMessageA(shopCursorButton3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopCursorButton3, WM_SETTEXT, NULL, (LPARAM)("Вопрос?.  Цена " + std::to_string(HELPCursorCost)).c_str());
	ShowWindow(shopCursorButton3, SW_SHOW);
	ShowWindow(shopCursorButton4, SW_HIDE);
	SendMessageA(shopCursorButton4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopCursorButton4, WM_SETTEXT, NULL, (LPARAM)("Запрещаю.  Цена " + std::to_string(NOCursorCost)).c_str());
	ShowWindow(shopCursorButton4, SW_SHOW);
	ShowWindow(shopCursorButton5, SW_HIDE);
	SendMessageA(shopCursorButton5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopCursorButton5, WM_SETTEXT, NULL, (LPARAM)("Компас.  Цена " + std::to_string(SIZEALLCursorCost)).c_str());
	ShowWindow(shopCursorButton5, SW_SHOW);
	ShowWindow(shopCursorButton6, SW_HIDE);
	SendMessageA(shopCursorButton6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopCursorButton6, WM_SETTEXT, NULL, (LPARAM)("Вверх.  Цена " + std::to_string(UPARROWCursorCost)).c_str());
	ShowWindow(shopCursorButton6, SW_SHOW);

	SetClassLongPtr(shopCursorButton2, GCLP_HCURSOR, (LONG_PTR)selectedCursor);
}

void ChangePic(HWND hWnd) {
	InvalidateRect(hWnd, NULL, TRUE);
	UpdateWindow(hWnd);

	ShowWindow(MoneyMessage, SW_HIDE);
	SendMessageA(MoneyMessage, WM_SETTEXT, NULL, (LPARAM)("Монеты: " + std::to_string(money)).c_str());
	ShowWindow(MoneyMessage, SW_SHOW);

	ShowWindow(shopPicButton1, SW_HIDE);
	SendMessageA(shopPicButton1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopPicButton1, WM_SETTEXT, NULL, (LPARAM)("Стандарт.  Цена " + std::to_string(pic1Cost)).c_str());
	ShowWindow(shopPicButton1, SW_SHOW);
	ShowWindow(shopPicButton2, SW_HIDE);
	SendMessageA(shopPicButton2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopPicButton2, WM_SETTEXT, NULL, (LPARAM)("Зелень.  Цена " + std::to_string(pic2Cost)).c_str());
	ShowWindow(shopPicButton2, SW_SHOW);
	ShowWindow(shopPicButton3, SW_HIDE);
	SendMessageA(shopPicButton3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopPicButton3, WM_SETTEXT, NULL, (LPARAM)("Радуга.  Цена " + std::to_string(pic3Cost)).c_str());
	ShowWindow(shopPicButton3, SW_SHOW);
	ShowWindow(shopPicButton4, SW_HIDE);
	SendMessageA(shopPicButton4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopPicButton4, WM_SETTEXT, NULL, (LPARAM)("Модерн.  Цена " + std::to_string(pic4Cost)).c_str());
	ShowWindow(shopPicButton4, SW_SHOW);
	ShowWindow(shopPicButton5, SW_HIDE);
	SendMessageA(shopPicButton5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopPicButton5, WM_SETTEXT, NULL, (LPARAM)("РГБ.  Цена " + std::to_string(pic5Cost)).c_str());
	ShowWindow(shopPicButton5, SW_SHOW);
	ShowWindow(shopPicButton6, SW_HIDE);
	SendMessageA(shopPicButton6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(shopPicButton6, WM_SETTEXT, NULL, (LPARAM)("Изящество.  Цена " + std::to_string(pic6Cost)).c_str());
	ShowWindow(shopPicButton6, SW_SHOW);
}

void WorkSpaceMath3(HWND hWnd) {
	points = math3class[0];

	// turn on the necessary
	SendMessageA(scrollMessage, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(scrollMessage, SW_SHOW);
	SendMessageA(pageScrollerMath3, WM_SETFONT, (WPARAM)bigSelectedFont, TRUE);
	ShowWindow(pageScrollerMath3, SW_SHOW);
	SendMessageA(numberOfPoints, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(numberOfPoints, SW_SHOW);
	SendMessageA(checkAnswersButton, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(checkAnswersButton, SW_SHOW);
	SendMessageA(workSpaceToMainMenu, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(workSpaceToMainMenu, SW_SHOW);

	SetClassLongPtr(welcomeButton1, GCLP_HCURSOR, (LONG_PTR)selectedCursor); // change to selected cursor for buttons

	// turn off the rest
	ShowWindow(welcomeMessage1, SW_HIDE);
	ShowWindow(welcomeMessage2, SW_HIDE);
	ShowWindow(welcomeButton1, SW_HIDE);
	ShowWindow(welcomeButton2, SW_HIDE);
	ShowWindow(welcomeButton3, SW_HIDE);
	ShowWindow(shopMessage1, SW_HIDE);
	ShowWindow(shopMessage2, SW_HIDE);
	ShowWindow(shopMessage3, SW_HIDE);
	ShowWindow(shopMessage4, SW_HIDE);
	ShowWindow(shopFontButton1, SW_HIDE);
	ShowWindow(shopFontButton2, SW_HIDE);
	ShowWindow(shopFontButton3, SW_HIDE);
	ShowWindow(shopFontButton4, SW_HIDE);
	ShowWindow(shopFontButton5, SW_HIDE);
	ShowWindow(shopFontButton6, SW_HIDE);
	ShowWindow(shopCursorButton1, SW_HIDE);
	ShowWindow(shopCursorButton2, SW_HIDE);
	ShowWindow(shopCursorButton3, SW_HIDE);
	ShowWindow(shopCursorButton4, SW_HIDE);
	ShowWindow(shopCursorButton5, SW_HIDE);
	ShowWindow(shopCursorButton6, SW_HIDE);
	ShowWindow(shopPicButton1, SW_HIDE);
	ShowWindow(shopPicButton2, SW_HIDE);
	ShowWindow(shopPicButton3, SW_HIDE);
	ShowWindow(shopPicButton4, SW_HIDE);
	ShowWindow(shopPicButton5, SW_HIDE);
	ShowWindow(shopPicButton6, SW_HIDE);
	ShowWindow(shopToMainMenu, SW_HIDE);
	ShowWindow(pageScrollerMath4, SW_HIDE);
}

void WorkSpaceMath4(HWND hWnd) {
	points = math4class[0];

	// turn on the necessary
	SendMessageA(scrollMessage, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(scrollMessage, SW_SHOW);
	SendMessageA(pageScrollerMath4, WM_SETFONT, (WPARAM)bigSelectedFont, TRUE);
	ShowWindow(pageScrollerMath4, SW_SHOW);
	SendMessageA(numberOfPoints, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(numberOfPoints, SW_SHOW);
	SendMessageA(checkAnswersButton, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(checkAnswersButton, SW_SHOW);
	SendMessageA(workSpaceToMainMenu, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	ShowWindow(workSpaceToMainMenu, SW_SHOW);

	SetClassLongPtr(welcomeButton1, GCLP_HCURSOR, (LONG_PTR)selectedCursor); // change to selected cursor for buttons

	// turn off the rest
	ShowWindow(welcomeMessage1, SW_HIDE);
	ShowWindow(welcomeMessage2, SW_HIDE);
	ShowWindow(welcomeButton1, SW_HIDE);
	ShowWindow(welcomeButton2, SW_HIDE);
	ShowWindow(welcomeButton3, SW_HIDE);
	ShowWindow(shopMessage1, SW_HIDE);
	ShowWindow(shopMessage2, SW_HIDE);
	ShowWindow(shopMessage3, SW_HIDE);
	ShowWindow(shopMessage4, SW_HIDE);
	ShowWindow(shopFontButton1, SW_HIDE);
	ShowWindow(shopFontButton2, SW_HIDE);
	ShowWindow(shopFontButton3, SW_HIDE);
	ShowWindow(shopFontButton4, SW_HIDE);
	ShowWindow(shopFontButton5, SW_HIDE);
	ShowWindow(shopFontButton6, SW_HIDE);
	ShowWindow(shopCursorButton1, SW_HIDE);
	ShowWindow(shopCursorButton2, SW_HIDE);
	ShowWindow(shopCursorButton3, SW_HIDE);
	ShowWindow(shopCursorButton4, SW_HIDE);
	ShowWindow(shopCursorButton5, SW_HIDE);
	ShowWindow(shopCursorButton6, SW_HIDE);
	ShowWindow(shopPicButton1, SW_HIDE);
	ShowWindow(shopPicButton2, SW_HIDE);
	ShowWindow(shopPicButton3, SW_HIDE);
	ShowWindow(shopPicButton4, SW_HIDE);
	ShowWindow(shopPicButton5, SW_HIDE);
	ShowWindow(shopPicButton6, SW_HIDE);
	ShowWindow(shopToMainMenu, SW_HIDE);
	ShowWindow(pageScrollerMath3, SW_HIDE);
}

void Math3Page1(HWND hWnd) {
	ShowWindow(numberOfPoints, SW_HIDE);
	SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());
	ShowWindow(numberOfPoints, SW_SHOW);

	resp1 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 455, 190, 40, 30, hWnd, (HMENU)q1, NULL, NULL);
	resp2 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 510, 190, 40, 30, hWnd, (HMENU)q2, NULL, NULL);
	resp3 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 615, 190, 40, 30, hWnd, (HMENU)q3, NULL, NULL);
	resp4 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 665, 190, 40, 30, hWnd, (HMENU)q4, NULL, NULL);
	resp5 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 420, 240, 40, 30, hWnd, (HMENU)q5, NULL, NULL);
	resp6 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 510, 240, 40, 30, hWnd, (HMENU)q6, NULL, NULL);
	resp7 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 650, 240, 40, 30, hWnd, (HMENU)q7, NULL, NULL);
	resp8 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 700, 240, 40, 30, hWnd, (HMENU)q8, NULL, NULL);
	SendMessageA(resp1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp7, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp8, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp9 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 400, 320, 20, 27, hWnd, (HMENU)q9, NULL, NULL);
	resp10 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 400, 347, 20, 27, hWnd, (HMENU)q10, NULL, NULL);
	resp11 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 400, 374, 20, 27, hWnd, (HMENU)q11, NULL, NULL);
	resp12 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 540, 317, 20, 27, hWnd, (HMENU)q12, NULL, NULL);
	resp13 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 540, 344, 20, 27, hWnd, (HMENU)q13, NULL, NULL);
	resp14 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 540, 371, 20, 27, hWnd, (HMENU)q14, NULL, NULL);
	resp15 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 757, 314, 20, 27, hWnd, (HMENU)q15, NULL, NULL);
	resp16 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 747, 341, 20, 27, hWnd, (HMENU)q16, NULL, NULL);
	resp17 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 747, 368, 20, 27, hWnd, (HMENU)q17, NULL, NULL);
	SendMessageA(resp9, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp10, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp11, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp12, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp13, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp14, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp15, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp16, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp17, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp18 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 440, 450, 30, 30, hWnd, (HMENU)q18, NULL, NULL);
	resp19 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 615, 450, 30, 30, hWnd, (HMENU)q19, NULL, NULL);
	resp20 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 770, 450, 30, 30, hWnd, (HMENU)q20, NULL, NULL);
	resp21 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 440, 550, 30, 30, hWnd, (HMENU)q21, NULL, NULL);
	resp22 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 615, 550, 30, 30, hWnd, (HMENU)q22, NULL, NULL);
	resp23 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 770, 550, 30, 30, hWnd, (HMENU)q23, NULL, NULL);
	SendMessageA(resp18, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp19, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp20, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp21, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp22, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp23, WM_SETFONT, (WPARAM)selectedFont, TRUE);
}

void CheckResponseInMath3Page1(HWND hWnd) {
	points = 0;
	LPWSTR respons;
	respons = new TCHAR[GetWindowTextLength(resp1) + 1];
	GetWindowText(resp1, respons, GetWindowTextLength(resp1) + 1);
	if (respons[0] == '9' && respons[1] == '6') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp2) + 1];
	GetWindowText(resp2, respons, GetWindowTextLength(resp2) + 1);
	if (respons[0] == '9' && respons[1] == '7') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp3) + 1];
	GetWindowText(resp3, respons, GetWindowTextLength(resp3) + 1);
	if (respons[0] == '7' && respons[1] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp4) + 1];
	GetWindowText(resp4, respons, GetWindowTextLength(resp4) + 1);
	if (respons[0] == '8' && respons[1] == '0') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp5) + 1];
	GetWindowText(resp5, respons, GetWindowTextLength(resp5) + 1);
	if (respons[0] == '6' && respons[1] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp6) + 1];
	GetWindowText(resp6, respons, GetWindowTextLength(resp6) + 1);
	if (respons[0] == '7' && respons[1] == '1') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp7) + 1];
	GetWindowText(resp7, respons, GetWindowTextLength(resp7) + 1);
	if (respons[0] == '4' && respons[1] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp8) + 1];
	GetWindowText(resp8, respons, GetWindowTextLength(resp8) + 1);
	if (respons[0] == '5' && respons[1] == '0') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp9) + 1];
	GetWindowText(resp9, respons, GetWindowTextLength(resp9) + 1);
	if (respons[0] == '3') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp10) + 1];
	GetWindowText(resp10, respons, GetWindowTextLength(resp10) + 1);
	if (respons[0] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp11) + 1];
	GetWindowText(resp11, respons, GetWindowTextLength(resp11) + 1);
	if (respons[0] == '5') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp12) + 1];
	GetWindowText(resp12, respons, GetWindowTextLength(resp12) + 1);
	if (respons[0] == '8') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp13) + 1];
	GetWindowText(resp13, respons, GetWindowTextLength(resp13) + 1);
	if (respons[0] == '3') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp14) + 1];
	GetWindowText(resp14, respons, GetWindowTextLength(resp14) + 1);
	if (respons[0] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp15) + 1];
	GetWindowText(resp15, respons, GetWindowTextLength(resp15) + 1);
	if (respons[0] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp16) + 1];
	GetWindowText(resp16, respons, GetWindowTextLength(resp16) + 1);
	if (respons[0] == '5') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp17) + 1];
	GetWindowText(resp17, respons, GetWindowTextLength(resp17) + 1);
	if (respons[0] == '8') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp18) + 1];
	GetWindowText(resp18, respons, GetWindowTextLength(resp18) + 1);
	if (respons[0] == '4' && respons[1] == '8') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp19) + 1];
	GetWindowText(resp19, respons, GetWindowTextLength(resp19) + 1);
	if (respons[0] == '5' && respons[1] == '4') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp20) + 1];
	GetWindowText(resp20, respons, GetWindowTextLength(resp20) + 1);
	if (respons[0] == '3' && respons[1] == '5') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp21) + 1];
	GetWindowText(resp21, respons, GetWindowTextLength(resp21) + 1);
	if (respons[0] == '6' && respons[1] == '3') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp22) + 1];
	GetWindowText(resp22, respons, GetWindowTextLength(resp22) + 1);
	if (respons[0] == '3' && respons[1] == '4') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp23) + 1];
	GetWindowText(resp23, respons, GetWindowTextLength(resp23) + 1);
	if (respons[0] == '4' && respons[1] == '5') {
		points = points + 1;
	}

	if (points > math3class[0]) {
		money = money + (points - math3class[0]) * 10;
		math3class[0] = points;
		ShowWindow(numberOfPoints, SW_HIDE);
		SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());
		ShowWindow(numberOfPoints, SW_SHOW);
		ShowWindow(MoneyMessage, SW_HIDE);
		SendMessageA(MoneyMessage, WM_SETTEXT, NULL, (LPARAM)("Монеты: " + std::to_string(money)).c_str());
		ShowWindow(MoneyMessage, SW_SHOW);
	}
	points = 0;
}

void Math3Page2(HWND hWnd) {
	SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());

	resp1 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 490, 235, 30, 30, hWnd, (HMENU)q1, NULL, NULL);
	SendMessageA(resp1, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp2 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 505, 435, 30, 25, hWnd, (HMENU)q2, NULL, NULL);
	resp3 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 505, 460, 30, 25, hWnd, (HMENU)q3, NULL, NULL);
	resp4 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 505, 485, 30, 25, hWnd, (HMENU)q4, NULL, NULL);
	resp5 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 505, 510, 30, 25, hWnd, (HMENU)q5, NULL, NULL);
	resp6 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 647, 440, 30, 25, hWnd, (HMENU)q6, NULL, NULL);
	resp7 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 647, 465, 30, 25, hWnd, (HMENU)q7, NULL, NULL);
	resp8 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 656, 490, 30, 25, hWnd, (HMENU)q8, NULL, NULL);
	resp9 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 656, 515, 30, 25, hWnd, (HMENU)q9, NULL, NULL);
	resp10 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 800, 440, 30, 25, hWnd, (HMENU)q10, NULL, NULL);
	resp11 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 800, 465, 30, 25, hWnd, (HMENU)q11, NULL, NULL);
	resp12 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 808, 490, 30, 25, hWnd, (HMENU)q12, NULL, NULL);
	resp13 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 808, 515, 30, 25, hWnd, (HMENU)q13, NULL, NULL);
	SendMessageA(resp2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp7, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp8, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp9, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp10, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp11, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp12, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp13, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp14 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 445, 555, 20, 25, hWnd, (HMENU)q14, NULL, NULL);
	resp15 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 485, 555, 20, 25, hWnd, (HMENU)q15, NULL, NULL);
	resp16 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 452, 580, 20, 25, hWnd, (HMENU)q16, NULL, NULL);
	resp17 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 492, 580, 20, 25, hWnd, (HMENU)q17, NULL, NULL);
	resp18 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 452, 605, 20, 25, hWnd, (HMENU)q18, NULL, NULL);
	resp19 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 492, 605, 20, 25, hWnd, (HMENU)q19, NULL, NULL);
	resp20 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 655, 555, 20, 25, hWnd, (HMENU)q20, NULL, NULL);
	resp21 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 692, 555, 20, 25, hWnd, (HMENU)q21, NULL, NULL);
	resp22 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 647, 580, 20, 25, hWnd, (HMENU)q22, NULL, NULL);
	resp23 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 683, 580, 20, 25, hWnd, (HMENU)q23, NULL, NULL);
	resp24 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 647, 605, 20, 25, hWnd, (HMENU)q24, NULL, NULL);
	resp25 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 683, 605, 20, 25, hWnd, (HMENU)q25, NULL, NULL);
	SendMessageA(resp14, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp15, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp16, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp17, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp18, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp19, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp20, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp21, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp22, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp23, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp24, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp25, WM_SETFONT, (WPARAM)selectedFont, TRUE);
}

void CheckResponseInMath3Page2(HWND hWnd) {
	points = 0;
	LPWSTR respons;
	respons = new TCHAR[GetWindowTextLength(resp1) + 1];
	GetWindowText(resp1, respons, GetWindowTextLength(resp1) + 1);
	if (respons[0] == '3' && respons[1] == '7') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp2) + 1];
	GetWindowText(resp2, respons, GetWindowTextLength(resp2) + 1);
	if (respons[0] == '7' && respons[1] == '8') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp3) + 1];
	GetWindowText(resp3, respons, GetWindowTextLength(resp3) + 1);
	if (respons[0] == '7' && respons[1] == '2') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp4) + 1];
	GetWindowText(resp4, respons, GetWindowTextLength(resp4) + 1);
	if (respons[0] == '4' && respons[1] == '5') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp5) + 1];
	GetWindowText(resp5, respons, GetWindowTextLength(resp5) + 1);
	if (respons[0] == '5' && respons[1] == '4') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp6) + 1];
	GetWindowText(resp6, respons, GetWindowTextLength(resp6) + 1);
	if (respons[0] == '2' && respons[1] == '2') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp7) + 1];
	GetWindowText(resp7, respons, GetWindowTextLength(resp7) + 1);
	if (respons[0] == '2' && respons[1] == '8') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp8) + 1];
	GetWindowText(resp8, respons, GetWindowTextLength(resp8) + 1);
	if (respons[0] == '6' && respons[1] == '7') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp9) + 1];
	GetWindowText(resp9, respons, GetWindowTextLength(resp9) + 1);
	if (respons[0] == '7' && respons[1] == '2') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp10) + 1];
	GetWindowText(resp10, respons, GetWindowTextLength(resp10) + 1);
	if (respons[0] == '5' && respons[1] == '3') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp11) + 1];
	GetWindowText(resp11, respons, GetWindowTextLength(resp11) + 1);
	if (respons[0] == '8' && respons[1] == '4') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp12) + 1];
	GetWindowText(resp12, respons, GetWindowTextLength(resp12) + 1);
	if (respons[0] == '5' && respons[1] == '5') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp13) + 1];
	GetWindowText(resp13, respons, GetWindowTextLength(resp13) + 1);
	if (respons[0] == '2' && respons[1] == '3') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp14) + 1];
	GetWindowText(resp14, respons, GetWindowTextLength(resp14) + 1);
	if (respons[0] == '+') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp15) + 1];
	GetWindowText(resp15, respons, GetWindowTextLength(resp15) + 1);
	if (respons[0] == '+') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp16) + 1];
	GetWindowText(resp16, respons, GetWindowTextLength(resp16) + 1);
	if (respons[0] == '-') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp17) + 1];
	GetWindowText(resp17, respons, GetWindowTextLength(resp17) + 1);
	if (respons[0] == '+') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp18) + 1];
	GetWindowText(resp18, respons, GetWindowTextLength(resp18) + 1);
	if (respons[0] == '-') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp19) + 1];
	GetWindowText(resp19, respons, GetWindowTextLength(resp19) + 1);
	if (respons[0] == '+') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp20) + 1];
	GetWindowText(resp20, respons, GetWindowTextLength(resp20) + 1);
	if (respons[0] == '-') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp21) + 1];
	GetWindowText(resp21, respons, GetWindowTextLength(resp21) + 1);
	if (respons[0] == '+') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp22) + 1];
	GetWindowText(resp22, respons, GetWindowTextLength(resp22) + 1);
	if (respons[0] == '-' || respons[0] == '+') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp23) + 1];
	GetWindowText(resp23, respons, GetWindowTextLength(resp23) + 1);
	if (respons[0] == '+') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp24) + 1];
	GetWindowText(resp24, respons, GetWindowTextLength(resp24) + 1);
	if (respons[0] == '-') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp25) + 1];
	GetWindowText(resp25, respons, GetWindowTextLength(resp25) + 1);
	if (respons[0] == '+') {
		points = points + 1;
	}

	if (points > math3class[1]) {
		money = money + (points - math3class[1]) * 10;
		math3class[1] = points;
		ShowWindow(numberOfPoints, SW_HIDE);
		SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());
		ShowWindow(numberOfPoints, SW_SHOW);
		ShowWindow(MoneyMessage, SW_HIDE);
		SendMessageA(MoneyMessage, WM_SETTEXT, NULL, (LPARAM)("Монеты: " + std::to_string(money)).c_str());
		ShowWindow(MoneyMessage, SW_SHOW);
	}
	points = 0;
}

void Math3Page3(HWND hWnd) {
	SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());

	resp1 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 720, 215, 30, 30, hWnd, (HMENU)q1, NULL, NULL);
	SendMessageA(resp1, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp2 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 400, 400, 30, 30, hWnd, (HMENU)q2, NULL, NULL);
	resp3 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 600, 400, 30, 30, hWnd, (HMENU)q3, NULL, NULL);
	SendMessageA(resp2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp3, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp4 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 530, 495, 30, 30, hWnd, (HMENU)q4, NULL, NULL);
	resp5 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 530, 525, 30, 30, hWnd, (HMENU)q5, NULL, NULL);
	resp6 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 730, 495, 30, 30, hWnd, (HMENU)q6, NULL, NULL);
	resp7 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 780, 525, 30, 30, hWnd, (HMENU)q7, NULL, NULL);
	SendMessageA(resp4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp7, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp8 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 550, 582, 30, 30, hWnd, (HMENU)q8, NULL, NULL);
	resp9 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 550, 612, 30, 30, hWnd, (HMENU)q9, NULL, NULL);
	resp10 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 770, 582, 40, 30, hWnd, (HMENU)q10, NULL, NULL);
	resp11 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 770, 612, 40, 30, hWnd, (HMENU)q11, NULL, NULL);
	SendMessageA(resp8, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp9, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp10, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp11, WM_SETFONT, (WPARAM)selectedFont, TRUE);
}

void CheckResponseInMath3Page3(HWND hWnd) {
	points = 0;
	LPWSTR respons;
	respons = new TCHAR[GetWindowTextLength(resp1) + 1];
	GetWindowText(resp1, respons, GetWindowTextLength(resp1) + 1);
	if (respons[0] == '4' && respons[1] == '4') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp2) + 1];
	GetWindowText(resp2, respons, GetWindowTextLength(resp2) + 1);
	if (respons[0] == '1' && respons[1] == '2') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp3) + 1];
	GetWindowText(resp3, respons, GetWindowTextLength(resp3) + 1);
	if (respons[0] == '1' && respons[1] == '9') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp4) + 1];
	GetWindowText(resp4, respons, GetWindowTextLength(resp4) + 1);
	if (respons[0] == '+') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp5) + 1];
	GetWindowText(resp5, respons, GetWindowTextLength(resp5) + 1);
	if (respons[0] == '-') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp6) + 1];
	GetWindowText(resp6, respons, GetWindowTextLength(resp6) + 1);
	if (respons[0] == '-') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp7) + 1];
	GetWindowText(resp7, respons, GetWindowTextLength(resp7) + 1);
	if (respons[0] == '+') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp8) + 1];
	GetWindowText(resp8, respons, GetWindowTextLength(resp8) + 1);
	if (respons[0] == '5' && respons[1] == '0') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp9) + 1];
	GetWindowText(resp9, respons, GetWindowTextLength(resp9) + 1);
	if (respons[0] == '6' && respons[1] == '0') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp10) + 1];
	GetWindowText(resp10, respons, GetWindowTextLength(resp10) + 1);
	if (respons[0] == '1' && respons[1] == '0' && respons[2] == '0') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp11) + 1];
	GetWindowText(resp11, respons, GetWindowTextLength(resp11) + 1);
	if (respons[0] == '1' && respons[1] == '0' && respons[2] == '0') {
		points = points + 1;
	}

	if (points > math3class[2]) {
		money = money + (points - math3class[2]) * 10;
		math3class[2] = points;
		ShowWindow(numberOfPoints, SW_HIDE);
		SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());
		ShowWindow(numberOfPoints, SW_SHOW);
		ShowWindow(MoneyMessage, SW_HIDE);
		SendMessageA(MoneyMessage, WM_SETTEXT, NULL, (LPARAM)("Монеты: " + std::to_string(money)).c_str());
		ShowWindow(MoneyMessage, SW_SHOW);
	}
	points = 0;
}

void Math3Page4(HWND hWnd) {
	SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());

	resp1 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 660, 180, 20, 30, hWnd, (HMENU)q1, NULL, NULL);
	resp2 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 735, 265, 30, 30, hWnd, (HMENU)q2, NULL, NULL);
	resp3 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 560, 350, 20, 30, hWnd, (HMENU)q3, NULL, NULL);
	resp4 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 595, 450, 20, 30, hWnd, (HMENU)q4, NULL, NULL);
	resp5 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 735, 535, 30, 30, hWnd, (HMENU)q5, NULL, NULL);
	SendMessageA(resp1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp5, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp6 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 465, 620, 30, 30, hWnd, (HMENU)q6, NULL, NULL);
	resp7 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 550, 620, 30, 30, hWnd, (HMENU)q7, NULL, NULL);
	resp8 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 635, 620, 30, 30, hWnd, (HMENU)q8, NULL, NULL);
	resp9 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 720, 620, 30, 30, hWnd, (HMENU)q9, NULL, NULL);
	resp10 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 805, 620, 30, 30, hWnd, (HMENU)q10, NULL, NULL);
	SendMessageA(resp6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp7, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp8, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp9, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp10, WM_SETFONT, (WPARAM)selectedFont, TRUE);
}

void CheckResponseInMath3Page4(HWND hWnd) {
	points = 0;
	LPWSTR respons;
	respons = new TCHAR[GetWindowTextLength(resp1) + 1];
	GetWindowText(resp1, respons, GetWindowTextLength(resp1) + 1);
	if (respons[0] == '5') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp2) + 1];
	GetWindowText(resp2, respons, GetWindowTextLength(resp2) + 1);
	if (respons[0] == '1' && respons[1] == '6') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp3) + 1];
	GetWindowText(resp3, respons, GetWindowTextLength(resp3) + 1);
	if (respons[0] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp4) + 1];
	GetWindowText(resp4, respons, GetWindowTextLength(resp4) + 1);
	if (respons[0] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp5) + 1];
	GetWindowText(resp5, respons, GetWindowTextLength(resp5) + 1);
	if (respons[0] == '1' && respons[1] == '1') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp6) + 1];
	GetWindowText(resp6, respons, GetWindowTextLength(resp6) + 1);
	if (respons[0] == '5' && respons[1] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp7) + 1];
	GetWindowText(resp7, respons, GetWindowTextLength(resp7) + 1);
	if (respons[0] == '8' && respons[1] == '2') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp8) + 1];
	GetWindowText(resp8, respons, GetWindowTextLength(resp8) + 1);
	if (respons[0] == '3' && respons[1] == '2') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp9) + 1];
	GetWindowText(resp9, respons, GetWindowTextLength(resp9) + 1);
	if (respons[0] == '2' && respons[1] == '7') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp10) + 1];
	GetWindowText(resp10, respons, GetWindowTextLength(resp10) + 1);
	if (respons[0] == '2' && respons[1] == '7') {
		points = points + 1;
	}

	if (points > math3class[3]) {
		money = money + (points - math3class[3]) * 10;
		math3class[3] = points;
		ShowWindow(numberOfPoints, SW_HIDE);
		SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());
		ShowWindow(numberOfPoints, SW_SHOW);
		ShowWindow(MoneyMessage, SW_HIDE);
		SendMessageA(MoneyMessage, WM_SETTEXT, NULL, (LPARAM)("Монеты: " + std::to_string(money)).c_str());
		ShowWindow(MoneyMessage, SW_SHOW);
	}
	points = 0;
}

void Math4Page1(HWND hWnd) {
	ShowWindow(numberOfPoints, SW_HIDE);
	SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());
	ShowWindow(numberOfPoints, SW_SHOW);

	resp1 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 400, 170, 40, 30, hWnd, (HMENU)q1, NULL, NULL);
	resp2 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 450, 170, 40, 30, hWnd, (HMENU)q2, NULL, NULL);
	resp3 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 500, 170, 40, 30, hWnd, (HMENU)q3, NULL, NULL);
	resp4 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 550, 170, 40, 30, hWnd, (HMENU)q4, NULL, NULL);
	resp5 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 600, 170, 40, 30, hWnd, (HMENU)q5, NULL, NULL);
	resp6 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 650, 170, 40, 30, hWnd, (HMENU)q6, NULL, NULL);
	resp7 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 700, 170, 40, 30, hWnd, (HMENU)q7, NULL, NULL);
	SendMessageA(resp1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp7, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp8 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 490, 300, 40, 30, hWnd, (HMENU)q8, NULL, NULL);
	resp9 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 545, 300, 40, 30, hWnd, (HMENU)q9, NULL, NULL);
	resp10 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 600, 300, 40, 30, hWnd, (HMENU)q10, NULL, NULL);
	resp11 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 660, 300, 40, 30, hWnd, (HMENU)q11, NULL, NULL);
	resp12 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 715, 300, 60, 30, hWnd, (HMENU)q12, NULL, NULL);
	SendMessageA(resp8, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp9, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp10, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp11, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp12, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp13 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 428, 372, 18, 30, hWnd, (HMENU)q13, NULL, NULL);
	resp14 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 627, 374, 18, 30, hWnd, (HMENU)q14, NULL, NULL);
	resp15 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 710, 376, 18, 30, hWnd, (HMENU)q15, NULL, NULL);
	resp16 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 395, 406, 18, 30, hWnd, (HMENU)q16, NULL, NULL);
	resp17 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 545, 408, 18, 30, hWnd, (HMENU)q17, NULL, NULL);
	resp18 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 690, 410, 18, 30, hWnd, (HMENU)q18, NULL, NULL);
	SendMessageA(resp13, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp14, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp15, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp16, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp17, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp18, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp19 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 545, 490, 30, 30, hWnd, (HMENU)q19, NULL, NULL);
	resp20 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 545, 520, 30, 30, hWnd, (HMENU)q20, NULL, NULL);
	resp21 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 790, 490, 30, 30, hWnd, (HMENU)q21, NULL, NULL);
	resp22 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 775, 520, 30, 30, hWnd, (HMENU)q22, NULL, NULL);
	SendMessageA(resp19, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp20, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp21, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp22, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp23 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 460, 605, 40, 30, hWnd, (HMENU)q23, NULL, NULL);
	resp24 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 560, 605, 40, 30, hWnd, (HMENU)q24, NULL, NULL);
	resp25 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 660, 606, 40, 30, hWnd, (HMENU)q25, NULL, NULL);
	resp26 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 760, 606, 40, 30, hWnd, (HMENU)q26, NULL, NULL);
	SendMessageA(resp23, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp24, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp25, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp26, WM_SETFONT, (WPARAM)selectedFont, TRUE);
}

void CheckResponseInMath4Page1(HWND hWnd) {
	points = 0;
	LPWSTR respons;
	respons = new TCHAR[GetWindowTextLength(resp1) + 1];
	GetWindowText(resp1, respons, GetWindowTextLength(resp1) + 1);
	if (respons[0] == '7' && respons[1] == '1' && respons[2] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp2) + 1];
	GetWindowText(resp2, respons, GetWindowTextLength(resp2) + 1);
	if (respons[0] == '7' && respons[1] == '2' && respons[2] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp3) + 1];
	GetWindowText(resp3, respons, GetWindowTextLength(resp3) + 1);
	if (respons[0] == '7' && respons[1] == '3' && respons[2] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp4) + 1];
	GetWindowText(resp4, respons, GetWindowTextLength(resp4) + 1);
	if (respons[0] == '7' && respons[1] == '4' && respons[2] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp5) + 1];
	GetWindowText(resp5, respons, GetWindowTextLength(resp5) + 1);
	if (respons[0] == '7' && respons[1] == '5' && respons[2] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp6) + 1];
	GetWindowText(resp6, respons, GetWindowTextLength(resp6) + 1);
	if (respons[0] == '7' && respons[1] == '6' && respons[2] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp7) + 1];
	GetWindowText(resp7, respons, GetWindowTextLength(resp7) + 1);
	if (respons[0] == '7' && respons[1] == '7' && respons[2] == '9') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp8) + 1];
	GetWindowText(resp8, respons, GetWindowTextLength(resp8) + 1);
	if (respons[0] == '4' && respons[1] == '4' && respons[2] == '2') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp9) + 1];
	GetWindowText(resp9, respons, GetWindowTextLength(resp9) + 1);
	if (respons[0] == '3' && respons[1] == '1' && respons[2] == '2') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp10) + 1];
	GetWindowText(resp10, respons, GetWindowTextLength(resp10) + 1);
	if (respons[0] == '5' && respons[1] == '2' && respons[2] == '2') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp11) + 1];
	GetWindowText(resp11, respons, GetWindowTextLength(resp11) + 1);
	if (respons[0] == '8' && respons[1] == '9' && respons[2] == '2') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp12) + 1];
	GetWindowText(resp12, respons, GetWindowTextLength(resp12) + 1);
	if (respons[0] == '1' && respons[1] == '0' && respons[2] == '0' && respons[3] == '2') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp13) + 1];
	GetWindowText(resp13, respons, GetWindowTextLength(resp13) + 1);
	if (respons[0] == '0' || respons[0] == '1' || respons[0] == '2' || respons[0] == '3' || respons[0] == '4' || 
		respons[0] == '5' || respons[0] == '6' || respons[0] == '7' || respons[0] == '8' || respons[0] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp14) + 1];
	GetWindowText(resp14, respons, GetWindowTextLength(resp14) + 1);
	if (respons[0] == '5' || respons[0] == '6' || respons[0] == '7' || respons[0] == '8' || respons[0] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp15) + 1];
	GetWindowText(resp15, respons, GetWindowTextLength(resp15) + 1);
	if (respons[0] == '0') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp16) + 1];
	GetWindowText(resp16, respons, GetWindowTextLength(resp16) + 1);
	if (respons[0] == '1' || respons[0] == '2' || respons[0] == '3' || respons[0] == '4' || respons[0] == '5' || 
		respons[0] == '6') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp17) + 1];
	GetWindowText(resp17, respons, GetWindowTextLength(resp17) + 1);
	if (respons[0] == '4' || respons[0] == '5' || respons[0] == '6' || respons[0] == '7' || respons[0] == '8' || 
		respons[0] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp18) + 1];
	GetWindowText(resp18, respons, GetWindowTextLength(resp18) + 1);
	if (respons[0] == '1') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp19) + 1];
	GetWindowText(resp19, respons, GetWindowTextLength(resp19) + 1);
	if (respons[0] == '6' && respons[1] == '0') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp20) + 1];
	GetWindowText(resp20, respons, GetWindowTextLength(resp20) + 1);
	if (respons[0] == '5' && respons[1] == '4') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp21) + 1];
	GetWindowText(resp21, respons, GetWindowTextLength(resp21) + 1);
	if (respons[0] == '5') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp22) + 1];
	GetWindowText(resp22, respons, GetWindowTextLength(resp22) + 1);
	if (respons[0] == '2' && respons[1] == '1') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp23) + 1];
	GetWindowText(resp23, respons, GetWindowTextLength(resp23) + 1);
	if (respons[0] == '9' && respons[1] == '8' && respons[2] == '4') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp24) + 1];
	GetWindowText(resp24, respons, GetWindowTextLength(resp24) + 1);
	if (respons[0] == '6' && respons[1] == '4' && respons[2] == '6') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp25) + 1];
	GetWindowText(resp25, respons, GetWindowTextLength(resp25) + 1);
	if (respons[0] == '2' && respons[1] == '0' && respons[2] == '9') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp26) + 1];
	GetWindowText(resp26, respons, GetWindowTextLength(resp26) + 1);
	if (respons[0] == '2' && respons[1] == '3' && respons[2] == '5') {
		points = points + 1;
	}

	if (points > math4class[0]) {
		money = money + (points - math4class[0]) * 10;
		math4class[0] = points;
		ShowWindow(numberOfPoints, SW_HIDE);
		SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());
		ShowWindow(numberOfPoints, SW_SHOW);
		ShowWindow(MoneyMessage, SW_HIDE);
		SendMessageA(MoneyMessage, WM_SETTEXT, NULL, (LPARAM)("Монеты: " + std::to_string(money)).c_str());
		ShowWindow(MoneyMessage, SW_SHOW);
	}
	points = 0;
}

void Math4Page2(HWND hWnd) {
	SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());

	resp1 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 740, 250, 40, 30, hWnd, (HMENU)q1, NULL, NULL);
	resp2 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 740, 500, 40, 30, hWnd, (HMENU)q2, NULL, NULL);
	SendMessageA(resp1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp2, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp3 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 510, 590, 40, 30, hWnd, (HMENU)q3, NULL, NULL);
	resp4 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 575, 590, 40, 30, hWnd, (HMENU)q4, NULL, NULL);
	resp5 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 645, 590, 40, 30, hWnd, (HMENU)q5, NULL, NULL);
	resp6 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 705, 590, 40, 30, hWnd, (HMENU)q6, NULL, NULL);
	resp7 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 760, 590, 60, 30, hWnd, (HMENU)q7, NULL, NULL);
	SendMessageA(resp3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp6, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp7, WM_SETFONT, (WPARAM)selectedFont, TRUE);
}

void CheckResponseInMath4Page2(HWND hWnd) {
	points = 0;
	LPWSTR respons;
	respons = new TCHAR[GetWindowTextLength(resp1) + 1];
	GetWindowText(resp1, respons, GetWindowTextLength(resp1) + 1);
	if (respons[0] == '5' && respons[1] == '5') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp2) + 1];
	GetWindowText(resp2, respons, GetWindowTextLength(resp2) + 1);
	if (respons[0] == '1' && respons[1] == '2') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp3) + 1];
	GetWindowText(resp3, respons, GetWindowTextLength(resp3) + 1);
	if (respons[0] == '1' && respons[1] == '0' && respons[2] == '3') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp4) + 1];
	GetWindowText(resp4, respons, GetWindowTextLength(resp4) + 1);
	if (respons[0] == '6' && respons[1] == '0' && respons[2] == '3') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp5) + 1];
	GetWindowText(resp5, respons, GetWindowTextLength(resp5) + 1);
	if (respons[0] == '7' && respons[1] == '4' && respons[2] == '3') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp6) + 1];
	GetWindowText(resp6, respons, GetWindowTextLength(resp6) + 1);
	if (respons[0] == '9' && respons[1] == '9' && respons[2] == '3') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp7) + 1];
	GetWindowText(resp7, respons, GetWindowTextLength(resp7) + 1);
	if (respons[0] == '1' && respons[1] == '0' && respons[2] == '0' && respons[3] == '3') {
		points = points + 1;
	}

	if (points > math4class[1]) {
		money = money + (points - math4class[1]) * 10;
		math4class[1] = points;
		ShowWindow(numberOfPoints, SW_HIDE);
		SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());
		ShowWindow(numberOfPoints, SW_SHOW);
		ShowWindow(MoneyMessage, SW_HIDE);
		SendMessageA(MoneyMessage, WM_SETTEXT, NULL, (LPARAM)("Монеты: " + std::to_string(money)).c_str());
		ShowWindow(MoneyMessage, SW_SHOW);
	}
	points = 0;
}

void Math4Page3(HWND hWnd) {
	SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());

	resp1 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 530, 75, 40, 30, hWnd, (HMENU)q1, NULL, NULL);
	resp2 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 530, 105, 40, 30, hWnd, (HMENU)q2, NULL, NULL);
	resp3 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 530, 135, 40, 30, hWnd, (HMENU)q3, NULL, NULL);
	resp4 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 780, 75, 40, 30, hWnd, (HMENU)q4, NULL, NULL);
	resp5 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 795, 105, 40, 30, hWnd, (HMENU)q5, NULL, NULL);
	resp6 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 795, 135, 40, 30, hWnd, (HMENU)q6, NULL, NULL);
	SendMessageA(resp1, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp2, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp3, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp4, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp5, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp6, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp7 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 710, 260, 40, 30, hWnd, (HMENU)q7, NULL, NULL);
	SendMessageA(resp7, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp8 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 425, 375, 40, 30, hWnd, (HMENU)q8, NULL, NULL);
	resp9 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 575, 375, 40, 30, hWnd, (HMENU)q9, NULL, NULL);
	resp10 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 725, 375, 40, 30, hWnd, (HMENU)q10, NULL, NULL);
	resp11 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 425, 465, 40, 30, hWnd, (HMENU)q11, NULL, NULL);
	resp12 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 575, 465, 40, 30, hWnd, (HMENU)q12, NULL, NULL);
	resp13 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 725, 465, 40, 30, hWnd, (HMENU)q13, NULL, NULL);
	SendMessageA(resp8, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp9, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp10, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp11, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp12, WM_SETFONT, (WPARAM)selectedFont, TRUE);
	SendMessageA(resp13, WM_SETFONT, (WPARAM)selectedFont, TRUE);

	resp14 = CreateWindowA("edit", NULL, WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, 710, 595, 40, 30, hWnd, (HMENU)q14, NULL, NULL);
	SendMessageA(resp14, WM_SETFONT, (WPARAM)selectedFont, TRUE);
}

void CheckResponseInMath4Page3(HWND hWnd) {
	points = 0;
	LPWSTR respons;
	respons = new TCHAR[GetWindowTextLength(resp1) + 1];
	GetWindowText(resp1, respons, GetWindowTextLength(resp1) + 1);
	if (respons[0] == '5' && respons[1] == '4') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp2) + 1];
	GetWindowText(resp2, respons, GetWindowTextLength(resp2) + 1);
	if (respons[0] == '6') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp3) + 1];
	GetWindowText(resp3, respons, GetWindowTextLength(resp3) + 1);
	if (respons[0] == '1') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp4) + 1];
	GetWindowText(resp4, respons, GetWindowTextLength(resp4) + 1);
	if (respons[0] == '5' && respons[1] == '3' && respons[2] == '1') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp5) + 1];
	GetWindowText(resp5, respons, GetWindowTextLength(resp5) + 1);
	if (respons[0] == '8' && respons[1] == '6') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp6) + 1];
	GetWindowText(resp6, respons, GetWindowTextLength(resp6) + 1);
	if (respons[0] == '5') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp7) + 1];
	GetWindowText(resp7, respons, GetWindowTextLength(resp7) + 1);
	if (respons[0] == '1' && respons[1] == '8') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp8) + 1];
	GetWindowText(resp8, respons, GetWindowTextLength(resp8) + 1);
	if (respons[0] == '0') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp9) + 1];
	GetWindowText(resp9, respons, GetWindowTextLength(resp9) + 1);
	if (respons[0] == '0') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp10) + 1];
	GetWindowText(resp10, respons, GetWindowTextLength(resp10) + 1);
	if (respons[0] == '2' && respons[1] == '7') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp11) + 1];
	GetWindowText(resp11, respons, GetWindowTextLength(resp11) + 1);
	if (respons[0] == '5' && respons[1] == '7') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp12) + 1];
	GetWindowText(resp12, respons, GetWindowTextLength(resp12) + 1);
	if (respons[0] == '3' && respons[1] == '7') {
		points = points + 1;
	}
	respons = new TCHAR[GetWindowTextLength(resp13) + 1];
	GetWindowText(resp13, respons, GetWindowTextLength(resp13) + 1);
	if (respons[0] == '7') {
		points = points + 1;
	}

	respons = new TCHAR[GetWindowTextLength(resp14) + 1];
	GetWindowText(resp14, respons, GetWindowTextLength(resp14) + 1);
	if (respons[0] == '5' && respons[1] == '5') {
		points = points + 1;
	}

	if (points > math4class[2]) {
		money = money + (points - math4class[2]) * 10;
		math4class[2] = points;
		ShowWindow(numberOfPoints, SW_HIDE);
		SendMessageA(numberOfPoints, WM_SETTEXT, NULL, (LPARAM)("Кол-во баллов: " + std::to_string(points) + "/" + std::to_string(currentMaxPoints)).c_str());
		ShowWindow(numberOfPoints, SW_SHOW);
		ShowWindow(MoneyMessage, SW_HIDE);
		SendMessageA(MoneyMessage, WM_SETTEXT, NULL, (LPARAM)("Монеты: " + std::to_string(money)).c_str());
		ShowWindow(MoneyMessage, SW_SHOW);
	}
	points = 0;
}

void DestroyAllResponseFields(HWND hWnd) {
	DestroyWindow(resp1);
	DestroyWindow(resp2);
	DestroyWindow(resp3);
	DestroyWindow(resp4);
	DestroyWindow(resp5);
	DestroyWindow(resp6);
	DestroyWindow(resp7);
	DestroyWindow(resp8);
	DestroyWindow(resp9);
	DestroyWindow(resp10);
	DestroyWindow(resp11);
	DestroyWindow(resp12);
	DestroyWindow(resp13);
	DestroyWindow(resp14);
	DestroyWindow(resp15);
	DestroyWindow(resp16);
	DestroyWindow(resp17);
	DestroyWindow(resp18);
	DestroyWindow(resp19);
	DestroyWindow(resp20);
	DestroyWindow(resp21);
	DestroyWindow(resp22);
	DestroyWindow(resp23);
	DestroyWindow(resp24);
	DestroyWindow(resp25);
	DestroyWindow(resp26);
	DestroyWindow(resp27);
	DestroyWindow(resp28);
	DestroyWindow(resp29);
	DestroyWindow(resp30);
	DestroyWindow(resp31);
	DestroyWindow(resp32);
	DestroyWindow(resp33);
	DestroyWindow(resp34);
	DestroyWindow(resp35);
	DestroyWindow(resp36);
	DestroyWindow(resp37);
	DestroyWindow(resp38);
	DestroyWindow(resp39);
	DestroyWindow(resp40);
}
