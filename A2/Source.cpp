#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// This new compiler directive will add new functionalities to the existing code to read the email address of the students
#define PRE_RELEASE

// Structure STUDENT_DATA contains the first and last name of each student, separated by a comma in the StudentData.txt file,
struct STUDENT_DATA {
	string firstName;
	string lastName;

#ifdef PRE_RELEASE
	string emailAddress; // It will be declared only while running in PRE_RELEASE version
#endif // PRE_RELEASE
};

int main() {

	// Empty vector named vectorList is created
	vector <STUDENT_DATA> vectorList;
	fstream studentDataFile;

#ifdef PRE_RELEASE
	cout << "PreRelease Version Running" << endl << endl;
	studentDataFile.open("StudentData_Emails.txt", ios::in);
#else
	cout << "Standard Version Running" << endl << endl;
	studentDataFile.open("StudentData.txt", ios::in);
#endif // PRE_RELEASE

	if (studentDataFile.is_open()) {

		// This while loop will continue until it reaches the end of file and parses all the names in the file
		while (!studentDataFile.eof()) {

			string fName, lName;

			// object student_data is created
			STUDENT_DATA student_data_object;

			// Pre-Release version will parse LastName, FirstName, Email from StudentData_Email.txt
#ifdef PRE_RELEASE
			string email;

			// The getline() function will first read the last name, then a comma will separate the data, with the first name
			getline(studentDataFile, lName, ',');
			// The getline() function will first read the first name, then a comma will separate the data, with the email address
			getline(studentDataFile, fName, ',');
			// '\n' will indicates a new line which will separate the email and this loop will go on 
			getline(studentDataFile, email, '\n');
			student_data_object.emailAddress = email;

#else // Standard Version (Step #3) will parse only LastName, First from StudentData.txt
			// The getline() function will first read the last name, then a comma will separate the data, with the first name
			getline(studentDataFile, lName, ',');
			// '\n' will indicates a new line which will separate the first name and this loop will go on 
			getline(studentDataFile, fName, '\n');

#endif // PRE_RELEASE

			// First and Last name will be parsed into this object student_data
			student_data_object.lastName = lName;
			student_data_object.firstName = fName;

			// The first and last name parsed from StudentData.txt will be pushed to the vector <STUDENT_DATA>
			vectorList.push_back(student_data_object);
		}
		// StudentData.txt will be closed
		studentDataFile.close();
	}

	// It will print out the first and last names of the student only if it is compiled in the Debug mode in Standard Version and will print first name, last name and email address if PreRelease Version is running
#ifdef _DEBUG
	for (STUDENT_DATA student_data_object : vectorList) {

#ifdef PRE_RELEASE
		cout << student_data_object.firstName << " " << student_data_object.lastName << " - " << student_data_object.emailAddress << endl;

#else
		cout << student_data_object.firstName << " " << student_data_object.lastName << endl;

#endif // PRE_RELEASE
	}
#endif

	return 1;
}