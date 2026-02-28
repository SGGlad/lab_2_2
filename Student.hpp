#pragma once
#include <iostream>
#include <vector>

struct Name {
	Name();
	Name(std::string name);
	Name(const Name& other);
	Name& operator=(const Name& other);
	Name operator+(const Name& other);
	Name operator+(const std::string& other);
	Name operator+(const char& other);
	void print();
	std::string name_;
};
struct Second_name {
	Second_name();
	Second_name(std::string second_name);
	Second_name(const Second_name& other);
	Second_name& operator=(const Second_name& other);
	Second_name operator+(const Second_name& other);
	Second_name operator+(const std::string& other);
	void print();
	std::string second_name_;
};
class Student {
public:
	Student(Name name, Second_name second_name, std::vector<std::string>& debts);
	Student(const Student& other);
	~Student();
	Student& operator=(const Student& other);
	const Student operator+(const Student& other_1);
	Student& operator-=(const Student& other);
	const Student operator/(const Student& other);
	void set_name(Name name);
	void set_second_name(Second_name second_name);
	void set_debts(std::vector<std::string> debts);
	Name get_name();
	Second_name get_second_name();
	std::vector<std::string> get_debts();
private:
	Name name_;
	Second_name second_name_;
	std::vector<std::string> debts_;
};