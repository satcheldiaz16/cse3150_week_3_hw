
#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
	
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa){
	if (gpaPtr!=nullPtr{
		*gpaPtr = newGpa;		
	}
}

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa){
	std::cout << name << ", GPA: " << gpa << std::endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size){
	if(size <= 0){
		throw "error at averageGPA: size of gpas[] must be larger than zero";
	}

	double sum = 0;
	for(double gpa: gpas){
		sum+=gpa;
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

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
                break;
            }
            case 2: {
                // TODO: implement menu logic
                break;
            }
            case 3: {
                // TODO: implement menu logic
		for(int i = 0; i < capacity; i++){
			if(names[i] != null){
				printStudent(names[i], gpas[i]);
			}
		}
                break;
            }
            case 4: {
                // TODO: implement menu logic
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory

    return 0;
}
