#include"University.h"
#include"Second_task.h"
#include<iostream>
#include<fstream>
#include<string>
#include<exception>
using namespace std;
int main() {
	setlocale(LC_ALL, "");
	University Univer; 
	Student* ptr; 
	string surname; 
	string nname;
	int choose; 
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "1: ���������� ������ ��������" << endl;
		cout << "2: �������� ���������� ��������" << endl;
		cout << "3: ����� ���� ��������� �� �����" << endl;
		cout << "4: ����� ���� ��������� � ������� 2 �� �����" << endl;
		cout << "5: ��������� ������ ��������" << endl;
		cout << "0: ������� �� ������ ������� ->" << endl;
		cin >> choose;
		if (cin.fail()) {
			choose = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (choose) {
		case 1:
			cin >> Univer;
			break;
		case 2:
			Univer.delete_student();
			break;
		case 3:
			system("cls");
			cout << Univer; 
			system("pause");
			break;
		case 4:
			Univer.show_student_two();
			break;
		case 5:
			if (Univer.get_number_of_student() == 0) {
				system("cls");
				cout << "������ ��������� ����!" << endl << endl;
				system("pause");
			}
			else {
				cout << "������� �������: ";
				cin >> surname;
				cout << "������� ���: ";
				cin >> nname;
				ptr = Univer.find_student(surname, nname); 
				if (ptr == nullptr) {
					cout << "������ �������� ���!" << endl << endl;
					system("pause");
				}
				else {
					ptr->change_data();
				}
			}
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << "������� ������������ �������" << endl << endl;
			system("pause");
		}
		Univer.sort_student();
	}
	system("cls");
	cout << "������ �������:" << endl << endl;
	second_task();

	return 0;
}
