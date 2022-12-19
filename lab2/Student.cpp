#include"Student.h"
Student::Student() {
	cout << "Вызван конструктор класса Student" << endl << endl;
	cout << "Введите фамилию: ";
	cin >> surname;
	cout << "Введите Имя: ";
	cin >> nname;
	cout << "Введите номер группы: ";
	cin >> group;
	number_of_disciplines = 0;
	average_mark = 0;
	head_disciplines = nullptr;
	next_student = nullptr;
}
Student::Student(string surname, string nname, string group, Disciplines* head_disciplines) {
	cout << "Вызван конструктор с параметрами класса Student" << endl << endl;
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
	cout << "Вызван деструктор класса Student" << endl << endl;
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
	cout << "Введите название дисциплины: ";
	cin >> tmp->name;
	while (true) {
		cout << "Введите оценку: ";
		cin >> tmp->mark;
		if (cin.fail()) {
			cout << "Некорретный ввод оценки!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		if (tmp->mark < 2 || tmp->mark > 5)
			cout << "Такой оценки нет" << endl;
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
	cout << "Дисциплина успешно добавлена!" << endl << endl;
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
			cout << "Дисциплина успешно удалена!" << endl << endl;
			average_score();
			break;
		}
		if (i == number_of_disciplines - 1)
			cout << "Такой дисциплины нет!" << endl << endl;
		prev = current;
		current = current->next_disciplines;
	}
	system("pause");
}
void Student::show_data() {
	cout << "Фамилия и Имя: " << surname << " " << nname << endl;
	cout << endl << "Номер группы: " << group;
	cout << endl << "Дисциплины и оценки" << endl;
	if (number_of_disciplines == 0)
		cout << "Дисциплин нет" << endl;
	else {
		Disciplines* current = head_disciplines;
		for (int i = 0; i < number_of_disciplines; ++i) {
			cout << current->name << " - " << current->mark << endl;
			current = current->next_disciplines;
		}
	}
	cout << endl << "Средний бал: " << average_mark << endl;
}
void Student::change_data() {
	int button;
	string name;
	bool flag = true;
	while (flag) {
		system("cls");
		show_data();
		cout << endl << "Выберите, что нужно поменять" << endl << endl;
		cout << "1 - Фамилия" << endl;
		cout << "2 - Имя" << endl;
		cout << "3 - Номер группы" << endl;
		cout << "4 - Добавить дисциплину" << endl;
		cout << "5 - Удалить дисциплину" << endl;
		cout << "6 - Показать информацию" << endl;
		cout << "0 - Выход из меню редактирования студента" << endl;
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (button) {
		case 1:
			cout << endl << "Введите новую фамилию: ";
			cin >> surname;
			cout << endl << "Фамилия успешно изменена!" << endl << endl;
			system("pause");
			break;
		case 2:
			cout << endl << "Введите новое имя: ";
			cin >> nname;
			cout << endl << "Имя успешно изменено!" << endl << endl;
			system("pause");
			break;
		case 3:
			cout << endl << "Введите новую группу: ";
			cin >> group;
			cout << endl << "Группа успешно изменена!" << endl << endl;
			system("pause");
			break;
		case 4:
			push_disciplines();
			break;
		case 5:
			cout << "Введите название дисциплины: ";
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
			cout << "Введена некорректная команда" << endl << endl;
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
