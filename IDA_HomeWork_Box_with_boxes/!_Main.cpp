// HomeWork template project v 6.0 // 27.06.2023 //

/*

Задание 1

*/

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
#include <cassert>
//My own headers
#include "Service functions.h"
#include "MainMenu.h"
#include "Box.h"



// Homework OOP 08 ----------------------------------------------------	


//Task 1 Overcoat class demo with overloaded operators: = | == | < | > 
void Task_1(std::string name_of_task)
{
//	std::cout <<
		Box box_1(50,50,50);
		Box box_2(25, 25, 25);
		Box box_3(10, 10, 10);
		Box box_4(5, 5, 5);
		Box box_5(2, 2, 2);

		box_1.pushback(box_2).pushback(box_3);
		box_3.pushfront(box_5).pushfront(box_4);
	
		//assert((box_1.size() != 4) & "box_1.size()!=4");
		std::cout << box_1.size();
		std::cout << box_3.size();


	_getch();
}

//Task 2
void Task_2(std::string name_of_task)
{
}

//Task 3 
void Task_3() {}

//Task 4
void Task_4() {}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	srand(time(NULL));
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=60 lines=40"); 
	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 07: ");	// Homework name
	MainMenu.AddElement("Collection class demo");
	//MainMenu.AddElement("Flat class demo with overloaded operators: = | == | < | > ");

	//MainMenu.AddElement("XXX");

	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

