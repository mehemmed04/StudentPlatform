#pragma once

struct Date
{
	int year;
	int month;
	int day;
};

struct Student
{
	char* username;
	char* password;
	char* name;
	char* surname;
	int age;
	Date date;
};