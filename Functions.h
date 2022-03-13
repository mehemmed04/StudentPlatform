#pragma once
#include<iostream>
using namespace std;
#include"Entities.h"
#include"FileHelper.h"

Student** students = new Student * [3]{
	new Student{new char[] {"mehemmed_bayramov"},new char[] {"mehemmed123"},new char[] {"Mehemmed"},new char[] {"Bayramov"},17,Date{13,3,2022}},
	new Student{new char[] {"nurlan_shirinov"},new char[] {"nurlan123"},new char[] {"Nurlan"},new char[] {"Shirinov"},24,Date{13,3,2022} },
};

void ShowMenu() {
	cout << "Sign in (1)\nSign up (2)\nShow All Stundets(3) : ";
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
	
	for (size_t i = 0; i < global_student_count; i++)
	{
		ShowStudent(students[i]);
	}
}
#pragma endregion 