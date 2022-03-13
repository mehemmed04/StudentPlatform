#pragma once
#include<iostream>
#include "Entities.h"
using namespace std;
int global_student_count = 2;
bool isExist(const char* filename) {
	FILE* file;
	fopen_s(&file, filename, "rb");
	if (file != nullptr) {
		fclose(file);
		return true;
	}
	return false;
}


void WriteStudentsToFile(Student** students) {
	FILE* file;
	fopen_s(&file, "students.bin", "wb");

	fwrite(&global_student_count, sizeof(int), 1, file);

	for (size_t i = 0; i < global_student_count; i++)
	{
		int l_username = strlen(students[i]->username);
		fwrite(&l_username, sizeof(int), 1, file); //username length 
		fwrite(students[i]->username, sizeof(char), l_username, file);//username

		int l_password = strlen(students[i]->password);
		fwrite(&l_password, sizeof(int), 1, file); //password length 
		fwrite(students[i]->password, sizeof(char), l_password, file);//password

		int l_name = strlen(students[i]->name);
		fwrite(&l_name, sizeof(int), 1, file); //name length 
		fwrite(students[i]->name, sizeof(char), l_name, file);//name

		int l_surname = strlen(students[i]->surname);
		fwrite(&l_surname, sizeof(int), 1, file); //surname length 
		fwrite(students[i]->surname, sizeof(char), l_surname, file);//surname

		fwrite(&students[i]->age, sizeof(int), 1, file); //age 

		//DATE	
		fwrite(&students[i]->date.day, sizeof(int), 1, file);
		fwrite(&students[i]->date.month, sizeof(int), 1, file);
		fwrite(&students[i]->date.year, sizeof(int), 1, file);

	}
	fclose(file);
}


Student** ReadFromFile() {
	int count = 0;
	FILE* file;
	fopen_s(&file, "students.bin", "rb");
	fread_s(&count, sizeof(int), sizeof(int), 1, file);

	global_student_count = count;

	auto students = new Student * [count] {};

	for (size_t i = 0; i < count; i++)
	{
		int l_username = 0;
		fread_s(&l_username, sizeof(int), sizeof(int), 1, file);
		char* username = new char[l_username + 1]{};
		fread_s(username, l_username, sizeof(char), l_username, file);

		int l_password = 0;
		fread_s(&l_password, sizeof(int), sizeof(int), 1, file);
		char* password = new char[l_password + 1]{};
		fread_s(password, l_password, sizeof(char), l_password, file);

		int l_name = 0;
		fread_s(&l_name, sizeof(int), sizeof(int), 1, file);
		char* name = new char[l_name + 1]{};
		fread_s(name, l_name, sizeof(char), l_name, file);

		int l_surname = 0;
		fread_s(&l_surname, sizeof(int), sizeof(int), 1, file);
		char* surname = new char[l_surname + 1]{};
		fread_s(surname, l_surname, sizeof(char), l_surname, file);

		int age = 0;
		fread_s(&age, sizeof(int), sizeof(int), 1, file);

		Date date;
		fread_s(&date.day, sizeof(int), sizeof(int), 1, file);
		fread_s(&date.month, sizeof(int), sizeof(int), 1, file);
		fread_s(&date.year, sizeof(int), sizeof(int), 1, file);

		students[i] = new Student{ username,password,name,surname,age,date };
	}
	fclose(file);
	return students;
}

