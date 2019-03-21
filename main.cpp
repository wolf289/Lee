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




int main(){
    SetConsoleTitle("supplies manage ver1.0");
	color_set();
   	ShowConsoleCursor(false);
	system("cls");

	ShowConsoleCursor(true);

	while (login() != true)
	{
		login();
	
	}

    system("cls");
    ShowConsoleCursor(false);
	   menu();    
    //draw_case3();
	getch();
	return 0;
	}
