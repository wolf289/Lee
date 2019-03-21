#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <unistd.h>
#define true 1
#define faule 0
#include "menu.h"
using namespace std;

enum Colors{
	black,          //  0 text color - multiply by 16, for background colors
	dark_blue,      //  1
	dark_green,     //  2
	dark_cyan,      //  3
	dark_red,       //  4
	dark_magenta,   //  5
	dark_yellow,    //  6
	light_gray,     //  7
	dark_gray,      //  8
	light_blue,     //  9
	light_green,    // 10
	light_cyan,     // 11
	light_red,      // 12
	light_magenta,  // 13
	light_yellow,   // 14
	white           // 15
};
		 
void color_set(){
	 HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int k=0;k<=255;k++) {
        SetConsoleTextAttribute(hConsoleColor, 245);
        cout << k << " - Change color!  ";
        if (k%3==0) cout << endl;
    }
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
bool Check_ASCII_words(char word) {
	return(word >= 32 && word <= 127);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
	struct position {
		int x,y;	
	};
	/*
		int don_gia;
	};
	ChiTiet CT_HOADON;
	struct 	HOADON {
		char soHD;
		string ngaylap;
		char loai;
		struct HOADON *CT_HOADON;
		struct HOADON *pNext;
	};
	*/
	
void draw_case1 (){
	color_set();
	system("cls");
	SetBGColor(0);
	gotoxy(5,2);
	cout << string(80, char(219));
	for (int i = 3; i < 25; i++) {
		gotoxy(5, i);
		cout << char(219);
	
	}
	gotoxy(5, 25);
	cout << string(80, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(85,i);
		cout << char(219);
	}
	gotoxy(6,3);
	SetBGColor(15);
	cout <<" MA VAT TU |        	 TEN VAT TU 	      | DON VI TINH | SO LUONG TON  ";
	gotoxy(6,4);
	cout <<"------------------------------------------------------------------------------";
	gotoxy(55,28);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(54,29);
	cout <<"*NHAN --> DE HIEU CHINH VAT TU\n";
	gotoxy(53,30);
	cout <<"*SU DUNG PHIM MUI TEN DE LUA CHON\n";
	gotoxy(87,2);
	cout << string(41, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(87,i);
		cout << char(219);}
	gotoxy(87,25);
	cout << string(41, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(128,i);
		cout << char(219);
	}
	gotoxy(100,3);
	cout <<"BANG HIEU CHINH";
	gotoxy(88,4);
	cout << "----------------------------------------";
	gotoxy(17,4);
	for (int i =3; i<25;i++){
		gotoxy(17,i);
		cout <<"|";}
	gotoxy(54,4);
	for (int i =3; i<25;i++){
		gotoxy(54,i);
		cout <<"|";
	}
	gotoxy(68,4);
	for (int i =3; i<25;i++){
		gotoxy(68,i);
		cout <<"|";}
	
	
	 int luachon1 = 1;
	position luachon_case1[3];
	string case1[5]={"them vat tu","xoa vat tu","cap nhat"};
	for (int i= 0;i < 3;i++){
		luachon_case1[i].x=101;
		luachon_case1[i].y=20+i;
		gotoxy(luachon_case1[i].x,luachon_case1[i].y);
		cout << case1[i];
		}
	gotoxy (luachon_case1[0].x,luachon_case1[0].y);
	cout<< case1[0];
	while (true){
	 if(kbhit){
		 char input = getch();
		 if (input == -32){
		 	input = getch();
		 	switch (input){
		 		case 80 : {gotoxy(luachon_case1[luachon1].x,luachon_case1[luachon1].y);
		 			 SetBGColor(15);
					 cout <<case1[luachon1];
                     luachon1++;
                     if(luachon1 > 3){
                     	luachon1 = 0;
					 }
					 gotoxy(luachon_case1[luachon1].x,luachon_case1[luachon1].y);
					 SetBGColor(light_cyan);   //light_cyan
					 cout <<case1[luachon1]; 
					 
					break;
				 } 
				case 72: {
					gotoxy(luachon_case1[luachon1].x,luachon_case1[luachon1].y);
		 			 SetBGColor(15);
					 cout <<case1[luachon1];
                     luachon1--;
                     if(luachon1 < 0){
                     	luachon1 = 3;
					 }
					 gotoxy(luachon_case1[luachon1].x,luachon_case1[luachon1].y);
					 SetBGColor(light_cyan);
					 cout <<case1[luachon1]; 
					break;
				}
		 		}
}
else if(input == 13)
				{
					switch (luachon1) {
						case 0 : {// thuc hien them vat tu
							break;
						}
						case 1 :{ // thuc hien xoa vat tu
							break;
						}
						case 2 : {// thuc hien cap nhat
							break;
						}	
					}
					
}
else if(input == 27){
	
	color_set();
	system("cls");
	SetBGColor(15);
	//SetBGColor(0);
	menu();
}
}
}

	}

	
void draw_case2(){
	color_set();
	system("cls");
	SetBGColor(15);
	gotoxy(27,2);
	cout << string(80, char(219));
	for (int i = 3; i < 25; i++) {
		gotoxy(27, i);
		cout << char(219);
	
	}
	gotoxy(27, 25);
	cout << string(80, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(107,i);
		cout << char(219);
	}
	gotoxy(28,3);
	cout <<" MA VAT TU |        	 TEN VAT TU 	      | DON VI TINH | SO LUONG TON ";
	gotoxy(28,4);
	cout <<"------------------------------------------------------------------------------";

	gotoxy(55,28);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(53,29);
	cout <<"*SU DUNG PHIM MUI TEN DE LUA CHON\n";
	gotoxy(39,4);
	for (int i =3; i<25;i++){
		gotoxy(39,i);
		cout <<"|";}
	gotoxy(78,4);
	for (int i =3; i<25;i++){
		gotoxy(78,i);
		cout <<"|";
	}
	gotoxy(92,4);
	for (int i =3; i<25;i++){
		gotoxy(92,i);
		cout <<"|";}
	
}
void draw_case3 (){
	color_set();
	system("cls");
	SetBGColor(0);
	gotoxy(5,2);
	cout << string(80, char(219));
	for (int i = 3; i < 25; i++) {
		gotoxy(5, i);
		cout << char(219);
	
	}
	gotoxy(5, 25);
	cout << string(80, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(85,i);
		cout << char(219);
	}
	gotoxy(6,3);
	SetBGColor(15);
	cout <<" MA NHAN VIEN |        	  TEN NHAN VIEN           | GIOI TINH |  DIA CHI  ";
	gotoxy(6,4);
	cout <<"------------------------------------------------------------------------------";
	gotoxy(55,28);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(54,29);
	cout <<"*NHAN --> DE HIEU CHINH VAT TU\n";
	gotoxy(53,30);
	cout <<"*SU DUNG PHIM MUI TEN DE LUA CHON\n";
	gotoxy(87,2);
	cout << string(41, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(87,i);
		cout << char(219);}
	gotoxy(87,25);
	cout << string(41, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(128,i);
		cout << char(219);
	}
	gotoxy(100,3);
	cout <<"BANG HIEU CHINH";
	gotoxy(88,4);
	cout << "----------------------------------------";
	gotoxy(20,4);
	for (int i =3; i<25;i++){
		gotoxy(20,i);
		cout <<"|";}
	gotoxy(58,4);
	for (int i =3; i<25;i++){
		gotoxy(58,i);
		cout <<"|";
	}
	gotoxy(70,4);
	for (int i =3; i<25;i++){
		gotoxy(70,i);
		cout <<"|";}
	
	
	
	
	 int luachon = 1;
	position luachon_case1[3];
	string case1[5]={"them nhan vien","xoa nhan vien","cap nhat"};
	for (int i= 0;i < 3;i++){
		luachon_case1[i].x=101;
		luachon_case1[i].y=20+i;
		gotoxy(luachon_case1[i].x,luachon_case1[i].y);
		cout << case1[i];
		}
	gotoxy (luachon_case1[0].x,luachon_case1[0].y);
	cout<< case1[0];
	while (true){
	 if(kbhit){
		 char input = getch();
		 if (input == -32){
		 	input = getch();
		 	switch (input){
		 		case 80 : {gotoxy(luachon_case1[luachon].x,luachon_case1[luachon].y);
		 			 SetBGColor(15);
					 cout <<case1[luachon];
                     luachon++;
                     if(luachon > 3){
                     	luachon = 0;
					 }
					 gotoxy(luachon_case1[luachon].x,luachon_case1[luachon].y);
					 SetBGColor(light_cyan);   //light_cyan
					 cout <<case1[luachon]; 
					 
					break;
				 } 
				case 72: {
					gotoxy(luachon_case1[luachon].x,luachon_case1[luachon].y);
		 			 SetBGColor(15);
					 cout <<case1[luachon];
                     luachon--;
                     if(luachon < 0){
                     	luachon = 3;
					 }
					 gotoxy(luachon_case1[luachon].x,luachon_case1[luachon].y);
					 SetBGColor(light_cyan);
					 cout <<case1[luachon]; 
					break;
				}
		 		}
}
else if(input == 13)
				{
					
					switch (luachon) {
						case 0 : {// thuc hien them vat tu
						gotoxy(101,24);
						cout << luachon;
							break;
						}
						case 1 :{ // thuc hien xoa vat tu
						gotoxy(101,24);
						cout << luachon;
							break;
						}
						case 2 : {// thuc hien cap nhat
						gotoxy(101,24);
						cout << luachon;
							break;
						}	
					}
					
}
else if(input == 27){
	
	color_set();
	system("cls");
	SetBGColor(15);
	//SetBGColor(0);
	menu();
}
}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
		
	
	
	
}

void draw_case4(){
	color_set();
	system("cls");
	SetBGColor(15);
	gotoxy(27,2);
	cout << string(80, char(219));
	for (int i = 3; i < 25; i++) {
		gotoxy(27, i);
		cout << char(219);
	
	}
	gotoxy(27, 25);
	cout << string(80, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(107,i);
		cout << char(219);
	}
	gotoxy(28,3);
	cout <<" MA NHAN VIEN |        	  TEN NHAN VIEN           | GIOI TINH |  DIA CHI  ";
	gotoxy(28,4);
	cout <<"------------------------------------------------------------------------------";
	gotoxy(55,28);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(53,29);
	cout <<"*SU DUNG PHIM MUI TEN DE LUA CHON\n";
	gotoxy(42,4);
	for (int i =3; i<25;i++){
		gotoxy(42,i);
		cout <<"|";}
	gotoxy(82,4);
	for (int i =3; i<25;i++){
		gotoxy(82,i);
		cout <<"|";
	}
	gotoxy(94,4);
	for (int i =3; i<25;i++){
		gotoxy(94,i);
		cout <<"|";}
	
	
	
}



void draw_case7(){
	color_set();
	system("cls");
	SetBGColor(15);
	gotoxy(17,7);
	cout << string(100, char(219));
	for (int i = 7; i < 30; i++) {
		gotoxy(17, i);
		cout << char(219);
	
	}
	gotoxy(17, 30);
	cout << string(100, char(219)) << endl;
	for (int i = 7;i <= 30;i++){
		gotoxy(117,i);
		cout << char(219);
	}
	gotoxy(44,3);
	cout <<"BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN";
	gotoxy(48,4);
	cout <<"TU NGAY:|";
	gotoxy(66,4);
	cout <<"| DEN NGAY: |";
	gotoxy(87,4);
	cout <<"|";
	gotoxy(18,8);
	cout <<"  SO HD	 |	NGAY LAP | LOAI HD |		HO TEN NV LAP   	| TRI GIA HOA DON";
	gotoxy(18,9);
	cout <<"--------------------------------------------------------------------------------------------------";
	
	gotoxy(55,32);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(33,4);
	for (int i =8; i<30;i++){
		gotoxy(33,i);
		cout <<"|";}
	gotoxy(49,4);
    for (int i =8; i<30;i++){
		gotoxy(49,i);
		cout <<"|";
	}
	gotoxy(59,4);
	for (int i =8; i<30;i++){
		gotoxy(59,i);
		cout <<"|";}
	gotoxy(96,4);
	for (int i =8; i<30;i++){
		gotoxy(96,i);
		cout <<"|";}
	
	
	
	
}

void draw_case8(){
	color_set();
	system("cls");
	SetBGColor(15);
	gotoxy(17,7);
	cout << string(100, char(219));
	for (int i = 7; i < 30; i++) {
		gotoxy(17, i);
		cout << char(219);
	
	}
	gotoxy(17, 30);
	cout << string(100, char(219)) << endl;
	for (int i = 7;i <= 30;i++){
		gotoxy(117,i);
		cout << char(219);
	}
	gotoxy(44,3);
	cout <<"BANG LIET KE 10 HOA DON CO DOANH THU CAO NHAT TRONG KHOANG";
	gotoxy(48,4);
	cout <<"TU NGAY:|";
	gotoxy(66,4);
	cout <<"| DEN NGAY: |";
	gotoxy(87,4);
	cout <<"|";
	gotoxy(18,8);
	cout <<"  SO HD	 |	NGAY LAP | LOAI HD |		HO TEN NV LAP   	| TRI GIA HOA DON";
	gotoxy(18,9);
	cout <<"--------------------------------------------------------------------------------------------------";
	
	
	gotoxy(55,32);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(33,4);
	for (int i =8; i<30;i++){
		gotoxy(33,i);
		cout <<"|";}
	gotoxy(49,4);
    for (int i =8; i<30;i++){
		gotoxy(49,i);
		cout <<"|";
	}
	gotoxy(59,4);
	for (int i =8; i<30;i++){
		gotoxy(59,i);
		cout <<"|";}
	gotoxy(96,4);
	for (int i =8; i<30;i++){
		gotoxy(96,i);
		cout <<"|";}
	
}


bool login()
{
	system("cls") ;
	gotoxy(30, 5);
	cout << string(57, char(219));
	for (int i = 6; i < 10; i++) {
		gotoxy(30, i);
		cout << char(219);
		for (int j = 0; j < 55; j++)cout << " ";
		cout << char(219);
	}
	gotoxy(30, 10);
	cout << string(57, char(219)) << endl;
	gotoxy(33, 7);
	cout << "Username:   ";
	gotoxy(33, 8);
	cout << "Password:   ";
	gotoxy(45,7);
	
	string user_name = "", user_password = "";
	
	int user_name_index = 45;
	int user_password_index = 45;
	int start_pos = 45;
	int UserNameField = 7, UserPasswordField = 8;
	int FieldSelect = 0;
	while (true) {
		if (_kbhit()) {
			char user_input = _getch();
			if (user_input == 80) {			//ARROW-DOWN is pressed
				if (FieldSelect == 1) {
					FieldSelect = 0;
					gotoxy(user_name_index, UserNameField);
				}
				else if (FieldSelect == 0) {
					FieldSelect = 1;
					gotoxy(user_password_index, UserPasswordField);
				}
			}
			else if (user_input == 72) {		//ARROW-UP is pressed
				if (FieldSelect == 1) {
					FieldSelect = 0;
					gotoxy(user_name_index, UserNameField);
				}
				else if (FieldSelect == 0) {
					FieldSelect = 1;
					gotoxy(user_password_index, UserPasswordField);
				}
			}
			//Check input from keyboards is visible or not?:
			else if (Check_ASCII_words(user_input)) {
				if (FieldSelect == 1) {
					user_password += user_input;
					gotoxy(user_password_index, UserPasswordField);
					cout << "*";
					user_password_index++;
				}
				else if (FieldSelect == 0) {
					user_name += user_input;
					gotoxy(user_name_index, UserNameField);
					cout << user_name;
				}
			}
			//pop back the buffer:
			else if (user_input == 8) {		//BACKSPACES is pressed
				if (FieldSelect == 1) {
					if (!user_password.empty()) {
						//vector <string> user_password ;
						user_password.pop_back();
						gotoxy(start_pos, UserPasswordField);
						cout << string(user_password.size(), '*') << ' ';
						--user_password_index;
					}
				}
				else if (FieldSelect == 0) {
					if (!user_name.empty()) {
					//	vector <string> user_name ;
						user_name.pop_back();
						gotoxy(user_name_index, UserNameField);
						cout << user_name << " ";
					}
				}
			}
			else if (user_input == 13) {			//ENTER is pressed
				break;
			}
		}
    }

if (user_name == "admin" && user_password == "cc") {
		gotoxy(49, 10);
		cout << "Login successful" << endl;
		getch();
		
		return true;
	}

	else {
		gotoxy(49, 10);
		cout << "Login error" << endl;
	
		getch();
		return false;
	}

}
void  menu(){
int x =40, y =5;

 /*   
    
	cout << "*************************************MENU****************************************\n";
	cout << "*********************************************************************************\n";
	cout << "**                                                                             **\n";
	cout << "**            1. NHAP VAT TU                                                   **\n";
	cout << "**            2. IN DANH SACH VAT TU TON KHO                                   **\n";
	cout << "**            3. NHAP NHAN VIEN                                                **\n";
	cout << "**            4. IN DANH SACH NHAN VIEN                                        **\n";
	cout << "**            5. LAP HOA DON NHAP, XUAT                                        **\n";
	cout << "**            6. IN HOA DON THEO SO HOA DON                                    **\n";
	cout << "**            7. THONG KE HOA DON THEO KHOANG THOI GIAN                        **\n";
	cout << "**            8. IN 10 HOA DON CO DOANH THU CAO NHAT                           **\n";
	cout << "**                                                                             **\n";
	cout << "**                      *NHAN ENTER DE CHON CHUC NANG                          **\n";
	cout << "**                      NHAN ESC DE THOAT CHUONG TRINH                         **\n";
	cout << "**                                                                             **\n";
	cout << "*********************************************************************************\n";
	cout << "*********************************************************************************\n";
	
	SetColor(20);
	
*/

	int FieldSelect = 0;
	string Menu[8]={"1. NHAP VAT TU","2. IN DANH SACH VAT TU TON KHO","3. NHAP NHAN VIEN","4. IN DANH SACH NHAN VIEN","5. LAP HOA DON NHAP, XUAT","6. IN HOA DON THEO SO HOA DON","7. THONG KE HOA DON THEO KHOANG THOI GIAN ","8. IN 10 HOA DON CO DOANH THU CAO NHAT"};
	position vitri [8];
	gotoxy(x+14,y-2);
	cout<< "MENU";
	gotoxy(x+5,y+20);
	cout <<"*NHAN ENTER DE CHON CHUC NANG\n";
	gotoxy(x+4,y+21);
	cout <<"*NHAN ESC DE THOAT CHUONG TRINH\n";
	gotoxy(x+3,y+22);
	cout <<"*SU DUNG PHIM MUI TEN DE LUA CHON\n";
	
	for (int i= 0;i < 8;i++){
		vitri[i].x=x;
		vitri[i].y=y+i;
		gotoxy(vitri[i].x,vitri[i].y);
		cout << Menu[i];
		}
		
	gotoxy (vitri[0].x,vitri[0].y);
	cout<< Menu[0];
	while (true){
	 if(kbhit){
		 char input = getch();
		 if (input == -32){
		 	input = getch();
		 	switch (input){
		 		case 80 : {
		 			 gotoxy(vitri[FieldSelect].x,vitri[FieldSelect].y);
		 			 SetBGColor(15);
					 cout <<Menu[FieldSelect];
                     FieldSelect++;
                     if(FieldSelect > 7){
                     	FieldSelect = 0;
					 }
					 gotoxy(vitri[FieldSelect].x,vitri[FieldSelect].y);
					 SetBGColor(light_cyan);   //light_cyan
					 cout <<Menu[FieldSelect]; 
					 
					break;
				 } 
				case 72: {
					gotoxy(vitri[FieldSelect].x,vitri[FieldSelect].y);
		 			 SetBGColor(15);
					 cout <<Menu[FieldSelect];
                     FieldSelect--;
                     if(FieldSelect < 0){
                     	FieldSelect = 7;
					 }
					 gotoxy(vitri[FieldSelect].x,vitri[FieldSelect].y);
					 SetBGColor(light_cyan);
					 cout <<Menu[FieldSelect]; 
					break;
				}
				
				case 77:{
					break;
					}
			}
		}
			else if(input == 13){
				
				
				break;
				/*	switch(FieldSelect) {
						case 0: {	
						//gotoxy(x+5,y+10);
						//gotoxy(x+5,y+10); "ban chon chuc nang 1";		// noi thuc hien chuc nang 1
					//	draw_case1();
					
							break;
						}
						case 1: {
						//gotoxy(x+5,y+11);
					//	cout << "ban chon chuc nang 2";		// noi thuc hien chuc nang 2
					//	draw_case2();	
					
							break;
						}
						case 2: {
					//	gotoxy(x+5,y+12);
					//	cout << "ban chon chuc nang 3";		// noi thuc hien chuc nang 3
					//	draw_case3();	
					
							break;
						}
						case 3: {
					//	gotoxy(x+5,y+13);
					//	cout << "ban chon chuc nang 4";		// noi thuc hien chuc nang 4
					//	draw_case4();	
					
							break;
						}
						case 4: {
					//	gotoxy(x+5,y+14);
					//	cout << "ban chon chuc nang 5";		// noi thuc hien chuc nang 5
						
							break;
						}
						case 5: {
					//	gotoxy(x+5,y+15);
					//	cout << "ban chon chuc nang 6";		// noi thuc hien chuc nang 6
					
							break;
							
						}
						case 6: {
					//	gotoxy(x+5,y+16);
					//	cout << "ban chon chuc nang 7";		// noi thuc hien chuc nang 7
					//	draw_case7();	
					
							break;
						}
						case 7: {
					//	gotoxy(x+5,y+17);
					//	cout << "ban chon chuc nang 8";		// noi thuc hien chuc nang 8
					//	draw_case8();
						
							break;
						}
			}
				*/
			}
				else if(input ==27)
				{
				
					system("cls");
					gotoxy(42,5);
					cout << " Product of NghiaLe Student of PTIT";
					gotoxy(46,6);
					cout <<"supplies manage ver1.0";
					string GoodBye[20] ={"G","O","O","D",".",".","B","Y","E"," ","!","!"};
					gotoxy(54,9);
					for (int i;i <=16; i++){
						cout << GoodBye[i];
						sleep(1);
					}
					break;}
				}
						}
				
				switch(FieldSelect) {
						case 0: {	
						gotoxy(x+5,y+10);
						gotoxy(x+5,y+10); "ban chon chuc nang 1";		// noi thuc hien chuc nang 1
						draw_case1();
						
					
							break;
						}
						case 1: {
						gotoxy(x+5,y+11);
						cout << "ban chon chuc nang 2";		// noi thuc hien chuc nang 2
						draw_case2();	
					
							break;
						}
						case 2: {
						gotoxy(x+5,y+12);
						cout << "ban chon chuc nang 3";		// noi thuc hien chuc nang 3
						draw_case3();	
					
							break;
						}
						case 3: {
						gotoxy(x+5,y+13);
						cout << "ban chon chuc nang 4";		// noi thuc hien chuc nang 4
						draw_case4();	
					
							break;
						}
						case 4: {
						gotoxy(x+5,y+14);
						cout << "ban chon chuc nang 5";		// noi thuc hien chuc nang 5
						
							break;
						}
						case 5: {
						gotoxy(x+5,y+15);
						cout << "ban chon chuc nang 6";		// noi thuc hien chuc nang 6
					
							break;
							
						}
						case 6: {
						gotoxy(x+5,y+16);
						cout << "ban chon chuc nang 7";		// noi thuc hien chuc nang 7
						draw_case7();	
					
							break;
						}
						case 7: {
						gotoxy(x+5,y+17);
						cout << "ban chon chuc nang 8";		// noi thuc hien chuc nang 8
						draw_case8();
						
							break;
						}
			}
				}
				


	
	
	
	
	
	
