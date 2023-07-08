// HomeWork template project v 6.0 // 27.06.2023 //

/**

Основы ООП на языке С++

Перегрузка оператора Квадратные скобки

Задание 1
Реализовать класс-коллекцию для зранения элементов. в публичном интерфейсе этого
класса должны содержаться методы для работы с коллекуией и обязательно реализуйте
операторы для доступа к элементам.

вариант со звёздочкой
Предусмотреть что если элемент коллекции сам является коллекцией то метод возвращающий
количество элементов должен возвращать количество учитывающее вложеные элементы.
Например: если в коллекции 10 элементов 2 из которых коллекции содержащие по 3
элемента в себе, то вернуться должно число 16 а не 10.

Задание 2
Изучите какие структуры данных помимо линейного массива и списка существуют и
составьте их описание на тему для чего они используются в программировании.
``` задание сдаётся в виде ссылки на репозиторий либо подготовленным архивом проекта 1

*/

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
#include <cassert>
#include <fstream>
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

//Task 2 Standart template library container class info
void Task_2(std::string name_of_task)
{
	std::ifstream file_read_obj;
	do
	{
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";
		file_read_obj.open("Task_2.txt");
		if (file_read_obj.is_open())
		{
			std::string str_tmp;
			while (std::getline(file_read_obj, str_tmp))
				std::cout << str_tmp << '\n';
		}
		file_read_obj.close();

		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
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
	MainMenu.AddElement("Standart template library container class info");
	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

