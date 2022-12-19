#pragma once
#include "Disciplines.h"
class Student{ 
	string surname; 
	string nname; 
	string group; 
	Disciplines* head_disciplines; 
	int number_of_disciplines; 
	double average_mark; 
	Student* next_student;
public:
	Student();
	Student(string, string, string, Disciplines*);
	~Student();
	void set_next_student(Student* next_student) { this->next_student = next_student; } 
	Student* get_next_student() { return next_student; } 
	string get_surname() { return surname; } 
	string get_nname() { return nname; }
	string get_group() { return group; } 
	Disciplines* get_head_disciplines() { return head_disciplines; }
	double get_average_mark() { return average_mark; } 
	void push_disciplines(); 
	void delete_disciplines(string); 
	void show_data(); 
	void change_data(); 
	void average_score(); 
	bool find_mark_two();
};
