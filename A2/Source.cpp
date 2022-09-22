#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Structure STUDENT_DATA contains the first and last name of each student, separated by a comma in the StudentData.txt file,
struct STUDENT_DATA {
	string firstName;
	string lastName;
};

int main() {
	vector <STUDENT_DATA> vectorList;
	fstream studentDataFile;

	studentDataFile.open("StudentData.txt", ios::in);

	if (studentDataFile.is_open()) {

		// This while loop will continue until it reaches the end of file and parses all the names in the file
		while (!studentDataFile.eof()) {

			string fName, lName;

			// The getline() function will first read the last name, then a comma will separate the data, with the first name
			getline(studentDataFile, lName, ',');
			// '\n' will indicates a new line which will separate the first name and this loop will go on 
			getline(studentDataFile, fName, '\n');

			// object student_data will be created
			STUDENT_DATA student_data_object;

			// First and Last name will be parsed into this object student_data
			student_data_object.lastName = lName;
			student_data_object.firstName = fName;

			// The first and last name parsed from StudentData.txt will be pushed to the vector <STUDENT_DATA>
			vectorList.push_back(student_data_object);
		}
		// StudentData.txt will be closed
		studentDataFile.close();
	}

	// It will print out the first and last names of the student only if it is compiled in the Debug mode
#ifdef _DEBUG
	for (STUDENT_DATA student_data_object : vectorList) {
		cout << student_data_object.firstName << " " << student_data_object.lastName << endl;
	}
#endif

	return 1;
}