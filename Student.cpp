#include "Student.hpp"


Name::Name() = default;
Name::Name(std::string name) :name_(name) {}
Name::Name(const Name& other) {
	name_ = other.name_;
}
Name& Name::operator=(const Name& other) {
	name_ = other.name_;
	return *this;
}
Name Name::operator+(const Name& other) {
	return Name{ name_ + other.name_ };
}
Name Name::operator+(const std::string& other) {
	return Name{ name_ + other };
}
Name Name::operator+(const char& other) {
	return Name{ name_ + other };
}
void Name::print() {
	std::cout << name_<<" ";
}




Second_name::Second_name() = default;
Second_name::Second_name(std::string second_name) :second_name_(second_name) {}
Second_name::Second_name(const Second_name& other) {
	second_name_ = other.second_name_;
}
Second_name& Second_name::operator=(const Second_name& other) {
	second_name_ = other.second_name_;
	return *this;
}
Second_name Second_name::operator+(const Second_name& other) {
	return Second_name{ second_name_ + other.second_name_ };
}
Second_name Second_name::operator+(const std::string& other) {
	return Second_name{ second_name_ + other };
}
void Second_name::print() {
	std::cout << second_name_<<" ";
}


Student::Student(Name name, Second_name second_name, std::vector<std::string>& debts) : name_(name), second_name_(second_name), debts_(debts) {}
Student::Student(const Student& other) {
	name_ = other.name_;
	second_name_ = other.second_name_;
	debts_.clear();
	debts_ = other.debts_;
}
Student::~Student() {
	debts_.clear();
	debts_.shrink_to_fit();
	std::cout << "dtor" << std::endl;
}
Student& Student::operator=(const Student& other) {
	name_ = other.name_;
	second_name_ = other.second_name_;
	std::copy(begin(other.debts_), end(other.debts_), begin(debts_));
	debts_.pop_back();
	return *this;
}
const Student Student::operator+(const Student& other_1) {
	Name name_tmp_ = name_ + " and " + other_1.name_ + " ";
	Second_name second_name_tmp_ = second_name_ + "/" + other_1.second_name_ + " ";
	std::vector<std::string> debts_tmp_;
	for (int i = 0; i < size(other_1.debts_); ++i) {
		if (std::count(begin(debts_), end(debts_), other_1.debts_[i]) == 0) {
			debts_tmp_.push_back(other_1.debts_[i]);
		}
	}
	for (int i = 0; i < size(debts_); ++i) {
		if (std::count(begin(debts_tmp_), end(debts_tmp_), debts_[i]) == 0) {
			debts_tmp_.push_back(debts_[i]);
		}
	}
	return Student{ name_tmp_, second_name_tmp_, debts_tmp_ };
}
Student& Student::operator-=(const Student& other) {
	name_ = name_ + " without " + other.name_ + " ";
	second_name_ = second_name_ + "/" + other.second_name_ + " ";
	for (int i = 0; i < size(debts_); ++i) {
		if (std::count(begin(other.debts_), end(other.debts_), debts_[i]) != 0) {
			std::erase(debts_, debts_[i]);
		}
	}
	return *this;
}
const Student Student::operator/(const Student& other) {
	Name name_tmp_ = name_ + " and " + other.name_ + " ";
	Second_name second_name_tmp_ = second_name_ + "/" + other.second_name_ + " ";
	std::vector<std::string> debts_tmp_ = debts_;
	for (int i = 0; i < size(debts_tmp_); ++i) {
		if (std::count(begin(other.debts_), end(other.debts_), debts_tmp_[i]) == 0) {
			std::erase(debts_tmp_, debts_tmp_[i]);
		}
	}
	return Student{ name_tmp_, second_name_tmp_, debts_tmp_ };
}
void Student::set_name(Name name) {
	name_ = name;
}
void Student::set_second_name(Second_name second_name) {
	second_name_ = second_name;
}
void Student::set_debts(std::vector<std::string> debts) {
	std::copy(begin(debts), end(debts), begin(debts_));
	debts_.pop_back();
}
Name Student::get_name() { return name_; }
Second_name Student::get_second_name() { return second_name_; }
std::vector<std::string> Student::get_debts() { return debts_; }

