
#include <iostream>
#include <cstring>   // for strlen, strcpy
#include <string>


// TODO: function prototypes
void addStudent(char* name, double gpa, char* names[], double gpas[], int &size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
	if(size < capacity){
		names[size] = new char[std::strlen(name)+1];
		std::strcpy(names[size], name);
		gpas[size] = gpa;
		++size;
	}	
	else{
		throw "List full";
	}
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa){
	if (gpaPtr!=nullptr){
		*gpaPtr = newGpa;		
	}
	else{
		throw "error: pointer to GPA is null";
	}
}

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa){
	std::cout << "NAME: " << name << ", GPA: " << gpa << std::endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size){
	if(size <= 0){
		throw "No students";
	}

	double sum = 0;
	for(int i = 0; i < size; i++){
		sum+=gpas[i];
	}
	return sum/size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
	
	std::cin.ignore();
        switch (choice) {
            case 1: {
                // TODO: implement menu logic
		std::cout << "Enter name" << std::endl;
		std::string name;
		std::getline(std::cin, name);
	
		std::cout << "Enter GPA" << std::endl;
		std::string gpa;
		std::getline(std::cin, gpa);

		try{
			double gpaD = std::stod(gpa);
			addStudent(const_cast<char*>(name.c_str()), gpaD, names, gpas, size, capacity);
			std::cout << name << " has been added!" << std::endl;
		}
		catch (const char *msg){
			std::cout << msg << std::endl;
		}

                break;
            }
            case 2: {
                // TODO: implement menu logic
                if(size==0){
			std::cout << "No students to update" << std::endl;
			break;
		}
		std::string name;
		double gpa;

		std::cout << "Index of student to update gpa: ";
		int idx = -1;
		std::cin >> idx;
		std::cin.ignore();

		if(idx < 0 || idx >= size){
			std::cout << "Index out of range" << std::endl;
			break;
		}

		std::cout << "Enter GPA: ";
		std::cin >> gpa;
		std::cin.ignore();

		try{
			updateGPA(&gpas[idx], gpa);
		}
		catch(const char *msg){
			std::cout << msg <<std::endl;
		}

		break;
            }
            case 3: {
                // TODO: implement menu logic
		for(int i = 0; i < size; i++){
			if(names[i] != nullptr){
				printStudent(names[i], gpas[i]);
			}
		}
                break;
            }
            case 4: {
		try{
			double avg = averageGPA(gpas, size);
			std::cout << "Average GPA: " << avg << std::endl;

			int intAvg = static_cast<int>(avg);
			std::cout << "Rounded Average GPA: " << intAvg << std::endl;
		}
		catch(const char *msg){
			std::cout << msg << std::endl;
		}
                // TODO: implement menu logic
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
		std::cin.clear();
		std::cin.ignore();
            }
        }
    } while (choice != 5);

    // TODO: free memory
    for(int i = 0; i<size;i++){
    	if(names[i] != nullptr){
		delete[] names[i];
		names[i] = nullptr;
	}
    }

    return 0;
}
