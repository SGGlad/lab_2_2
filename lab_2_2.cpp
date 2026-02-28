#include "Student.hpp"
#include <iostream>
#include <vector>

int main()
{
	Name name_1{ "Vasya" };
	Second_name sec_name_1{ "Petrov" };
	std::vector<std::string> debts_1{ "math", "geometry" };
	Student student_1{ name_1, sec_name_1, debts_1 };

	Name name_2{ "Petr" };
	Second_name sec_name_2{ "Vasilev" };
	std::vector<std::string> debts_2{ "geometry", "programming", "algebra" };
	Student student_2{ name_2, sec_name_2, debts_2 };

	Student students_12 = student_1 + student_2;
	Name names_12 = students_12.get_name();
	Second_name sec_names_12 = students_12.get_second_name();
	std::vector<std::string> debts_12 = students_12.get_debts();
	names_12.print(); sec_names_12.print();
	for (int i = 0; i < size(debts_12); ++i) {
		std::cout << debts_12[i] << " ";
	}
	std::cout << "\n=============== " << std::endl;

	Student students_12_2 = student_1 / student_2;
	Name names_12_2 = students_12_2.get_name();
	Second_name sec_names_12_2 = students_12_2.get_second_name();
	std::vector<std::string> debts_12_2 = students_12_2.get_debts();
	names_12_2.print(); sec_names_12_2.print();
	for (int i = 0; i < size(debts_12_2); ++i) {
		std::cout << debts_12_2[i] << " ";
	}
	std::cout << "\n=============== " << std::endl;

	student_1 -= student_2;
	Name names_12_3 = student_1.get_name();
	Second_name sec_names_12_3 = student_1.get_second_name();
	std::vector<std::string> debts_12_3 = student_1.get_debts();
	names_12_3.print(); sec_names_12_3.print();
	for (int i = 0; i < size(debts_12_3); ++i) {
		std::cout << debts_12_3[i] << " ";
	}
	std::cout << "\n=============== " << std::endl;
}

