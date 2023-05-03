#pragma once

// Button signals (сигналы нажатия кнопок)
#define OnMath4ButtonClicked		5
#define OnMath3ButtonClicked		6
#define OnShopButtonClicked			7
#define ToMainMenuButtonClicked		8
#define OnFont1ButtonClicked		10
#define OnFont2ButtonClicked		11
#define OnFont3ButtonClicked		12
#define OnFont4ButtonClicked		13
#define OnFont5ButtonClicked		14
#define OnFont6ButtonClicked		15
#define OnCursor1ButtonClicked		20
#define OnCursor2ButtonClicked		21
#define OnCursor3ButtonClicked		22
#define OnCursor4ButtonClicked		23
#define OnCursor5ButtonClicked		24
#define OnCursor6ButtonClicked		25
#define OnPic1ButtonClicked			30
#define OnPic2ButtonClicked			31
#define OnPic3ButtonClicked			32
#define OnPic4ButtonClicked			33
#define OnPic5ButtonClicked			34
#define OnPic6ButtonClicked			35
#define PageListMath3				1001
#define PageListMath4				1002
#define OnCheckResponseClicked		1003
#define q1							1011
#define q2							1012
#define q3							1013
#define q4							1014
#define q5							1015
#define q6							1016
#define q7							1017
#define q8							1018
#define q9							1019
#define q10							1020
#define q11							1021
#define q12							1022
#define q13							1023
#define q14							1024
#define q15							1025
#define q16							1026
#define q17							1027
#define q18							1028
#define q19							1029
#define q20							1030
#define q21							1031
#define q22							1032
#define q23							1033
#define q24							1034
#define q25							1035
#define q26							1036
#define q27							1037
#define q28							1038
#define q29							1039
#define q30							1040
#define q31							1041
#define q32							1042
#define q33							1043
#define q34							1044
#define q35							1045
#define q36							1046
#define q37							1047
#define q38							1048
#define q39							1049
#define q40							1040


int whatToDraw = 0; // !!!


// Fonts (Шрифты)
HFONT DEFAULTFontRectangle = CreateFontA(25, 9, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_ROMAN, "1 font");
HFONT DECORATIVEFontRectangle = CreateFontA(25, 9, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DECORATIVE | FIXED_PITCH, "2 font");
HFONT DONTCAREFontRectangle = CreateFontA(25, 9, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, "3 font");
HFONT MODERNFontRectangle = CreateFontA(25, 9, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, "4 font");
HFONT SCRIPTFontRectangle = CreateFontA(25, 9, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SCRIPT, "5 font");
HFONT SWISSFontRectangle = CreateFontA(25, 9, 0, 0, FW_HEAVY, TRUE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, "6 font");
HFONT BigDEFAULTFontRectangle = CreateFontA(50, 18, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_ROMAN, "1 font");
HFONT BigDECORATIVEFontRectangle = CreateFontA(50, 18, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DECORATIVE | FIXED_PITCH, "2 font");
HFONT BigDONTCAREFontRectangle = CreateFontA(50, 18, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, "3 font");
HFONT BigMODERNFontRectangle = CreateFontA(50, 18, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, "4 font");
HFONT BigSCRIPTFontRectangle = CreateFontA(50, 18, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SCRIPT, "5 font");
HFONT BigSWISSFontRectangle = CreateFontA(50, 18, 0, 0, FW_HEAVY, TRUE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, "6 font");

HFONT selectedFont = DEFAULTFontRectangle;
HFONT bigSelectedFont = BigDEFAULTFontRectangle;
int intSelectedFont = 0;

// Fonts cost (Стоимость шрифтов)
int DEFAULTFontRectangleCost = 0;
int DECORATIVEFontRectangleCost = 1000;
int DONTCAREFontRectangleCost = 1000;
int MODERNFontRectangleCost = 1000;
int SCRIPTFontRectangleCost = 1000;
int SWISSFontRectangleCost = 1000;

// Cursors (Курсоры)
HCURSOR ARROWCursor = LoadCursor(NULL, IDC_ARROW);
HCURSOR CROSSCursor = LoadCursor(NULL, IDC_CROSS);
HCURSOR HELPCursor = LoadCursor(NULL, IDC_HELP);
HCURSOR NOCursor = LoadCursor(NULL, IDC_NO);
HCURSOR SIZEALLCursor = LoadCursor(NULL, IDC_SIZEALL);
HCURSOR UPARROWCursor = LoadCursor(NULL, IDC_UPARROW);

HCURSOR selectedCursor = ARROWCursor;
int intSelectedCursor = 0;

// Cursors cost (Стоимость курсоров)
int ARROWCursorCost = 0;
int CROSSCursorCost = 1000;
int HELPCursorCost = 1000;
int NOCursorCost = 1000;
int SIZEALLCursorCost = 1000;
int UPARROWCursorCost = 1000;

// Pics (Фоны)
HBITMAP hBitmap; // needed for pics
HBITMAP PagePic;
HBITMAP hPic1;
HBITMAP hPic2;
HBITMAP hPic3;
HBITMAP hPic4;
HBITMAP hPic5;
HBITMAP hPic6;
const wchar_t pic1[14] = L"Pics\\Фон1.bmp";
const wchar_t pic2[14] = L"Pics\\Фон2.bmp";
const wchar_t pic3[14] = L"Pics\\Фон3.bmp";
const wchar_t pic4[14] = L"Pics\\Фон4.bmp";
const wchar_t pic5[14] = L"Pics\\Фон5.bmp";
const wchar_t pic6[14] = L"Pics\\Фон6.bmp";
int intSelectedPic = 0;

// Pics cost (Стоимость фонов)
int pic1Cost = 0;
int pic2Cost = 1000;
int pic3Cost = 1000;
int pic4Cost = 1000;
int pic5Cost = 1000;
int pic6Cost = 1000;

// Money (Деньги)
int money = 0;

// Progress mas (Массивы с прогрессом)
int math3classSize = 4;
int math3class[4];
int math4classSize = 3;
int math4class[3];

// Bought fonts, cursors and pics (Купленные шрифты, курсоры и фоны)
int boughtFonts = 100000;
int boughtCursors = 100000;
int boughtPics = 100000;

// Money window (Окно с монетками)
HWND MoneyMessage;

// Welcome window (Приветственное окно)
HWND welcomeMessage1;
HWND welcomeMessage2;
HWND welcomeButton1;
HWND welcomeButton2;
HWND welcomeButton3;

// Shop window (Окно магазина)
HWND shopMessage1;
HWND shopMessage2;
HWND shopMessage3;
HWND shopMessage4;
HWND shopFontButton1;
HWND shopFontButton2;
HWND shopFontButton3;
HWND shopFontButton4;
HWND shopFontButton5;
HWND shopFontButton6;
HWND shopCursorButton1;
HWND shopCursorButton2;
HWND shopCursorButton3;
HWND shopCursorButton4;
HWND shopCursorButton5;
HWND shopCursorButton6;
HWND shopPicButton1;
HWND shopPicButton2;
HWND shopPicButton3;
HWND shopPicButton4;
HWND shopPicButton5;
HWND shopPicButton6;
HWND shopToMainMenu;

// Work space
int points = 0;
int currentMaxPoints = 0;
HWND scrollMessage;
HWND numberOfPoints;
HWND checkAnswersButton;
HWND workSpaceToMainMenu;
int currentPage = 0;

// Math 3
HWND pageScrollerMath3;
HBITMAP hMath3Page1;
HBITMAP hMath3Page2;
HBITMAP hMath3Page3;
HBITMAP hMath3Page4;
const wchar_t math3Page1[12] = L"Math3\\1.bmp";
const wchar_t math3Page2[12] = L"Math3\\2.bmp";
const wchar_t math3Page3[12] = L"Math3\\3.bmp";
const wchar_t math3Page4[12] = L"Math3\\4.bmp";
int math3PageNum = 4;
int maxMath3Page1Points = 23;
int maxMath3Page2Points = 25;
int maxMath3Page3Points = 11;
int maxMath3Page4Points = 10;

// Math 4
HWND pageScrollerMath4;
HBITMAP hMath4Page1;
HBITMAP hMath4Page2;
HBITMAP hMath4Page3;
const wchar_t math4Page1[12] = L"Math4\\1.bmp";
const wchar_t math4Page2[12] = L"Math4\\2.bmp";
const wchar_t math4Page3[12] = L"Math4\\3.bmp";
int math4PageNum = 3;
int maxMath4Page1Points = 26;
int maxMath4Page2Points = 7;
int maxMath4Page3Points = 14;


// Response fields
HWND resp1;
HWND resp2;
HWND resp3;
HWND resp4;
HWND resp5;
HWND resp6;
HWND resp7;
HWND resp8;
HWND resp9;
HWND resp10;
HWND resp11;
HWND resp12;
HWND resp13;
HWND resp14;
HWND resp15;
HWND resp16;
HWND resp17;
HWND resp18;
HWND resp19;
HWND resp20;
HWND resp21;
HWND resp22;
HWND resp23;
HWND resp24;
HWND resp25;
HWND resp26;
HWND resp27;
HWND resp28;
HWND resp29;
HWND resp30;
HWND resp31;
HWND resp32;
HWND resp33;
HWND resp34;
HWND resp35;
HWND resp36;
HWND resp37;
HWND resp38;
HWND resp39;
HWND resp40;


LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);
int ReadSaveFile();

void CreateWidgets(HWND hWnd);
void MainWndAddWidgets(HWND hWnd);
void ShopWndAddWidgets(HWND hWnd);
void ChangeFont(HWND hWnd);
void ChangeCursor(HWND hWnd);
void ChangePic(HWND hWnd);
void WorkSpaceMath3(HWND hWnd);
void WorkSpaceMath4(HWND hWnd);
void Math3Page1(HWND hWnd);
void CheckResponseInMath3Page1(HWND hWnd);
void Math3Page2(HWND hWnd);
void CheckResponseInMath3Page2(HWND hWnd);
void Math3Page3(HWND hWnd);
void CheckResponseInMath3Page3(HWND hWnd);
void Math3Page4(HWND hWnd);
void CheckResponseInMath3Page4(HWND hWnd);
void Math4Page1(HWND hWnd);
void CheckResponseInMath4Page1(HWND hWnd);
void Math4Page2(HWND hWnd);
void CheckResponseInMath4Page2(HWND hWnd);
void Math4Page3(HWND hWnd);
void CheckResponseInMath4Page3(HWND hWnd);
void DestroyAllResponseFields(HWND hWnd);
