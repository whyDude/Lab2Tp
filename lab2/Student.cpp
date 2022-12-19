#include"Student.h"
Student::Student() {
	cout << "������ ����������� ������ Student" << endl << endl;
	cout << "������� �������: ";
	cin >> surname;
	cout << "������� ���: ";
	cin >> nname;
	cout << "������� ����� ������: ";
	cin >> group;
	number_of_disciplines = 0;
	average_mark = 0;
	head_disciplines = nullptr;
	next_student = nullptr;
}
Student::Student(string surname, string nname, string group, Disciplines* head_disciplines) {
	cout << "������ ����������� � ����������� ������ Student" << endl << endl;
	this->surname = surname;
	this->nname = nname;
	this->group = group;
	Disciplines* cur = head_disciplines;
	while (cur != NULL) {
		Disciplines* tmp = new Disciplines(cur->name, cur->mark);
		tmp->next_disciplines = nullptr;
		if (this->head_disciplines == nullptr) {
			this->head_disciplines = tmp;
		}
		else {
			Disciplines* current = this->head_disciplines;
			for (int i = 1; i < this->number_of_disciplines; ++i) {
				current = current->next_disciplines;
			}
			current->next_disciplines = tmp;
		}
		++this->number_of_disciplines;
		average_score(); 
		cur = cur->next_disciplines;
	}
}
Student::~Student() {
	cout << "������ ���������� ������ Student" << endl << endl;
	Disciplines* current;
	for (int i = 0; i < number_of_disciplines; ++i) {
		current = head_disciplines;
		head_disciplines = head_disciplines->next_disciplines;
		delete current;
	}
}

void Student::push_disciplines() {
	Disciplines* tmp = new Disciplines;
	system("cls");
	cout << "������� �������� ����������: ";
	cin >> tmp->name;
	while (true) {
		cout << "������� ������: ";
		cin >> tmp->mark;
		if (cin.fail()) {
			cout << "����������� ���� ������!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		if (tmp->mark < 2 || tmp->mark > 5)
			cout << "����� ������ ���" << endl;
		else
			break;
	}
	tmp->next_disciplines = nullptr;
	if (head_disciplines == nullptr) {
		head_disciplines = tmp;
	}
	else {
		Disciplines* current = head_disciplines;
		for (int i = 1; i < number_of_disciplines; ++i) {
			current = current->next_disciplines;
		}
		current->next_disciplines = tmp;
	}
	++number_of_disciplines;
	average_score();
	cout << "���������� ������� ���������!" << endl << endl;
	system("pause");
}
void Student::delete_disciplines(string name) {
	Disciplines* current = head_disciplines;
	Disciplines* prev = head_disciplines;
	for (int i = 0; i < number_of_disciplines; ++i) {
		if (current->name == name) {
			if (current == head_disciplines) {
				head_disciplines = head_disciplines->next_disciplines;
				delete current;
			}
			else {
				prev->next_disciplines = current->next_disciplines;
				delete current;
			}
			--number_of_disciplines;
			cout << "���������� ������� �������!" << endl << endl;
			average_score();
			break;
		}
		if (i == number_of_disciplines - 1)
			cout << "����� ���������� ���!" << endl << endl;
		prev = current;
		current = current->next_disciplines;
	}
	system("pause");
}
void Student::show_data() {
	cout << "������� � ���: " << surname << " " << nname << endl;
	cout << endl << "����� ������: " << group;
	cout << endl << "���������� � ������" << endl;
	if (number_of_disciplines == 0)
		cout << "��������� ���" << endl;
	else {
		Disciplines* current = head_disciplines;
		for (int i = 0; i < number_of_disciplines; ++i) {
			cout << current->name << " - " << current->mark << endl;
			current = current->next_disciplines;
		}
	}
	cout << endl << "������� ���: " << average_mark << endl;
}
void Student::change_data() {
	int button;
	string name;
	bool flag = true;
	while (flag) {
		system("cls");
		show_data();
		cout << endl << "��������, ��� ����� ��������" << endl << endl;
		cout << "1 - �������" << endl;
		cout << "2 - ���" << endl;
		cout << "3 - ����� ������" << endl;
		cout << "4 - �������� ����������" << endl;
		cout << "5 - ������� ����������" << endl;
		cout << "6 - �������� ����������" << endl;
		cout << "0 - ����� �� ���� �������������� ��������" << endl;
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (button) {
		case 1:
			cout << endl << "������� ����� �������: ";
			cin >> surname;
			cout << endl << "������� ������� ��������!" << endl << endl;
			system("pause");
			break;
		case 2:
			cout << endl << "������� ����� ���: ";
			cin >> nname;
			cout << endl << "��� ������� ��������!" << endl << endl;
			system("pause");
			break;
		case 3:
			cout << endl << "������� ����� ������: ";
			cin >> group;
			cout << endl << "������ ������� ��������!" << endl << endl;
			system("pause");
			break;
		case 4:
			push_disciplines();
			break;
		case 5:
			cout << "������� �������� ����������: ";
			cin >> name;
			delete_disciplines(name);
			break;
		case 6:
			system("cls");
			show_data();
			system("pause");
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << "������� ������������ �������" << endl << endl;
			system("pause");
		}
	}
}
bool Student::find_mark_two() {
	Disciplines* current = head_disciplines;
	for (int i = 0; i < number_of_disciplines; ++i) {
		if (current->mark == 2)
			return true;
		current = current->next_disciplines;
	}
	return false;
}
void Student::average_score() {
	Disciplines* current = head_disciplines;
	int sum = 0;
	for (int i = 0; i < number_of_disciplines; ++i) {
		sum += current->mark;
		current = current->next_disciplines;
	}
	average_mark = static_cast<double>(sum) / number_of_disciplines;
}
