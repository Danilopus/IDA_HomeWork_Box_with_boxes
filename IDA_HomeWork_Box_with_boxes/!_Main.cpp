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


//Task 1 Box class demo
void Task_1(std::string name_of_task)
{
//	std::cout <<
		
		Box box_1(50,50,50);
		Box box_2(25, 25, 25);
		Box box_3(10, 10, 10);
		Box box_4(5, 5, 5);
		Box box_5(2, 2, 2);
		std::cout << "Box box_1(50,50,50);\nBox box_2(25, 25, 25);\nBox box_3(10, 10, 10);\nBox box_4(5, 5, 5);\nBox box_5(2, 2, 2);\n";

		
		std::cout << "\nbox_1.pushback(box_2).pushback(box_3);\nbox_1[1].pushfront(box_5).pushfront(box_4);\n";
		box_1.pushback(box_2).pushback(box_3);
		box_1[1].pushfront(box_5).pushfront(box_4);

		//assert((box_1.size() != 4) & "box_1.size()!=4");
		std::cout <<"\nbox_1.size() -> " << box_1.size();
		std::cout <<"\nbox_3.size() -> " << box_3.size();

		std::cout << "\nbox_3.popback();\nbox_1.popfront();\n";
		box_3.popback();
		box_1.popfront();

		std::cout << "\nbox_1.size() -> " << box_1.size();
		std::cout << "\nbox_3.size() -> " << box_3.size();


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
	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 08: Overload []");	// Homework name
	MainMenu.AddElement("Box class demo");
	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

