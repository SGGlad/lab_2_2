#include <iostream>
#include <vector>

struct Name {
	Name() = default;
	Name(std::string name) :name_(name) {}
	Name(const Name& other) {
		name_ = other.name_;
	}
	Name& operator=(const Name& other) {
		name_ = other.name_;
		return *this;
	}
	Name operator+(const Name& other){
		return Name{name_+other.name_};
	}
	Name operator+(const std::string& other) {
		return Name{name_+other};
	}
	Name operator+(const char& other) {
		return Name{ name_ + other };
	}
	void print() {
		std::cout << name_;
	}
	std::string name_;
};

struct Second_name {
	Second_name() = default;
	Second_name(std::string second_name) :second_name_(second_name) {}
	Second_name(const Second_name& other) {
		second_name_ = other.second_name_;
	}
	Second_name& operator=(const Second_name& other) {
		second_name_ = other.second_name_;
		return *this;
	}
	Second_name operator+(const Second_name& other) {
		return Second_name{ second_name_ + other.second_name_ };
	}
	Second_name operator+(const std::string& other) {
		return Second_name{ second_name_ + other };
	}
	void print() {
		std::cout << second_name_;
	}
	std::string second_name_;
};




class Student {
public:
	Student(Name name, Second_name second_name, std::vector<std::string> &debts) : name_(name), second_name_(second_name), debts_(debts) {}
	Student(const Student& other) {
		name_ = other.name_;
		second_name_ = other.second_name_;
		debts_.clear();
		debts_ = other.debts_;
	}
	~Student() {
		debts_.clear();
		debts_.shrink_to_fit();
		std::cout << "dtor" << std::endl;
	}
	Student& operator=(const Student& other){
		name_ = other.name_;
		second_name_ = other.second_name_;
		std::copy(begin(other.debts_), end(other.debts_), begin(debts_));
		return *this;
	}
	const Student operator+(const Student& other_1) {
		Name name_tmp_= name_ + " and " + other_1.name_ + " " ;
		Second_name second_name_tmp_= second_name_ + "/" + other_1.second_name_ + " " ;
		std::vector<std::string> debts_tmp_ = debts_;
		for (int i=0; i < size(other_1.debts_); ++i) {
			if  (std::count(begin(debts_tmp_), end(debts_tmp_), other_1.debts_[i])==0) {
				debts_tmp_.push_back(other_1.debts_[i]);
			}
		}
		return Student{name_tmp_, second_name_tmp_, debts_tmp_};
	}
	Student& operator-=(const Student& other) {
		name_ = name_ + " without " + other.name_ + " ";
		second_name_ = second_name_ + "/" + other.second_name_ + " ";
		for (int i = 0; i < size(debts_); ++i) {
			if (std::count(begin(other.debts_), end(other.debts_), debts_[i]) != 0) {
				std::erase(debts_,debts_[i]);
			}
		}
		return *this;
	}
	const Student operator/(const Student& other) {
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
	void set_name(Name name) {
		name_ = name;
	}
	void set_second_name(Second_name second_name) {
		second_name_ = second_name;
	}
	void set_debts(std::vector<std::string> debts) {
		std::copy(begin(debts), end(debts), begin(debts_));
	}
	Name get_name() { return name_; }
	Second_name get_second_name() { return second_name_; }
	std::vector<std::string> get_debts() { return debts_; }
private:
	Name name_;
	Second_name second_name_;
	std::vector<std::string> debts_;
};





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

