#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <map>

void to_upper_inplace(std::string & s){
	for (char & c : s){
		c = toupper(static_cast<unsigned char>(c));
	}
}

void capitalize_name(std::string& s){
	if (s.empty()) return;
	s[0] = toupper(static_cast<unsigned char>(s[0]));
	for (size_t i = 1; i < s.size(); ++i) {
		s[i] = tolower(static_cast<unsigned char>(s[i]));
	}
}

template <typename it>
double average(it first, it last){
	if(first == last){
		return 0.0;
	}
	auto count = std::distance(first, last);

	double sum = std::accumulate(first, last, 0.0);

	return sum / count;
}

class Student{
private:
	int id{};
	std::string firstname;
	std::string lastname;
	std::vector<int> grades;

public:
	Student() = default;

	Student(int id_, std::string f, std::string l): id(id_), firstname(f), lastname(l) { normalizeNames();}

	int getId() const {
		return id;
	}

	std::string getFirst() const {
		return firstname;
	}

	std::string getLast() const {
		return lastname;
	}

	std::vector<int> getGrades() const {
		return grades;
	}

	void addGrade(int g){
		if(g >= 0 && g<=100 ){

			grades.push_back(g);

		} else {
			std::cout << "Invalid grade : " <<g << "\n";
		}
	}

	double avg() const {
		return average(grades.begin(), grades.end());
	}

	std::string fullName() const {
		return firstname + " " + lastname;
	} 

	void normalizeNames(){
		capitalize_name(firstname);
		to_upper_inplace(lastname);
	}

};

int main(){

	std::map<int, Student> students;

	auto addStudent = [&] (int id, std::string first, std::string last ){
		if(students.count(id)){
			std::cout << "Student already exists" << "\n";

		} else{
			students.emplace(id, Student{id, first, last});
			std::cout << "Added student " << id <<"\n";
		}
	};

	auto addStudentGrade = [&](int id, int g){
		auto it = students.find(id);
		if(it== students.end()){
			std::cout << "No student with the id found" << "\n";
			return;
		}else{
			it->second.addGrade(g);
			std::cout << "Grade added successfully" << "\n";

		}
	};

	auto showStudent = [&] (int id){
		auto it = students.find(id);
		if(it == students.end()){
			std::cout << "Student with id not found" << "\n";
		} else {
			const Student & s = it->second;
			std::cout << s.fullName() << "\n";
			for(int g: s.getGrades()){
				std::cout << g << '\n';
			}
		}
	};

	auto listAll = [&] {
	        if (students.empty()) {
	            std::cout << "No students found\n";
	            return;
	        }
	        for (const auto& a : students) {
	            std::cout << "ID: " << a.first << ", Name: " << a.second.fullName();
	            std::cout << ", Grades: ";
	            const auto& gg = a.second.getGrades();
	            if (gg.empty()) {
	                std::cout << "None";
	            } else {
	                for (size_t i = 0; i < gg.size(); ++i) {
	                    std::cout << gg[i];
	                    if (i < gg.size() - 1) std::cout << ", ";
	                }
	            }
	            std::cout << "\n\n";
	        }
	    };
	while (true){
		std::cout <<
        "\n=== Gradebook Menu ===\n"
        "1) Add student\n"
        "2) Add grade\n"
        "3) Show student\n"
        "4) Show all students\n"
        "0) Quit\nChoose: ";

        int choice;
        std::cin >> choice;
        if(choice ==1){
        	int id;
        	std::string f, l;
        	std::cout << "ID first last: ";
        	std::cin >> id >> f >> l;
        	addStudent(id,f,l);
        	
        } else if (choice == 2) {
        	int id, g;
        	std::cout << "ID grade: ";
        	std::cin >> id >> g;
        	addStudentGrade(id, g);
        } else if (choice == 3) {
        	int id;
        	std::cout << "ID: ";
        	std::cin >> id;
        	showStudent(id);
        } else if (choice == 4){

        	listAll();


        } else if (choice == 0) {
        	break;
        } else {
        	std::cout << "Invalid choice.\n";
        }
	}

	return 0;
}