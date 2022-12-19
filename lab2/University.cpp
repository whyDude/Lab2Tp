#include"University.h"
University::University() {
	head_student = nullptr;
	number_of_student = 0;
}
University::University(const University& other) {
	Student* cur = other.head_student; 
	for (int i = 0; i < other.number_of_student; ++i) {
		Student* tmp = new Student(cur->get_surname(), cur->get_nname(), cur->get_group(), cur->get_head_disciplines());
		++this->number_of_student;

		if (this->head_student == nullptr) {
			this->head_student = tmp;
		}
		else {
			tmp->set_next_student(this->head_student);
			this->head_student = tmp;
		}
		cur = cur->get_next_student();
	}
}
University::~University() {
	Student* current;
	for (int i = 0; i < number_of_student; ++i) {
		current = head_student;
		head_student = head_student->get_next_student();
		delete current;
	}
}
istream& operator >> (istream& in, University& obj) {
	system("cls");
	Student* tmp = new Student; 
	++obj.number_of_student; 
	if (obj.head_student == nullptr) { 
		obj.head_student = tmp;
	}
	else {
		tmp->set_next_student(obj.head_student); 
		obj.head_student = tmp; 
	}
	cout << "Студент успешно добавлен!" << endl << endl;
	system("pause");
	return in;
}
ostream& operator<<(ostream& out, University& obj) {
	Student* current = obj.head_student;
	try {
		if (obj.number_of_student == 0)
			throw exception("Список студентов пуст!");
		for (int i = 0; i < obj.number_of_student; ++i) {
			current->show_data(); 
			out << "------------------------------------------------------" << endl;
			current = current->get_next_student();
		}
	}
	catch (exception& ex) {
		out << ex.what() << endl << endl;
	}
	return out;
}
void University::delete_student() {
	system("cls");
	try {
		if (get_number_of_student() == 0)
			throw exception("Список студентов пуст!");
		string surname;
		string nname;
		cout << "Введите фамилию: ";
		cin >> surname;
		cout << "Введите имя: ";
		cin >> nname;
		Student* current = head_student;
		Student* prev = head_student;
		for (int i = 0; i < number_of_student; ++i) {
			if (current->get_surname() == surname && current->get_nname() ==
				nname) {
				if (current == head_student) {
					head_student = head_student->get_next_student();
					delete current;
					--number_of_student;
				}
				else {
					prev->set_next_student(current->get_next_student());
					delete current;
					--number_of_student;
				}
				cout << "Студент успешно удален!" << endl << endl;
				break;
			}
			if (i == number_of_student - 1)
				cout << "Такого студента нет!" << endl << endl;
			prev = current;
			current = current->get_next_student();
		}
		system("pause");
	}
	catch (exception& ex) {
		system("cls");
		cout << ex.what() << endl << endl;
		system("pause");
	}
}
void University::show_student_two() {
	system("cls");
	Student* current = head_student;
	bool flag = false;
	cout << "Список студентов, у которых есть хотя бы одна оценка 2" << endl << endl;
	try {
		if (number_of_student == 0)
			throw exception("Список студентов пуст!");
		for (int i = 0; i < number_of_student; ++i) {
			if (current->find_mark_two()) {
				flag = true;
				current->show_data();
				cout << "------------------------------------------------------" << endl <<
					endl;
			}
			current = current->get_next_student();
		}
		if (!flag) 
			cout << "Студентов с оценкой 2 нет!" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;
	}
	system("pause");
}
void University::sort_student() { 
	for (int i = 0; i < number_of_student - 1; ++i) {
		Student* current = head_student;
		Student* prev = head_student;
		while (current->get_next_student() != nullptr) {
			if (current->get_average_mark() > current->get_next_student()->get_average_mark()) { 
				Student* next = current->get_next_student();
				if (current == head_student) {
					head_student = next;
					current->set_next_student(next->get_next_student());
					next->set_next_student(current);
					current = head_student;
				}
				else {
					prev->set_next_student(next);
					current->set_next_student(next->get_next_student());
					next->set_next_student(current);
					current = next;
				}
			}
			prev = current;
			current = current->get_next_student();
		}
	}
}

Student* University::find_student(string surname, string nname) {
	Student* current = head_student;
	for (int i = 0; i < number_of_student; ++i) {
		if (current->get_surname() == surname && current->get_nname() == nname)
			return current;
		current = current->get_next_student();
	}
	return nullptr;
}
