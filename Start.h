#pragma once
#include<iostream>
#include"Functions.h"
using namespace std;

void Run() {
	while (true)
	{
		auto students = LoadData();
		ShowMenu();
		int select = 0;
		cin >> select;
		system("cls");
		if (select == 1) {
			SignIn();
		}
		else if (select == 2) {
			SignUp();
		}
		else if (select == 3) {
			ShowAllStudents();
		}
		else {
			cout << "Invalid number. Try again " << endl;
		}
	}
}