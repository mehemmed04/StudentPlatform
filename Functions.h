#pragma once
#include<iostream>
using namespace std;
#include"Entities.h"
#include"FileFunctions.h"

Student** students = new Student * [3]{
	new Student{new char[] {"mehemmed_bayramov"},new char[] {"mehemmed123"},new char[] {"Mehemmed"},new char[] {"Bayramov"},17,Date{13,3,2022}},
	new Student{new char[] {"nurlan_shirinov"},new char[] {"nurlan123"},new char[] {"Nurlan"},new char[] {"Shirinov"},24,Date{13,3,2022} },
};

void ShowMenu() {
	cout << "Sign in (1)\nSign up (2)\nShow All Stundets(3) : ";
}


Student** LoadData() {
	Student** student_s = nullptr;
	if (isExist("students.bin")) {
		student_s = ReadFromFile();
	}
	else {
		WriteStudentsToFile(students);
		student_s = ReadFromFile();
	}
	return student_s;
}


bool HasUsarname(char* username) {
	auto students = LoadData();
	for (size_t i = 0; i < global_student_count; i++)
	{
		if (strcmp(students[i]->username, username) == 0) {
			return true;
		}
	}
	return false;
}

bool IsReady(char* username, char* password, int age)
{
	if (HasUsarname(username)) {
		cout << "This username already exists" << endl;
		return false;
	}
	int l_password = strlen(password);
	if (l_password < 6) {
		cout << "Password must be minimum 6 charachter" << endl;
		return false;
	}
	if (age <= 0) {
		cout << "Age must be grather than 0" << endl;
		return false;
	}
	return true;

}

bool CheckPassword(char* username, char* pass) {
	for (size_t i = 0; i < global_student_count; i++)
	{
		if (strcmp(students[i]->username, username) == 0) {
			if (strcmp(students[i]->password, pass) == 0) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

void SignIn() {
	cin.ignore();
	cin.clear();
	cout << "Enter username : ";
	char* username = new char[100];
	cin.getline(username, 100);

	if (HasUsarname(username)) {
		cout << "Enter password : ";
		char* password = new char[100];
		cin.getline(password, 100);
		if (CheckPassword(username, password)) {
			system("cls");
			cout << "WELCOME" << endl;
			system("pause");
		}
		else {
			cout << "Password is not correct.Try again" << endl;
		}
	}
	else {
		cout << "There is not such username." << endl;
	}
}

void AddStudent(Student* student) {
	Student** newstudents = new Student * [global_student_count + 1]{};
	for (size_t i = 0; i < global_student_count; i++)
	{
		newstudents[i] = students[i];
	}
	newstudents[global_student_count] = student;
	students = newstudents;
	newstudents = nullptr;
	global_student_count++;
}

void SignUp() {
	char* username = new char[100]{};
	cout << "Enter username : ";
	cin.ignore();
	cin.clear();
	cin.getline(username, 100);

	char* password = new char[100]{};
	cout << "Enter password (at least 6 characther) : ";

	cin.getline(password, 100);

	char* name = new char[100]{};
	cout << "Enter name : ";

	cin.getline(name, 100);

	char* surname = new char[100]{};
	cout << "Enter surname : ";
	cin.getline(surname, 100);

	int age = 0;
	cout << "Enter age : ";
	cin >> age;

	cout << "Enter register day : ";
	int day = 0;
	cin >> day;
	cout << "Enter register month : ";
	int month = 0;
	cin >> month;
	cout << "Enter register year : ";
	int year = 0;
	cin >> year;

	if (IsReady(username, password, age)) {
		Student* s = new Student{ username,password,name,surname,age,Date{day,month,year } };
		AddStudent(s);
		WriteStudentsToFile(students);
	}
}




#pragma region ShowFunctions
void ShowStudent(Student* student) {
	cout << "Student's username : ";
	cout << student->username;
	cout << endl;
	cout << "Student's name : ";
	cout << student->name;
	cout << endl;
	cout << "Student's surname : ";
	cout << student->surname;
	cout << endl;
	cout << "Student's age : ";
	cout << student->age;
	cout << endl;
	cout << "Student's registered date : ";
	cout << student->date.day << "/" << student->date.month << "/" << student->date.year << endl;
	cout << "==================================" << endl;
}

void ShowAllStudents() {
	auto students = LoadData();
	for (size_t i = 0; i < global_student_count; i++)
	{
		ShowStudent(students[i]);
	}
}
#pragma endregion 