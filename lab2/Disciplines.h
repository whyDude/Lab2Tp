#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;
struct Disciplines{ 
	string name; 
	int mark;
	Disciplines* next_disciplines;
	Disciplines() : name("No"), mark(0) {}; 
	Disciplines(string name, int mark) : name(name), mark(mark) {}; 
};
